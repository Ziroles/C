#include <stdio.h>
/*
int main() {
    int beuzeu = 7;
    for (int i = 0; i < 100; i++) {
       if(i%beuzeu == 0 || i%10 == beuzeu || i/10 == 7){
           printf("Beuzeu\n");
           continue;
       }
       printf("%d\n", i);
    }
    
    return 0;
}
*/

int main() {
    int beuzeu = 7;
    for (int i = 0; i < 100; i++) {
       if(i%beuzeu == 0 || i%10 == beuzeu || i/10 == 7){
           printf("Beuzeu\n");
           
       }else{
            printf("%d\n", i);
       }
       
    }
    
    return 0;
}