#include <stdio.h>
/* 
---- Pointers ----

Como declaramos apontadores.:
(type) * p;

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
    *m = v[0];

    for (int i=0; i<N; i++) {
        if (v[i]>*m) {
            *m = v[i];
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

// 8 

long fatorial (int n) {
    long fatorial;

    for (fatorial=1; n>1; n=n-1) {
        fatorial *= n;  
    }
    return fatorial;
}

// 8
/*Nota -> Linha N tem N elementos.*/



int main () {
    
    // 2
    printf("2) ");
    int x = 3, y = 5;
    swapM (&x, &y);

    printf ("%d %d\n", x, y);

    int v1 [5] = {1,2,3,4,5};
    int v2 [5] = {6,7,8,9,10};
    int v3 [5] = {11,12,13,14,15};
    int q [5];

    // 3
    printf("3) ");
    swap(v1,1,3);

    for (int i=0; i<5; i++) {
        printf("%d ", v1[i]);
    }
    printf("\n");

    // 4
    int s1 = soma(v1,5);
    int s2 = soma(v2,5);
    int s3 = soma(v3,5);

    printf("4) v1: %d, v2: %d, v3: %d \n", s1, s2, s3);
    
    // 5
    printf("5) \n");
    inverteArray2 (v2,5);

    for (int i=0; i<5; i++) {
        printf("%d ", v2[i]);
    }
    printf("\n");
    
    inverteArray1(v3,5);

    for (int i=0; i<5; i++) {
        printf("%d ", v3[i]);
    }
    printf("\n");

    // 6
    int *max;
    int max1 = maximum(v1,5,max);
    int max2 = maximum(v2,5,max);
    int max3 = maximum(v3,5,max);

    printf("6) v1: %d, v2: %d, v3: %d \n", max1, max2, max3);
    
    // 7
    printf("7) ");    
    quadrados(q, 5);

    for (int i=0; i<5; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
    
    // 8 -> FAZER

    return 0;
}