#include <stdio.h>

int main(int argc, char const *argv[]) {

  int a;
  int b;
  int w;

  a = 3;
  b = 5;
  w = ++b % a;
  printf("a %d\n", w);
  a = 3;
  b = 5;
  w = --b % a;
  printf("i %d\n", w);
  a = 3;
  b = 5;
  w = b++ % a;
  printf("u %d\n", w);
  a = 3;
  b = 5;
  w = b-- % a;
  printf("e %d\n", w);

  printf("---(24)---\n");
  a = 2;
  b = 4;
  w = (b--) % (a--);
  printf("a %d\n", w);
  a = 2;
  b = 4;
  w = (b--) / (a--);
  printf("i %d\n", w);
  a = 2;
  b = 4;
  w = (++b) % (a++);
  printf("u %d\n", w);
  a = 2;
  b = 4;
  w = (++b) / (a++);
  printf("e %d\n", w);

  printf("---(25)---\n");
  a = 3;
  b = 4;
  w = (++a) == b;
  printf("a %d\n", w);
  a = 3;
  b = 4;
  w = a = (b -= 2);
  printf("i %d\n", w);
  a = 3;
  b = 4;
  w = a >= (b -= 2);
  printf("u %d\n", w);
  a = 3;
  b = 4;
  w = (a + 1) < b;
  printf("e %d\n", w);

  printf("---(26)---\n");
  a = 4;
  b = 3;
  w = !(a - ++b);
  printf("a %d\n", w);
  a = 4;
  b = 3;
  w = !(a / b);
  printf("i %d\n", w);
  a = 4;
  b = 3;
  w = !(a % b);
  printf("u %d\n", w);
  a = 4;
  b = 3;
  w = !(--a / b--);
  printf("e %d\n", w);

  return 0;
}
