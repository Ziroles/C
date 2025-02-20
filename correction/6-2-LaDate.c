#include<stdio.h>

typedef enum {
    janvier = 1,
    fevrier,
    mars,
    avril,
    mai,
    juin,
    juillet,
    aout,
    septembre,
    octobre,
    novembre,
    decembre
} EMois;

typedef struct {
    char jour;
    short annee;
    EMois mois;
} SDate;


int main()
{
    SDate date;
    printf("Entrez une date sous la forme jj/mm/aaaa\n", sizeof(SDate));
    scanf(" %hhd / %d / %hd", &(date.jour), &(date.mois), &(date.annee));

    char bissextille = !(date.annee%4) && date.annee%100 || !(date.annee%400);
    printf("L'année %hd %s bissextille\n", date.annee, bissextille?"est":"n'est pas");

    char correcte = date.jour>=1;
    if(correcte) {
        switch(date.mois) {
            case avril :
            case juin :
            case septembre :
            case novembre :
                correcte = date.jour<=30; break;
            case fevrier : 
                correcte = bissextille && date.jour <=29 || !bissextille && date.jour <= 28; break;
            default :
                correcte = date.jour <= 31; break;
        }
    }
    printf("La date %s correcte\n", correcte?"est":"n'est pas");
    if(!correcte)
        return 1;

    printf("jour : %hhd\n", date.jour);
    printf("mois : ");
    switch(date.mois) {
        case janvier : printf("Janvier\n"); break;
        case fevrier : printf("Février\n"); break;
        case mars : printf("Mars\n"); break;
        case avril : printf("Avril\n"); break;
        case mai : printf("Mai\n"); break;
        case juin : printf("Juin\n"); break;
        case juillet : printf("Juillet\n"); break;
        case aout : printf("Août\n"); break;
        case septembre : printf("Septembre\n"); break;
        case octobre : printf("Octobre\n"); break;
        case novembre : printf("Novembre\n"); break;
        case decembre : printf("Décembre\n"); break;
    }
    printf("année : %hd\n", date.annee);
    
    int numJour=date.jour;
    switch(date.mois) {
        case decembre : numJour+=30;
        case novembre : numJour+=31;
        case octobre : numJour+=30;
        case septembre : numJour+=31;
        case aout : numJour+=31;
        case juillet : numJour+=30;
        case juin : numJour+=31;
        case mai : numJour+=30;
        case avril : numJour+=31;
        case mars : numJour += bissextille?29:28;
        case fevrier : numJour+=31;
    }
    printf("C'est le %d%s jour de l'année\n", numJour, numJour==1?"er":"ème");
    return 0;
}