#include <stdio.h.h>

typedef struct nodo {
	int valor;
	struct nodo *esq, *dir;
} * ABin;

//Ex_1
ABin newABin (int r, ABin e, ABin d) {
	ABin a = malloc (sizeof(struct nodo));
	if (a!=NULL) {
		a->valor = r; 
		a->esq = e; 
		a->dir = d;
	}
	return a;
}

int altura (ABin a) {
	int altEsq, altDir, r=0;

	if(a!=NULL) {
		altEsq = altura(a->esq);
		altDir = altura(a->dir);
		if(altEsq>altDir) {
			r = 1 + altEsq;
		}
		else r = 1 + altDir;
	}
	return r;
}

int nFolhas (ABin a){
	int r=0;

	if(a!=NULL){
		if(a->esq==NULL && a->dir==NULL) r=1;
		else{
			r = nFolhas(a->esq) + nFolhas (a->dir);
		}
	}
	return r;
}

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

void imprimeNivel(ABin a, int l){

	if(l==0) printf("%d ", a->valor);

	else  {
		imprimeNivel(a->esq, l-1);
		imprimeNivel(a->dir, l-1);
	}
}

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

//Ex_2
/*Árvore binária de procura, todos os elementos à direita são maires
que a respetiva raiz, vice-versa para os elementos da esquerda.*/
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