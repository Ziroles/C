#include<stdio.h>

int main () {
    int n1;
    int n2;
    char opérateur;

    
    printf("\tN1\n");
    scanf(" %d", &n1);
    printf("\tN2\n");
    scanf(" %d", &n2);

    
    printf("\tSaisissez l'opérateur (+ ou -) : ");
    scanf(" %c", &opérateur);

    
    if (opérateur == '+') {  
        printf("Dividende %d + diviseur %d = %d (quotient)\n", n1, n2, n1 + n2);
    } else if (opérateur == '-') {  
        printf("Dividende %d - diviseur %d = %d (quotient)\n", n1, n2, n1 - n2);
    } else {
        printf("Opérateur invalide. Veuillez entrer + ou -.\n");
    }

    return 0;
}
