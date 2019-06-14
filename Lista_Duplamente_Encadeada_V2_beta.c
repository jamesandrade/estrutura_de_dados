#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct sno{
    int chave;
    struct sno *ant, *prox;
}sno;

typedef struct lista{
    sno *inicio;
    sno *fim;
}lista;

sno *inicio = NULL;
sno *fim = NULL;

void insere_inicio(int valor){ 					
    sno *novo = (sno*) malloc(sizeof(sno));
    novo -> chave = valor;
    novo -> prox = NULL;
	novo -> ant = NULL;
	
	if(inicio == NULL){
		inicio = novo;
		fim = novo;	
	}
	else{
		inicio -> ant = novo;
		novo -> prox = inicio;
		inicio = novo;
	}
}
void insere_fim(int valor){ 					
    sno *novo = (sno*) malloc(sizeof(sno));
    novo -> chave = valor;
    novo -> prox = NULL;
	novo -> ant = NULL;
	
	if(inicio == NULL){
		inicio = novo;
		fim = novo;	
	}
	else{
		fim -> prox = novo;
		novo -> ant = fim;
		fim = novo;
	}
}
void remover_inicio(int x, sno *remov){
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
	 printf("\nREMOVIDO\n");
}
void remover_fim(int x, sno *remov){
//copiei do mounif    
     sno *anterior, *atual;
     anterior = NULL;
     atual = remov;
     while(x != atual->chave){		
          anterior = atual;
          atual = atual->ant;
     }
      atual-> ant = anterior -> ant;
     free (atual);
	 printf("\nREMOVIDO\n");
}
sno *buscar_inicio(int x, sno *busca){
//peguei de https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html
   if (busca == NULL){  
   printf("nao encontrado\n");
   return busca;
   }
   if (busca->chave == x){
   printf("encontrado\n");
   return busca;
   }
   return buscar_inicio(x, busca->prox);
}
sno *buscar_fim(int x, sno *busca){
   if (busca == NULL){  
   printf("nao encontrado\n");
   return busca;
   }
   if (busca->chave == x){
   printf("encontrado\n");
   return busca;
   }
   return buscar_fim(x, busca->ant);
}
void imprime_inicio(){					

sno *aux;

  if (inicio == NULL)
  {
    printf("\nfim da lista\n");
    
  }

 aux = inicio;
  while (aux !=NULL) {
     printf("%d ",aux -> chave);
     aux = aux -> prox;
  }
  printf("\nfim da lista\n");
}

void imprime_fim(){					

sno *aux;

  if (fim == NULL)
  {
    printf("\nfim da lista\n");
    
  }

 aux = fim;
  while (aux !=NULL) {
     printf("%d ",aux -> chave);
     aux = aux -> ant;
  }
  printf("\nfim da lista\n");
}
int main()
{
   setlocale(LC_ALL, "Portuguese");
   
   menu:
   printf("-----------------LISTA DUPLAMENTE ENCADEADA-----------------\n");
   printf("1- INSERIR VALORES PELO INICIO   2- INSERIR VALORES PELO FIM\n");
   printf("\n");
   printf("3- REMOVER VALOR PELO INICIO     4- REMOVER VALOR PELO FIM\n");
   printf("\n");
   printf("5- BUSCA DE VALOR  PELO INICIO   6- BUSCA DE VALOR PELO FIM\n");
   printf("\n");
   printf("7- IMPRIMIR LISTA PELO INICIO    8- IMPRIMIR LISTA PELO FIM\n");
   printf("------------------------------------------------------------\n");
   int x,n;
   scanf("%d",&x);
   
   if(x == 1){
   	  printf("digite quantidade de valores e os valores:\n");	
      int i,valor;
      scanf("%d",&n);
      for(i=0;i<n;i++){
         scanf("%d",&valor);
         insere_inicio(valor);
		 
      }
	  goto menu;	
   }
   
   if(x == 2){
   	  printf("digite quantidade de valores e os valores:\n");	
      int i,valor;
      scanf("%d",&n);
      for(i=0;i<n;i++){
         scanf("%d",&valor);
         insere_fim(valor);
		 
      }
	  goto menu;	
   }
   
   if(x == 3){
      printf("digite o valor a ser removido:\n");
   	  scanf("%d",&n);
      remover_inicio(n,inicio);	
	  goto menu;  
   }
   
    if(x == 4){
      printf("digite o valor a ser removido:\n");
   	  scanf("%d",&n);
      remover_fim(n,fim);	
	  goto menu;  
   }
   
   if(x == 5){
   	  printf("digite o valor a ser buscado:\n");
	  scanf("%d",&n);
      buscar_inicio(n,inicio);
	  goto menu;
   }
   
   if(x == 6){
   	  printf("digite o valor a ser buscado:\n");
	  scanf("%d",&n);
      buscar_fim(n,fim);
	  goto menu;
   }
   
   if(x == 7){
      printf("imprimindo itens : \n");
      imprime_inicio();
	  goto menu;
   }
   
   if(x == 8){
      printf("imprimindo itens : \n");
      imprime_fim();
	  goto menu;
   }
   
   return 0;
}