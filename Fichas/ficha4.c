#include <stdio.h>


// Ex1

// 1.
int isVogal (char c) {
    return (c== 'a' || c=='e' || c=='i' || c=='o' || c=='u'
    || c== 'A' || c=='E' || c=='I' || c=='O' || c=='U');
}

int contaVogais1 (char *s) {
    int conta=0;

    for (int i=0; s[i]!='\0'; i++) {
        if (isVogal(s[i])) conta++;
    }

    return conta;
}

int contaVogais2 (char *s) {
    int conta=0;

    for (; *s; s++) {
        if (isVogal(*s)) conta++;
    }

    return conta;
}



int main () {
    char v [5] = {'o','l','a',':',')'};

    int conta = contaVogais2(&v[0]);
    printf ("1.1) %d\n", conta);

    return 0;
}
