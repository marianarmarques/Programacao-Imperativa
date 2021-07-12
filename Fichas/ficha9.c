#include <stdio.h>

typedef struct nodo {
	int valor;
	struct nodo *esq, *dir;
} * ABin;

/*Função auxiliar*/
ABin newABin (int r, ABin e, ABin d) {
	ABin a = malloc (sizeof(struct nodo));
	if (a!=NULL) {
		a->valor = r; 
		a->esq = e; 
		a->dir = d;
	}
	return a;
}

/*Ex1.*/
//a.
int altura (ABin a) {
	int altEsq, altDir;

	if(a) {
		altEsq = altura(a->esq);
		altDir = altura(a->dir);
		if(altEsq>altDir) return 1 + altEsq;
		else return 1 + altDir;
	}
	else return 0;
}

//b.
int nFolhas (ABin a){

	if(a){
		if(a->esq==NULL && a->dir==NULL) return 1;
		else return nFolhas(a->esq) + nFolhas (a->dir);
	}
	else return 0;
}

//c.
ABin maisEsquerda (ABin a){

	if (a==NULL || a->esq==NULL) return a;

	return maisEsquerda(a->esq);
	/*
	ou
	while(a->esq!=NULL) {
	a = a->esq;
	}
	return a;
	*/
}

//d.
void imprimeNivel(ABin a, int l){

	if(l==0) printf("%d ", a->valor);

	else  {
		imprimeNivel(a->esq, l-1);
		imprimeNivel(a->dir, l-1);
	}
}

//e.
int procuraE(ABin a, int x) {
	int r=0;

	if (a!=NULL) {
		if (a->valor==x) r = 1;
		else {
			r = procuraE(a->esq, x) || procuraE(a->dir, x);
		}
	}
	return r;
}

/*Ex2.*/
/* Árvore binária de procura, todos os elementos à direita são maires
que a respetiva raiz, vice-versa para os elementos da esquerda. */
struct nodo *procura (ABin a, int x){
	ABin r = NULL;

	if(a!=NULL) {
		if (a->valor == x) r = a;

		else {
			if (x > a->valor) r = procura(a->dir, x);
			else r = procura(a->esq, x);
		}
	}
	return r;
}

//2.g) Fazer------------------------

void imprimeAte (ABin a, int x){
	if(a!=NULL) {
		if(a->valor < x) {
			imprimeAte(a->esq, x);
			printf("%d ", a->valor);
			imprimeAte(a->dir, x);
		}
		else {
			imprimeAte(a->esq, x);
		}
	}
}