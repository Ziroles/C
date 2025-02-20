#include <stdio.h>
#include "8-3-fonctions.h"

const int HAUTEUR = 10;
const int LARGEUR = 40;

void initialiser(char dessin[][LARGEUR]) {
    for(int j=0; j<HAUTEUR; j++)
        for(int i=0; i<LARGEUR; i++)
            dessin[j][i] = ' ';
}

int saisie(char* const message, int min, int max) {
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

void afficher(char const dessin[][LARGEUR]) {
    for(int j=0; j<HAUTEUR; j++) {
        for(int i=0; i<LARGEUR; i++) {
            printf("%c", dessin[j][i]);
        }
        printf("\n");
    }
}

void dessinerCaractere(char dessin[][LARGEUR]) {
    int y = saisie("ligne ?", 1, HAUTEUR) - 1;
    int x = saisie("colonne ?", 1, LARGEUR) - 1;
    char c;
    printf("caractère ?\n");
    scanf(" %c", &c);
    dessin[y][x] = c;
}

void dessinerRectangle(char dessin[][LARGEUR]) {
    int y1 = saisie("première ligne ?", 1, HAUTEUR) - 1;
    int y2 = saisie("dernière ligne ?", y1+1, HAUTEUR) - 1;
    int x1 = saisie("première colonne ?", 1, LARGEUR) - 1;
    int x2 = saisie("dernière colonne ?", x1+1, LARGEUR) - 1;
    char c;
    printf("caractère ?\n");
    scanf(" %c", &c);
    for(int j=y1; j<=y2; j++) {
        for(int i=x1; i<=x2; i++) {
            dessin[j][i] = c;
        }
    }
}

void changerCaractere(char dessin[][LARGEUR]) {
    int y = saisie("ligne ?", 1, HAUTEUR) - 1;
    int x = saisie("colonne ?", 1, LARGEUR) - 1;
    char nouveauCar;
    printf("caractère ?\n");
    scanf(" %c", &nouveauCar);
    char ancienCar = dessin[y][x];
    printf("%c -> %c\n", ancienCar, nouveauCar);
    if(ancienCar != nouveauCar) {
        propager(dessin, x, y, ancienCar, nouveauCar);
    }
}

void propager(char dessin[][LARGEUR], int x, int y, char ancienCar, char nouveauCar) {
    //printf("y=%d, x=%d, dessin[y][x]=%c, ancienCar=%c\n", y, x, dessin[y][x], ancienCar);
    if(0<=y && y<HAUTEUR && 0<=x && x<LARGEUR && dessin[y][x] == ancienCar) {
        dessin[y][x] = nouveauCar;
        propager(dessin, x, y-1, ancienCar, nouveauCar);
        propager(dessin, x+1, y, ancienCar, nouveauCar);
        propager(dessin, x, y+1, ancienCar, nouveauCar);
        propager(dessin, x-1, y, ancienCar, nouveauCar);
    }
}