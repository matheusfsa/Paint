#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct TpNo{
	char nome[25];
	char telefone[12];
	int bal;
	void *dir, *esq;
	
};

typedef struct TpNo No;
struct TpArv{
	No *raiz;
};
typedef struct TpArv *Arv;

No *Auxiliar, *Anterior,*Atual,*Raiz,*Pivo;
void lnr () {
   if (Raiz != NULL) {
		lnr (Raiz->esq);
		printf ("Nome %s\n Telefone:%s\n\n", Raiz->nome,Raiz->telefone);
		lnr (Raiz->dir); 
	 
   }
}
No* busca(char nome[25],char telefone[12]){
	printf("21");
	if(Raiz == NULL){
		printf("22");
		return NULL;
	}else{
		printf("23");
		Atual = Raiz;
		printf("24");
		Anterior = NULL;
		printf("25");
		while(Atual!=NULL){
			printf("26");
			
			printf("27");
			if(strcmp(nome,Atual->nome)>0){
				Anterior = Atual;
				Atual = Atual->dir;
			printf("28");	
			}else if(strcmp(nome,Atual->nome)<0){
				Anterior = Atual;
				Atual = Atual->esq;
				printf("29");
			}else{
				if(strcmp(telefone,Atual->telefone)>0){
					Anterior = Atual;
					Atual = Atual->dir;
					printf("30");
				}else if(strcmp(telefone,Atual->telefone)<0){
					Anterior = Atual;
					Atual = Atual->esq;
					printf("31");
				}else{
					printf("32");
					printf("\n%d\n",Atual->bal);
						return Atual;
					
				}
			}
			
		}
		return NULL;
	
	}
}
void rotacao(No *Pivo){

	printf("2");
	Atual = busca(Pivo->nome, Pivo->telefone);
	printf("33");
	printf("%d",Pivo->bal);
		if(Pivo->bal > 1){
			printf("3");
			Auxiliar = Pivo->dir;
			printf("Pivo %s\n",Pivo->nome);
			printf("Pivo->dir %s\n",Auxiliar->nome);
			if(Anterior!=NULL){
				printf("4");
				if(Anterior->esq == Pivo){
					Anterior->esq = Auxiliar;
				}else{
					Anterior->dir = Auxiliar;
					}
				}else{
					printf("5");
					Raiz = Auxiliar;
					}
			if(Auxiliar ->esq!=NULL){
				Pivo->dir = Auxiliar->esq;
			}
			Auxiliar->esq = Pivo; 
			Pivo->bal--;
		}else if(Pivo->bal < -1){
			Auxiliar = Pivo->esq;
			
			if(Anterior->esq == Pivo){
				Anterior->esq = Auxiliar;
			}else{
				Anterior->dir = Auxiliar;
				}
			if(Auxiliar ->dir!=NULL){
				Pivo->esq = Auxiliar->dir;
			}
			Auxiliar->dir = Pivo; 
			Pivo->bal++;
			}
	
	
}
void inserir(char nome[25],char telefone[12]){
	Auxiliar =  (No*)malloc(sizeof(No));
	Pivo = NULL;
	strcpy(Auxiliar->nome,nome);
	strcpy(Auxiliar->telefone,telefone);
	Auxiliar->dir = NULL;
	Auxiliar->esq = NULL;
	Auxiliar->bal = 0;
	
	if(Raiz == NULL){
		Raiz = Auxiliar;
	}else{
		Atual = Raiz;
		Anterior = NULL;
		while(Atual!=NULL){
			Anterior = Atual;
			
			if(strcmp(Auxiliar->nome,Atual->nome)>0){
				Atual = Atual->dir;
				Anterior->bal++;
				printf("Anterior:%d",Anterior->bal);
			}else if(strcmp(Auxiliar->nome,Atual->nome)<0){
				Atual = Atual->esq;
				Anterior->bal--;
				printf("Anterior:%d",Anterior->bal);
			}else{
				if(strcmp(Auxiliar->telefone,Atual->telefone)>0){
					Atual = Atual->dir;
					Anterior->bal++;
					printf("Anterior:%d",Anterior->bal);
				}else if(strcmp(Auxiliar->telefone,Atual->telefone)<0){
					Atual = Atual->esq;
					Anterior->bal--;
					printf("Anterior:%d",Anterior->bal);
				}
			}
			
			if(Anterior->bal>1 || Anterior->bal<-1){
				Pivo = Anterior;
				}
		}
		printf("Anterior:%s\n",Anterior->nome);
			if(strcmp(Auxiliar->nome,Anterior->nome)>0){
				Anterior->dir = Auxiliar;
			}else if(strcmp(Auxiliar->nome,Anterior->nome)<0){
				Anterior->esq = Auxiliar;
			}else{
				if(strcmp(Auxiliar->telefone,Atual->telefone)>0){
					Anterior->dir = Auxiliar;
				}else{
					Anterior->esq = Auxiliar;
				}
			}
				if(Pivo!=NULL){
					rotacao(Pivo);
					}
				
				
	
	}
	
}
int main(){
	
	char nome[25], telefone[12];
	char s='s';
	Raiz =NULL;

	while(s=='s'){
		scanf(" %s",nome);
		scanf(" %s",telefone);
		inserir(nome,telefone);
		scanf(" %c", &s);
		printf("Raiz:%d",Raiz->bal);
		}
	lnr(Raiz);
	system("pause");
	return 0;
}
