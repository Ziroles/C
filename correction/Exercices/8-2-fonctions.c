#include "8-2-fonctions.h"
#include <stdio.h>

const int NB_PIONS_PAR_COULEUR = 3;
const int TAILLE = NB_PIONS_PAR_COULEUR * 2 + 1;

void init(char plateau[]) {
    int i;
    for(i=0; i<NB_PIONS_PAR_COULEUR; i++)
        plateau[i] = '>';
    plateau[NB_PIONS_PAR_COULEUR] = ' ';
    for(i=NB_PIONS_PAR_COULEUR+1; i<TAILLE; i++)
        plateau[i] = '<';
}

void afficher(const char plateau[]) {
    int i;
    for(i=1; i<=TAILLE; i++)
        printf("%2d", i);
    printf("\n");
    for(i=0; i<TAILLE; i++)
        printf("|%c", plateau[i]);
    printf("|\n");
}

char gagne(const char plateau[]) {
    char ok = plateau[NB_PIONS_PAR_COULEUR] == ' ';
    int i=0;
    while(ok && i<NB_PIONS_PAR_COULEUR) {
        ok = plateau[i] == '<';
        i++;
    }
    return ok;
}

char bloque(const char plateau[]) {
    // recherche de la position de la case blanche
    int posCB = 0;
    while (plateau[posCB] != ' ') {
        posCB++;
    }
    // un mouvement est-il possible vers cette case blanche ?
    return !(posCB>0        && plateau[posCB-1]=='>'
        ||   posCB>1        && plateau[posCB-2]=='>'
        ||   posCB<TAILLE-1 && plateau[posCB+1]=='<'
        ||   posCB<TAILLE-2 && plateau[posCB+2]=='<');
}

void joueUnCoup(char plateau[]) {
    int pos;
    printf("Quel mouton souhaitez-vous déplacer ?\n");
    scanf(" %d", &pos);
    pos--;
    if(pos<0 || pos>=TAILLE) {
        printf("Position hors du plateau de jeu !\n");
    } else if(plateau[pos] == ' ') {
        printf("Il n'y a pas de mouton dans cette case !\n");
    } else if(plateau[pos] == '>') {
        if(pos < TAILLE-1 && plateau[pos+1]==' ') {
            plateau[pos] = ' ';
            plateau[pos+1] = '>';
        } else if(pos < TAILLE-2 && plateau[pos+1]=='<' && plateau[pos+2]==' ') {
            plateau[pos] = ' ';
            plateau[pos+2] = '>';
        } else {
            printf("Déplacement impossible !\n");
        }
    } else if(plateau[pos] == '<') {
        if(pos > 0 && plateau[pos-1]==' ') {
            plateau[pos] = ' ';
            plateau[pos-1] = '<';
        } else if(pos > 1 && plateau[pos-1]=='>' && plateau[pos-2]==' ') {
            plateau[pos] = ' ';
            plateau[pos-2] = '<';
        } else {
            printf("Déplacement impossible !\n");
        }
    }
}