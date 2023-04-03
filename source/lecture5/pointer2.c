#include <stdio.h>

int main(int argc, char const *argv[]) {

  int a = 5;
  int b = 10;
  int *p; // intポインタ型 変数 p を宣言

  // p = &a;     // int型の変数aのアドレスを、pに代入
  *p = 100;

  printf("sizeof(int) %lu\n", sizeof(int));
  printf("sizeof(int*) %lu\n", sizeof(int *));
  printf("sizeof(char) %lu\n", sizeof(char));
  printf("sizeof(char*) %lu\n", sizeof(char *));

  printf("a の値は     %d\n", a);
  printf("a のアドレスは %p\n", &a);
  printf("a のアドレスは %08x\n", &a);

  printf("p の値　　　は %08x\n", p);
  printf("p の値　　　は %d\n", p);
  printf("p の指し示している先の値は %d\n", *p);

  *p = 100;
  printf("*p = 100;\n");
  printf("p の指し示している先の値は %d\n", *p);

  p = &b; // int型の変数bのアドレスを、pに代入
  *p = 100;
  printf("*p = 100;\n");
  printf("p の指し示している先の値は %d\n", *p);

  printf("a の値は     %d\n", a);
  printf("b の値は     %d\n", b);

  return 0;
}
