#include<stdio.h>
//Que fait-il ?
int main() {
  int op1, op2, res;
  char operateur;
  printf("saisissez l'opération'\n");
  scanf(" %d %c %d", &op1, &operateur, &op2);
  switch(operateur) {
    case '/':
    if(op2!=0)
      res = op1 / op2;
    else {
      printf("La division par zéro n'est pas définie !\n");
      return 2;
    }
    break;
    case '%':
    if(op2!=0)
      res = op1 % op2;
    else {
      printf("La division par zéro n'est pas définie !\n");
      return 2;
    }
    break;
    case '*':
      res = op1 * op2; break;
    case '+':
      res = op1 + op2; break;
    case '-':
      res = op1 - op2; break;
    default :
      printf("opérateur inconnu\n");
  }
  printf("%d %c %d = %d\n", op1, operateur, op2, res);
  return 0;
}
