#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  FILE *fp; // ファイルポインタ

  // ファイルを開く
  fp = fopen("orginal.txt", "w");
  // エラーチェック
  if (fp == NULL) {
    printf("Can't write\n");
    exit(1); // プログラム強制終了
  }
  // ファイルへ書き出し
  fprintf(fp, "おはようございます\n");
  // ファイルクローズ
  fclose(fp);

  // ファイルを開く
  fp = fopen("orginal.txt", "w");
  // エラーチェック
  if (fp == NULL) {
    printf("Can't write\n");
    exit(1); // プログラム強制終了
  }
  // ファイルへ書き出し　（上書き）
  fprintf(fp, "こんにちは\n");
  // ファイルクローズ
  fclose(fp);

  // ファイルを開く
  fp = fopen("backup.txt", "w");
  // エラーチェック
  if (fp == NULL) {
    printf("Can't write\n");
    exit(1); // プログラム強制終了
  }
  // ファイルへ同一内容を書き出し
  // （ファイル名が別なので、結果として、名前を付けて保存）
  fprintf(fp, "おはようございます\n");
  // ファイルクローズ
  fclose(fp);

  return 0;
}
