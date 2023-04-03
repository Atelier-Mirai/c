#include <stdio.h>
int main(int argc, char const *argv[]) {
  char str[5] = "test";
  char *p;
  p = str;
  printf("p   の値は%p\n", p);
  printf("p   の指し示す先の値は %c\n", *p);
  printf("p+1 の指し示す先の値は %c\n", *(p + 1));

  printf("str   の指し示す先の値は %c\n", *str);
  printf("str+1 の指し示す先の値は %c\n", *(str + 1));

  char name[5] = "taro";
  printf("name   のアドレスは%p\n", name);
  p = name;
  printf("p   の値は%p\n", p);
  printf("p   の指し示す先の値は %c\n", *p);
  printf("p+1 の指し示す先の値は %c\n", *(p + 1));

  str = name;
  printf("str   の値は%p\n", p);
  printf("str   の指し示す先の値は %c\n", *str);
  printf("str+1 の指し示す先の値は %c\n", *(str + 1));

  return 0;
}
