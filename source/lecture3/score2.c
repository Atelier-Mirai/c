#include <stdio.h>

int main(int argc, char const *argv[]) {
  //１０人の生徒の成績を格納する配列
  int student[4][10] = {{14, 15, 92, 65, 35, 89, 79, 32, 38, 46}, // 国語
                        {26, 43, 38, 32, 79, 50, 28, 84, 19, 71}, // 算数
                        {69, 39, 93, 75, 10, 58, 20, 97, 49, 44}, // 理科
                        {59, 23, 07, 81, 64, 06, 28, 62, 8, 99}}; // 社会
  int top;                                                        // 最高点
  int total;                                                      // 合計点
  int average;                                                    // 最低点
  int subject;                                                    // 科目
  int i; // 添字 index

  // 平均点を求める処理
  for (subject = 0; subject < 4; subject++) {
    total = 0;
    for (i = 0; i < 10; i++) {
      // 合計点を求める
      total = total + student[subject][i];
    }
    average = total / 10;
    printf("平均点は %d です\n", average);
  }

  // 最高点を求める処理
  for (subject = 0; subject < 4; subject++) {
    top = 0;
    for (i = 0; i < 10; i++) {
      if (top < student[subject][i]) {
        top = student[subject][i];
      }
    }
    printf("最高点は %d です\n", top);
  }

  return 0;
}
