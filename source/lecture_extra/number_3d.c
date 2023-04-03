#include <stdio.h>

void print_number(int num[5][3]) {
  int i, j;
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 3; j++) {
      if (num[i][j] == 1) {
        printf("■");
      } else {
        printf("□");
      }
    }
    printf("\n");
  }
}

int main(int argc, char const *argv[]) {

  int num0[5][3] = {{1, 1, 1}, {1, 0, 1}, {1, 0, 1}, {1, 0, 1}, {1, 1, 1}}, ;
  num1 = {{{1, 1, 1}, {1, 0, 1}, {1, 0, 1}, {1, 0, 1}, {1, 1, 1}}

  };
  print_number(num0);

  int **number[10]; // = { num0, num1, };
  number[0] = (int **)num0;
  print_number(number[0]);

  return 0;
}
