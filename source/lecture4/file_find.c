/**************************************************************************
 * ファイル内に指定された文字列があるか、検索
 * 検索文字列が見つかった行番号を表示する
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 記号定数の定義
#define TRUE 1
#define FALSE 0
#define SIZE 1024

int main(int argc, char const *argv[]) {
  // 変数宣言
  FILE *fp;            // ファイルポインタ
  char filename[SIZE]; // ファイル名
  char keyword[128];   // 検索文字列
  char c;
  int keyword_length; // 検索文字列の長さ
  int i;              // 検索文字列中の走査位置
  int search;         // 検索文字列内を走査中かどうかのフラグ
  int count;          // 検索文字列の出現回数
  int line;           // 現在、検索中の行数
  int find_line[100] = {}; // 何行目に見つかったか
                           // = {} で全てを0に初期化出来る

  // 検索対象ファイル名と、検索文字列の取得
  printf("ファイル内に指定された文字列があるか、検索します。\n");
  printf("検索対象ファイル名を入力して下さい。\n");
  scanf("%s", filename);
  printf("検索文字列を入力して下さい。\n");
  scanf("%s", keyword);
  keyword_length = strlen(keyword);

  // 指定されたファイルを、読み取り専用モード("r")で開く
  if ((fp = fopen(filename, "r")) == NULL) {
    printf("指定されたファイル %s を開けませんでした。\n", filename);
    exit(1); // エラーコード1として、プログラム終了
  }

  // 初期化処理
  search = 1; // 検索中フラグ
  i = 0;      // 検索文字列中の走査位置
  count = 0;  // 検索文字列の出現回数
  line = 1;   // 現在、検索中の行数

  // ファイル読み込み
  while ((c = fgetc(fp)) != EOF) {
    // 現在の行数の把握
    if (c == '\n') {
      line++;
    }
  }
  printf("lineは%d行でした", line);

  // 検索処理
  if (search == 0) { // 検索文字列内を走査中の場合
    if (search) {    // 検索文字列内を走査中の場合
      if (c == keyword[i]) {
        // ファイルから読み取った文字 c と
        // 検索文字列の i 番目の文字が一致した。
        i++;
      } else {
        // 検索文字列に一致しない文字が現れた
        search = FALSE;
        i = 0;
      }
    } else {                 // 走査中でない場合
      if (c == keyword[0]) { // キーワードの先頭文字
        search = TRUE;       // 文字列の走査モードに入る
        i++;
      }
    }

    // 検索文字列と全て一致した場合
    if (i == keyword_length) {
      find_line[count] = line; // 出現した行番号を格納
      count++;                 // 検索文字列の出現回数
      i = 0;                   // 検索文字列中の走査位置
      search = FALSE;
    }
  }

  fclose(fp); // ファイルを閉じる

  // 検索結果の表示
  printf("指定ファイル %s 内で\n", filename);
  printf("検索文字列   %s を検索しました。\n", keyword);
  printf("\n");
  printf("%d 回、検索文字列が出現しました。\n", count);
  printf("出現した行番号は、次のとおりです。\n");
  // for 文の継続条件に着目して下さい
  for (i = 0; find_line[i] != 0; i++) {
    printf("%3d ", find_line[i]);
  }
  printf("\n");

  return 0;
}
