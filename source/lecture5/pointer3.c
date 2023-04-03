#include <stdio.h>
int main(int argc, char const *argv[]) {

  int number[4];
  number[0] = 10;
  number[1] = 20;
  number[2] = 30;
  number[3] = 40;
  puts("");
  printf("number   のアドレスは%p\n", number);
  printf("number[0]のアドレスは%p\n", &number[0]);
  printf("number[1]のアドレスは%p\n", &number[1]);
  printf("number[2]のアドレスは%p\n", &number[2]);
  printf("number[3]のアドレスは%p\n", &number[3]);

  int *p;
  // p = number;
  p = &number[0];
  puts("");
  printf("pの値は%p\n", p);
  printf("pの指し示す先の値 *pは%d\n", *p);

  p = 0x0022ff30;
  puts("");
  printf("pの値は%p\n", p);
  printf("pの指し示す先の値 *pは%d\n", *p);

  printf("p+0の指し示す先の値 *(p+0)は%d\n", *(p + 0));
  printf("p+1の指し示す先の値 *(p+1)は%d\n", *(p + 1));
  printf("p+2の指し示す先の値 *(p+2)は%d\n", *(p + 2));
  printf("p+3の指し示す先の値 *(p+3)は%d\n", *(p + 3));

  puts("");
  puts("for文でも書けます");
  int i;
  for (i = 0; i < 4; i++) {
    printf("p+%dの指し示す先の値 *(p+%d)は%d\n", i, i, *(p + i));
  }

  puts("");
  printf("p++する前のpの値 は%p\n", p);
  printf("pの指し示す先の値 *pは%d\n", *p);
  p++;
  printf("p++ した後のpの値 は%p\n", p);
  printf("pの指し示す先の値 *pは%d\n", *p);

  char string[4];
  string[0] = 'a';
  string[1] = 'b';
  string[2] = 'c';
  string[3] = 'd';

  puts("");
  printf("string   のアドレスは%p\n", string);
  printf("string[0]のアドレスは%p\n", &string[0]);
  printf("string[1]のアドレスは%p\n", &string[1]);
  printf("string[2]のアドレスは%p\n", &string[2]);
  printf("string[3]のアドレスは%p\n", &string[3]);

  float f[4] = {1.1, 2.2, 3.3, 4.4};
  puts("");
  printf("f   のアドレスは%p\n", f);
  printf("f[0]のアドレスは%p\n", &f[0]);
  printf("f[1]のアドレスは%p\n", &f[1]);
  printf("f[2]のアドレスは%p\n", &f[2]);
  printf("f[3]のアドレスは%p\n", &f[3]);

  double d[4] = {1.1, 2.2, 3.3, 4.4};
  puts("");
  printf("d   のアドレスは%p\n", d);
  printf("d[0]のアドレスは%p\n", &d[0]);
  printf("d[1]のアドレスは%p\n", &d[1]);
  printf("d[2]のアドレスは%p\n", &d[2]);
  printf("d[3]のアドレスは%p\n", &d[3]);

  return 0;
}
