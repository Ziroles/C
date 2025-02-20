#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* creeEtInitTab(int taille, int min, int max) {
    srand(time(NULL));
    int* tab = malloc(sizeof(int)*taille);
    if(tab != NULL) {
        for(int i=0; i<taille; i++) {
            tab[i] = rand()%(max-min+1)+min;
        }
    }
    return tab;
}

int max(int const tab[], int taille) {
    int maxi = tab[0];
    for(int i=1; i<taille; i++) {
        if(tab[i]>maxi) {
            maxi = tab[i];
        }
    }
    return maxi;
}

int main() {
    const int taille = 10;
    const int* const tableau = creeEtInitTab(taille, -100, 100);
    if(tableau == NULL) {
        printf("Allocation mémoire impossible...\n");
        return 1;
    }
    for(int i=0; i<taille; i++) {
        printf("%d\n", tableau[i]);
    }
    printf("La plus grandes valeur tirée est %d\n", max(tableau, taille));
}