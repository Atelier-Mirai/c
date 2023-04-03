#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_MAX_LENGTH 256 // 定数

int main(int argc, char const *argv[]) {
  FILE *fp;                        // ファイルポインタ
  char filename[256];              // ファイル名
  char buffer[256];                // 入力文字列保管用のバッファ
  int total = 0;                   // 入力文字数
  int str_max = STRING_MAX_LENGTH; // 入力最大文字数

  // ファイル名入力
  printf("ファイル名を入力してください\n");
  gets(filename);

  // ファイルオープン
  if ((fp = fopen(filename, "r")) == NULL) {
    printf("file open error!");
    exit(1); // 異常終了
  }

  // 文字数カウント
  while (fgets(buffer, str_max, fp) != NULL) {
    total += strlen(buffer);
  }
  fclose(fp);
  printf("文字数 %d \n", total);
}
