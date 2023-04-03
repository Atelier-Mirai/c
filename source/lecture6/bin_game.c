#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 3
#define PLAYER 1
#define COMPUTER 0

// プレーヤーの取ったビンの数
int player_get() {
  int get;
  do {
    printf("何本とりますか(1-3)\n");
    scanf("%d", &get);
    while (getchar() != '\n')
      ;
  } while (!(1 <= get && get <= MAX));
  return get;
}

// コンピュータの取ったビンの数
int computer_get(int bin) {
  if (bin <= 4) {
    return bin - 1;
  } else {
    srand(time(NULL));
    return rand() % 3 + 1;
  }
}

// ビンの表示
void disp_bin(int bin, int bin_max) {
  int i;
  for (i = 1; i <= bin; i++) {
    printf("■");
  }
  for (i = bin + 1; i <= bin_max; i++) {
    printf("□");
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  // 変数宣言
  int bin_max;
  int bin;
  int player_get_bin;
  int computer_get_bin;
  int turn;

  // ビンの総数
  srand(time(NULL));
  bin_max = rand() % 5 + 20;
  bin = bin_max;

  // オープニング
  printf("ビン取りゲーム\n");
  printf("交互に１〜３本のビンを取ります。\n");
  printf("最後の一本を取ると負けです\n");
  printf("ビンの本数: %d\n", bin);

  // 先攻後攻
  printf("先攻: 1 後攻: 0\n");
  scanf("%d", &turn);
  while (getchar() != '\n')
    ;
  if (turn == 1) {
    turn = PLAYER;
    printf("プレーヤーの先攻です\n");
  } else {
    turn = COMPUTER;
    printf("コンピュータの先攻です\n");
  }
  printf("ゲームスタート\n");

  // ビンを交互にとる
  do {
    if (turn == PLAYER) {
      printf("\nプレーヤーの番です\n");
      printf("%d 本のビンが残っています\n", bin);
      disp_bin(bin, bin_max);
      player_get_bin = player_get();
      printf("%d 本のビンを取りました。\n", player_get_bin);
      bin -= player_get_bin;
      turn = COMPUTER;
    } else {
      printf("\nコンピュータの番です\n");
      printf("%d 本のビンが残っています\n", bin);
      disp_bin(bin, bin_max);
      computer_get_bin = computer_get(bin);
      printf("%d 本のビンを取りました。\n", computer_get_bin);
      bin -= computer_get_bin;
      turn = PLAYER;
    }
  } while (bin > 0);

  // エンディング
  if (turn == PLAYER) {
    printf("\nプレーヤーの勝ちです\n");
  } else {
    printf("\nコンピュータの勝ちです\n");
  }
}
