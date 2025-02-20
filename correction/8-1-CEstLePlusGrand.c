#include "8-1-Fonctions.h"
#include <stdio.h>

int main() {
    float val1, val2;
    printf("Saisissez deux valeurs réelles\n");
    scanf(" %f %f", &val1, &val2);
    float maxi = max(val1, val2);
    printf("la plus grande valeur est %f\n", maxi);
    return 0;
}