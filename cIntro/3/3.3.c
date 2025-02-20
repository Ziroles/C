#include <stdio.h>

int main() {
    int x;
    printf("Combien de nombres voulez-vous entrer? ");
    scanf("%d", &x);
    int res =0;
    if (x >= 100){
        printf("Trop de nombres");
        return 0;
    }

    int numbers[x];
    printf("Entrez %d nombres:\n", x);
    for (int i = 0; i < x; i++) {
        scanf(" %d", &numbers[i]);
    }

    for (int i = 0; i+1 < x; i++) {
        if(numbers[i] < numbers[i+1]){
            res = res + 2*(numbers[i+1]-numbers[i]);
        }else{
            res = res + (numbers[i]-numbers[i+1]);
        }
    }
    printf("\n %d", res);

    return 0;
}