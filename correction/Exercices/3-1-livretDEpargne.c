#include<stdio.h>

int main() {
    const float TAUX = 0.03;
    float montant;
    int nbAnnees;
    printf("Montant initial ?\n");
    scanf(" %f", &montant);
    printf("Nombre d'années ?\n");
    scanf(" %d", &nbAnnees);
    for (int i = 1; i <= nbAnnees; i++) {
        montant *= (1+TAUX);
        printf("Année %d : %.2f\n", i, montant);
    }
    return 0;
}
