#include <stdio.h>
#include <stdlib.h>
#include "10-2-fonctions.h"

int main() {
    unsigned char hauteur;
    unsigned char largeur;
    unsigned char saisieChoix;
    char* dessin = NULL;
    char* choix[] = {"Nouveau", "Ouvrier", "Enregistrer", "Dessiner un caractère", "Dessiner un rectangle", "Changer de caractère pour une zone", "quitter"};
    for(unsigned char i=0; i<2; i++) {
        printf("%d - %s\n", i+1, choix[i]);
    }
    saisieChoix = saisie("", 1, 2);
    switch (saisieChoix) {
        case 1: creer(&dessin, &largeur, &hauteur); break;
        case 2: charger(&dessin, &largeur, &hauteur); break;
    }
    do {
        afficher(dessin, largeur, hauteur);
        for(unsigned char i=0; i<7; i++) {
            printf("%d - %s\n", i+1, choix[i]);
        }
        saisieChoix = saisie("", 1, 7);
        if(saisieChoix<=2 || saisieChoix==7) {
            proposerEnregistrement(dessin, largeur, hauteur);
        }
        switch (saisieChoix) {
            case 1: creer(&dessin, &largeur, &hauteur); break;
            case 2: charger(&dessin, &largeur, &hauteur); break;
            case 3: enregistrer(dessin, largeur, hauteur); break;
            case 4: dessinerCaractere(dessin, largeur, hauteur); break;
            case 5:  dessinerRectangle(dessin, largeur, hauteur);break;
            case 6: changerCaractere(dessin, largeur, hauteur); break;
            case 7: free(dessin);
        }
    } while(saisieChoix!=7);
    return 0;
}