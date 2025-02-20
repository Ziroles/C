#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage : %s nom_fichier_valeur\n", argv[0]);
        return 1;
    }
    FILE* fd = fopen(argv[1], "r");
    int nbVal;
    fscanf(fd, " %d", &nbVal);
    int* valeurs = malloc(sizeof(int)*nbVal);
    for(int i=0; i<nbVal; i++) {
        fscanf(fd, " %d", &valeurs[i]);
    }
    int pos = 1;
    for(int i=0; i<10; i++) {
        printf("%d\n", pos);
        pos = valeurs[pos-1];
    }
    return 0;
}