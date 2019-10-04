#include<stdio.h>
	
/* 
Raniel Evangelista - 1910026087
*/
	
char Q7_nome[40];

int main(){
	printf("\nQ7 - Digite um nome completo: ");
	scanf("%[^\n]s", Q7_nome);
	
	int i;
	for(i=0; i<40; i++){
		
		if(Q7_nome[i] == '\0')
			break;
		
		else if(Q7_nome[i] == ' '){
			printf("\n");
			continue;
		}
		
		printf("%c", Q7_nome[i]);	
	}
}
				
				
