#include <stdio.h>
#include "8-2-fonctions.h"

int main() {
    char plateau[TAILLE];
    char victoire;

    init(plateau);
    afficher(plateau);
    do {
        joueUnCoup(plateau);
        afficher(plateau);
        victoire = gagne(plateau);
    } while(!victoire && !bloque(plateau));
    if(victoire) {
        printf("Bravo ! Vous avez réussi !!!\n");
    } else {
        printf("Perdu ! Vous êtes bloqué...\n");
    }
    return 0;
}