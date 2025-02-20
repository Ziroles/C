#include <stdio.h>
enum mois {
    janvier = 1,
    fevrier = 2,
    mars = 3,
    avril = 4,
    mai = 5,
    juin = 6,
    juillet = 7,
    aout = 8,
    septembre = 9,
    octobre = 10,
    novembre = 11,
    decembre = 12
};
struct date {
    int jour;
    enum mois mois;
    int annee; 
};
int main(){
    struct date Mydate;
    printf("Entrez une date (jj/mm/aaaa): ");
    scanf("%d/%d/%d", &Mydate.jour, &Mydate.mois, &Mydate.annee);
    printf("La date est: %d/%d/%d\n", Mydate.jour, Mydate.mois, Mydate.annee);
    return 0;
}