#include <stdio.h>
#include <stdlib.h>

typedef struct sno{
	int chave;
	struct sno *ant;
	struct sno *prox;
}sno;

typedef struct lista{
	struct sno *inicio;
	struct sno *fim;
}lista;

void crialista (lista *l){
	l -> inicio = NULL;
	l -> fim = NULL;
}

void insere (int valor, lista *l){
	sno *novo = malloc (sizeof(sno));
	novo -> chave = valor;
	if (l -> inicio == NULL && l -> fim == NULL){
		l -> inicio = l -> fim = novo; 
		l -> fim -> prox = novo; 
		novo -> ant = l -> fim;
		return;
	}
	
	else{
		l -> fim -> prox = novo; 
		l -> fim = novo;
		l -> fim -> prox = l -> inicio;
		l -> inicio -> ant = l -> fim; 
	}
}

void imprime(lista *l){
	sno *aux = l -> inicio;
	do{
		printf("|%d|",aux -> chave);
		aux = aux -> prox;
	}while(aux -> chave != l -> inicio -> chave);
	
}

int main(){
	lista *l1 = malloc (sizeof (lista));
	crialista(l1);
	insere (10,l1);
	insere (0,l1);
	insere (20,l1);
	insere (8,l1);
	imprime(l1);
	return 0;
}
