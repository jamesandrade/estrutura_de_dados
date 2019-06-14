#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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
    novo -> prox = inicio;
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
   printf("nao encontrado\n");
   return busca;
   }
   if (busca->chave == x){
   printf("encontrado\n");
   return busca;
   }
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
     printf("%d ",ptr -> chave);
     ptr = ptr -> prox;
  }
  
}
int main()
{
   setlocale(LC_ALL, "Portuguese");
   menu:
   
   printf("------------LISTA ENCADEADA-----------\n");
   printf("1- INSERIR VALORES   2- REMOVER VALOR\n");
   printf("3- BUSCA DE VALOR    4- IMPRIMIR LISTA\n");
   printf("--------------------------------------\n");
   int x,n;
   scanf("%d",&x);
   if(x == 1){
   	  printf("digite quantidade de valores e os valores:\n");	
      int i,valor;
      scanf("%d",&n);
      for(i=0;i<n;i++){
         scanf("%d",&valor);
         insere(valor);
		 
      }
	  goto menu;	
   }
   if(x == 2){
      printf("digite o valor a ser removido:\n");
   	  scanf("%d",&n);
      remover(n,inicio);	
	  goto menu;  
   }
   if(x == 3){
   	  printf("digite o valor a ser buscado:\n");
	  scanf("%d",&n);
      buscar(n,inicio);
	  goto menu;
   }
   if(x == 4){
      printf("imprimindo itens : \n");
      imprime();
	  goto menu;
   }
   return 0;
}
