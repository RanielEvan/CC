#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>

#include <dos.h>
#include <dir.h>


//------- MACROS
//Altura e Largura da Tela
#define TLARGURA 30
#define TALTURA 15

//Tempo de cada Atualizacao
#define SLEEPRATE 1

//Quantidade de Mobs no Grupo
#define MOBCOUNT 25
#define QTDFILA 5

//Intervalo de updates para que os moves se movam
#define MOBINTERVALO 20
#define MOBTIROINTERVALO 5

//Maximo de tiros no game
#define MAXTIROS 20

//https://stackoverflow.com/questions/29574849/how-to-change-text-color-and-console-color-in-codeblocks

void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}



//------- ESTRUTURAS/TIPOS
typedef struct {
	int posicao[2];//	Posicao X [0] e Y [1]
	int speed;//= 1		Quantidade de espacos que o player vai andar por atualização.
	int dano;//= 10		Dano do player
	int vida;//= 50		Vida do player
} Player;

typedef struct {
	int posicao[2];//	Posicao X [0] e Y [1]
	int vida;//= 10		Vida do mob
	int dano;//= 5		Dano do mob
	int vivo;//= 1		Estado do mob (1 Vivo, 0 Dead)
} Mob;

typedef struct {
	int posicao[2];//		Posicao inicial do grupo
	Mob mobs[MOBCOUNT];//	Array de Mobs
	int mobCount;//			QTD de mobs.
} MobGroup;


typedef struct {
	int doPlayer;//		Indica se é do player ou do mob
	int posicao[2];//	Posicao X [0] e Y [1]
	int speed;//= 10	Rapidez da bala mob
	int dano;//= 5	 	Dano dessa bala
	int ativo;//= 1		Estado da bala
} Tiro;


//------- VARIAVEIS GLOBAIS
int ATIVO = 1;//	Se estiver jogando ou nao. Inicia 0, pois antes, existe o menu. 1 para Debug

//PLAYER
Player player; //				Declara um player (global), os valores serão setados no metodo MontarJogo()
char playerSkin[] = "/A\\";//	Desenho do Player

//MOBS
MobGroup mobs;//	Declara uma lista de Mobs
int mobsMoveDir = 1;//	Direção de movimento dos mobs (-1 Esquerda, 1 Direita)
int mobVidaMax;//	Vida maxima do bot

//PROJETEIS
Tiro tiros[MAXTIROS];//	Declara lista de tiros (OBJ POOL)


//Métodos do Game
void MontarJogo(); //	Instancia Player e Mobs
void Atualizar(); //	Atualiza o console.

void Controles();// 	Le as entradas do usuario e atualiza o player
void Desenhar();//		Desenha o conteudo no console.
void MobsAI();// 		AI dos mobs (atirar e mover)

void Atirar(int, int);//		Metodo de Atirar
void MoverProjeteis();//		Metodo que move os tiros durante o update
void CausarDano(int, int);//	Metodo que causa dano 


//CODIGOS DA NET
void OcultarCursor();
void ResetCursor();


//------ MAIN
int main(){
	
	char *locale;
    locale = setlocale(LC_ALL, "");
    
	OcultarCursor(); //Oculta o Cursor do console..
	
    //Instancia Player e Inimigos
    MontarJogo();
	
	//Metodo principal, atualiza o console.
	Atualizar();
	
	return 0;
}

void MontarJogo(){

	//Player
    player.posicao[0] = (TLARGURA - 3) / 2; //	Essa conta centraliza o player na horizontal.
	player.posicao[1] = TALTURA - 2; //			Pega a altura maxima e coloca o player -2 linhas da borda.
	player.speed = 1;//		Velocidade de movimento
	player.dano = 5;// 		Dano de tiro
	player.vida = 50;//		Vida do player
	
	
	
	//Mobs
	mobs.mobCount = MOBCOUNT;//	Qtd de Mobs (necessaria pra checar o fim do jogo)	
	
	mobs.posicao[0] = (TLARGURA - QTDFILA * 2) / 2; //2 coluna
	mobs.posicao[1] = 2; //2 linha
	
	int i;
	for(i=0; i < MOBCOUNT; i++){
		
		mobs.mobs[i].vida = 15;
		mobs.mobs[i].dano = 5;
		mobs.mobs[i].vivo = 1;
		
		if(i > 0) {
			
			mobs.mobs[i].posicao[0] = mobs.mobs[i-1].posicao[0] + 2;
			mobs.mobs[i].posicao[1] = mobs.mobs[i-1].posicao[1];
			
			if(i % QTDFILA == 0){
				mobs.mobs[i].posicao[0] = mobs.mobs[0].posicao[0];
				mobs.mobs[i].posicao[1] = mobs.mobs[i-1].posicao[1] + 1;
			}
			
		} else {
			mobs.mobs[i].posicao[0] = mobs.posicao[0];
			mobs.mobs[i].posicao[1] = mobs.posicao[1];
			
			mobVidaMax = mobs.mobs[i].vida;
		}	
	}
}


void Atualizar(){


	SetColor(11);
	printf("Pressione qualquer tecla para iniciar!");
	
  	getch();
	system("cls");

	//Esse é o loop do Game
	do
	{
		//Esse metodo faz com que o cursor que 'escreve' na tela
		//volte para a posição 0,0 (canto superior esquerdo)
		ResetCursor();
		
		
		/*
		system("cls"); //LIMPA O CONSOLE [nesse caso não é bom utiliza-lo]
	
		Ao invez de limpar todo o console,
		ele reescreve tudo em cima do que ja esta escrito.
		sem a necessidade de LIMPAR (o que causa o fliker [conteudo fica piscando no loop])
		*/
		
	
		
		//Mover Projeteis
		MoverProjeteis();
		
		//Mobs AI
		MobsAI(); //Move e atira
		
		//Controles
		Controles();
		
		//Desenha
		Desenhar();
		
		
	
		
//		Sleep(SLEEPRATE); //Tempo para reescrever no console, resolvi tirar, pois é o fator de Lag
	}
	while(ATIVO);
	
	printf("\n\n Fim de Jogo... Pressione qualquer tecla para sair!");
	getch();
}

char ch;
void Controles(){
	
	//Se alguma tecla for pressionada...
	if(kbhit()){
		
		//Captura essa tecla, e faz algo..
		ch = getch(); 
		switch(ch){
		
			case 80:	//SETA BAIXO (Oculta o cursor, pra nao ter que ficar chamando sempre)
				OcultarCursor();
				break;
			case 75:	//SETA ESQUERDA
				player.posicao[0] -= player.speed;
				break;
			case 77:	//SETA DIREITA
				player.posicao[0] += player.speed;
				break;
//			case 72:	//SETA CIMA
//				Atirar(1, 0);
//				break;
//			case 32:	//ESPACO
//				Atirar(1, 0);
//				break;		
		} 
		
		if(ch == 72 || ch == 32) { //Seta cima
			Atirar(1, 0);
		}
		
//		if(ch == 75){	//SETA ESQUERDA
//			player.posicao[0] -= player.speed;
//		} else if (ch == 77){ 	//SETA DIREITA
//			player.posicao[0] += player.speed;
//		}
//	
    }

}


int interCount, mobMoveCount, mg = 0;
void MobsAI(){
	
	interCount++; //	Incrementa a cada update
	if(interCount < MOBINTERVALO){ //	Se o contador for menor que o intervalo
		return; //		Para esse metodo aqui.
	}
	//Se por acaso o contador for igual ao intervalo, não entra no IF, dai continua o metodo...
	interCount = 0; //	Zeramos esse contador.
	
	

	//MOVIMENTACAO MOBS
	mobs.posicao[0] -= mobsMoveDir;// 	MOVE O GRUPO DE MOBS..
	
	if(mobs.posicao[0] <= 1 || mobs.posicao[0] + QTDFILA * 2 >= TLARGURA - 1 ){ //Se chegar nos limites da tela
		mobsMoveDir *= -1;  //Inverte a orientação dos Mobs
		mobMoveCount++;
		if(mobMoveCount % 2 == 0){
			mobs.posicao[1] += 1;
		}
	}
	
	
	//Move todos os mobs individualmente
	for(mg=0; mg < MOBCOUNT; mg++){

		if(mg > 0) {
			
			mobs.mobs[mg].posicao[0] = mobs.mobs[mg-1].posicao[0] + 2;
			mobs.mobs[mg].posicao[1] = mobs.mobs[mg-1].posicao[1];
			
			if(mg % QTDFILA == 0){
				
				if(mg/QTDFILA == 2 || mg/QTDFILA == 4){ //	Essa operação intercala as posicoes das filas pares
					mobs.mobs[mg].posicao[0] = mobs.mobs[0].posicao[0];
				} else {
					mobs.mobs[mg].posicao[0] = mobs.mobs[0].posicao[0] + 1;
				}
				
				mobs.mobs[mg].posicao[1] = mobs.mobs[mg-1].posicao[1] + 1;
			}
			
		} else {
			mobs.mobs[mg].posicao[0] = mobs.posicao[0];
			mobs.mobs[mg].posicao[1] = mobs.posicao[1];
		}	
	}
	
	//Pega um numero aleatorio entre 1 e MOBCOUNT, pra saber qual mob vai atirar..
	int mobSorteado;
	
	while (ATIVO){
		mobSorteado = (rand() % (0 - MOBCOUNT + 1)) + 0; 
		if(mobs.mobs[mobSorteado].vivo){
			Atirar(0, mobSorteado);
			break;
		}
	}
//	 else {
//		int prm;
//		for(prm = 0; prm < MOBCOUNT; prm++){
//			if(mobs.mobs[prm].vivo){
//				Atirar(0, prm);
//				break;
//			}
//		}	
//	}
	
	
	
}


int p, mi = 0;
void MoverProjeteis(){
	
	//Esse metodo muda a posicao da bala a cada atualizacao
	
	for(p=0; p<MAXTIROS; p++){ //Para cada ...
		
		if(tiros[p].ativo){ //... tiro ativo no mapa
			
			if(tiros[p].doPlayer){
				
				//Se forem tiros do PLAYER (de baixo para cima) eles se movem  Y-Speed
				tiros[p].posicao[1] -= tiros[p].speed;

			} else {
				mi++;
				if(mi >= MOBTIROINTERVALO){ // 	Delayzinho do tiro do mob.. Tire se quiser modo hardcore kkk
					mi = 0;
					
					//Se forem tiros do MOB (de cima para baixo) eles se movem  Y+Speed
					tiros[p].posicao[1] += tiros[p].speed;
				}
				

			}
			
			//Se o tiro chegar ao fim do mapa, ele Desativa para ser reutilizado
			if(tiros[p].posicao[1] > TALTURA - 1  || tiros[p].posicao[1] < 1){
				tiros[p].ativo = 0;
			}
		}
	}
}


int t;
void Atirar(int quem, int mobId){
	
	//Limitamos o maximo de tiros para fazer uma 'pool' de balas
	for(t=0; t<MAXTIROS; t++){
		
		//Se algum tiro estiver inativo, utilizaremos este para ser este tiro...
		if(!tiros[t].ativo){
			
			tiros[t].ativo = 1; //AGORA ESTA ATIVO!
			
			switch(quem){  //Verifica de quem é (passamos no parametro)
				case 0:		//É MOB!
					tiros[t].dano = 5; //		Dano do tiro do MOB
					tiros[t].doPlayer = 0; //		Usamos isso para indentificar de quem é a bala.
					tiros[t].speed = 1; //		Velocidade da bala por update..
					tiros[t].posicao[0] = mobs.mobs[mobId].posicao[0];// X			Posicao X na tela. Nesse caso é a mesma posicao X do mob.
					tiros[t].posicao[1] = mobs.mobs[mobId].posicao[1] + 1; // Y		Posicao Y na tela. Nesse caso fica 1 casa para baixo (+1)
					//																[o eixo Y aqui é invertido, se compado c/ plano cartesiano]
					break;
					
				case 1:		//É PLAYER {Mesma coisa de cima, só que pra o player}
					tiros[t].dano = 5; //		Bota o teu dano kkkk
					tiros[t].doPlayer = 1; // 	Pra o mob poder levar dano...
					tiros[t].speed = 1; //		Velocidade, tbm nao exagere kkkk				  *			       *
					tiros[t].posicao[0] = player.posicao[0]+1;//	Posicao X do player + 1  [X = /A\  e	X+1 = /A\] 
					tiros[t].posicao[1] = player.posicao[1]-1;//	Posicao Y do player, -1 para poder ficar a frente do player.
					break;
			}
			break;
			
		}
		
	}
}

int mli;
void CausarDano(int quem, int mobId){
	
	if(quem){
		mobs.mobs[mobId].vida -= player.dano; //Mob recebe o dano do Player
		if(mobs.mobs[mobId].vida <= 0){ //Se a vida chegar a zero ou menos
			mobs.mobs[mobId].vivo = 0; //Mata o mob..
			mobs.mobCount -= 1;// Decrementa na contagem de mobs
			if(mobs.mobCount == 0){
				ATIVO = 0;
			}
		}
		
		for(mli =0; mli < MOBCOUNT; mli++){
			
		}
		
	} else {
		player.vida -= mobs.mobs[mobId].dano; //Player recebe o dano do Mob
		if(player.vida <= 0){ //Se a vida chegar a zero ou menos
			ATIVO = 0; //GAMEOVER!
			//GameOver(); 
		}
	}
}


int h, v, i, tem, tm; 
void Desenhar(){
		
	for(v=0; v < TALTURA; v++){ //Vertical
		
		printf("  %c", (v == 0)? ' ' : '|'); //Inicio da Linha...
		
		for(h=0; h < TLARGURA; h++){ //Horizontal
		
			tem = 0; //Por hora nao tem nada..
			
			//Desenha os projeteis
			for(i=0; i< MAXTIROS; i++){
				
				if(tiros[i].ativo){
					if(tiros[i].posicao[0] == h && tiros[i].posicao[1] == v){
						for(tm=0; tm<MOBCOUNT; tm++){
							if((mobs.mobs[tm].posicao[0] == tiros[i].posicao[0] &&
							mobs.mobs[tm].posicao[1] == tiros[i].posicao[1]) && 
							mobs.mobs[tm].vivo){
								
								CausarDano(1, tm); //Causa dano no MOB
								
								tiros[i].ativo = 0; //Inativa esse projetil
								break;
							}
						}
						printf("*");
						tem = 1;
						break;
					}
				}
			}
			
			
			if(tem)
				continue;
				
				
			//Desenha os mobs 
			for(i=0; i< MOBCOUNT; i++){
				
				if(mobs.mobs[i].posicao[0] == h && mobs.mobs[i].posicao[1] == v){
					if(mobs.mobs[i].vivo){
						
						printf("%c", (mobs.mobs[i].vida < mobVidaMax/2)? '#':'@');
						
						tem = 1;
						break;//Sai desse loop ao achar mob nessa posicao
						continue;
					} else {
						tem = 0;
					}
				}	
			}
			
			
			if(tem)
			continue;
		
		
			//Desenha o player
			if(player.posicao[0] == h && v == player.posicao[1]){
				tem = 1;
				printf(playerSkin);
				h += 2;
				//continue;
			} 
		
			
			if(tem)
			continue;
		
			
			//SE NAO TIVER MOBS, PROJETEIS OU PLAYER, Desenha elementos do mapa, ou espaco vazio.
			//BORDAS DE CIMA E DE BAIXO..
			//if(!tem){
			printf("%c", (v == 0 || v == TALTURA - 1)? '_' : ' ');	
			//}
			
			
		}
			
		printf("%c", (v == 0)? ' ' : '|'); //Fim da Linha.
			
		printf("\n"); //Pula linha.	
	} 	
}






//Metodos que já peguei prontos na net
void ResetCursor() 
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

void OcultarCursor()
{
   	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   	CONSOLE_CURSOR_INFO info;
   	info.dwSize = 100;
   	info.bVisible = FALSE;
   	SetConsoleCursorInfo(consoleHandle, &info);
   	
	//https://stackoverflow.com/questions/30126490/how-to-hide-console-cursor-in-c
}
