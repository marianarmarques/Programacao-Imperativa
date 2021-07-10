#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct slist {
	int valor;
	struct slist *prox;
} *LInt;

typedef struct nodo {
    int valor;
    struct nodo *pai,*esq,*dir;
} *ABin;

//Ex1.
int paresImpares(int v[], int N) {
    int i, j, temp, pares=N;

    for(i=0; i<N; i++) {
        if (v[i]%2!=0) {
            pares--;
            for (j=i+1; j<N; j++) {
                if(v[j]%2==0) {
                    temp=v[i];
                    v[i]=v[j];
                    v[j]= temp;

                    pares++;
                    break;
                }
            }
            if(j==N) break;
        }
    }
    return pares;
}

//Ex2.
void merge(LInt *r, LInt a, LInt b) {
    LInt *curr = r;

    while(a || b) {
        if (!b || (a && a->valor < b->valor)) {
            *curr=a;
            a=a->prox;
        }
        else {
            *curr=b;
            b=b->prox;
        }
        curr = &((*curr)->prox);
    }
}

//Ex3.
void latino(int N,int m[N][N]) {
     int lin, col, flag;

     for(col=0; col<N; col++) {
        for(lin=0, flag=col+1; lin<N; lin++, flag++) {
            if(flag==N+1) flag=1;
            m[col][lin] = flag;
        }
    }
}

//Ex4.

//Ex5.
typedef struct palavras{
    char* palavra;
    int nOcorr;
    struct palavras *esq, *dir;
} *Palavras;

void rodaDir (Palavras *a){
	Palavras b = (*a)->esq;
	(*a)->esq = b->dir;
	b->dir = *a;
	*a = b;
}

void rodaEsq (Palavras *a){
	Palavras b = (*a)->dir;
	(*a)->dir = b->esq;
	b->esq = (*a);
	*a = b;
}

int acrescentaPal(Palavras *p, char *pal) {
    Palavras *ant = malloc(sizeof(struct palavra *));
    *ant = NULL;
    int lado=0;


    while(*p && strcmp((*p)->palavra,pal)) {
        ant=p;
        if(strcmp((*p)->palavra, pal)<0) {p=&((*p)->dir); lado=0;} // Àrvore de procura -> Menores à esq, maiores à dir
        else {p=&((*p)->esq); lado=1;}
    }

    // Caso *p==NULL -> A palavra *pal não existe na árvore;    
    if(!*p) {
        Palavras new_p = malloc(sizeof(struct palavras));
        new_p->palavra = strdup(pal);
        new_p->nOcorr=1;
        new_p->dir = new_p->esq = NULL;
        *p=new_p;
    }

    // Existe e temos de verificar se vale a pena rodar a àrvore ou não;
    else {
        ((*p)->nOcorr)++;

        if((*ant) && (*ant)->nOcorr<(*p)->nOcorr) {
            if(lado) rodaDir(ant);
            else rodaEsq(ant);
        }
    }
    return (*p)->nOcorr;
}



///////////////////////////////////////////////////////////////////////////////////

/*Funções auxiliares*/
void appendL (LInt *l, int x) {
    LInt *curr;
    
    for (curr = l; *curr; curr=&((*curr)->prox));

    LInt new = malloc(sizeof(struct slist));
    new -> valor = x;
    new -> prox = NULL;
    *curr = new;
}

int main() {

    /* ----- EX1 ----- */
    int v[5] = {1,2,3,4,5};
    int pares = paresImpares(v, 5);

    printf("Ex_1: \n");
    for(int i=0; i<5; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    printf("PARES: %d\n\n", pares);

    /* ----- EX2 ----- */
    LInt r=NULL;

    LInt a=NULL;
    appendL(&a, 1);
    appendL(&a, 2);
    appendL(&a, 5);

    LInt b=NULL;
    appendL(&b, 3);
    appendL(&b, 6);
    appendL(&b, 7);

    merge(&r, a, b);

    printf("Ex_3: \n");
    for(LInt *curr=&r; *curr; curr=&((*curr)->prox)) printf("%d ", (*curr)->valor);
    printf("\n\n");

    /* ----- EX3 ----- */
    int matriz[3][3];

    latino(3, matriz);

    printf("Ex_2: \n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    /* ----- EX4 ----- */



    /* ----- EX5 ----- */
    Palavras raiz;
	raiz = malloc(sizeof(struct palavras));
	raiz->palavra = strdup("Gabriel");
	raiz->nOcorr = 5;
	raiz->esq = malloc(sizeof(struct palavras));
	raiz->dir = malloc(sizeof(struct palavras));
	(raiz->esq)->palavra = strdup("Carlos");
	(raiz->esq)->nOcorr = 3;
	(raiz->esq)->esq = NULL;
	(raiz->dir)->palavra = strdup("Mario");
	(raiz->dir)->nOcorr = 3;
	(raiz->dir)->dir = (raiz->dir)->esq = NULL;
	(raiz->esq)->dir = malloc(sizeof(struct palavras));
	((raiz->esq)->dir)->nOcorr = 3;
	((raiz->esq)->dir)->palavra = strdup("Duarte");
	((raiz->esq)->dir)->esq = NULL;
	((raiz->esq)->dir)->dir = NULL;

    int numP1 = acrescentaPal(&raiz, "Gabriel"); // Caso crítico
    int numP2 = acrescentaPal(&raiz, "Mariana");

    printf("Ex_5: > %d > %d\n", numP1, numP2);
}