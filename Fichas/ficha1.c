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

    int numespaco = (((2*num)-1)/2)-(1/2); //número de espaços inicial
    int inicilizar = 1; // var que dá origem ao num de impressões por linha

    for(int col=0;col<num;col++, numespaco --, inicilizar++) {
        for (int lin=0; lin<numespaco; lin++) {
             printf ("%c", 32);
        }
        
        for (int lin=2*inicilizar-1; lin>0; lin--) {
            printf ("%c", 35);
        }
    printf("\n");
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



