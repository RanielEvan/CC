#include <stdio.h>

int main(){
	
	//ATIVIDADE C - Wallace
	//Raniel Evangelista
	
	printf("Q1 - Preencha a matriz 3x4 (grid)\n");
	
	//Questão 1 (estrutura)
	int grid[3][4];
	int i, o, p; //Contadores do Loop
	
	int qtdCinco = 0; //Questão 2
	int maiorNumero = 0, menorNumero = 5000; //Questão 3
	
	
	//RECEBE OS VALORES
	for(i = 0; i < 3; i++){ 
		for(o = 0; o<4; o++){
			printf("Digite o valor da posicao (%d,%d): ", i+1, o+1);
			scanf("%d", &grid[i][o]);			
		}
	}
	
	
	//DESENHA O GRID
	for(i = 0; i < 3; i++){
		
		for(o = 0; o<4; o++){
			printf("%d", grid[i][o]); //Valor
			
			if(grid[i][o] == 5)
				qtdCinco++; //Incrementa no contador dos 'cincos'
			
			if(grid[i][o] > maiorNumero)
				maiorNumero = grid[i][o];
			else if(grid[i][o] < menorNumero)
				menorNumero = grid[i][o];
			
			if(o != 3){ //Separador
				printf(" - ");
			}
		}
		printf("\n");
	}
	
	printf("\nQ2 - O numero 5 foi digitado %d vezes\n", qtdCinco);
	printf("\nQ3 - O maior numero digitado foi %d, o menor foi %d\n", maiorNumero, menorNumero);	
	
	
	printf("\nQ4 - Temos 10 alunos... Digite 2 notas por aluno:\n");
	float notas[10][3]; //Nota1, Nota2, Media
	
	for(i=0; i<10; i++){
		printf("- Aluno%d:\n", i);
		for(o=0; o<2;o++){
			scanf("%f", &notas[i][o]);
		}
		notas[i][2] = (notas[i][0] + notas[i][1]) / 2; //Média
				
		printf("NOTAS: %.2f %.2f\nMEDIA: %.2f\n", notas[i][0], notas[i][1], notas[i][2]);
	}
	
	
	printf("\nQ5 - Irei desenhar quadrados como esse\n");
	int tamanho = 0;
	for(i=0; i<5; i++){
		for(o=0; o<5;o++){
			printf("X ");
		}
		printf("\n");
	}
	printf("Agora me informe qual tamanho de quadrado deseja ver: ");
	scanf("%d", &tamanho);
	
	for(i = 0; i<tamanho; i++){
		for(o=0; o<tamanho; o++){
			printf("X ");
		}
		printf("\n");
	}
	
	
	
	
	return 0;
	
}
