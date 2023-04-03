#include <stdio.h>
int main(int argc, char const *argv[]) {

  char str[5] = "test";
  char *p;

  puts("");
  printf("str   のアドレスは%p\n", str);
  printf("str           は%s\n", str);
  printf("str[0]のアドレスは%p\n", &str[0]);
  printf("str[1]のアドレスは%p\n", &str[1]);
  printf("str[2]のアドレスは%p\n", &str[2]);
  printf("str[3]のアドレスは%p\n", &str[3]);
  printf("str[4]のアドレスは%p\n", &str[4]);

  puts("");
  p = str;
  printf("p   の値は%p\n", p);
  printf("p   の指し示す先の値は %c\n", *p);
  printf("p+1 の指し示す先の値は %c\n", *(p + 1));
  printf("p+2 の指し示す先の値は %c\n", *(p + 2));
  printf("p+3 の指し示す先の値は %c\n", *(p + 3));
  printf("p+4 の指し示す先の値は %c\n", *(p + 4));

  puts("");
  // p = &str[0];
  printf("str   の指し示す先の値は %c\n", *str);
  printf("str+1 の指し示す先の値は %c\n", *(str + 1));
  printf("str+2 の指し示す先の値は %c\n", *(str + 2));
  printf("str+3 の指し示す先の値は %c\n", *(str + 3));
  printf("str+4 の指し示す先の値は %c\n", *(str + 4));

  char name[5] = "taro";
  printf("name   のアドレスは%p\n", name);
  p = name;
  printf("p   の値は%p\n", p);
  printf("p   の指し示す先の値は %c\n", *p);
  printf("p+1 の指し示す先の値は %c\n", *(p + 1));
  printf("p+2 の指し示す先の値は %c\n", *(p + 2));
  printf("p+3 の指し示す先の値は %c\n", *(p + 3));
  printf("p+4 の指し示す先の値は %c\n", *(p + 4));

  puts("");
  printf("str           は%s\n", str);

  return 0;
}
