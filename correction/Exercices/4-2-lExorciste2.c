#include<stdio.h>

int main() {
    int beuzeu = 7;
    for(int i=1; i<100; i++) {
        if(i%beuzeu==0 || i%10==7 || i/10==7)
            printf("Beuzeu\n");
        else
            printf("%d\n", i);
    }
    return 0;
}