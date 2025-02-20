#include<stdio.h>

int main() {
    float val = 2.25f;
    float* pval = &val;

    (*pval)++;

    printf("valeur : %.2f\nadresse de la variable : %p\nadresse du pointeur : %p\n", *pval, pval, &pval);

    return 0;
}