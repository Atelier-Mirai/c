/*******************************************************
 * 関数とポインタ
 *******************************************************/
#include <stdio.h>

void half(int *num) {
  printf("half &num[0]: %p\n", &num[0]);
  printf("half &num[1]: %p\n", &num[1]);
  printf("half &num[2]: %p\n", &num[2]);
  num[0] /= 2;
  num[1] /= 2;
  num[2] /= 2;
}

int main(int argc, char const *argv[]) {
  int num[3] = {10, 20, 30};
  printf("main &num[0]: %p\n", &num[0]);
  printf("main &num[1]: %p\n", &num[1]);
  printf("main &num[2]: %p\n", &num[2]);
  half(num);
  half(&num[0]);

  printf("%d\n", num[0]);
  printf("%d\n", num[1]);
  printf("%d\n", num[2]);
}
