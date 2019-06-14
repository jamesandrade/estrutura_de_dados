#include "stdio.h"
#include "stdlib.h"

typedef struct sno{
	int chave;
	struct sno *prox;
	struct sno *ant;
}sno;

typedef struct lista{
	sno *inicio;
	sno *fim;
}lista;

void crialista (lista *l){
	l -> inicio = NULL;
	l -> fim = NULL;
}

void insere(int valor, lista *l){
	sno *novo = (sno*) malloc (sizeof(sno));
	sno *aux = l -> fim;
	sno *aux2 = NULL;
	novo -> chave = valor;
	if(l -> fim == NULL && l -> inicio == NULL){
		l -> fim = l -> inicio = novo;
		novo -> prox = NULL;	
		novo -> ant = NULL;
		return ;
	}
	if (l -> inicio -> chave > valor){
		novo -> ant = NULL;
		l -> inicio -> ant = novo;
		novo -> prox = l -> inicio;
		l -> inicio = novo;
		return;
	}
	else{
		if(l -> fim -> chave < valor){
			novo -> ant = l -> fim;
			l -> fim = novo;
			novo -> prox = NULL;
			return;
		}
		
		while(aux != NULL && aux -> chave > valor){	
			aux2 = aux;
			aux = aux -> ant; 
		}
		aux2 -> ant = aux -> prox = novo;
		novo -> ant = aux;
		novo -> prox = aux2;
		
	}

}

void concatenalista(lista *l1, lista *l2){
	l1 -> fim -> prox = l2 -> inicio;
	l2 -> inicio -> ant = l1 -> fim;
	l1 -> fim = l2 -> fim;
}

void imprime(lista *l){
	sno *aux = l -> fim;
	while(aux != NULL){
		printf("|%d|",aux -> chave);
		aux = aux -> ant;
	}
}
void invertelista(lista *l){
	sno *aux = l -> inicio;
	sno *aux2 = l -> fim;
	sno *temp;
	while(aux != NULL && aux2 != NULL){
		while(&aux != &aux2){
			temp == aux;
			aux == aux2;
			aux2 == temp;
			aux = aux -> prox;
			aux2 = aux2 -> ant;
		}
	}
}
int main(){
	lista *l1 = (lista*) malloc (sizeof(lista));
	crialista(l1);
	lista *l2 = (lista*) malloc (sizeof(lista));
	crialista(l2);
	insere(5,l1);
	insere(4,l1);
	insere(3,l1);
	insere(1,l2);
	insere(3,l2);
	insere(2,l2);
	concatenalista(l1,l2);
	imprime(l1);
	invertelista(l1);
	imprime(l1);
	return 0;
}


