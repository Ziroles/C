#include <stdio.h>


double max(double a, double b) {
    return (a > b) ? a : b;
}


int compare(double a, double b) {
    if (a == b) {
        return 0;
    } else if (a > b) {
        return 1;
    } else {
        return -1;
    }
}

int main() {
    double val1, val2;
    int result;

   
    printf("Entrez la première valeur : ");
    scanf("%lf", &val1);
    printf("Entrez la deuxième valeur : ");
    scanf("%lf", &val2);

    
    double maxValue = max(val1, val2);
    result = compare(val1, val2);

   
    printf("La plus grande valeur est : %.2f\n", maxValue);

    if (result == 0) {
        printf("Les deux valeurs sont égales.\n");
    } else if (result == 1) {
        printf("La première valeur est la plus grande.\n");
    } else {
        printf("La deuxième valeur est la plus grande.\n");
    }

    return 0;
}
