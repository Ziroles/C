#include<stdio.h>

typedef enum {
    entreePlat = 1,
    platDessert,
    entreePlatDessert
} EFormule;

typedef enum {
    crudite = 1,
    pateEnCroute
} EEntree;

typedef enum {
    steak = 1,
    poisson
} EPlat;

typedef enum {
    gateau = 1,
    glace
} EDessert;

typedef enum {
    saignant = 1,
    aPoint,
    bienCuit
} ECuisson;

int main()
{
    EFormule formule;
    EEntree entree;
    EPlat plat;
    EDessert dessert;
    ECuisson cuisson;
    int saisie;
    do {
        printf("Quelle formule ?\n");
        printf("1 - Entrée - Plat\n");
        printf("2 - Plat - Dessert\n");
        printf("3 - Entrée - Plat - Dessert\n");
        scanf(" %d", &saisie);
    } while(saisie<1 || saisie>3);
    formule = saisie;

    if(formule!=platDessert) {
        do {
            printf("choix de l'entrée\n");
            printf("1 - Salade de crudités\n");
            printf("2 - Pâté en croute\n");
            scanf(" %d", &saisie);
        } while(saisie<1 || saisie>2);
        entree = saisie;
    }

    do {
        printf("choix du plat\n");
        printf("1 - Steak\n");
        printf("2 - Poisson\n");
        scanf(" %d", &saisie);
    } while(saisie<1 || saisie>2);
    plat = saisie;

    if(plat==steak) {
        do {
            printf("choix de la cuisson\n");
            printf("1 - Saignant\n");
            printf("2 - À point\n");
            printf("3 - Bien cuit\n");
            scanf(" %d", &saisie);
        } while(saisie<1 || saisie>3);
        cuisson = saisie;
    }

    if(formule!=entreePlat) {
        do {
            printf("choix du dessert\n");
            printf("1 - Gâteau\n");
            printf("2 - Glace\n");
            scanf(" %d", &saisie);
        } while(saisie<1 || saisie>2);
        dessert = saisie;
    }

    printf("Formule choisie : ");
    switch(formule) {
        case entreePlat: printf("Entrée - Plat\n"); break;
        case platDessert: printf("Plat - Dessert\n"); break;
        case entreePlatDessert: printf("Entrée - Plat - Dessert\n"); break;
    }

    if(formule != platDessert) {
        printf("Entrée : ");
        switch(entree) {
            case crudite : printf("Crudités\n"); break;
            case pateEnCroute : printf("Pâté en croute\n"); break;
        }
    }

    printf("Plat : ");
    switch(plat) {
        case steak : printf("Steak (cuisson : ");
            switch(cuisson) {
                case saignant : printf("saignant)\n"); break;
                case aPoint : printf("À point)\n"); break;
                case bienCuit : printf("Bien cuit)\n"); break;
            }
            break;
        case poisson : printf("Poisson\n"); break;
    }

    if(formule != entreePlat) {
        printf("Dessert : ");
        switch(dessert) {
            case gateau : printf("Gâteau\n"); break;
            case glace : printf("Glace\n"); break;
        }
    }

    return 0;
}