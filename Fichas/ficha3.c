#include <stdio.h>
/* ---- Pointers ----

Como declaramos apontadores.:
(type) * p;

Caso o apontador não tenha '*' temos que lhe indicar o "caminho", isto é,
o endereço de memória da var, dado por &.
> Atribuir valor ao apontador <
p = &var; 

> Aceder ao valor que o apontador está a apontar <
*p = var;

*/

// 2
void swapM (int *x, int *y) {
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}


// 3
void swap (int v[], int i, int j) {
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// 4
int soma (int v[], int N) {
    int soma=0;
    
    for (int i=0; i<N; i++) {
        soma+= v[i];
    }
    return soma;
}

// 5
void inverteArray1 (int v[], int N) {
    
    for (int i=0, j=N-1; i<j; i++, j--) {
        swapM(&v[i], &v[j]);
    }
}


void inverteArray2 (int v[], int N) {
    
    for (int i=0, j=N-1; i<j;  i++, j--) {
        swap(v,i,j);
    }
}

// 6

int maximum (int v[], int N, int *m) {
    int max = 0;

    for (int i=0; i<N; i++) {
        if (v[i]>max) {
            m = &v[i];
        }
    }
    return *m;
}

// 7
void quadrados (int q[], int N) {
    
    for (int i=0; i<N; i++) {
        q[i] = i*i;
    }
    
}

// 8 -> FAZER


int main () {
    /* Para testar um exercício é necessário meter em comentário os outros,
    visto que, vários exercícios se referem ao mesmo vetor e as mudanças vão sendo 
    feitas.*/
    
    // 2
    int x = 3, y = 5;
    swapM (&x, &y);

    printf ("%d %d\n", x, y);

    
    int v [5] = {1,2,3,4,5};
    int q [5];
    // 3
    swap(v,0,3);

    // 4
    int acc = soma(v,5);

    printf("%d \n", acc);
    
    // 5
    inverteArray2(v,5);
    
    inverteArray1(v,5);

    for (int i=0; i<5; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    // 6
    int *m;
    int max = maximum(v,5,m);

    printf("%d \n", max);
    
    // 7
    quadrados(q, 4);

    for (int i=0; i<5; i++) {
        printf("%d ", q[4]);
    }
    printf("\n");
    
    // 8 -> FAZER
    return 0;
}