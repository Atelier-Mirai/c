#include <math.h>
#include <stdio.h>

typedef struct {
  int a;
  int b;
  int c;
  double area;
} triangle;

int main(int argc, char const *argv[]) {
  triangle t1;

  printf("辺Aの長さを入れてください。\n");
  scanf("%d", &t1.a);
  while (getchar() != '\n')
    ;
  printf("辺Bの長さを入れてください。\n");
  scanf("%d", &t1.b);
  while (getchar() != '\n')
    ;
  printf("辺Cの長さを入れてください。\n");
  scanf("%d", &t1.c);
  while (getchar() != '\n')
    ;

  // ヘロンの公式 Triangle by Heron's formula
  double S, s, a, b, c;
  a = t1.a;
  b = t1.b;
  c = t1.c;
  s = (a + b + c) / 2;
  S = sqrt(s * (s - a) * (s - b) * (s - c));
  t1.area = S;
  printf("面積は %5.1f です\n", t1.area);

  return 0;
}
