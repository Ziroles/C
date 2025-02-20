#include<stdio.h>
//Que fait-il ?
int main() {
  int op1, op2, res;
  char operateur;
  printf("saisissez le premier operande\n");
  scanf(" %d", &op1);
  printf("saisissez l'operateur (* ou /)\n");
  scanf(" %c", &operateur);
  printf("saisissez le second operande\n");
  scanf(" %d", &op2);
  if(operateur=='/') {
    if(op2!=0)
      res = op1 / op2;
    else {
      printf("La division par zéro n'est pas définie !\n");
      return 2;
    }
  } else
    res = op1 * op2;
  printf("%d %c %d = %d\n", op1, operateur, op2, res);
  return 0;
}
