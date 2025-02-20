#include <stdio.h>

int main()
{
    long tab[97];
    int nbVal;
	printf("nombre de valeurs ?\n");
    scanf(" %d", &nbVal);
    nbVal -= 3;
    int v1, v2, v3, v4;
	printf("Saisissez les valeurs\n");
    scanf(" %d %d %d", &v1, &v2, &v3);
    for(int i=0; i<nbVal; i++) {
        scanf(" %d", &v4);
        tab[i] = v1 * 1000000000L + v2 * 1000000 + v3 * 1000 + v4;
        v1 = v2;
        v2 = v3;
        v3 = v4;
    }
    int max=0;
    for(int i=0; i<nbVal; i++) {
        int nbOcc = 1;
        for(int j=i+1; j<nbVal; j++) {
            if(tab[j] == tab[i]) {
                nbOcc++;
            }
        }
        if(nbOcc > max) {
            max = nbOcc;
        }
    }
    printf("Il y a au maximum une serie de %d blocs successifs\n", max);
    return 0;
}