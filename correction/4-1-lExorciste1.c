#include<stdio.h>

int main() {
    const int PWD=1234;
    int saisie, nbEssai = 0;
    do {
        printf("codecarte bleu ?\n");
        scanf(" %d", &saisie);
        nbEssai++;
    } while(saisie!=PWD && nbEssai<3);
    if(saisie==PWD) {
        printf("Bon mot de passe\n");
    } else {
        printf("Carte confisquée\n");
    }
    return 0;
}