#include <stdio.h>
#include <math.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

//1
int nota (Aluno a) {
    int i;
    double miniTestes=0, nota=0;
    
    for (i=0; i<6; i++){
        if(a.miniT[i]==0) miniTestes+=0;
        if(a.miniT[i]==1) miniTestes+=10;
        if(a.miniT[i]==2) miniTestes+=20;
    }
    miniTestes /= 6;
    
    nota = round(miniTestes*0.3 + (a.teste)*0.7);
    
    return nota;
}

//2
int procuraNum (int num, Aluno t[], int N){
  int i;

  for (i=0; i<N; i++) {
    if (t[i].numero==num) return i; 
  }
  return -1;
}

//3
void ordena (int numero)

void ordenaPorNum (Aluno t [], int N){

}