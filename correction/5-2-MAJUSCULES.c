#include<stdio.h>

int main() {
    const int MAX = 100;
    char saisie[MAX];
    printf("Saisisser un texte de maximum %d caractères\n", MAX);
    scanf(" %[^\n]", saisie);
    int i=0;

    while(saisie[i]!='\0') {
        if(saisie[i]>='a' && saisie[i]<='z')
            saisie[i]+='A'-'a';
        i++;
    }
    printf("Tout en majuscules : %s\n", saisie);

    char maj=1;
    i=0;
    while(saisie[i]!='\0') {
        if(maj && saisie[i]>='a' && saisie[i]<='z')
            saisie[i]+='A'-'a';
        if(!maj && saisie[i]>='A' && saisie[i]<='Z')
            saisie[i]+='a'-'A';
        maj = saisie[i]==' ' || saisie[i]=='\t' || saisie[i]==',' || saisie[i]=='.' || saisie[i]=='!' || saisie[i]=='?';
        i++;
    }
    printf("Majuscules en début de mot : %s\n", saisie);
    return 0;
}