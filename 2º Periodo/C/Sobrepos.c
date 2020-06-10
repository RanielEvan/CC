#include <stdio.h>

int contador; //Variavel Global (fora do escopo MAIN)

void setContador(int); //Declaracao dos metodos

int main(){
	
	//Metodo DENTRO do escopo
	void setContador(int valor){
		contador = valor+5;
	}
	
	
	setContador(10); //Chama o metodo
	
	printf("VALOR : %d", contador); //Mostra o valor
	
	return 0;
}

//Metodo FORA do escopo
void setContador(int valor){
	contador = valor;
}
