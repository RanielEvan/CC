#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"");
	
	/* 
	Raniel Evangelista - 1910026087
	*/
	
	int questao;
	
	do{
		printf("\n\nLista de Pr�ticas\n");		
		printf("~ Quest�es: 1 2 3 4 5 6 7 8 9  (0-Sair)\n");
		printf("~ Escolha uma quest�o:");
		
		scanf("%d", &questao);
		
		switch(questao){
			
			int Q1_num[5];
			case 1:
			
				printf("\nQ1 - Informe 5 n�meros, irei mostrar em ordem crescente e decrescente dos �ndices.\n(Ex.: 5 10 15 16 25)\n Informe: ");
				scanf("%d %d %d %d %d", &Q1_num[0], &Q1_num[1], &Q1_num[2], &Q1_num[3], &Q1_num[4]);
				
				printf("CRESCENTE: ");
				int i;
				for(i = 0; i<5; i++){
					printf(" %d", Q1_num[i]);
				}		
				
				printf("\nDECRESCENTE: ");
				for(i = 4; i>-1; i--){
					printf(" %d", Q1_num[i]);
				}
				
			break;
			
			
			int Q2_num[10];
			case 2:
				printf("\nQ2 - Informe 10 n�meros, irei dizer quantas vezes digitou o n�mero 3.\n(Ex.: 5 10 3 16 25 3 3 15 10 3)\n Informe: ");
				scanf("%d %d %d %d %d %d %d %d %d %d", &Q2_num[0], &Q2_num[1], &Q2_num[2], &Q2_num[3], &Q2_num[4], &Q2_num[5], &Q2_num[6], &Q2_num[7], &Q2_num[8], &Q2_num[9]);
				
				int contador = 0;
				for(i=0; i<10; i++){
					if(Q2_num[i] == 3){
						contador++;
					}
				}
				
				printf("O n�mero 3 foi digitado %d vezes!", contador);
			break;
			
			int Q3_num[10];
			case 3:
				printf("\nQ3 - Informe 10 n�meros, irei te dizer qual � o maior.\n(Ex.: 5 10 3 16 25 3 3 15 10 3)\n Informe: ");
				scanf("%d %d %d %d %d %d %d %d %d %d", &Q3_num[0], &Q3_num[1], &Q3_num[2], &Q3_num[3], &Q3_num[4], &Q3_num[5], &Q3_num[6], &Q3_num[7], &Q3_num[8], &Q3_num[9]);
				
				int maior = 0;
				for(i=0; i<10; i++){
					if(Q3_num[i] > maior){
						maior = Q3_num[i];
					}
				}
				
				printf("O n�mero %d foi o maior n�mero que voc� digitou.", maior);
			break;	
			
			
			char Q4_nome[40];
			case 4:
				printf("\nQ4 - Digite um nome: ");
				scanf("%s", Q4_nome);
				
				printf("Texto Normal: %s\n", Q4_nome);
				

				//Ordem Crescente
				for(i=0; i<40; i++){
					if(Q4_nome[i] == '\0'){
						break;
					}
					
					printf("%c ", Q4_nome[i]);
				}
				printf("\n");
				
				//Ordem Decrescente
				for(; i>=0; i--){
					
					printf("%c ", Q4_nome[i]);
				}
				
			break;
			
			
			char Q5_nome1[30], Q5_nome2[30];
			case 5:
				printf("\nQ5 - Digite um nome: ");
				scanf("%s", Q5_nome1);
				
				printf("Digite outro nome:");
				scanf("%s", Q5_nome2);
				
				printf("%s - %d\n", Q5_nome1, strlen(Q5_nome1));
				printf("%s - %d\n", Q5_nome2, strlen(Q5_nome2));

				int dif = strcmp(Q5_nome1, Q5_nome2);
				
				if(dif == 0){
					printf("Os nomes tem a mesma quantidade de caracteres.\n");
				} else if(dif < 0){
					printf("O Nome 1 � MENOR que o Nome 2.\n");
				} else if(dif > 0){
					printf("O Nome 1 � MAIOR que o Nome 2.\n");
				}
				
			break;
			
			
			char Q6_texto[40];
			case 6:
				printf("\nQ6 - Digite um texto: ");
				scanf("%s", Q6_texto);
				//fgets(Q6_texto, 40, stdin);
			
				printf("Mai�sculo: ");
				for(i=0; i<40; i++){
					if(Q6_texto[i] == '\0'){
						break;
					}
					char to = toupper(Q6_texto[i]);
					printf("%c", to);	
				}
				printf("\nMin�sculo: ");
				for(i=0; i<40; i++){
					if(Q6_texto[i] == '\0'){
						break;
					}
					char to = tolower(Q6_texto[i]);
					printf("%c", to);	
				}
				
				
			break;
			
			
			case 7:
				printf("AO EXECUTAR O CODIGO DESTE EXERCICIO HOUVE UM BUG, DEVIDO AO LOOP DAS QUESTOES...\n- Enviei essa quest�o separadamente no GITHUB.");
				getch();
			break;
			
			
			case 8:
				printf("Devido ao hor�rio, n�o consegui concluir esta quest�o (8) e a 9.\n");
				getch();
			break;
			
			
			case 9:
				printf("Devido ao hor�rio, n�o consegui concluir esta quest�o (8) e a 9.\n");
				getch();
			break;	
		}
		
	} while(questao != 0);
		
	return 0;
}
