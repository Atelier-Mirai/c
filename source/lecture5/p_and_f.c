/*******************************************************
 * 関数とポインタ
 *******************************************************/
#include <stdio.h>
int num1, num2;

void swap(int x, int y) {
  int work;
  work = num1;
  num1 = num2;
  num2 = work;
  printf("swap num1  : %d\n", num1);
  printf("swap num2  : %d\n", num2);
}

int main(int argc, char const *argv[]) {
  int a, b;
  a = 3;
  b = 5;
  num1 = 3;
  num2 = 5;
  swap(a, b);
  printf("main num1  : %d\n", num1);
  printf("main num2  : %d\n", num2);

  return 0;
}
