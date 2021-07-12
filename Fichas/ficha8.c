#include <stdio.h>
#include <stdlib.h>

typedef struct slist{
	int valor;
	struct slist *prox;
} *LInt;

typedef LInt Stack;

typedef struct {
	LInt inicio,fim;
} Queue;

/*Funções auxiliares*/
LInt newLInt (int x, LInt xs){
	LInt r = malloc (sizeof(struct slist));
	if (r!=NULL){
		r->valor=x;
		r->prox=xs;
	}
	return r;
}

// 1.
void initStack (Stack *s) {
	*s = NULL;
}

int SisEmpty (Stack s){
	return (s==NULL) ? 1 : 0;
}

int push (Stack *s, int x){
	*s = newLInt(x, *s);
}

//ou
int push_opcional (Stack *s, int x) {
	Stack nova = malloc(sizeof(struct slist));

	nova -> valor = x;
	nova -> prox = *s;

	*s=nova;
}

int pop (Stack *s, int *x) {
	Stack *l;

	for (l=s; (*l)->prox; (*l)=(*l)->prox);
	if (*l) {
		*x=(*l) -> valor;
		*l= NULL;
	}
	else return 1;

	return 0;
}

//Ex_2

//Ex_3
typedef LInt QueueC;

void initQueuec (QueueC *q){
	*q = NULL;
}

int QisEmpty (QueueC q){
	return (q==NULL);
}

int enqueueC (QueueC *q, int x){
	int r=1;
	if (nova!=NULL) {
		r=0;
		nova->valor =x;

		QueueC nova = (QueueC)malloc(sizeof(struct slist));
		nova->valor = x;
		QueueC head = *q, aux = *q;

		if (head==NULL) {
			nova->prox = nova;
			*q = nova;
		}
		else {
			while(aux->prox != head) 
				aux = aux -> prox;
			aux->prox = nova;
			nova->prox = head;
		}
	}
	return r;
}

