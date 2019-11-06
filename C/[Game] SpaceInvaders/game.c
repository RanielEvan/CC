#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>



//------- MACROS
//Altura e Largura da Tela
#define TLARGURA 40
#define TALTURA 10

//Tempo de cada Update
#define SLEEPRATE 10


#include <windows.h>




void GerarMapa(){
		
	
	int h, v; 
	for(v=0; v < TALTURA; v++){ //Vertical
			
		for(h=0; h < TLARGURA; h++){ //Horizontal
		
		
			printf("%c", (h == 0 || h == TLARGURA -1)? '¦' : ' ');
			printf("%c", (v == 0 || v == TALTURA - 1)? '-' : ' ');
			
			
		}
		
		printf("\n"); //Pula linha...	
	} 	
}



//CODIGOS DA NET
void HideCursor()
{
   	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   	CONSOLE_CURSOR_INFO info;
   	info.dwSize = 100;
   	info.bVisible = FALSE;
   	SetConsoleCursorInfo(consoleHandle, &info);
   
	//https://stackoverflow.com/questions/30126490/how-to-hide-console-cursor-in-c
}


void Update(){
	
	//METODO UPDATE
	//Esse é o loop do Game
	//Talvez passar parametro...
	
	
	do
	{
		system("cls"); //Limpa a tela
	
		//METODOS
		GerarMapa();
		
		
		
		
		
		
		Sleep(SLEEPRATE);
	}
	while(1); //Loop infinito.. O jogo terá um metodo com Break;
}

int main(){
	
	char *locale;
    locale = setlocale(LC_ALL, "");
    
	
	HideCursor();
	
	
	//Metodo Principal
	Update();
	
	
	return 0;
}




