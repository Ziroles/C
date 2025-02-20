#include<stdio.h>
int main() {
  int e = 72;
  printf("%d\n", e != 72);
  printf("%d\n", e && 72);
  printf("%d\n", !e || 0 && e);
  printf("%d\n", e & 123);
  printf("%d\n", -~e | 23);
  printf("%d\n", e ^ 23);
  printf("%d\n", e<<2);
  printf("%d\n", e>>2);
  return 0;
}
