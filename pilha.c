#include "stdio.h"
#include "stdlib.h"

typedef struct sno{
    int chave;
    struct sno *prox;
}sno;

typedef struct pilha {
    sno *topo;
}pilha;

void criapilha(pilha *p){
    p -> topo = NULL;
}
void insere(int valor,pilha *p){
    sno *novo = (sno*) malloc(sizeof(sno));
    novo->chave = valor;

    if(p -> topo == NULL){
        p -> topo = novo;
        p -> topo -> prox = NULL;
        return;
    }
    else{
        novo -> prox = p -> topo;
        p -> topo = novo;
    }
}

void busca(int valor,pilha *p){
    sno *aux = p -> topo;
    if(aux == NULL){
        printf("lista vazia\n");
        return;
    }
    while(aux -> chave != valor && aux -> prox != NULL){
        aux = aux -> prox;
    }
    if(aux -> chave == valor){
        printf("encontrado\n");
    }
    else{
        printf("nao encontrado\n");
    }
}
void remov(pilha *p){
    sno *aux = p -> topo;
    if(aux == NULL){
        printf("lista vazia\n");
        return;
    }
    else{
        p -> topo = p -> topo -> prox;
        free(aux);
    }

}
void imprime(pilha *p){
    sno *aux = p -> topo;
    if(aux == NULL){
        printf("lista vazia\n");
        return;
    }
    else{
        while(aux!= NULL){
            printf("|%d| ",aux -> chave);
            aux = aux -> prox;
        }

    }
}

int main(){
    pilha *p1 = (pilha*) malloc(sizeof(pilha));
    criapilha(p1);


          insere(5,p1);
          insere(3,p1);
          insere(8,p1);
          insere(0,p1);
          busca(5,p1);
          remov(p1);
          imprime(p1);


return 0;
}



