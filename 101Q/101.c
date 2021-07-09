#include <stdio.h>
#include <stdlib.h>

/************************LISTAS LIGADAS************************/
typedef struct lligada {
	int valor;
	struct lligada *prox;
} *LInt;

/*Função auxiliar*/
LInt newLInt (int x, LInt l) {
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = x;
        new->prox  = l;
    }
    return new;
}

//1. -- 10 testes corretos
int length (LInt l) {
    int tam=0;

    while(l) {tam++; l=l->prox;}

    return tam;
}

//2. -- certo
/*Como cada célula da lista tem a sua própria 
informação e o endereço da próxima célula, se 
fizermos free, por ex, do primeiro elemento 
perdemos as restantes células, logo temos de 
guardar o endereço da seguinte célula e só 
depois dar free do atual nodo. */

void freeL (LInt l) {
	while (l) {
		LInt temp=l;
        free(temp);
		l=l->prox;
	}
}

//3. -- certo
void imprimeL (LInt l) {
	LInt temp;

	if(l) {
		for (temp=l; temp; temp=temp->prox) {
			printf("%d\n", temp->valor);
		}
	}
	else {
		printf("Lista vazia.\n");
	}
}

//4. -- 10 testes corretos
LInt reverseL (LInt l) {
    LInt ant = NULL, // A posição anterior tem de começar a NULL pois o último elemento da lista aponta para NULL, considerando que a lista vai ser invertida.
         next = NULL, 
         curr = l;
         
    while (curr) {
        next = curr->prox;
        curr -> prox = ant;
        ant = curr;
        curr = next;
    }
    return ant;
}

//5. -- 10 testes corretos
void insertOrd (LInt *l, int x) {
	LInt new = (LInt) malloc (sizeof(struct lligada));
	new->valor = x;
    
    // Empty linked list or insert in the first place
	if(*l==NULL || (*l)->valor > x) {
		new->prox = *l; 
		*l=new; // Indicar à lista a nova cabeça da lista;
	}
	
	LInt curr,
	     prev = NULL, // No primeiro -if- inserimos o caso do primeiro lugar porque se não o prev tentava aceder ao prox sendo null 
	     next;
    
    for (curr = *l; curr; curr = curr->prox) {
        
        if (curr->valor > x) break;
    
        prev = curr;
        next = curr -> prox;
        
    }
    // Condições fora do -for- pois caso o x fosse o maior elemento da linked list não iria ser adicionado porque chegavamos ao fim
    prev->prox = new;
    new->prox = next;
}

//6. -- 10 testes corretos
int removeOneOrd (LInt *l, int x) {
    
    LInt *curr;
    for (curr=l; *curr;) {
        if ((*curr)->valor==x) {
            *curr=(*curr)->prox;
            return 0;
        }
        else curr=&((*curr)->prox);
    }
    return 1;
}

//7. -- 10 testes corretos
/*Com alocação de memória*/
void merge1 (LInt *r, LInt a, LInt b) {
    *r = NULL;
    LInt l1;

    for (l1 = a; l1; l1 = l1->prox) {
        appendL (r,l1->valor);
    }
    for (l1 = b; l1; l1 = l1->prox) {
        insertOrd (r,l1->valor);
    }
}

/*Sem alocação de memória*/
void merge2 (LInt *r, LInt a, LInt b) {
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

//8. -- 10 testes corretos
/*Com alocação de memória*/
void splitQS (LInt l, int x, LInt *mx, LInt *Mx) {
    if(l) {
        int i;
        LInt l1;
        
        for(l1=l; l1; l1=l1->prox) {
            if (l1->valor<x) appendL(mx, l1->valor);
            else appendL(Mx, l1->valor);
        }
    }
}

/*Sem alocação de memória*/
void splitQS (LInt l, int x, LInt *mx, LInt *Mx) {
    LInt l1 = l;
    LInt *mx_curr = mx, *Mx_curr = Mx;

    while(l1) {
        LInt temp = l1;
        if(l1->valor < x) {
            *mx_curr = temp;
            mx_curr=&((*mx_curr)->prox);
        }
        else {
            *Mx_curr = temp;
            Mx_curr=&((*Mx_curr)->prox);
        }
        l1=l1->prox;
        temp->prox = NULL;
    }
}

//9.


//10. -- 10 testes corretos
int removeAll (LInt *l, int x) {
    int ocorr=0;
    
    LInt *l1;
    for (l1=l; *l1;) {
        if ((*l1)->valor==x) {
            *l1=(*l1)->prox;
            ocorr++;
        }
        else l1=&((*l1)->prox);
    }
}

//11. -- 10 teste corretos
int removeDups (LInt *l) {
    LInt *l1,*l2;
    for (l1 = l; *l1; l1 = &((*l1)->prox)) {

        for (l2 = &((*l1)->prox); *l2; ) {
            
            if ((*l2)->valor == (*l1)->valor)
                *l2 = (*l2)->prox;
            else l2 = &((*l2)->prox);
        }
        //ou removeAll ((*l1)->prox, (*l1)->valor);
    }
}

//12. -- 10 testes corretos
int removeMaiorL (LInt *l) {
    int maior=0;
    LInt *curr;
    
    for(curr=l; *curr; curr=&((*curr)->prox)) {
        if ((*curr)->valor>maior) maior = (*curr)->valor;
    }
    
    for(curr=l; *curr;) {
        if ((*curr)->valor == maior) {
            (*curr) = (*curr)->prox;
            break;
        }
        else curr = &((*curr))->prox;
    }
    return maior;
}

//13. -- 10 testes corretos
void init (LInt *l) {
    LInt *curr;
    
    for(curr=l; (*curr)->prox; curr=&((*curr)->prox));
    
    *curr=NULL; //Libertar o espaço.
}

//14. -- 10 testes corretos
void appendL (LInt *l, int x) {
    LInt *curr;
    
    for (curr = l; *curr; curr=&((*curr)->prox));

    LInt new = malloc(sizeof(struct lligada));
    new -> valor = x;
    new -> prox = NULL;
    *curr = new;
}

//15. -- 10 testes corretos
void concatL (LInt *a, LInt b) {
    LInt *curr;
    
    for(curr=a; *curr; curr=&((*curr)->prox));
    *curr=b;
}

//16. -- certo
LInt cloneL (LInt l) {
    LInt result = NULL;

    for(; l; l=l->prox) {
        appendL(&result, l->valor);
    }
    return result;
}


//17. -- certo
LInt cloneRev (LInt l) {
    LInt result = NULL;

    for (; l; l=l->prox) {
        result = newLInt(l->valor, result);
    }
    return result;
}

//18. -- 10 testes corretos
int maximo (LInt l) {
    int max = 0;
    LInt curr;
    
    for (curr=l; curr; curr=curr->prox) {
        if (curr->valor > max) max = curr->valor;
    }
    return max;
}

//19. -- 10 testes corretos
int take (int n, LInt *l) {
    int length=0;
    int lim = 0;
    LInt *curr;
    
    for (curr=l; *curr; curr=&((*curr)->prox)) length++;
    if (length<=n) return length;
    else {
        for(curr=l; *curr;) {
            if (lim<n) {
                curr = &((*curr)->prox);
                lim++;
            }
            else (*curr)=(*curr)->prox;
        }
    }
    return lim;
}

//20. -- 10 testes corretos
int drop (int n, LInt *l){
    int tam = length(*l);
    
    if (tam<=n) {
        while(*l) {
            LInt temp = (*l)->prox;
            free(*l);
            *l = temp;
        }
        return tam;
    }

    else {
        int i=0;
        
        while(*l && i<n) {
            LInt temp = (*l)->prox;
            free(*l);
            *l = temp;
            
            i++;
        }
        return n;
    }
}

//21. -- 10 testes corretos
LInt NForward (LInt l, int N){
    int i;
    LInt *l1 = &l;
    
    for (i = 0; i < N && *l1; i++,l1 = &((*l1)->prox));
    
    return *l1;
}

//22. -- 10 testes corretos
int listToArray (LInt l, int v[], int N){
    int i;
    LInt curr;
    
    for (i=0, curr=l; i<N && curr; i++, curr=curr->prox) {
        v[i] = curr->valor;
    }
    return i;
}

//23. -- 10 testes corretos
LInt arrayToList (int v[], int N){
    int i;
    LInt l=NULL;
    
    for(i=N-1; i>=0; i--) {
        l = newLInt(v[i], l);
    }
    return l;
}

//24. -- 10 testes corretos
LInt somasAcL (LInt l) {
    if(l){   
        int soma=0;
        LInt *l1;
        LInt result=NULL;
        
        for(l1=&l; *l1; l1=&((*l1)->prox)){
            soma += (*l1)->valor;
            appendL(&result, soma);
        }
        return result;
        
    } 
    return NULL;
}

//25. -- 10 testes corretos
void remreps (LInt l) {
    if(!l || !l->prox) return;
    
    LInt ant = l;
    LInt l1;
    
    for(l1 = l->prox; l1; l1=l1->prox) {
        if(l1->valor==ant->valor) {
            ant->prox=l1->prox;
            free(l1);
        }
        else ant=l1;
    }
}

//26.
LInt rotateL (LInt l) {
    if (!l || !l->prox)return l;

    LInt *l1, newHead = l->prox;

    for (l1 = &l; *l1; l1 = &((*l1)->prox));
    l->prox = NULL;
    *l1 = l;

    return newHead;
}

//27. -- 10 testes corretos
LInt parte (LInt l){
    int conta=1;
    
    if (l) {
        LInt new;
        LInt par;
        LInt *curr=&l;
        
        while (*curr) {
            if((conta%2)==0) { //par
                new = malloc(sizeof(struct lligada));
                new->valor = (*curr)->valor;
                new->prox = NULL;
                
                appendL (&par, new->valor);
                (*curr)=(*curr)->prox;
            }
            else  {
                curr=&((*curr)->prox);
            }
        conta++;
        }
        return par;
    }
}


/***********************ÁRVORES BINÁRIAS***********************/
typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

/*Função auxiliar*/
ABin newABin (int r, ABin e, ABin d){
	ABin new = (ABin) malloc (sizeof (struct nodo));

	if (new!=NULL){
		new->valor = r;
		new->esq   = e;
		new->dir   = d;
	}
	return new;
}

//28. -- 10 testes corretos
int altura (ABin a){
    int altEsq, altDir, alt=0;
    
    if (a!=NULL) {
        altEsq = altura(a->esq);
        altDir = altura(a->dir);
        
        if (altEsq>altDir) alt=1+altEsq;
        else alt = 1+altDir;
    }
    return alt;
}

//29. -- 10 testes corretos
ABin cloneAB (ABin a) {
    if (!a) return NULL;
    
    ABin new = malloc(sizeof(struct nodo));
    new->valor = a->valor;
    new->esq = cloneAB(a->esq);
    new->dir = cloneAB(a->dir);
    
    return new;
}

//30. -- 10 testes corretos
void mirror (ABin *a) {
   if(*a) {   
        ABin temp = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = temp;
        mirror(&(*a)->dir);
        mirror(&(*a)->esq);
   }
}

/*
Preorder -> R E D
Inorder -> E R D
Posorder -> E D R
*/

//31. -- 10 testes corretos
void inorder (ABin a, LInt * l) {
    if (a) {
        LInt new = malloc(sizeof(struct nodo));
        new->valor = a->valor;
        new->prox = NULL;
        
        inorder (a->esq, l);
        
        
        for(; *l; l=&((*l)->prox));
        *l = new;
        
        inorder(a->dir, l);
    }
}

//32. -- 10 testes corretos
void preorder (ABin a, LInt * l) {
    if (a) {
        LInt new = malloc(sizeof(struct nodo));
        new->valor = a->valor;
        new->prox = NULL;
        
        *l=new;
        preorder(a->esq, &((*l)->prox));
        
        for(; *l; l=&((*l)->prox));
        preorder(a->dir, l);
         
    }
    else *l=NULL;
}

//33.

//34. -- 10 testes corretos
int depth (ABin a, int x) {
    if(!a) return -1;
    
    if(a->valor==x) return 1;
    int dir = depth(a->dir, x);
    int esq = depth(a->esq, x);
    
    if(dir==-1 && esq==-1) return -1;
    if(dir==-1) return 1+esq;
    if(esq==-1) return 1+dir;
    
    return 1+dir>1+esq ? 1+esq : 1+dir;
}

//35. -- 10 testes corretos
int freeAB (ABin a) {
    if (!a) return 0;
    
    int dir = freeAB(a->dir);
    int esq = freeAB(a->esq);
    
    free(a);
    
    return 1+dir+esq;
}

//36.

//37. -- 10 corretas
int iguaisAB (ABin a, ABin b) {
    if (!a && !b) return 1;
    if (a && b) {
        if(a->valor != b->valor) return 0;
        return iguaisAB(a->esq, b->esq) * iguaisAB(a->dir, b->dir);
    }
    return 0;
}

//38.

//39.

//40.
int dumpAbin (ABin a, int v[], int N) {
   int i;
   LInt l = NULL, *l1;
   
   inorder(a, &l);

   
   for(l1 = &l, i=0;*l1 && i<N; l1=&((*l1)->prox), i++) {
       v[i] = (*l1)->valor;
   }
   return i;
}

//41.

//42. -- 10 testes corretos
int contaFolhas (ABin a) {
    int folhas = 0;
    
    if (a) {
        if (a->esq == NULL && a->dir == NULL) return 1;
        folhas = contaFolhas(a->esq)+contaFolhas(a->dir);
    }
    return folhas;
}

//43. -- 10 testes corretos
ABin cloneMirror (ABin a) {
    if (!a) return NULL;
    
    ABin new =  newABin (a->valor, cloneMirror(a->dir), cloneMirror(a->esq));
    return new;
}

//44. -- 10 testes corretos
/* Árvore binária de procura: todos os elementos à direita da raiz são maires
que ela (raiz), e os elementos da esquerda menores. */
int addOrd (ABin *a, int x) {
    
    if (!*a) {
        ABin new = malloc(sizeof(struct nodo));
        new -> valor = x;
        new -> esq = NULL;
        new -> dir = NULL;
        *a = new;
        return 0;
    }
    
    if (x == (*a)->valor) return 1;
    if (x > (*a)->valor) return addOrd(&((*a)->dir), x);
    else  return addOrd(&((*a)->esq), x);
}

//45. -- 10 testes corretos
int lookupAB (ABin a, int x) {
    if(a) {
        if(x == a->valor) return 1;
        if(x > a->valor) return lookupAB(a->dir, x);
        else return lookupAB(a->esq, x);
    }
    return 0;
}

//46.

//47. -- 10 testes corretos
int maiorAB (ABin a) {
    if (!(a->dir)) return a->valor;
    return maiorAB(a->dir);
}

//48. -- 10 testes corretos
void removeMaiorA (ABin *a) {
    if(*a) {
        if (!(*a)->dir) (*a)=(*a)->esq;
        else removeMaiorA(&(*a)->dir);
    }
}

//49. -- 10 testes corretos
int quantosMaiores (ABin a, int x) {
    if (a) {
        if (a->valor>x) return 1 + quantosMaiores(a->esq, x) + quantosMaiores(a->dir, x);
        else quantosMaiores(a->dir, x);
    }
    else return 0;
}

//50.

//51.


int main() {
    return 0;
}



