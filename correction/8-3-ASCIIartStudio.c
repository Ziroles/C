#include <stdio.h>
#include "8-3-fonctions.h"

int main() {
    char saisie;
    char dessin[HAUTEUR][LARGEUR];
    initialiser(dessin);
    do {
        afficher(dessin);
        printf("1 - Dessiner un caractère\n2 - Dessiner un rectangle\n3 - Changer de caractère pour une zone\n4 - Quitter\n");
        scanf(" %hhd", &saisie);
        switch (saisie) {
            case 1: dessinerCaractere(dessin); break;
            case 2: dessinerRectangle(dessin); break;
            case 3: changerCaractere(dessin); break;
            case 4: break;
            default: printf("Saisie incorrecte\n"); break;
        }
    } while(saisie!=4);
    return 0;
}