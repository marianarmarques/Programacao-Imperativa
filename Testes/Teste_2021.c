#include <stdio.h>
#include <stdlib.h>

typedef struct slist {
	int valor;
	struct slist *prox;
} *LInt;

typedef struct nodo {
    int valor;
    struct nodo *pai,*esq,*dir;
} *ABin;


//Ex1.
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int n) {
   int i, j;
   for (i = 0; i < n-1; i++)       
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

int sumhtpo(int n) {
    int r=0, ind=0;
    int array[100];

    while(n!=1){
        //r+=n;

        if(ind==100 && n<array[99]) array[99]=n;
        else array[ind++] = n;

        bubbleSort(array, ind);

        if(n%2==0) n=n/2;
        else n=1+(3*n);
    }

    if(ind<100) return -1;
    return array[99];
}

//Ex2.
int moda (int v[], int N, int *m) {
    int i, j, freq, max=0, flag=0;

    for (i=0; i<N; i++) {
        freq=1;
        for (j=i+1; j<N; j++) {
            if (v[i]==v[j]) freq++;
        }
        if (freq>max) {
            max = freq;
            *m = v[i];
            flag=0;
        }
        else if (freq==max) flag=1;
    }
    if (flag) return 0;
    return max;
}

//Ex3.
/*
Ex: {1,2,3} -> x = 2
    Caso crítico -> Primeiro elem da lista -> 1
*/
int procura (LInt *l, int x) {
    if(!*l) return 0;
    
    int ret=0;
    LInt *head =l;
    LInt *curr=l;
    LInt temp;

    while(*curr) {
        if((*curr)->valor==x && (*head)->valor!=x) {
            temp = *curr; // Guardar o 2;
            (*curr)=(*curr)->prox; // Ligar o 1 ao 3;
            temp->prox = *head; // Colocar o 2 à cabeça; 
            *l = temp; // Indicar que a cabeça da lista é o 2;
            
            ret=1;
        }
        else {
          if((*head)->valor==x) ret=1;
          curr=&((*curr)->prox);
        }
    }
    return ret;
}

//Ex4. 
int freeAB(ABin a) {
    if(!a) return 0;

    int esq = freeAB(a->esq);
    int dir = freeAB(a->dir);

    free(a); 
    return 1+esq+dir;
}

//Ex5.
void caminho(ABin a) {

    if (a && a->pai) {
        caminho(a->pai);

        if((a->pai)->dir==a) printf (" > dir\n"); 
        else printf (" > esq\n");
    }
}


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
    int ultpartcela = sumhtpo(500);
    printf("Ex_1: %d \n", ultpartcela);

    /* ----- EX2 ----- */
    printf("Ex_2 \n");
    int m;
    int v1[5] = {1,2,3,4,5};
    int v2[5] = {1,1,2,2,3};
    int v3[7] = {1,1,2,2,3,3,3};

    int r1 = moda(v1,5,&m);
    printf(" > 1. %d \n", r1);
    int r2 = moda(v2,5,&m);
    printf(" > 2. %d \n", r2);
    int r3 = moda(v3,7,&m);
    printf(" > 3. %d \n\n", r3);

    /* ----- EX3 ----- */
    LInt l=NULL;
    appendL(&l, 1);
    appendL(&l, 2);
    appendL(&l, 3);

    int ex3 = procura(&l, 1);
    printf("Ex_3: %d \n\n", ex3);

    /* ----- EX4 ----- */
    ABin a = malloc(sizeof(struct nodo));
    a->valor = 1;
    a->esq = malloc(sizeof(struct nodo));
    a->esq->valor = 2;
    a->dir = malloc(sizeof(struct nodo));
    a->dir->valor = 3;

    int ex4 = freeAB(a);
    printf("Ex_4: %d \n\n", ex4);

    /* ----- EX5 ----- */
    printf("Ex_5 \n");

    ABin b = malloc(sizeof(struct nodo));
    b->pai=NULL;
    b->valor = 1;
    b->esq = malloc(sizeof(struct nodo));
    b->esq->pai = b;
    b->esq->valor = 2;
    b->dir = malloc(sizeof(struct nodo));
    b->dir->pai = b;
    b->dir->valor = 3;

    caminho(b->dir);

    return 0;
}


