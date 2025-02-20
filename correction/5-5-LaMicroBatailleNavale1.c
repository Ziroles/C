#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    const int HAUTEUR = 4;
    const int LARGEUR = 4;
    const char PLOUF = '~';
    const char BATEAU = 'b';
    const char EAU = 'e';
    const char INCONNU = '?';
    int i, j;

    // initialisation du plateau de jeu
    char plateau[HAUTEUR][LARGEUR];
    for(j=0; j<HAUTEUR; j++)
        for(i=0; i<LARGEUR; i++)
            plateau[j][i] = EAU;
    // dépôt du bateau
    srand(time(NULL));
    plateau[rand()%HAUTEUR][rand()%LARGEUR] = BATEAU;

    do {
        //affichage du plateau de jeu
        for(j=0; j<HAUTEUR; j++) {
            for(i=0; i<LARGEUR; i++)
                printf("%c", plateau[j][i]==BATEAU||plateau[j][i]==EAU?INCONNU:plateau[j][i]);
            printf("\n");
        }
        // saisie des coordonnées de tir
        do {
            printf("Quelle colonne ? ");
            scanf(" %d", &i);
            i--;
            printf("Quelle ligne ? ");
            scanf(" %d", &j);
            j--;
        } while(i<0 || i>=LARGEUR || j<0 || j>=HAUTEUR);
        if(plateau[j][i]!=BATEAU) {
            plateau[j][i] = PLOUF;
            printf("Plouf !\n");
        }
    } while(plateau[j][i]!=BATEAU);
    printf("Touché coulé ! Bravo, vous avez gagné !\n");
    return 0;
}