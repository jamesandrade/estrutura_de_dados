/*ACADEMICO: JAMESON FELIPE DE ANDRADE BANHEZA
  RGA: 2015.1802.016-0
  TRABALHO: MATRIZ ESPARSA*/
  
#include "stdio.h"
#include "stdlib.h"

typedef struct sno{
    float valor;
    int coluna;
    struct sno *prox;
    struct sno *ant;
}sno;

typedef sno *pont;

typedef struct matriz{
    pont *a;
    int nlin,ncol;
}matriz;

void criamatriz(matriz *m, int lin, int col){
    int i=0;
    m -> nlin = lin;
    m -> ncol = col;
    m -> a = (pont*) malloc (lin*sizeof(pont));
    while (i < lin){
    m -> a[i] = NULL;
    i++;
    }
}
void insere(matriz *m, int lin, int col, float valor){
    lin = lin - 1; col = col - 1;
    if(lin < 0 || lin >= m -> nlin || col < 0 || col >= m -> ncol){
        printf("Local invalido\n");
        return ;
    }
    pont ant = NULL;
    pont atual = m -> a[lin];
    while (atual != NULL && atual -> coluna < col){
        ant = atual;
        atual = atual -> prox;
    }
    
    if (atual != NULL && atual -> coluna == col){
		atual -> valor = valor;
	
	}
    pont novo = (pont) malloc (sizeof(pont));
        novo -> coluna = col;
        novo -> valor = valor;
    

    if(ant == NULL && atual == NULL){
        m -> a[lin] = novo;
        novo -> ant = novo -> prox = NULL;
    }
    else if(ant == NULL && col < atual -> coluna){
        m -> a[lin] = novo;
        novo -> ant = ant;
        novo -> prox = atual;
    }
    else if(ant != NULL && atual == NULL){
        ant -> prox = novo;
        novo -> prox = NULL;
        novo -> ant = ant;
    }
    else if(ant != NULL && col < atual -> coluna){
        ant -> prox = novo;
        novo -> ant = ant;
        novo -> prox = atual;
    }
}


int  remover(matriz *m, int lin, int col){
    lin = lin - 1; col = col - 1;
    if(lin < 0 || lin >= m -> nlin || col < 0 || col >= m -> ncol){
        return 0;
    }
    pont atual = m -> a[lin];
    while(atual != NULL && atual -> coluna < col){
        atual = atual -> prox;
    }
    if(atual != NULL && atual -> coluna == col){
        
		atual -> valor = 0;
        
        return 1;
    }
}

int busca(matriz *m,float chave,int lin, int col){
int i = 0, j;
    while(lin >= 0){
        pont novo = m -> a[lin];  
        j = col;
        while (j >= 0){
            if(novo != NULL && novo -> coluna == j){
            	if(novo -> valor == chave){	
                return 1;
            }
                novo = novo -> ant;
            }   
            j--;
        }
    lin--;
	}
	return 0;
}
    
void imprimir(matriz *m){
    int i = 0, j;

    while(i < m -> nlin){
        pont novo = m -> a[i];
        j = 0;
        while (j < m -> ncol){
            if(novo != NULL && novo -> coluna == j && novo -> valor != 0){
                printf("%.1f    ",novo -> valor);
                novo = novo -> prox;
            }
            else
                printf("0      ");
            j++;
        }
    printf ("\n");
    i++;
    }
}

void somar(matriz *m, int lin, int col, float chave){	
	lin = lin - 1;
	col = col - 1;
	if(lin < 0 || lin >= m -> nlin || col < 0 || col >= m -> ncol){
	    printf("Local invalido\n");
	    return;
	}
    pont atual = m -> a[lin];  
    if (atual == NULL){
    	insere(m,lin+1,col+1,chave);
    	return;
	}
    while(atual != NULL && atual -> coluna < col){
        atual = atual -> prox;
    }
	atual -> valor = atual -> valor + chave; 
}	

float maiorelemento(matriz *m){
	int i = 0,j;
	float acm = 0;

    while(i < m -> nlin){
        pont novo = m -> a[i];
        j = 0;
        while (j < m -> ncol){
            if(novo != NULL && novo -> coluna == j){
                if(acm < novo -> valor)
					acm = novo -> valor;
					
                novo = novo -> prox;
            }
            j++;
        }
   		i++;
    }
    return acm;
}

void multiplicar(matriz *m, float chave){
	 int i = 0, j;

    while(i < m -> nlin){
        pont novo = m -> a[i];
        j = 0;
        while (j < m -> ncol){
            if(novo != NULL && novo -> coluna == j){
                novo -> valor = novo -> valor * chave;
                novo = novo -> prox;
            }
            j++;
        }
    i++;
    }
}

float somatudo(matriz *m){
	int i = 0,j;
	float acm = 0;

    while(i < m -> nlin){
        pont novo = m -> a[i];
        j = 0;
        while (j < m -> ncol){
            if(novo != NULL && novo -> coluna == j){
                if(novo -> valor != 0)
					acm = acm + novo -> valor;
						
                novo = novo -> prox;
            }
            j++;
        }
   		i++;
    }
    return acm;
}

int main(){
    int lin,col,menu,menu1,menu2;
    float valor;
    matriz *m = (matriz*) malloc (sizeof(matriz));
    printf("*****matriz esparsa*****\n");
    printf("digite numero de linhas e colunas:\n");
    scanf("%d%d",&lin,&col);

    criamatriz(m,lin,col);
    do{
    	
        printf("menu:\n");
		printf("1-Insere\n"); 
		printf("2-Remover Elemento\n");
		printf("3-Busca Elemento\n");  
		printf("4-Imprimir Matriz\n"); 
		printf("5-Somar celula com variavel\n"); 
		printf("6-Encontrar o maior elemento\n");
		printf("7-Multiplica elementos por constante\n");
		printf("8-Soma todos os elementos\n"); 
		printf("9-Sair\n");
		 
        scanf("%d",&menu);
        if(menu == 1){
            printf("digite linha, coluna e valor:\n");
            scanf("%d%d%f",&menu1,&menu2,&valor);
            insere(m,menu1,menu2,valor);
        }
        if(menu == 2){
            printf("digite linha e coluna:\n");
            scanf("%d%d",&menu1,&menu2);
            remover(m,menu1,menu2);
            if(remover(m,menu1,menu2) == 0)
            	printf("Local invalido\n");
            else
            	printf("removido\n");
        }
        if(menu == 3){
        	printf("digite valor:\n");
        	scanf("%f",&valor);
            if(busca(m,valor,lin,col) == 0)
				printf("nao encontrado\n");
			else
				printf("encontrado\n");
        }
        if(menu == 4){
            imprimir(m);
        }
        if(menu == 5){
            printf("digite linha e coluna:\n");
            scanf("%d%d",&menu1,&menu2);
            printf("Digite valor para soma:\n");
            scanf("%f",&valor);
            somar(m,menu1,menu2,valor);
        }
        if(menu == 6){
        	printf("maior elemento: |%.1f|\n",maiorelemento(m));
		}
		if(menu == 7){
			printf("Digite valor da constante:\n");
            scanf("%f",&valor);
            multiplicar(m,valor);
		}
		if(menu == 8){
			printf("resultado: |%.1f|\n",somatudo(m));
	}
    }while(menu > 0 && menu < 9);
    return 0;
    
}
