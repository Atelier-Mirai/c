#include <stdio.h>

int main(int argc, char const *argv[]) {
  int vegetable;  // 野菜を食べた量
  int total = 0;  // 今まで食べた量の合計
  int ratio;      // 率
  int goal = 350; // 目標
  int i;          // 何回目の食事か？

  float a = 1.0;
  float b = 7.0;
  double x = 1.0;
  double y = 7.0;

  printf("%20.15f \n", a / b);
  printf("%20.15f \n", x / y);

  printf("野菜を一日３５０ｇ食べましょう\n");
  for (i = 0; i < 3; i++) {
    switch (i) {
    case 0:
      printf("朝ごはん");
      break;
    case 1:
      printf("昼ごはん");
      break;
    case 2:
      printf("夜ごはん");
      break;
    }

    printf("何グラム食べましたか？\n");
    scanf("%d", &vegetable);
    while (getchar() != '\n') {
      ; // 何もせず読み飛ばす
    }

    total = total + vegetable;
    ratio = 100 * total / goal;
    printf("達成率は %d %%  です\n", ratio);
    printf("残り %d グラムの野菜を食べましょう\n", goal - total);
  }

  if (total >= goal) {
    printf("\n健康な食生活です(*^_^*)\n");
  } else {
    printf("\nもう少し野菜を食べましょう(*^_^*)\n");
  }
}
