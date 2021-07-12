#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct slist {
	int valor;
	struct lligada *prox;
} *LInt;

typedef struct nodo {
    int valor;
    struct nodo *esq,*dir;
} *ABin;

//A 

//Ex1.
int retiraNeg (int v[], int N){
    int i, j;
    
    for(i=0; i<N;) {
        if(v[i]<0) {
            N--; 
            for(j=i; j<N; j++) {
                v[j]=v[j+1];
            }
        }
        else i++;
    }
    return i;
}

//Ex2.

//Ex3.
int maximo (LInt l){
    int max=0;
    LInt l1;
    
    for(l1=l; l1; l1=l1->prox) {
        if(l1->valor>max) max = l1->valor;
    }
    return max;
}

//Ex4.
int removeAll (LInt *l, int x){
    int numRemv=0;
    LInt *curr;
    
    for(curr=l; *curr;) {
        if((*curr)->valor==x) {
            numRemv++;
            (*curr)=(*curr)->prox;
        }
        else curr=&((*curr)->prox);
    }
    return numRemv;
}

//Ex5. 
LInt arrayToList (int v[], int N){
    int i;
    LInt *result = malloc(sizeof(struct slist)), *head_result;
    
    *result=NULL;
    head_result = result;
    
    for(i=0; i<N; i++) {
        LInt new = malloc(sizeof(struct slist));
        new->valor = v[i];
        new->prox = NULL;
        
        *result=new;
        result=&((*result)->prox);
    }
    (*result)=NULL;
    
    return *head_result;
}

//B
/*Min-heap -> Se o elemento que está na raíz é o menor dos elementos da ́arvore tal como as sub-árvores*/

//Ex1.
int minheapOK (ABin a){
    if(!a || (a && (!a->esq && !a->dir) || 
          ((a->esq)->valor>a->valor && !a->dir) ||
          ((a->dir)->valor>a->valor && !a->esq) ||
          ((a->dir)->valor>a->valor && (a->esq)->valor>a->valor))) return 1;
    else return 0;
    
    return minheapOK(a->esq)*minheapOK(a->dir);
}

//Ex2.
int maxHeap (ABin a) {
    if(!a) return 0;
    if(a && !a->esq && !a->dir) return a->valor;

    if(a && (!a->dir || (a->esq)->valor>(a->dir)->valor)) return maxHeap(a->esq);
    else return maxHeap(a->dir);
}

//Ex3. CORRIGIR 
/*             1
           2       3
         6   7   9   10

               2
          6         3
            7     9   10
*/

void removeMin (ABin *a) {
    if(*a && !(*a)->esq && !(*a)->dir) {
        free(*a);
        (*a)=NULL;
    }
    if(*a && (!(*a)->esq || ((*a)->esq && (*a)->dir && (*a)->esq->valor>(*a)->dir->valor))) {
        (*a)->valor=(*a)->dir->valor;
        removeMin(&(*a)->dir);
    }
    if(*a && (!(*a)->dir || ((*a)->esq && (*a)->dir && (*a)->esq->valor<(*a)->dir->valor))) {
        (*a)->valor=(*a)->esq->valor;
        removeMin(&(*a)->esq);
    }
}

//Ex4. -- certo >Estratégia: Construir/adicionar o valor à min-heap sempre à sua dir.<
void add (ABin *a, int x) {

    ABin new = malloc(sizeof(struct nodo));
    new->valor=x;
    new->esq=new->dir=NULL;

    while(*a && (*a)->valor<x) a=&((*a)->dir);
    if(*a) {
        new->dir = *a;
        *a=new;
    }
    else {
        new->dir = NULL;
        *a=new;
    }
}

void heapSort (int v[], int N) {
    int i;
    ABin minHeap = NULL;

    for(i=0; i<N; i++) {
        add(&minHeap, v[i]);
    }
    
    for(i=0; i<N && minHeap; i++, minHeap=minHeap->dir) {
        v[i]= minHeap->valor;
    }
}


//Ex5. <- Fazer

/////////////////////////////////////////////////

int main() {


    /*********** B ***********/
    printf("Parte B\n\n");
    ABin a = malloc(sizeof(struct nodo));
    a->valor = 1;
    a->esq = malloc(sizeof(struct nodo));
    a->esq->valor = 6;
    a->dir = malloc(sizeof(struct nodo));
    a->dir->valor = 3;

    int ok = minheapOK(a);
    printf("Ex_1: %d\n\n", ok);

    int max = maxHeap(a);
    printf("Ex_2: %d\n\n", max);

    removeMin(a);


    return 0;
}