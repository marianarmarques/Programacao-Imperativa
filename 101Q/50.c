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

//2.
int main () {
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

//17 -- 10 testes corretos
int maiorPrefixo (char s1 [], char s2 []) {
    int i, j, comprimento=0;

    for (i=0, j=0; 
         s1[i]!='\0' && s2[j]!='\0' && s1[i]==s2[j]; 
         i++, j++, comprimento++);
    return comprimento;
    
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

//21 -- 10 testes corretos
int contaVogais (char s[]) {
    int i, acc=0;
    
    for (i=0; s[i]!='\0'; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') acc++;
    }
    return acc;
}
