#include<stdio.h>

int main(){
	
	/* Raniel da Silva Evangelista - 1910026087 */
	
	//Variaveis das Questoes
	//Q1
	int valor1;
	int valor2;
	int total = 0;
	
	//Q2
	float numQ2;
	float count;
	float soma;
	float media;
				
	
	//Peco perdao mas devido a restricao do tempo, não consegui concluir.
		
	
	int q = 0;
	
	do{
		
		printf("\n\n Questão (1)   |   Questão (2)\n~ Escolha uma questao:");
		scanf("%d", &q);
		
		switch(q){
			
			case 1:
				printf("Digite um numero: ");
				scanf("%d", &valor1);
				printf("Digite outro numero: ");				
				scanf("%d", &valor2);
				
				int i;
				printf("Soma: 0 ");
				
				if(valor1 < valor2){
					for(i = valor1; i <= valor2; i++) 
						if(i%13 != 0){
							total += i;
							
							printf("+ %d = %d ", i, total);
						}else {
							printf("+ 0(%d) = %d ", i, total);
						}
				} else {
					for(i = valor1; i >= valor2; i--) 
						if(i%13 != 0){
							total += i;
							
							printf("+ %d = %d ", i, total);
						}else {
							printf("+ 0(%d) = %d ", i, total);
						}
				}
				
				break;
				
				

				case 2:
					
					numQ2 = 0;
					count = 0;
					soma = 0;
					media = 0;
					
					do{
						
						printf("Digite idade:");
						scanf("%f", &numQ2);
						
						if(numQ2 >= 0){
							count++;
							soma += numQ2;
						}
						
					}
					while(numQ2 >= 0);
					
					media = soma / count;
					
					printf("A media de idade foi %.2f", media);
					
				break;
				
		}
		
		
		//Peco perdao mas devido a restricao do tempo, não consegui concluir.
		
	}while(q != 0);
	
	return 0;
}
