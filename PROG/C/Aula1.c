#include <stdio.h>

int main(){
	
	int x = 10;
	int y = 3;
	float total;
	
	int entrada;
	
	scanf("%d", entrada); //Entrada do usuário
	
	total = (float) x / y; //Casting
	
	/* 	
		Multiline
		Comment
		
		%f - Float/Double
		%d - Inteiro
	
	*/
	
	printf("Total e: %f\n", total);
	printf("Unidade e: %d\n", x);
	printf("A conta foi: %d / %d = %f\n", x, y, total);
	
	
	return 0;
}
