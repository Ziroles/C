#include "10-2-fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

unsigned char saisie(char* const message, unsigned char min, unsigned char max) {
    unsigned char val;
    char ok;
    printf("%s\n", message);
    do {
        scanf(" %hhu", &val);
        ok = min <= val && val <= max;
        if(!ok)
            printf("La valeur doit être comprise entre %hhu et %hhu. Resaisissez...\n", min, max);
    } while(!ok);
    return val;
}

void creer(char** dessin, unsigned char* largeur, unsigned char* hauteur) {
    *hauteur = saisie("Hauteur de la zone de dessin ?", 1, 50);
    *largeur = saisie("Largeur de la zone de dessin ?", 1, 80);
    *dessin = realloc(*dessin, sizeof(char) * *hauteur * *largeur);
    for(char j=0; j<*hauteur; j++) {
        for(char i=0; i<*largeur; i++)
            (*dessin)[(unsigned short)j * *largeur + i] = ' ';
    }
}

void afficher(char* dessin, unsigned char largeur, unsigned char hauteur) {
    printf("%hhu x %hhu\n", hauteur, largeur);
    ecrireAffichage(dessin, largeur, hauteur, stdout);
}

void ecrireAffichage(char* dessin, unsigned char largeur, unsigned char hauteur, FILE* sortie) {
    for(unsigned char j=0; j<hauteur; j++) {
        for(unsigned char i=0; i<largeur; i++) {
            fprintf(sortie, "%c", dessin[(unsigned short)j*largeur+i]);
        }
        if(sortie==stdout)
            printf("\n");
    }
}

void dessinerCaractere(char* dessin, unsigned char largeur, unsigned char hauteur) {
    unsigned char y = saisie("ligne ?", 1, hauteur) - 1;
    unsigned char x = saisie("colonne ?", 1, largeur) - 1;
    char c;
    printf("caractère ?\n");
    scanf(" %c", &c);
    dessin[(unsigned short)y*largeur+x] = c;
}

void dessinerRectangle(char* dessin, unsigned char largeur, unsigned char hauteur) {
    unsigned char y1 = saisie("première ligne ?", 1, hauteur) - 1;
    unsigned char y2 = saisie("dernière ligne ?", y1+1, hauteur) - 1;
    unsigned char x1 = saisie("première colonne ?", 1, largeur) - 1;
    unsigned char x2 = saisie("dernière colonne ?", x1+1, largeur) - 1;
    char c;
    printf("caractère ?\n");
    scanf(" %c", &c);
    for(unsigned char j=y1; j<=y2; j++) {
        for(unsigned char i=x1; i<=x2; i++) {
            dessin[(unsigned short)j*largeur+i] = c;
        }
    }
}

void propager(char* dessin, unsigned char largeur, unsigned char hauteur, unsigned char x, unsigned char y, char ancienCar, char nouveauCar) {
    if(0<=y && y<hauteur && 0<=x && x<largeur && dessin[y*largeur+x] == ancienCar) {
        dessin[y*largeur+x] = nouveauCar;
        propager(dessin, largeur, hauteur, x, y-1, ancienCar, nouveauCar); // haut
        propager(dessin, largeur, hauteur, x+1, y, ancienCar, nouveauCar); // droite
        propager(dessin, largeur, hauteur, x, y+1, ancienCar, nouveauCar); // bas
        propager(dessin, largeur, hauteur, x-1, y, ancienCar, nouveauCar); // gauche
    }
}

void changerCaractere(char* dessin, unsigned char largeur, unsigned char hauteur) {
    unsigned char y = saisie("ligne ?", 1, hauteur) - 1;
    unsigned char x = saisie("colonne ?", 1, largeur) - 1;
    char nouveauCar;
    printf("caractère ?\n");
    scanf(" %c", &nouveauCar);
    char ancienCar = dessin[y*largeur+x];
    if(ancienCar != nouveauCar) {
        propager(dessin, largeur, hauteur, x, y, ancienCar, nouveauCar);
    }
}

//privée
char fexist(char* const fichier) {
    struct stat buffer;
    return !stat(fichier, &buffer);
}

//privée
char choixOuiOuNon(char* const message) {
    printf("%s (o/n)\n", message);
    char rep;
    scanf(" %c", &rep);
    return rep == 'o';
}

void proposerEnregistrement(char* dessin, unsigned char largeur, unsigned char hauteur) {
    if(choixOuiOuNon("Voulez-vous enregistrer avant ?")) {
        enregistrer(dessin, largeur, hauteur);
    }
}

void enregistrer(char* dessin, unsigned char largeur, unsigned char hauteur) {
    char saisie[1024];
    char enregistre;
    do {
        printf("Entrer le nom du fichier dans lequel enregistrer\n");
        scanf(" %s", saisie);
        if(!fexist(saisie) || (enregistre = choixOuiOuNon("Voulez-vous remplacer le fichier ?"))) {
            FILE* fichier = fopen(saisie, "w");
            fprintf(fichier, "%hhux%hhu\n", largeur, hauteur);
            ecrireAffichage(dessin, largeur, hauteur, fichier);
            fclose(fichier);
            enregistre = 1;
        }
    } while(!enregistre);
}

void charger(char** dessin, unsigned char* largeur, unsigned char* hauteur) {
    char saisie[1024];
    printf("Entrer le nom du fichier à ouvrir\n");
    scanf(" %s", saisie);
    unsigned char existe = fexist(saisie);
    if(!existe) {
        printf("fichier non trouvé\n");
    } else {
        FILE* fichier = fopen(saisie, "r");
        fscanf(fichier, " %hhu x %hhu \n", largeur, hauteur);
        printf("%hhu x %hhu\n", *largeur, *hauteur);
        *dessin = realloc(*dessin, sizeof(char) * *hauteur * *largeur);
        for(unsigned short pos=0; pos<*hauteur * *largeur; pos++) {
            (*dessin)[pos] = fgetc(fichier);
        }
        fclose(fichier);
    }
}