#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  FILE *fp;           // ファイルポインタ
  char filename[256]; // ファイル名

  // ファイル名
  printf("出力ファイル名を入力してください\n");
  gets(filename);

  // ファイルオープン
  if ((fp = fopen(filename, "w")) == NULL) {
    printf("file open error!");
    exit(1);
  }

  // ファイル出力

  // 一文字ずつ書き出し
  char c;
  c = 'a';
  fputc(c, fp);
  c = '\n'; // 改行文字
  fputc(c, fp);

  // 文字列を書き出し
  char str[256] = "xyz\n";
  fputs(str, fp);

  double area; // 面積
  area = 5 * 5 * 3.14;
  // 書式設定して、画面に出力
  printf("円の面積は %5.2f です\n", area);
  // 書式設定して、ファイルに出力
  fprintf(fp, "円の面積は %5.2f です\n", area);
  // 書式設定して、文字列に出力
  sprintf(str, "円の面積は %5.2f です\n", area);
  printf("strの中身は%s\n", str); // 確認

  fclose(fp);
}
