#include <stdio.h>
/*
int main() {
    int saisie;
    int PWD = 1234;
    for (int nbEssai=0;nbEssai<3;nbEssai++){
        printf("code carte bleu : ? ");
        scanf("%d", &saisie);
        if (saisie ==PWD){
            break;

        }
    }
    if (saisie == PWD){
        printf("Code correct\n");
    }else{
        printf("Carte bloquée\n");
    }
    return 0;
}
*/
int main() {
    int saisie;
    int PWD = 1234;
    for (int nbEssai=0;nbEssai<3;nbEssai++){
        printf("code carte bleu : ? ");
        scanf("%d", &saisie);
        if (saisie ==PWD){
            printf("Code correct\n");
            return 0;
        }
    }
    
   
    printf("Carte bloquée\n");
    
    return 0;
}