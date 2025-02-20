#include<stdio.h>

typedef struct {
    char car;
    int nb;
} SOcc;

int main() {
    char texte[2000];
    printf("entrez votre texte\n");
    scanf(" %[^\n]", texte);

    SOcc nbOcc[26];
    char nbCarDiff = 0;

    int pos=0;
    while(texte[pos]!='\0') {
        if(texte[pos] >= 'a' && texte[pos] <= 'z') {
            char i=0;
            while(i<nbCarDiff && nbOcc[i].car != texte[pos])
                i++;
            if(i==nbCarDiff) {
                nbOcc[i].car = texte[pos];
                nbOcc[i].nb = 1;
                nbCarDiff++;
            } else {
                nbOcc[i].nb++;
            }
        }
        pos++;
    }

    printf("%s ->", texte);
    for(int j=0; j<nbCarDiff; j++) {
        printf(" %c:%d", nbOcc[j].car, nbOcc[j].nb);
    }
    printf("\n");

    return 0;
}