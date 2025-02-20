#include <stdio.h>

int main() {
    double P, r = 0.03;  
    int t;  

    printf("Entrez le capital initial (en euros) : ");
    scanf("%lf", &P);  

    printf("Entrez la durée de l'investissement en années : ");
    scanf("%d", &t);  
    
    for (int i = 0; i < t; i++) {
        
        P = P * (1 + r);  
        printf("%f \n",P);
    }

    printf("Le montant final après %d an(s) sera de : %.2f euros\n", t, P);

    return 0;
}
