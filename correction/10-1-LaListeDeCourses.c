#include <stdio.h>

int main() {
    const char FIN = 'q';
    char saisie[100];
    printf("Entrer un élément à ajouter à la liste de course\n", FIN);
    scanf(" %[^\n]", saisie);
    FILE* liste = fopen("liste", "w");
    while(saisie[0]!=FIN || saisie[1]!='\0') {
        fprintf(liste, " - %s\n", saisie);
        printf("Entrer un élément à ajouter à la liste de course ou %c pour quitter\n", FIN);
        scanf(" %[^\n]", saisie);
    }
    fclose(liste);
}