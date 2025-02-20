#include<stdio.h>
int main () {
    int dividende;
    int diviseur;
    printf ("\tSaisissez le dividende\n") ;
    scanf(" %d", &dividende);
    printf ("\tSaisissez le diviseur\n") ;
    scanf(" %d", &diviseur);
    printf("Dividende %d / diviseur %d = %d (quotient)\n", dividende, diviseur, dividende / diviseur);
    printf("Le reste de la division est : %d\n", dividende % diviseur);


}