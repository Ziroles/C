#include<stdio.h>

int main()
{
    const char SYMBOLE1 = 'o';
    const char SYMBOLE2 = 'x';
    const char INDEFINI = 'I';
    const char VIDE = ' ';
    int i, j;
    char joueur = SYMBOLE1;
    char gagnant = INDEFINI;
    int nbCoupsJoues = 0;

    // initialisation du plateau de jeu
    char grille[3][3];
    for(j=0; j<3; j++)
        for(i=0; i<3; i++)
            grille[j][i] = VIDE;

    do {
        // saisie des coordonnées
        printf("C'est au joueur %c de jouer\n", joueur);
        printf("Quelle colonne ? ");
        scanf(" %d", &i);
        i--;
        printf("Quelle ligne ? ");
        scanf(" %d", &j);
        j--;
        if(i<0 || i>=3 || j<0 || j>=3)
            printf("Mauvaises coordonnées, passez votre tour !\n");
        else {
            if(grille[j][i]!=VIDE) {
                printf("La case est occupée, passez votre tour !\n");
            } else {
                nbCoupsJoues++;
                grille[j][i] = joueur;
                // le joueur a-t-il gagné ?
                if(grille[j][0] == grille[j][1] && grille[j][0] == grille[j][2] ||
                    grille[0][i] == grille[1][i] && grille[0][i] == grille[2][i] ||
                    grille[0][0] == grille[1][1] && grille[0][0] == grille[2][2] && grille[0][0] == joueur ||
                    grille[0][2] == grille[1][1] && grille[0][2] == grille[2][0] && grille[0][2] == joueur) {
                    gagnant = joueur;
                }
                // changement de joueur
                if(joueur == SYMBOLE1)
                    joueur = SYMBOLE2;
                else
                    joueur = SYMBOLE1;
            }
        }
        //affichage du plateau de jeu
        for(j=0; j<3; j++) {
            for(i=0; i<3; i++)
                printf("%c%s", grille[j][i], i<2?"|":"");
            printf("\n%s", j<2?"-+-+-\n":"");
        }
    } while(gagnant == INDEFINI && nbCoupsJoues != 9);
    if(gagnant == INDEFINI)
        printf("Match nul !\n");
    else {
        printf("Le joueur %c a gagné !\n", gagnant);
    }
    return 0;
}