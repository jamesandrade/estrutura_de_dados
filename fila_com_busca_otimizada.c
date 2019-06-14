#include "stdio.h"
#include "stdlib.h"

typedef struct sno{
    int chave;
    struct sno *ant;
    struct sno *prox;
}sno;

typedef struct fila{
    sno *inicio;
    sno *fim;
}fila;

void criafila(fila *p){
    p -> inicio = NULL;
    p -> fim = NULL;
}
void insere(int valor, fila *p){
    sno *novo = (sno*) malloc (sizeof(sno));
    novo -> chave = valor;
    novo -> prox = NULL;
    if(p -> inicio == NULL && p->fim == NULL){
        p -> inicio = p-> fim = novo;
    }
    novo -> ant = p -> fim;
    p -> fim -> prox = novo;                         
    p -> fim = novo;
}
void busca(int valor,fila *p){
    sno *aux1 = p -> inicio;
    sno *aux2 = p -> fim;
    
    if(!(p->inicio)){
        printf("Busca: lista vazia\n");
        return ;
    }
    
    while(aux1 -> chave != valor && aux2 -> chave != valor && aux1 != NULL && aux2 != NULL){
        aux1 = aux1 -> prox;
        aux2 = aux2 -> ant;
    }
    
if(aux1 -> chave == valor || aux2 -> chave == valor){
    printf("encontrado\n");
}
else {
    printf(" nao encontrado\n");
}
    
}
void imprime(fila *p){
    sno *temp = p->inicio;
    if(temp == NULL){
        printf("fila vazia\n");
        return ;
    }
    while(temp){
        printf("|%d| ", temp->chave);
        temp = temp->prox;
    }
    puts("");
    
}

void remover(fila *p){
    if(p -> inicio == NULL){
        printf("fila vazia\n");
        return ;
    }
    sno *temp = p -> fim;
    sno *anterior = p -> fim -> ant;
    
    anterior -> prox = NULL;
    free(temp);
    p->fim = anterior;
    
    
}

void destruir(fila *p){
    sno *temp = p -> inicio;
    sno *prox = temp -> prox;
    if(temp == NULL){
        printf("fila vazia\n");
        return ;
    }
    else{
        while(temp){
            prox = temp->prox;
            free(temp);
            temp = prox;
        }
    }
    criafila(p);
    puts("Destruida");
}    

int main(){
    fila *p1 = (fila*) malloc (sizeof(fila));
    criafila(p1);
    insere(5,p1);
    insere(2,p1);
    insere(28,p1);
    imprime(p1);
    remover(p1);
    imprime(p1);
    busca(2,p1);
    destruir(p1);
    imprime(p1);
    insere(5,p1);
    insere(2,p1);
    insere(28,p1);
    imprime(p1);
    remover(p1);
    imprime(p1);
    busca(2,p1);
    destruir(p1);
    imprime(p1);
    return 0;
}
