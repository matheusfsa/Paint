
typedef struct NO* ArvAVL;

ArvAVL* cria_ArvAVL();
int insere_ArvAVL(ArvAVL *raiz, char nome[25],int telefone);
int estaVazia_ArvAVL(ArvAVL *raiz);
int altura_ArvAVL(ArvAVL *raiz);
void preOrdem_ArvAVL(ArvAVL *raiz);
void emOrdem_ArvAVL(ArvAVL *raiz);
void posOrdem_ArvAVL(ArvAVL *raiz);