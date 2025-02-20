#include <stdio.h>

int main(){
    int num1;
    int* num2;
    num2 = &num1;

    *num2 = 5;
    printf(" %p\n", num2);
    printf("%d\n", num1);


}