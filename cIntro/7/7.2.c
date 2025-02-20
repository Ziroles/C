#include <stdio.h>
int main(){
    const int* tableau[10];
    const char* tableauChar[10];
    const float* tableauFloat[10];
    const double* tableauDouble[10];
    const short* tableauShort[10];
    const long* tableauLong[10];
    while (1){
        for (int i = 0; i < 10; i++){
           printf("%p\n", &tableau[i]);
              printf("%p\n", &tableauChar[i]);
                printf("%p\n", &tableauFloat[i]);
                    printf("%p\n", &tableauDouble[i]);
                        printf("%p\n", &tableauShort[i]);
                        printf("%p\n", &tableauLong[i]);
                        printf("\n___________________________________________\n");
        }
        return 0;
    }
}