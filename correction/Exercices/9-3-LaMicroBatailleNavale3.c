#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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

char tirer(char** plateau, int hauteur, int largeur) {
    int i = saisieEntierEntreBornes("Quelle colonne ? ", 1, largeur) - 1;
    int j = saisieEntierEntreBornes("Quelle ligne ? ", 1, hauteur) - 1;
    if(plateau[j][i]!=BATEAU) {
        plateau[j][i] = PLOUF;
        printf("Plouf !\n");
    }
    return plateau[j][i]==BATEAU;
}

void afficherPlateau(char** plateau, int hauteur, int largeur) {
    for(int j=0; j<hauteur; j++) {
        for(int i=0; i<largeur; i++)
            printf("%c", plateau[j][i]==BATEAU||plateau[j][i]==EAU?INCONNU:plateau[j][i]);
        printf("\n");
    }
}

char** initialiserPlateau(int* hauteur, int* largeur) {
    *largeur = saisieEntierEntreBornes("largeur du plateau de jeu ?", 1, 10);
    *hauteur = saisieEntierEntreBornes("hauteur du plateau de jeu ?", 1, 10);
    char** plateau = malloc(sizeof(char*) * *hauteur);
    for(int j=0; j<*hauteur; j++) {
        plateau[j] = malloc(sizeof(char) * *largeur);
        for(int i=0; i<*largeur; i++)
            plateau[j][i] = EAU;
    }
    // dépôt du bateau
    srand(time(NULL));
    plateau[rand()%*hauteur][rand()%*largeur] = BATEAU;
    return plateau;
}

int main() {
    char gagne;
    int hauteur, largeur;
    // initialisation du plateau de jeu
    char** plateau = initialiserPlateau(&hauteur, &largeur);
    do {
        //affichage du plateau de jeu
        afficherPlateau(plateau, hauteur, largeur);
        // saisie des coordonnées de tir
        gagne = tirer(plateau, hauteur, largeur);
    } while(!gagne);
    printf("Touché coulé ! Bravo, vous avez gagné !\n");
    return 0;
}