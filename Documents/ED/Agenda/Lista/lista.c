#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct TpNo{
	char nome[25];
	int telefone;
	int bal;
	void *dir, *esq;
	
};

typedef struct TpNo No;
typedef struct TpArv Arv;
No* Raiz;
No *Anterior;
int alturaNo(No *no){
	if(no==NULL){
		return -1;
		}else{
			return no->bal;
			}
		
	}
int fatorBalanceamentoNo(No *no){
	return labs(alturaNo(no->esq)-alturaNo(no->dir));
	}
int maior(int x,int y){
	if(x>y){
		return x;
		}else{
			return y;
			}
	}
No* rotacaoLL(No *raiz){
	No *no;
	no = raiz->esq;
	raiz->esq = no->dir;
	no->dir = raiz;
	raiz->bal--;
	raiz->bal = maior(alturaNo(raiz->esq),alturaNo(raiz->dir)) + 1;
	no->bal = maior(alturaNo(no->esq),raiz->bal) + 1;
	raiz = no;
	return raiz;
}
No* rotacaoRR(No *raiz){
	No *no;
	no = raiz->dir;
	raiz->dir = no->esq;
	no->esq = raiz;
	raiz->bal++;
	return raiz;
}
No* visita_arvore(No *raiz,No *atual ,char nome[25],int telefone){
	Anterior = raiz;
	if(atual == NULL){
		atual  = (No*)malloc(sizeof(No));
		if (atual == NULL){
            printf("\n\nErro. Sem memoria para alocar\n\n");
            system("pause");
            exit(0);
        }
		atual ->dir = NULL;
		atual ->esq = NULL;
		atual->bal = 0;
		strcpy(atual->nome,nome);
		if(raiz ==NULL){
			printf("\n%s Adicionado e a raiz\n",atual->nome);
			system("pause");
			return atual;
			}
		raiz->bal=fatorBalanceamentoNo(raiz);
		if(strcmp(nome,raiz->nome)<0){
				
				raiz->esq = atual;
				}else{
					
					 raiz->dir = atual;
				}
		if(raiz->bal>1){
			printf("%s",raiz->nome);
			//rotacaoRR(raiz);
			}else if(raiz->bal<-1){
				//rotacaoLL(raiz);
				printf("%s",raiz->nome);
				}
			 
		system("pause");
        return atual;
        }
		 if(strcmp(nome,atual->nome)<0){
			visita_arvore(atual, atual->esq, nome,telefone);
		}else{
			visita_arvore(atual, atual->dir, nome,telefone);
		}
					
		
	 return atual;	
}
void incluir (){
	char nome[25];
     int telefone;
     scanf(" %s",nome);
	 scanf("%d",&telefone);
     if (Raiz == NULL){
        Raiz = visita_arvore(Raiz, Raiz, nome,telefone);
     }else{
        visita_arvore(Raiz, Raiz, nome,telefone);
     }
}
void lnr(No *pNo){
    if (pNo != NULL){
       lnr(pNo->esq);
       printf("%s - ", pNo->nome);
       lnr(pNo->dir);
    }
}
int main(){
	

	char s='s';
	Raiz =NULL;
	
	while(s=='s'){
		incluir();
		scanf(" %c", &s);
		}
	lnr(Raiz);
  

	
	system("pause");
	return 0;
}
