#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//3.1
void ex1 (int num) {
    
    for (int col=0; col<num; col ++) {
        for(int lin=0;lin<num;lin++) {
            printf ("%c", 35);
        }
        printf ("\n");
    }
    printf("\n");
}

//3.2
void ex2 (int num) {

    int col, lin;
    for(col=0;col<num; col++) {
        
        if (col%2==0) { //linhas pares
            for (lin=0; lin<num; lin++) {
                if (lin%2==0) {
                    printf("%c",35);
                }
                else {
                    printf ("%c",95);
                }
            }
            printf ("\n");
        }
        else { //linhas impar
            for (lin=0; lin<num; lin++) {
                if (lin%2==0) {
                    printf("%c",95);
                }
                else {
                    printf ("%c",35);
                }
            }
            printf ("\n");
        }
    }
    printf("\n");
}

//3.3
void triangulo1 (int num) {

    for(int col=0;col<num;col++) {
        for (int lin=0; lin<=col; lin++) {
            printf ("%c", 35);
        }
    printf("\n");
    }

    for (int col=num-1;col>0;col--) {
        for (int lin=0;lin<col;lin++) {
            printf ("%c", 35);
        }
    printf("\n");
    }
    printf("\n");
}

void triangulo2 (int num) {
    int numespaco = num-1, acc;
    
    for (int col=1; col<=num; col++) {
        for (int lin=0; lin<(numespaco + 2*col-1); lin++){
            if (lin<numespaco) printf("%c",32);
            else {
                printf("%c", 35);
            }
        }
        printf("\n");
        numespaco--;
    }
    printf("\n");
}

int main () {
    ex1(5);
    ex2(5);
    triangulo1 (5);
    triangulo2 (5);
    return 0;
}



