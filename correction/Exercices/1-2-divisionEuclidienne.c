#include <stdio.h>

int main()
{
    short dividende, diviseur;
    printf("Saisissez le dividende\n");
    scanf(" %hd", &dividende);
    printf("Saisissez le diviseur\n");
    scanf(" %hd", &diviseur);
    if (diviseur == 0)
    {
        printf("La division par zéro n'est pas définie\n");
    }
    else
    {
        printf("%hd / %hd = %hd\n", dividende, diviseur, dividende / diviseur);
        printf("%hd / %hd = %hd et reste %hd\n", dividende, diviseur, dividende / diviseur, dividende % diviseur);
    }
    return 0;
}