/*******************************************************
 * 関数とポインタ
 *******************************************************/
#include <stdio.h>

void swap_failure(int x, int y) {
  printf("swap_failure &x : %p\n", &x);
  printf("swap_failure &y : %p\n", &y);
  int work;
  work = x;
  x = y;
  y = work;
  printf("swap_failure x  : %d\n", x);
  printf("swap_failure y  : %d\n", y);
}

void swap(int *x, int *y) {
  printf("swap x : %p\n", x);
  printf("swap y : %p\n", y);
  int work;
  work = *x;
  *x = *y;
  *y = work;
  printf("swap *x  : %d\n", *x);
  printf("swap *y  : %d\n", *y);
}

int main(int argc, char const *argv[]) {
  int a, b;
  a = 3;
  b = 5;
  puts("------------");
  printf("main &a : %p\n", &a);
  printf("main &b : %p\n", &b);
  puts("------------");
  swap(&a, &b);
  printf("main a  : %d\n", a);
  printf("main b  : %d\n", b);
  puts("------------");
  swap_failure(a, b);

  return 0;
}
