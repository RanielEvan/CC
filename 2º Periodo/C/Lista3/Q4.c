#include <stdio.h>

int main(){
	
	char texto1[100];
	char texto2[100];	
	
	printf("\Q4 - Vou copiar o texto informado para outra variavel e te mostrar\nDigite algo: ");
	//scanf("%100[^\n]s", texto1);
	fgets(texto1, 100, stdin);
	
	int i;
	for(i=0; i < 100; i++){
	
		texto2[i] = texto1[i];
		
		if(texto1[i] == '\0'){					
			printf("Texto copiado com sucesso!\n RESULTADO: %s", texto2);
			break;
		}
	}
		
	return 0;
}
