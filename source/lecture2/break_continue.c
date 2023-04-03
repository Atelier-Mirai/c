#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  int player;
  int computer;
  int i;
  char c;

  while (1) {
    printf("グーチョキパーを入れてください\n");
    scanf("%d", &player);
    while (getchar() != '\n')
      ;

    while (1) {
      c = getchar();
      printf("c: %c\n", c);
      if (c == '\n') {
        break;
      }
    }

    while (getchar() != '\n') {
      ; // 読み飛ばす
    }

    while (getchar() != '\n')
      ;

    printf("player: %d\n", player);

    if (1 <= player && player <= 3) {
      printf("正しい入力です\n");
      break;
    }

    if (player < 1 || player > 3) {
      printf("もう一度、入力してください\n");
      continue;
    }
  }
  printf("while文を抜けました\n");
  return 0;

  for (i = 0; i < 3; i++) {
    srand(time(NULL));
    computer = rand() % 3 + 1;
    printf("コンピュータは %d: ", computer);

    if (computer == 1) {
      printf("グー");
    } else if (computer == 2) {
      printf("チョキ");
    } else {
      printf("パー");
    }
    printf("\n");
  }
  return 0;
}
