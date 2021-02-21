#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//3.1

void ex1 (int num) {
    char c;
    for (int numtemp=num; numtemp>0; numtemp --) {
        for(int inicio=0;inicio<num;inicio++) {
            printf ("%c", 35);
        }
        printf ("\n");
    }
    printf("\n");
}

//3.2
void ex2 (int num) {
    char c;
    int inicio=0;

   
    for(int iniciotemp=inicio;iniciotemp<num;iniciotemp++) {
        if (num%2==0) { //num é par
            if (iniciotemp%2==0) { //linhas pares
                for (int iniciotemp1=inicio; iniciotemp1<(num/2); iniciotemp1 ++) {
                    printf ("%c%c",35,95);
                }
                printf ("\n");
            }
            else { //linhas ímpar
                for (int iniciotemp2=inicio; iniciotemp2<(num/2); iniciotemp2 ++) {
                    printf ("%c%c",95,35);
                }
                printf ("\n");
            }
        }
        
        else { //num é ímpar
            if (iniciotemp%2==0){  // linhas pares
                for(int iniciotemp1=inicio; iniciotemp1<num; iniciotemp1++) {
                    if (iniciotemp1%2==0){
                    printf ("%c",35);
                    }
                    if (iniciotemp1%2!=0) {
                     printf ("%c",95);
                    }
                }
                printf("\n");
            }
            else { //linhas impares
                for(int iniciotemp2=inicio; iniciotemp2<num; iniciotemp2++) {
                    if (iniciotemp2%2==0){
                    printf ("%c",95);
                    }
                    if (iniciotemp2%2!=0) {
                     printf ("%c",35);
                    }
                }
                printf("\n");
            }
        }
    }
    printf("\n");
}

//3.3

void triangulo1 (int num) {
    char c;
    int inicio=0;

    for(;inicio<num;inicio++) {
        for (int iniciotemp=inicio; iniciotemp >=0; iniciotemp--) {
            printf ("%c", 35);
        }
    printf("\n");
    }
    num=num-1;
    for (;num>0;num--) {
        for (int numtemp=num;numtemp>0;numtemp --) {
            printf ("%c", 35);
        }
    printf("\n");
    }
    printf("\n");
}

void triangulo2 (int num) {

    char c;
    int inicio=1;
    int total= 2*num-1;
    int numeroespaco = (total/2)-(1/2); //número de espaços inicial

    for(inicio;inicio<=num;inicio++, numeroespaco --) {
        for (int numeroespacotemp=numeroespaco; numeroespacotemp>0; numeroespacotemp--) {
             printf ("%c", 32);
        }
        
        for (int iniciotemp=2*inicio-1; iniciotemp >0; iniciotemp--) {
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



