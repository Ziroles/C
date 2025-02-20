#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int HAUTEUR = 4;
const int LARGEUR = 4;
const char PLOUF = '~';
const char BATEAU = 'b';
const char EAU = 'e';
const char INCONNU = '?';

int saisieEntierEntreBornes(const char* message, int min, int max) {
    int val;
    char ok;
    printf("%s\n", message);
    do {
        scanf(" %d", &val);
        ok = min <= val && val <= max;
        if(!ok)
            printf("La valeur doit être comprise entre %d et %d. Resaisissez...\n", min, max);
    } while(!ok);
    return val;
}

char tirer(char** plateau) {
    int i = saisieEntierEntreBornes("Quelle colonne ? ", 1, LARGEUR) - 1;
    int j = saisieEntierEntreBornes("Quelle ligne ? ", 1, HAUTEUR) - 1;
    if(plateau[j][i]!=BATEAU) {
        plateau[j][i] = PLOUF;
        printf("Plouf !\n");
    }
    return plateau[j][i]==BATEAU;
}

void afficherPlateau(char** plateau) {
    for(int j=0; j<HAUTEUR; j++) {
        for(int i=0; i<LARGEUR; i++)
            printf("%c", plateau[j][i]==BATEAU||plateau[j][i]==EAU?INCONNU:plateau[j][i]);
        printf("\n");
    }
}

char** initialiserPlateau() {
    char** plateau = malloc(sizeof(char*)*HAUTEUR);
    for(int j=0; j<HAUTEUR; j++) {
        plateau[j] = malloc(sizeof(char)*LARGEUR);
        for(int i=0; i<LARGEUR; i++)
            plateau[j][i] = EAU;
    }
    // dépôt du bateau
    srand(time(NULL));
    plateau[rand()%HAUTEUR][rand()%LARGEUR] = BATEAU;
    return plateau;
}

int main() {
    char gagne;
    // initialisation du plateau de jeu
    char** plateau = initialiserPlateau();
    do {
        //affichage du plateau de jeu
        afficherPlateau(plateau);
        // saisie des coordonnées de tir
        gagne = tirer(plateau);
    } while(!gagne);
    printf("Touché coulé ! Bravo, vous avez gagné !\n");
    return 0;
}