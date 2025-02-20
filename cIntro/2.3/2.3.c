#include<stdio.h>
//Que fait-il?
int main() {
    int num1, num2;
    char ch;

    
    printf("saisissez le premier operande\n");
    scanf("%d %c %d", &num1, &ch, &num2);
    

    switch(ch){
        case '+' :
            printf(" %d %c %d = %d \n", num1, ch, num2, num1 + num2);
            break;
        case '-' :
            printf(" %d %c %d = %d \n", num1, ch, num2, num1 - num2);
            break;
        case '/' :
            printf(" %d %c %d = %f \n", num1, ch, num2, num1 / num2);
            break;
        case '*' :
            printf(" %d %c %d = %d \n", num1, ch, num2, num1 * num2);
            break;
        case '%' :
            printf(" %d %c %d = %d reste = %d\n", num1, ch, num2, num1 / num2, num1 % num2);
            break;

    }
    return 0;
}