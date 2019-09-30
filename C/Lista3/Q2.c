#include <stdio.h>

int main(){
	
	char texto[100];
	char vogais[5] = {'a', 'e', 'i', 'o', 'u'};
	int vogaisCount = 0;	
	
	printf("\Q2 - Vou te informar quantas vogais o texto tera.\nDigite algo: ");
	
	scanf("%[^\n]s", texto);
	
	int i;
	int v;
	for(i=0; i < 50; i++){
		
		for(v=0; v < 5; v++){
			if(texto[i] == vogais[v]){
				vogaisCount++;
				printf(".");
				break;
			}
		}
		
		if(texto[i] == '\0'){					
			printf("Esse texto possui %d caracteres e %d vogais.\n", i, vogaisCount);
			break;
		} else {
			printf("%c %d\n", texto[i], i+1);
		}
	}
		
	return 0;
}
