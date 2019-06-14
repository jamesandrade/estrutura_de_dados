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

sno *insere(int valor){
    sno *anterior = NULL;
    sno *atual = inicio;
    sno *novo = (sno*) malloc(sizeof(sno));
    novo -> chave = valor;
	if(inicio == NULL || novo -> chave < inicio -> chave ){
   	 novo -> prox = inicio;
   	 inicio = novo;
	 return NULL;
	}
	else{
	
		if(inicio -> prox == NULL){
			inicio -> prox = novo;
			novo -> prox = NULL;
			
		}
		else{
			while(atual != NULL && atual -> chave < novo -> chave){
				anterior = atual;
				atual = atual -> prox;
			}
			anterior -> prox = novo;
			novo -> prox = atual;
		}
		return NULL;
	}
}
sno *remover(int x, sno *remov){
	 sno *anterior = NULL;
     sno *atual = remov;
	 if(atual == NULL){
	 	printf("lista vazia\n");
		return NULL;
	 }
	 else{
		 if(remov -> chave == x){
		 	inicio = inicio -> prox;
		 } 	
    	 else{
     		while(atual -> chave != x && atual != NULL ){		
      		    anterior = atual;
      		    atual = atual->prox;
   			}
    		 anterior->prox = atual->prox;
	    }
 			 free (atual);
		     printf("removido\n");
		     return NULL;
	}
}
sno *buscar (int x, sno *busca){

   if (busca == NULL){  
   printf("lista vazia\n");
   return NULL;
   }
   else{
   	while(busca -> chave != x && busca != NULL){
		busca = busca -> prox;
	}
   	if (busca -> chave == x){
  		 printf("encontrado\n");
		 return NULL;
	}
   	else{
		printf(" nao encontrado\n");
		return NULL;
	}	
   }
}
sno *imprime(){
sno *aux = inicio;

  if (aux == NULL){
    printf("fim da lista\n");
	return NULL;
  }
  else{
  	while (aux !=NULL) {
    	 printf("%d ",aux -> chave);
    	 aux = aux -> prox;
  	}
	printf("\n");
	return NULL;
  }
}
   
    	

int main()
{
   insere(5);
   insere(10);
   insere(15);
   insere(20);
   insere(2);
   insere(9);
   insere(28);
   
   
   
   remover(15,inicio);
   buscar(20,inicio);
   imprime();
   return 0;
}
