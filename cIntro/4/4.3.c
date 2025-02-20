/*int main() {
    char operateur = '/';
    int op1 = 5;
    int op2 = 0;
    int res;
    switch(operateur){
        
        case '/' :
            if(op2==0){
                goto erreurDiv;
            }
            res = op1 /op2; break;
        default :
            goto erreurOp;
    }
    printf(" %d %c %d = %d \n", op1, operateur, op2, res);
    return 0;
    erreurDiv:
        printf("la division par 0 est interdite\n");
    erreurOp:
        printf("Operateur inconnu\n");

}*/
int eurreurDiv(){
    printf("la division par 0 est interdite\n");
    return 0;
}
int erreurOp(){
    printf("Operateur inconnu\n");
    return 0;
}
int main() {
    char operateur = '/';
    int op1 = 5;
    int op2 = 0;
    int res;
    switch(operateur){
        
        case '/' :
            if(op2==0){
                eurreurDiv();
            }
            res = op1 /op2; break;
        default :
            erreurOp();
    }
    printf(" %d %c %d = %d \n", op1, operateur, op2, res);
    return 0;
}