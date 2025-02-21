#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int TAILLE = -1;
const char PLOUF = '~';
const char BATEAU = 'b';
const char EAU = 'e';
const char INCONNU = '?';

char **initialiserPlateau()
{
    char **plateau = malloc(sizeof(char *) * TAILLE);
    for (int i = 0; i < TAILLE; i++)
    {
        plateau[i] = malloc(sizeof(char) * TAILLE);
        for (int j = 0; j < TAILLE; j++)
        {
            plateau[i][j] = EAU;
        }
    }
    srand(time(NULL));
    plateau[rand() % TAILLE][rand() % TAILLE] = BATEAU;
    return plateau;
}

void affichertableau(char **tableau)
{
    for (int i = 0; i < TAILLE; i++)
    {
        for (int j = 0; j < TAILLE; j++)
        {
            printf(" %c", tableau[i][j]);
        }
        printf(" \n");
    }
}
int saisirEntierEntreBornes(int min, int max)
{
    printf(" Entrer un valeur");
    int valeur = -1;
    scanf(" %d", &valeur);

    while (valeur > max || valeur < min)
    {
        printf("Valeur non valide merci d'en spécifier une autre");
        scanf(" %d", &valeur);
    }
    return valeur;
}

void tirer(char **plateau)
{
    int x = saisirEntierEntreBornes(0, TAILLE);
    int y = saisirEntierEntreBornes(0, TAILLE);
    printf(plateau[x][y] == BATEAU ? "TOUCHE" : "RATER");
}
int main()
{
    printf("Taille du plateau ? ");
    scanf(" %d", &TAILLE);
    char **plateau = initialiserPlateau();
    affichertableau(plateau);
    saisirEntierEntreBornes(0, 10);
    tirer(plateau);
}
