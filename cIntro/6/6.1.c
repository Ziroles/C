#include <stdio.h>
typedef enum {
    EntreePlat = 1,
    PlatDessert = 2,
    EntreePlatDessert =3
} TypePlat;
typedef enum {
    Salade = 1,
    PâtéEnCroute = 2,

} Entree;
typedef enum {
    Steak = 1,
    Poisson = 2
} Plat;
typedef enum {
    Gâteau = 1,
    Glace = 2
} Dessert;
int main(){
    
    TypePlat typePlat;
    printf("Quel type de menu voulez-vous? (1: EntreePlat, 2: PlatDessert, 3: EntreePlatDessert)\n");
    scanf("%d", &typePlat);
    if (typePlat == 1){
        printf("Quelle entrée voulez-vous? (1: Salade, 2: PâtéEnCroute)\n");
        Entree entree;
        scanf("%d", &entree);
        printf("Quel plat voulez-vous? (1: Steak, 2: Poisson)\n");
        Plat plat;
        scanf("%d", &plat);
    }
    if (typePlat == 2){
        printf("Quel plat voulez-vous? (1: Steak, 2: Poisson)\n");
        Plat plat;
        scanf("%d", &plat);
        printf("Quel dessert voulez-vous? (1: Gâteau, 2: Glace)\n");
        Dessert dessert;
        scanf("%d", &dessert);
    }
    if (typePlat == 3){
        printf("Quelle entrée voulez-vous? (1: Salade, 2: PâtéEnCroute)\n");
        Entree entree;
        scanf("%d", &entree);
        printf("Quel plat voulez-vous? (1: Steak, 2: Poisson)\n");
        Plat plat;
        scanf("%d", &plat);
        printf("Quel dessert voulez-vous? (1: Gâteau, 2: Glace)\n");
        Dessert dessert;
        scanf("%d", &dessert);
    }
}
