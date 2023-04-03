#include <stdio.h>
#include <stdlib.h>

#define STRING_MAX 256 // 定数の宣言

int main(int argc, char const *argv[]) {
  FILE *fpr, *fpw;         // ファイルポインタ
  char buffer[STRING_MAX]; // 読み込み文字のバッファ
  int score[5];            // 読み込んだ点数を格納する配列
  int i;                   // 配列の添え字(index)
  int number;              // 数
  int total;               // 合計点
  double average;          // 平均点

  // ファイル名
  printf("score.txtファイルから得点を読み込みます。\n");

  // 読み込みファイルオープン
  if ((fpr = fopen("score.txt", "r")) == NULL) {
    printf("score.txt が見つかりませんでした。");
    exit(1);
  }

  // 得点ファイルからの読み込み処理
  i = 0;
  // 文字列配列bufferへ
  // 読み取り用のファイルポインタ fpr から
  // 文字列を取得します。
  while (fgets(buffer, STRING_MAX, fpr) != NULL) {
    number = atoi(buffer); // buffer に読み取った文字列を整数に変換
    score[i] = number;
    i++;
  }
  // 読み取り用ファイルを閉じます。
  fclose(fpr);

  // 読み込めているか、確認
  printf("score.txtからの読み込み結果\n");
  for (i = 0; i < 5; i++) {
    printf("score[%d]: %d\n", i, score[i]);
  }

  // 合計点・平均点の算出
  total = 0;
  for (i = 0; i < 5; i++) {
    total += score[i];
  }
  // キャスト演算子 (double) で
  // totalをdouble型に変換して、割り算を行います。
  average = (double)total / 5;

  // 書き込みファイルオープン
  if ((fpw = fopen("result.txt", "w")) == NULL) {
    printf("result.txt へ書き込めませんでした。");
    exit(1);
  }
  // 処理結果を、ファイルへ出力する
  printf("合計は %3d 点です。\n", total);
  printf("平均は %5.2f 点です。\n", average);
  printf("result.txtファイルへ結果を書き込みました。\n");
  fprintf(fpw, "合計は %3d 点です。\n", total);
  fprintf(fpw, "平均は %5.2f 点です。\n", average);

  fclose(fpw);
}
