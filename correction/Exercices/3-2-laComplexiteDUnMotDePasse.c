#include <stdio.h>
#define ENTER 10

int main()
{
    char chiffres = 0;
    char minuscules = 0;
    char majuscules = 0;
    char speciaux = 0;
    printf("Entrez le mot de passe à tester\n");
    char c = getchar();
    while(c != ENTER) {
        if(c >= '0' && c <= '9')
            chiffres++;
        else if(c >= 'a' && c <= 'z')
            minuscules++;
        else if(c >= 'A' && c <= 'Z')
            majuscules++;
        else
            speciaux++;
        c = getchar();
    }
    char taille = chiffres + minuscules + majuscules + speciaux;
    printf("il y a %d caractères dont\n - %d chiffre%s\n - %d minuscule%s\n - %d majuscule%s\n - %d caractère%s\nQualité du mot de passe : ",
        taille,
        chiffres, chiffres>1?"s":"",
        minuscules, minuscules>1?"s":"",
        majuscules, majuscules>1?"s":"",
        speciaux, speciaux>1?"s spéciaux": " spécial"
        );
    char chiffresUniquement = chiffres == taille;
    char minusculesOuMajuscules = minuscules && !majuscules || !minuscules && majuscules;
    char minusculesEtMajuscules = minuscules && majuscules && !chiffres;
    char minusculesEtMajusculesEtChiffre = minuscules && majuscules && chiffres && !speciaux;
    if(taille <= 5 || (taille<=10 && chiffresUniquement) || (taille<=7 && minusculesOuMajuscules) || (taille <=6 && minusculesEtMajuscules))
        printf("mauvais\n");
    else if(taille <= 8 || chiffresUniquement || (taille<=10 && minusculesOuMajuscules) || (taille<=9 && minusculesEtMajuscules))
        printf("trop simple\n");
    else if(taille <= 10 || (taille <= 13 && minusculesOuMajuscules) || (taille <= 11 && minusculesEtMajuscules))
        printf("simple\n");
    else if(taille <= 12 || minusculesOuMajuscules || minusculesEtMajuscules || (taille <= 13 && minusculesEtMajusculesEtChiffre))
        printf("bon\n");
    else
        printf("très bon\n");
    return 0;
}