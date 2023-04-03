/**************************************************************************
 * 文字列の置換
 * (mononokehime -> kaguyahime)
 **************************************************************************/
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  // 変数宣言
  char princess[20] = "kaguyahime"; // 検索対象文字列
  int i;                            // 検索対象文字列用のindex変数
  int length = strlen(princess);    // 検索対象文字列の長さ
  printf("置換前の姫の名は %s です。\n", princess);

  int match; // 何文字まで検索文字列と一致しているか？
  char keyword[10] = "kaguya";          // 検索文字列
  int k;                                // 検索文字列用のindex変数
  int keyword_length = strlen(keyword); // 検索文字列の長さ

  char replace_keyword[10] = "mononoke"; // 置換文字列
  int r;                                 // 置換文字列用のindex変数
  int replace_keyword_length = strlen(replace_keyword); // 置換文字列の長さ

  // 文字列検索プログラム
  for (i = 0; i <= length - keyword_length; i++) {
    int match = 0;
    for (k = 0; k < keyword_length; k++) {
      if (princess[i + k] == keyword[k]) {
        match++;
      }
    }
    if (match == keyword_length) {
      printf("%d 文字目から %s が見つかりました。\n", i, keyword);
      // 01234567
      // kaguyahime // princess
      // ^^^^^^
      // ||||||
      // vvvvvv
      // mononoke     // keyword
      // 012345
      // mononoke       // replace_keyword

      // 0文字目(i文字目)から一致したことが分かったので、
      // mononokehime の 0 文字目から 7 文字目を
      // kaguya に置き換えればよい
      int find = i; // 何文字目で見つかったか保管
      for (r = 0; r < replace_keyword_length; r++) {
        princess[find + r] = replace_keyword[r];
      }

      // princess =>
      // 012345678901
      // kaguyakehime
      // となっている。

      // mononoke 8 文字
      // kaguya   6 文字
      // なので、 2 文字 後ろの文字を前に詰めるとよい
      // princess[6] = princess[8];   // 'h'
      // princess[7] = princess[9];   // 'i'
      // princess[8] = princess[10];  // 'm'
      // princess[9] = princess[11];  // 'e'
      // princess[10] = princess[12]; // '\0';  // 終端文字

      int left_shift = keyword_length - replace_keyword_length; // 2 文字 左へ
      for (r = find + replace_keyword_length; princess[r] != '\0'; r++) {
        princess[r] = princess[r + left_shift];
      }
      princess[r] = '\0';
    }
  }

  // 置換結果表示
  printf("%s を %s に置換しました。\n", keyword, replace_keyword);
  printf("置換後の姫の名は %s です。\n", princess);

  return 0;
}
