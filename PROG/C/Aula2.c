#include <stdio.h>

int main(){
	
	//DEFINE AS VARIAVEIS
	float num1, num2, result;
	
	//Ler dois numeros
	printf("Digite um numero: ");
	scanf("%f", &num1);
	
	printf("Digite outro numero: ");
	scanf("%f", &num2);
	
	//Multiplicar os numeros
	result = num1 * num2;
	
	//Mostrar o resultado
	printf("O resultado de %f * %f e igual a %f", num1, num2, result);
	
}
