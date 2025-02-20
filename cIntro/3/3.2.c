#include <stdio.h>
#include <ctype.h>
#include <string.h>
int hasDigitBool(int hasDigit){
    return hasDigit;
};
int HasUpperLower(int hasUpper, int hasLower) {
    return hasUpper && hasLower;
};
int HasDigitAndUpperLower(int hasUpper, int hasLower,int hasDigit) {
    return hasDigitBool( hasDigit) && HasUpperLower(hasUpper, hasLower);
}
int HasAll(int hasUpper, int hasLower,int hasDigit, int hasSC) {
    return HasDigitAndUpperLower( hasUpper,  hasLower, hasDigit) && hasSC;
}
int main() {
    
    
    char str[1000];
    int hasUpper = 0;
    int hasLower = 0;
    int hasDigit = 0;
    int hasSC = 0;
    scanf("%s", &str);
    int i =0;
    
    for (i = 0; i < 1000; i++) {
        if (str[i] == '\0'){
            break;
        }
        if (isupper(str[i])) {  
            hasUpper = 1;  
            continue;    
        }
        if (islower(str[i])){
            hasLower = 1;
            continue;
        }
        if (isdigit(str[i])){
            hasDigit = 1;
            continue;
        }
        
        hasSC = 1;
         
        i++;  
    }
    if (i<5){
        printf("Mauvais");
    }else{
        switch(i){
            case 6:
                if(HasDigitAndUpperLower( hasUpper,  hasLower, hasDigit) || HasAll(hasUpper,  hasLower, hasDigit,hasSC)){
                    printf("Trop simple");
                }
            
            case 7:
                if (HasDigitAndUpperLower( hasUpper,  hasLower, hasDigit) || HasAll(hasUpper,  hasLower, hasDigit,hasSC) || HasUpperLower(hasUpper,  hasLower)){
                    printf("Trop simple");
                }else{
                    printf("Mauvais");
                }
            case 8:
                if (HasDigitAndUpperLower( hasUpper,  hasLower, hasDigit) || HasAll(hasUpper,  hasLower, hasDigit,hasSC) || HasUpperLower(hasUpper,  hasLower)){
                    printf("Trop simple");
                }else{
                    printf("Mauvais");
                }
        }
    }
    return 0;
}
