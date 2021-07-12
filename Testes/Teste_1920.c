#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct lligada {
	int valor;
	struct lligada *prox;
} *LInt;

//Ex1.
int verificaArit(int s[], int N) {
	int i, a=s[0], b=s[1]-s[0];

	for(int i=0; i<N; i++) {
		if (s[i] != a+b*i) return 0;
	}
	return 1;
}

//Ex_2 
int fibonacci(int num) {
	int i;

	if (num==0) return 0;
	if (num<=2) return 1;
	return fibonacci (num-2) + fibonacci (num-1);
}

void gera(LInt *l, int N) {
	int i=1;
	if(N>0) {
		LInt head=*l;
		while(i<=N) {
			*l=malloc(sizeof(struct lligada));
			(*l)->valor = fibonacci(i);
			l=&((*l)->prox);

			i++;
		}
		*l=NULL;

		while(head) {
			head=head->prox;
			printf("%d ", head->valor);
		}
	}
}

//Ex_3
int tamanho (LInt l) {

	if (l) {
		LInt head = l;
		int length=1;

		while(l->prox!=head) {
			length++;
			l= l->prox;
		}
		return length;
	}
	return 0;
}

//Ex_4 <----------------------------
typedef struct dlist {
    int valor;
    struct dlist *ant, *prox;
} NodoD;

typedef struct {
    NodoD *front, *last;
} DLint; 

//Ex_5 <----------------------------

//Ex_6 <----------------------------

//Ex_7 <----------------------------

//Ex_8 <----------------------------

//Ex_9 <----------------------------


///////////////////////////////////////////////////////////////////////////////////

/*Funções auxiliares*/
void appendL (LInt *l, int x) {
    LInt *curr;
    
    for (curr = l; *curr; curr=&((*curr)->prox));

    LInt new = malloc(sizeof(struct lligada));
    new -> valor = x;
    new -> prox = NULL;
    *curr = new;
}

int main() {

	/*Ex_1*/
	int s1[5] = {1,4,7,10,13};
	int ex1 = verificaArit(s1, 5);
	printf("Ex_1 Arit: %d\n", ex1);

	/*Ex_2*/
	LInt l1 = NULL;
	gera(&l1, 10);

	/*Ex_3*/
	/*LInt l2=NULL;
	appendL(&l2, 1);
	appendL(&l2, 2);
	appendL(&l2, 3);

	((l2->prox)->prox)-> prox -> valor= 1;

	int tam = tamanho(l2);
	printf("Ex_2: %d\n\n", tam);*/

	return 0;
}