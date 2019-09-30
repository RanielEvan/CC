#include <stdio.h>

int main(){
	
	char texto1[100];
	char texto2[100];
	char textosConcat[200];	
	int index = 0;
	
	printf("\Q5 - Irei concatenar 2 textos para voce.\nDigite o texto 1: ");
	fgets(texto1, 100, stdin);
	
	printf("Digite o texto 2: ");
	fgets(texto2, 100, stdin);
	

	int i;
	for(i=0; i < 100; i++){
		
		if(texto1[i] == '\n'){
			continue;
		}
		textosConcat[index] = texto1[i];

		if(texto1[i] == '\0'){					
			break;
		}
		
		index++;		
	}
	
	for(i=0; i<100; i++){
		textosConcat[index] = texto2[i];
		
		if(texto2[i] == '\0'){
			break;
		}
		
		index++;
	}
		
	printf("Texto concatenado: %s", textosConcat);
	
	return 0;
}
