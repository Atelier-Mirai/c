#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  FILE *fp;           // ファイルポインタ
  char filename[256]; // ファイル名
  char c;
  int total = 0; // 行数

  // ファイル名入力
  printf("ファイル名を入力してください\n");
  gets(filename);

  // ファイルオープン
  if ((fp = fopen(filename, "r")) == NULL) {
    printf("file open error!");
    exit(1); // 異常終了
  }

  while ((c = fgetc(fp)) != EOF) {
    printf("%c", c);
    if (c == '\n') {
      total++;
    }
  }
  fclose(fp);

  printf("行数 %d\n", total);
}
