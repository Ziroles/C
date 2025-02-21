#include <stdio.h>

int main()
{
    char item = "t";
    FILE *out = fopen("test.txt", "w");
    while (1)
    {
        printf(" Item à ajouter à la liste ?");
        scanf(" %c", &item);
        item = "t";
        if (item != "t")
        {
            fscanf(out, " %c", &item);
        }
    }

    // int fscanf(FILE * fichier, const char *chaine, ...);
}
