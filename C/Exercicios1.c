#include <stdio.h>
#include <math.h>

int EPar(int num);

int main(){
	
	/*
	Raniel da Silva Evangelista - CCP2
	1910026087 mat
	*/

	//Variaveis (da erro quando declaro no loop)
	int num;
	//Questao1
	int num1;
	//Q2	
	int num2;
	float numf2, total2;
	//Q3
	int num3;
	float numf3, total3;
	//Q4
	int ano4;
	int resto4;
	//Q5
	float q5nota1, q5nota2, q5nota3, q5media;
	//Q6
	float q6nota1, q6nota2, q6media;
	
	
	//Loop
	do{
		
		//Controle
		printf("\nVoce tem essas opcoes:\n1 2 3 4 5 6 7 8 9\n\nDigite alguma? (0 - Sair) :");
		scanf("%d", &num);
		if(num < 0 || num > 9){
			printf("Eita... Essa opcao nao existe, Parsa.\n");
		}
		
		
		//Lista de questões
		switch(num){
			case 1:
				printf("\nQ1\nDigite um numero para saber se e Par: ");
				scanf("%d", &num1);
				
				
				if(EPar(num1) == 1){
					printf("Esse numero e IMPAR.");
				} else {
					printf("Esse numero e PAR.");
				}
			break;
			
			case 2:

				printf("\nQ2\nDigite um Numero (Float):");
				scanf("%f", &numf2);
				
				printf("Digite uma Potencia (Int):");
				scanf("%d", &num2);
				
				total2 = pow(numf2, num2);	
							
				printf("O valor resultante foi %E (n. cientifica)\n", total2);
								
			break;
			
			case 3:
				printf("\nQ3\nDigite um Numero (Float):");
				scanf("%f", &numf3);
				
				printf("Digite uma Base [Raiz] (Int):");
				scanf("%d", &num3);
				
				if(num3 != 2){
					printf("OPA.. NAO SOUBE RESPONDER ESSA... Mas\n");
				}
										
				printf("a raiz Quadrada do Numero Float seria %E (n. cientifica)\n", total2);
			
			break;
			
			case 4:
				printf("\nQ4\nIrei informar se o ano e bissexto, digite um ano:");
				scanf("%d", &ano4);
				
				resto4 = ano4 % 4;
				
				if(resto4 == 0){
					printf("Esse ano e bissexto!");
				} else {
					printf("Esse ano nao e bissexto.");
				}
			break;		
			
			case 5:
				printf("\nQ5\nCalcular media de 3 notas\nDigite a '1nota 2nota 3nota': ");
				scanf("%f %f %f", &q5nota1, &q5nota2, &q5nota3);
				
				//Nota 3 pesa 2, demais pesa 1
				q5nota3 *= 2;
				
				//Faz a media para 4 itens
				q5media = (q5nota1 + q5nota2 + q5nota3) / 4;
				
				printf("A media dessas notas foi %.2f.", q5media);				
				
			break;
			
			case 6:
				printf("\nQ6\nCalcular medias das notas (c/ validacao)\nDigite '1nota 2nota':");
				scanf("%f %f", &q6nota1, &q6nota2);
				
				if(q6nota1 < 0.0 || q6nota1 > 10.0 || q6nota2 < 0.0 || q6nota2 > 10.0){
					printf("Digite uma nota valida (entre 0 e 10)");
				} else {
					q6media = (q6nota1 + q6nota2) / 2;
					printf("A media dessas notas foi %.2f.", q6media);	
				}
				
			break;
			
			case 9:
				printf("\nRaniel\nMATRICULA 1910026087\nMatricula Hex %X\n", 1910026087);
			break;
				
			default:
				printf("Opa... Acho que nao tem nada aqui...");
				break;
		}
		
	} while (num != 0); //Só sai da aplicacao quando o numero for ZERO

	return 0;
}

//Funcao pra questao 1
int EPar(int _num){
	return _num % 2; //Retorna o resto de '_num/2'
}
