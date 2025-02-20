#include<stdio.h>

int main() {
    const int TAILLE = 10;

    printf(" *** Tableau d'int ***\n");
    int tabInt[TAILLE];
    for(int i=0; i<TAILLE; i++) {
        printf("Case n°%d à l'adresse mémoire %p\n", i, &tabInt[i]);
    }
    // Les adresses avancent de 4 en 4 car int utilise 4 octets

    printf(" *** Tableau de char ***\n");
    char tabChar[TAILLE];
    for(int i=0; i<TAILLE; i++) {
        printf("Case n°%d à l'adresse mémoire %p\n", i, &tabChar[i]);
    }
    // Les adresses avancent de 1 en 1 car char utilise 1 octet

    printf(" *** Tableau de short ***\n");
    short tabShort[TAILLE];
    for(int i=0; i<TAILLE; i++) {
        printf("Case n°%d à l'adresse mémoire %p\n", i, &tabShort[i]);
    }
    // Les adresses avancent de 2 en 2 car short utilise 2 octets

    printf(" *** Tableau de double ***\n");
    double tabDouble[TAILLE];
    for(int i=0; i<TAILLE; i++) {
        printf("Case n°%d à l'adresse mémoire %p\n", i, &tabDouble[i]);
    }
    // Les adresses avancent de 8 en 8 car double utilise 8 octets

    return 0;
}