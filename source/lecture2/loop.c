#include <stdio.h>

int main() {
  int i;
  for (i = 0; i < 3; i++) {
    printf("%d Hello\n", i);
  }

  i = 0;
  while (i < 3) {
    printf("%d Hello\n", i);
    i++;
  }

  i = 0;
  do {
    printf("%d Hello\n", i);
    i++;
  } while (i < 3);
}
