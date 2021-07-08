#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//1. -- certo
int max () {
    int x;
    scanf ("%d", &x);

    int max=0;
    while (x!=0) {
        if (x>max) max=x;
        scanf ("%d", &x);
    }
    printf ("%d\n", max);
    return 0;
}

//2. -- certo
int media () {
    int x;
    scanf ("%d", &x);

    int total = 0, soma = 0, media=0;
    while (x!= 0) {
        scanf ("%d", &x);

        soma += x;
        total ++;
    }
    media = soma / total;
    printf ("%d\n", media);
    return 0;  
}

//3.


//4. -- 10 testes corretos
int bitsUm (unsigned int n){
    int bitsUm=0;
    while (n!=0) {
        if (n % 2 == 0) n= n/2;
        else {
            n = n/2;
            bitsUm ++;
        }
    }
    return bitsUm;
}

//5.

//6. -- 10 testes corretos
int qDig (unsigned int n) {
    int acc=0;
    while (n>0) {
        n/=10;
        acc++;
    }
    return acc;
}

//7. -- 10 testes corretos
char *mystrcat (char s1[], char s2 []) {
    int i, j;
    for (i = 0; s1[i] != '\0'; i++);
    for (j=0; s2[j] != '\0'; j++, i++) {
        s1[i] = s2[j];
    }
    s1[i] = '\0';
    return s1;
}

//8. -- 10 testes corretos
char *mystrcpy (char *dest, char source []) {
    int i;
    for (i=0; source[i] != '\0'; i++) {
        dest [i] = source [i];
    }
    dest [i] = '\0';
    return dest;
}

//9. -- 10 testes corretos
int mystrcmp (char s1[], char s2[]) { 
    int i,j;
    for (i=0, j=0; s1[i]!='\0' && s1[i]==s2[j]; i++, j++);
    return (s1[i]-s2[j]);
}


//10. -- 10 testes corretos
char *mystrstr (char s1[], char s2[]) {
    int i, j, itemp;
    if (s2[0]=='\0') return s1;
    for ( i=0; s1[i]!='\0'; i++) {
        for (j=0, itemp=i; s2[j]!='\0' && s1[itemp]==s2[j]; j++, itemp++) {
        }
        if (s2[j]=='\0') return s1+i;
    }
    return NULL;
}

//11. -- 10 testes corretos
void strrev (char s[]) {
    int i = 0, j = 0;
    char guardar;
    for (j=0; s[j] != '\0'; j++);
    j--; // o apontador j chegou ao fim da lista, ou seja, '\0';
    for (i=0; i<j; i++, j--) {
        guardar = s[i];
        s[i] = s[j];
        s[j] = guardar;
    }
}

//12. -- 10 testes corretos
void strnoV (char t[]){
    int i = 0, j = 0;
    for (i=0; t[i] != '\0'; i++) {
        if (t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u' || 
            t[i] == 'A' || t[i] == 'E' || t[i] == 'I' || t[i] == 'O' || t[i] == 'U') {

            j = i;
            i--;
            for (;t[j] != '\0'; j++) t[j]= t[j+1];
        }      
    }
}

//13.

//14. -- 10 testes corretos
char charMaisfreq (char s[]) {
    int i, j, numero = 0, max = 0;
    char guarda = s[0];
    
    for (i = 0; s[i]!='\0'; i++) {
        for (j=0; s[j]!= '\0'; j++) {
            if (s[i]==s[j]) numero ++;
        }
        if (numero>max) {
            max = numero; 
            guarda = s[i];
        }
        numero=0;
    }
    return guarda;
}

//15. -- 10 testes corretos
int iguaisConsecutivos (char s[]) {
    int i, iguais=1, max=0;

    for (i=0; s[i]!='\0'; i++) {
        for (; s[i]==s[i+1]; i++, iguais++);

        if (iguais>max) max = iguais;
        iguais = 1;
    }
    return max;
}

//16.

//17 -- 10 testes corretos
int maiorPrefixo (char s1 [], char s2 []) {
    int i;

    for (i=0; s1[i]!='\0' && s2[i]!='\0' && s1[i]==s2[i]; i++);
    return i; 
}

//18 -- 10 testes corretos
int maiorSufixo (char s1 [], char s2 []) {
    int i, j, comprimento=0;

    for (i=0; s1[i]!='\0'; i++);
    i--;
    for (j=0; s2[j]!='\0'; j++);
    j--;

    for (i, j; s1[i]==s2[j]; i--, j--, comprimento++);
    return comprimento;
}

//19 -- 10 testes corretos
int sufPref (char s1[], char s2[]) {
    int i, j, final, comprimento=0;

    for (final=0; s1[final]!='\0'; final ++); 

    for (i=0; s1[i]!='\0'; i++) {
        for (j=0; 
            s2[j]!='\0' && s1[i]==s2[j]; 
            j++, i++, comprimento++);

        if (i!=final) comprimento = 0;
    }
    return comprimento;
}

//20. -- 10 testes corretos
int contaPal (char s[]){
    int i, pal = 0, numPal = 0; 
    for (i = 0; s[i]; i++){
        if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t'){
            if (!pal) numPal++;
            pal = 1;
        }
        else pal = 0;
    }
    return numPal;
}

//21 -- 10 testes corretos
int contaVogais (char s[]) {
    int i, acc=0;
    
    for (i=0; s[i]!='\0'; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') acc++;
    }
    return acc;
}

//22 -- 10 testes corretos
int contida (char a[], char b[]) {
    int i, j, acc=0, length=0;

    
    for (i=0; a[i]!='\0'; i++, length++) {
        for (j=0; b[j]!='\0'; j++) {
            if (a[i]==b[j]) break;
        }
        if (!b[j]) return 0;
    }
    return 1;
}

//23.

//24 -- 10 testes corretos
int remRep (char x[]) {
    int i, j=0;

    for (i=0; x[i]!='\0'; i++) {
        if (x[i]==x[i+1]) {

            j=i;
            i--;
            for (; x[j]!='\0'; j++) x[j]=x[j+1];
        }  
    }
    return (i); 
}

//25.

//26. -- 10 testes corretos
void insere (int s[], int N, int x) {
    int i, j;
    
    for (i=0; i<N; i++) {
        if (s[i]>x) {
            for (j=N; j>i; j--) s[j] = s[j-1];
            s[j]=x;
            break;
        }
    }
}

//27.

//28. -- 10 testes corretos
int crescente (int a[], int i, int j){
       
    for(; i<j; i++) {
        if (a[i] > a[i+1]) return 0;
    }
    return 1;
}

//29. -- 10 testes corretos
int retiraNeg (int v[], int N){
    int i, ind=0, count=0;
    
    for (i=0; i<N;) {
        if (v[i]<0) {
            N--;
            for (ind=i; ind<N; ind++) {
                v[ind]=v[ind+1];
            }
        }
        else {
            count++;
            i++;
        }
    }
    return count;
}

//30.

//31.

//32.

//33. -- 10 testes corretos
int elimRep (int v[], int N) {
       int i, j, ind=0, count = 0;
       
       for (i=0; i<N; i++) {
           for (j=i+1; j<N;) {
               if (v[i]==v[j]) {
                   N--;
                   for(ind=j; ind<N; ind++) v[ind] = v[ind+1];
               }
               else j++;
           }
       }
       for(i=0; i<N; i++) count++;
       return count;
   }

//34.

//35.

//36. -- 10 testes corretos
int comuns (int a[], int na, int b[], int nb){
      int i, j, count=0;
      
      for (i=0; i<na; i++) {
          for (j=0; j<nb; j++) {
              if (a[i]==b[j]) {
                  count++;
                  break;
              }
          }
      }
      return count;
   }

//37. -- 10 testes corretos
int minInd (int v[], int n) {
   int i, menorInd=0, menorValor=v[0];
   
   for(i=0; i<n; i++) {
       if(v[i]<menorValor) {
           menorValor = v[i];
           menorInd = i;
       }
   }
   return menorInd;
}

//38. -- 10 testes corretos
void somasAc (int v[], int Ac [], int N){
   int i, ac, soma=0;
   
   for(ac=0; ac<N; ac++) {
       for (i=0; i<=ac; i++) soma+=v[i];
       Ac[ac] = soma;
       soma=0;
   }
}

//39.

//40.

//41. -- 10 testes corretos
void addTo(int N, int M, int a [N][M], int b[N][M]) {
    int n, m;
    
    for(n=0; n<N; n++) {
        for(m=0; m<M; m++) {
            a[n][m] += b[n][m];
        }
    }
}

//42.

//43.

//44.

//45.

//46.

//47.

//48.

//49.

//50.



int main () {
    return 0;
}
