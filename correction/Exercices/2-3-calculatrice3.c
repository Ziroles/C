#include<stdio.h>
//Que fait-il ?
int main() {
  int op1, op2, res;
  char operateur;
  printf("saisissez l'opération'\n");
  scanf(" %d %c %d", &op1, &operateur, &op2);
  if(operateur=='+')
    res = op1 + op2;
  else if(operateur=='-')
    res = op1 - op2;
  else {
    printf("opérateur non accepté\n");
    return 2;
  }
  printf("%d %c %d = %d\n", op1, operateur, op2, res);
  return 0;
}
