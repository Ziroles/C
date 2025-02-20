#include <stdio.h>

int main()
{
    const int ENTER = 10;
    const int TAILLE = 30;
    char mot[TAILLE];
    int nbCar = 0;
    char palin = 1;
    int i;
    printf("Entrez le mot à tester\n");
    do {
        mot[nbCar] = getchar();
        if(mot[nbCar] != ENTER && mot[nbCar] >= 'a' && mot[nbCar] <= 'z') {
            nbCar++;
        }
    } while(mot[nbCar] != ENTER);
    i=0;
    mot[nbCar]= '\0';
    while (palin && i<nbCar/2) {
        palin = mot[i] == mot[nbCar - 1 - i];
        i++;
    }
    printf("le mot %s %s un palindrome\n", mot, palin?"est":"n'est pas");
    return 0;
}