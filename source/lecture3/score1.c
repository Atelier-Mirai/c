#include <stdio.h>

int main(int argc, char const *argv[]) {
  int student[10] = {18, 25, 73, 30, 55, 18, 21, 89, 17, 31};
  //１０人の生徒の成績を格納する配列
  int top;       // 最高点
  int total = 0; // 合計点
  int average;   // 平均点
  int i;

  // 平均点を求める処理
  total = 0;
  for (i = 0; i < 10; i++) {
    // 合計点を求める
    total = total + student[i];
  }
  average = total / 10;
  printf("平均点は %d です\n", average);

  // 最高点を求める処理
  top = 0;
  for (i = 0; i < 10; i++) {
    if (top < student[i]) {
      top = student[i];
    }
  }
  printf("最高点は %d です\n", top);

  return 0;
}
