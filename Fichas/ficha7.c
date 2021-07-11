#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
	char *palavra;
	int ocorr;
	struct celula * prox;
} *Palavras;


//Ex1. -- certo
void libertaLista (Palavras ps){
	if (ps) {
		libertaLista (ps->prox);
		free(ps);
	}
}

//Ex2. -- certo > Considerando que, na lista, não existem palavras iguais em células diferentes que é esse o objetivo. <
int quantasP (Palavras ps) {
	int r = 0;

	while (ps) {
		r++;
		ps = ps -> prox;
		// ou (recursivamente) return 1+quantasP(l->prox);
	}
	return r;
}

//Ex3. -- certo
void listaPal (Palavras ps) {
	while (ps) {
	printf("| PALAVRA: %s > OCORRÊNCIA: %d | ", ps->palavra, ps->ocorr);		
	ps=ps->prox;
	}
}

//Ex4. -- certo
char* ultima (Palavras ps) {
	if(ps) {
		while(ps->prox) ps=ps->prox;
		return ps->palavra;
	}
	else return NULL;
}

//Ex5. -- certo
Palavras acrescentaInicio (Palavras ps, char *p) {
	Palavras nova = (Palavras) malloc(sizeof(struct celula));
	nova->palavra = p;
	nova->ocorr = 1;
	nova->prox = ps;

	return nova; 
}

//Ex6. -- certo
Palavras acrescentaFim1 (Palavras ps, char *p){

	if(!ps) ps = acrescentaInicio(NULL, p);
	else {
		Palavras *curr = &ps;

		while(*curr) {curr=&((*curr)->prox);}
		
		Palavras new = malloc(sizeof(struct celula));
		new->palavra = p;
		new->ocorr = 1;
		new->prox=NULL;

		*curr=new;
	}
	return ps;
}

Palavras acrescentaFim2 (Palavras ps, char *p){

    if(!ps) ps = acrescentaInicio(NULL, p);
    else {
        Palavras curr = ps;

        while(curr->prox) {curr=curr->prox;}
        Palavras new = malloc(sizeof(struct celula));
        new->palavra = p;
        new->ocorr = 1;
        new->prox=NULL;

        curr->prox=new;
    }
    return ps;
}

//Ex7. -- certo
Palavras acrescenta (Palavras ps, char *p) {
	
	if(!ps) {
		ps=acrescentaInicio(NULL, p);
	}
	else {
		Palavras *curr=&ps;

		while(*curr && strcmp((*curr)->palavra, p)<0) curr=&((*curr)->prox);
		
		if(*curr && strcmp((*curr)->palavra, p)==0) (*curr)->ocorr +=1;
		else {
			Palavras new = malloc(sizeof(struct celula));
			new->palavra = strdup(p);
			new->ocorr = 1;
			new->prox = *curr; 

			*curr=new;
		}
	}
	return ps;
}

//Ex8. -- certo
struct celula* maisFreq (Palavras l) {
	Palavras r = l;
	int maior = l->ocorr;

	while (l) {
		if (l->ocorr > maior) {
			maior = l->ocorr;
			r=l;
		}
		l=l->prox;
	}
	r->prox = NULL;
	return r;
}

int main() {
	return 0;
}
