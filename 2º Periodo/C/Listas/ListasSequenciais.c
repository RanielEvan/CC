#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LISTMAX 100


//ESTRUTURAS
typedef struct cont {
	char nome[50];
	char telefone[50];
} Contato;

typedef struct lista {
	Contato contatos[LISTMAX];
	int ultimoContato;
} Lista;


//METODOS
Lista criar(){
	Lista l;
	l.ultimoContato = -1;	
	return l;
}

int estaVazia(Lista * l){	
	return (l->ultimoContato == -1);
}

int estaCheia(Lista * l){	
	return (l->ultimoContato == LISTMAX - 1);
}

int tamanho(Lista * l){	
	return l->ultimoContato + 1;
}

Contato * getContato(Lista* l, int indice){
	if(indice < 0 || indice > l->ultimoContato){
		printf("Erro ao pegar contato, indice fora de alcance.");
	}
	else
		return &(l->contatos[indice]);
}

//MAIN
int main(){
	
	Lista listaSeq = criar();
	
	if(estaVazia(&listaSeq)) printf("A lista esta vazia...\n");
	
	if(estaCheia(&listaSeq)) printf("A lista esta cheia!\n");
	
	printf("A lista possui %d contatos.\n", tamanho(&listaSeq));
	
	getContato(&listaSeq, 2);
	
	getch();

}


