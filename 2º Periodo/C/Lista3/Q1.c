#include <stdio.h>

int main(){
	
	char texto[100];	
	
	printf("\Q1 - Vou te informar quantos caracteres tem, digite um texto: ");
	
	scanf("%[^\n]s", texto);
	//fgets(Q1texto, 50, stdin);
	
	int i;
	for(i=0; i < 50; i++){
		if(texto[i] == '\0'){					
			printf("Esse texto possui %d caracteres.\n", i);
			break;
		} else {
			printf("%c %d\n", texto[i], i+1);
		}
	}
		
	return 0;
}
