#include <fcntl.h> // ファイルの存在確認
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  FILE *fp; // ファイルポインタ
  char buffer[256];
  char filename[256];
  char c;

  ///////////////////////////////////////////////////////////
  // ファイル読み込み
  // （一文字ずつ読み込む例）
  //////////////////////////////////////////////////////////

  // ファイル名の設定
  strcpy(filename, "sample.txt");
  // 指定されたファイルを、読み取り専用モード("r")で開く
  if ((fp = fopen(filename, "r")) == NULL) {
    printf("指定されたファイル %s を開けませんでした。\n", filename);
    exit(1); // エラーコード1として、プログラム終了
  }

  // ファイルから一文字ずつ読み込む
  while ((c = fgetc(fp)) != EOF) {
    // 読み込んだ文字、c を画面に出力する
    printf("%c", c);
  }

  // ファイルを閉じる
  fclose(fp);

  ///////////////////////////////////////////////////////////
  // ファイル読み込み
  // （一行ずつ読み込む例）
  //////////////////////////////////////////////////////////

  // ファイル名の設定
  strcpy(filename, "sample.txt");
  // 指定されたファイルを、読み取り専用モード("r")で開く
  if ((fp = fopen(filename, "r")) == NULL) {
    printf("指定されたファイル %s を開けませんでした。\n", filename);
    exit(1); // エラーコード1として、プログラム終了
  }

  // ファイルから一行ずつ読み込む
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    // 読み込んだ文字「列」、buffer を画面に出力する
    printf("%s", buffer);
  }

  // ファイルを閉じる
  fclose(fp);

  ///////////////////////////////////////////////////////////
  // ファイル書き込み
  //////////////////////////////////////////////////////////

  // ファイル名の設定
  strcpy(filename, "sample.txt");
  // 指定されたファイルを、書き込みモード("w")で開く
  if ((fp = fopen(filename, "w")) == NULL) {
    printf("指定されたファイル %s を開けませんでした。\n", filename);
    exit(1); // エラーコード1として、プログラム終了
  }

  // 一文字ずつ書き出す
  fputc('a', fp); // 直接一文字出力
  fputc('b', fp);
  c = 'c'; // 変数に代入してから出力
  fputc(c, fp);
  c = '\n'; // 改行文字
  fputc(c, fp);

  // 一行ずつ書き出す
  fputs("123\n", fp);      // 直接一行出力
  char str[256] = "xyz\n"; // 変数に代入してから出力
  fputs(str, fp);

  // 書式指定
  double area = 5 * 5 * 3.14; // 円の面積
  // 書式設定して、画面に出力
  printf("円の面積は %5.2f です\n", area);
  // 書式設定して、ファイルに出力
  fprintf(fp, "円の面積は %5.2f です\n", area);
  // 書式設定して、文字列に出力
  sprintf(str, "円の面積は %5.2f です\n", area);
  printf("strの中身は %s です\n", str); // 確認

  // ファイルを閉じる
  fclose(fp);

  return 0;
}
