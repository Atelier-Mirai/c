#include <stdio.h>

int main(int argc, char const *argv[]) {

  int a = 5;
  int *p; // intポインタ型 変数 p を宣言

  p = &a; // int型の変数aのアドレスを、pに代入
  printf("a の値は     %d\n", a);
  printf("a のアドレスは %p\n", &a);
  printf("a のアドレスは %08x\n", &a);
  printf("p の値　　　は %08x\n", p);
  printf("p の値　　　は %d\n", p);
  printf("p の指し示している先の値は %d\n", *p);

  *p = 100;
  printf("p の指し示している先の値は %d\n", *p);

  char c = 'a'; // 文字型の変数cを宣言　初期値を設定
  char *p;      // 文字ポインタ（指示）型の変数p を宣言
  p = &c;       // 変数cのアドレスを、pに代入
                // （p を 変数cの「ショートカット」として設定
  printf("c の値は     %c\n", c);
  printf("p の指し示している先の値は %c\n", *p);

  char str[] = "abcd"; // 文字型の配列strの宣言と、初期値
  p = &(str[0]);
  printf("str は %s\n", str);
  printf("str[0] は %c\n", str[0]);
  printf("p は %s\n", p);

  char *ch;
  ch = &str[0];
  printf("c は %c\n", *ch);

  return 0;
}
