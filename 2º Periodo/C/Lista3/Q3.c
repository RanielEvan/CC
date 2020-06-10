#include <stdio.h>

int main(){
	
	char texto1[100];
	char texto2[100];	
	
	printf("\Q3 - Vou te informar se 2 textos sao iguais.\nDigite o texto 1: ");
	//scanf("%100[^\n]s", texto1);
	fgets(texto1, 100, stdin);
	
	printf("Agora digite o texto 2: ");
	//scanf("%100[^\n]s", texto2);
	fgets(texto2, 100, stdin);
	
	int i;
	for(i=0; i < 100; i++){
	
		printf ("%c - %c\n", texto1[i], texto2[i]);
		
		if(texto1[i] != texto2[i]){
			printf("Os textos sao DIFERENTES!\n");
			break;
		} else if(texto1[i] == '\0'){					
			printf("Os textos sao IGUAIS!\n");
			break;
		}
	}
		
	return 0;
}
