#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    const char FIN = 'q';
    int nbval;

    FILE *fd = fopen(argv[1], "r");
    int nbVal;
    fscanf(fd, " %d", &nbVal);
    int *valeurs = (int *)malloc(sizeof(int) * nbVal);
    for (int i = 0; i < nbVal; i++)
    {
        fscanf(fd, " %d", &valeurs[i]);
    }
    int initialvalue = 0;
    for (int i = 0; i < nbVal; i++)
    {

        printf(" %d -> %d \n", initialvalue, valeurs[initialvalue]);
        printf(" %d", valeurs[i]);
        initialvalue = valeurs[initialvalue];
    }

    fclose(fd);
}