#include <stdio.h>

int main()
{
    char tab[10][40];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            tab[i][j] = ' ';
        }
    }
    int choice;
    char color = '&';
    scanf(" Que voulez vous faire ? \n 1 - Dessiner un caractère \n 2- Dessiner un rectancte avec un ensemble de caractère \n 3- Changer la couleur ", &choice);
    char c;
    int x, y;
    int x1, y1, x2, y2;
    switch (choice)
    {
    case 1:

        scanf("Entrez la position x : ", &x);
        scanf("Entrez la position y : ", &y);
        scanf("Entrez le caractère : ", &c);
        tab[x][y] = c;
        break;
    case 2:

        scanf("Entrez la position x1 : ", &x1);
        scanf("Entrez la position y1 : ", &y1);
        scanf("Entrez la position x2 : ", &x2);
        scanf("Entrez la position y2 : ", &y2);
        scanf("Entrez le caractère : ", &c);
        for (int i = x1; i < x2; i++)
        {
            for (int j = y1; j < y2; j++)
            {
                tab[i][j] = c;
            }
        }
        break;
    case 3:
        scanf("Entrez la couleur : ", &color);
        break;
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            printf("%c", tab[i][j]);
        }
        printf("\n");
    }
}