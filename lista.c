#include <stdio.h>
#include <stdlib.h>
typedef struct sno{
    int chave;
    struct sno *prox;
}sno;

typedef struct lista{
    sno *inicio;
    sno *fim;
}lista;

sno *inicio = NULL;

void insere(int valor){
    sno *novo = (sno*) malloc(sizeof(sno));
    novo -> chave = valor;
    novo -> prox =inicio;
    inicio = novo;
}
void remover(){}
void busca(){}

int main()
{
   insere (5);

    return 0;
}