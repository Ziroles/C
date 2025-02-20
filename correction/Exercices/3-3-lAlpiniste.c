#include<stdio.h>

int main() {
    int nbAltitudes;
    scanf(" %d", &nbAltitudes);
    int altitude1, altitude2, diff;
    int temps = 0;
    scanf(" %d", &altitude1);
    for(int i=0; i<nbAltitudes-1; i++) {
        scanf(" %d", &altitude2);
        diff = altitude2 - altitude1;
        if(diff>0)
            temps += 2*diff;
        else
            temps -= diff;
        altitude1 = altitude2;
    }
    printf("%d", temps);
    return 0;
}