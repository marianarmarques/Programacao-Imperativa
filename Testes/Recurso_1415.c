#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//A
typedef struct slist {
	int valor;
	struct lligada *prox;
} *LInt;

//Ex1.
int bitsUm (unsigned int n) {
    int bitsUm = 0;

    while(n>0) {
        if(n%2!=0) bitsUm++;
        n/=2;
    }
    return bitsUm;
}

//Ex2.
int limpaEspacos (char texto[]) {
    int i, j;
    
    for(i=0; texto[i];) {
        if(isspace(texto[i]) && isspace(texto[i+1])) {
            for(j=i; texto[j]; j++) {
                texto[j]=texto[j+1];
            }
        }
        else i++;
    }
    return i;
}

//Ex3.
int dumpL (LInt l, int v[], int N) {
    int i;

    for(i=0; i<N && l; i++, l=l->prox) v[i] = l->valor;

    return i;
}

//Ex4. -> Corrigir
LInt parte (LInt l) {
    if (!l) return NULL;
    if(!l->prox) return l;
    
    int i=0;
    LInt *x = &l, *x_head = x;
    LInt *y = malloc(sizeof(struct slist)), *y_head=y;
    *y=NULL;

    while(l) {
        if(i%2==0) {
            *y=l;
            y=&((*y)->prox);
            (*x)=(*x)->prox;

        }
        l=l->prox;
        i++;
    }
    l=*x_head;
    (*x)->prox=NULL;
    (*y)->prox=NULL;

    return *y_head;
}

//B
typedef struct nodo {
    char nome [50];
    int numero;
    int nota;
    struct nodo *esq, *dir;
} *Alunos;

//Ex1.
int fnotas (Alunos a, int notas[21]) {
    if(!a) return 0;
    notas[a->nota] +=1;
    int esq = fnotas(a->esq, notas);
    int dir = fnotas(a->dir, notas);

    return 1+esq+dir;
}

//Ex2. <----------------------------

//Ex3.
typedef struct strlist {
    char *string;
    struct strlist *prox;
} *StrList;

int comNota (Alunos a, int nota, StrList *l) {
    int raiz=0;
    if(!a) return 0;

    if(a->nota==nota) {
        StrList new = malloc(sizeof(struct strlist));
        new->string = strdup(a->nome);
        new->prox=NULL;
        *l=a;

        raiz=1;
    }

    int esq = comNota(a->esq, nota, l);
    int dir = comNota(a->dir, nota, l);

    return raiz+esq+dir;
}

//Ex4. <----------------------------

/*Funções auxiliares*/
void appendL (LInt *l, int x) {
    LInt *curr;
    
    for (curr = l; *curr; curr=&((*curr)->prox));

    LInt new = malloc(sizeof(struct slist));
    new -> valor = x;
    new -> prox = NULL;
    *curr = new;
}

/////////////////////////////////////////////////

int main() {
    return 0;
}