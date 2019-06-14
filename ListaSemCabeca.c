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
void remover(int x, sno *remov){
//copiei do mounif    
     sno *anterior, *atual;
     anterior = NULL;
     atual = remov;
     while(x != atual->chave){
          anterior = atual;
          atual = atual->prox;
     }
     anterior->prox = atual->prox;
     free (atual);
}
sno *buscar (int x, sno *busca){
//peguei de https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html
   if (busca == NULL){  
   printf("nao encontrado");
   return busca ;}
   if (busca->chave == x){
   printf("encontrado");
   return busca;}
   return buscar (x, busca->prox);
}
void imprime(){
//peguei de http://www.inf.pucrs.br/~pinho/LaproI/Listas/Listas1.htm
sno *ptr;

  if (inicio == NULL)
  {
    printf("fim da lista\n");
    
  }

 ptr = inicio;
  while (ptr !=NULL) {
     printf("%d ",ptr-> chave);
     ptr = ptr->prox;
  }
  printf("fim da lista\n");
}
int main()
{
   printf("digite quantidade de valores e os valores \n");	
   int n, i,valor;
   scanf("%d",&n);
   for(i=0;i<n;i++){
      scanf("%d",&valor);
      insere(valor);
   }

   printf("imprimindo itens : \n");
   imprime();
   printf("funcao busca,digite o valor para buscar: \n");
   int x;
   scanf("%d",&x);
   buscar(x, inicio);
   printf("remover item: \n");
   scanf("%d",&x);
   remover(x,inicio);
   printf("imprime sem item removido: \n");
   imprime();
   return 0;
}
