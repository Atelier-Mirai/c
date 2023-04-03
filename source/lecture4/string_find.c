/**************************************************************************
 * 文字列の検索
 **************************************************************************/
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  // 検索対象文字列 を "shirayukihime" で初期化
  // 一文字ずつ、初期値をセットする。
  // 文字列として扱えるよう、最後には終端文字'\0'もセット。
  char princess[20] = {'s', 'h', 'i', 'r', 'a', 'y', 'u',
                       'k', 'i', 'h', 'i', 'm', 'e', '\0'};
  // 長いので、宣言と同時に初期値を与える場合に限り、次のように書けます。
  // char princess[20] = "shirayukihime"; // '\0' 不要

  // 変数宣言と代入を別々にすると、エラーとなります。
  // char princess[20];               // この行はOKです。
  // princess[20] = "shirayukihime";  // この行でエラーになります。

  // 変数宣言後に、文字列をセットする場合には、
  // 文字列コピー関数 strcpy を使います。
  // char princess[20];                  // この行はOKです。
  // strcpy(princess, "shirayukihime");  // このように使います。

  // 次のように一文字ずつ代入することも出来ます。
  // princess[0] = 's';
  // princess[1] = 'h';
  // princess[2] = 'i';
  // // (略)
  // princess[11] = 'm';
  // princess[12] = 'e';
  // princess[13] = '\0';

  // C言語では文字列は「文字の配列」として表現します。
  printf("変数princess に初期値が設定されているか確認\n");
  printf("%c\n", princess[0]); // %c は 「文字」を出力する書式指定子です。
  printf("%c\n", princess[1]); // C 言語の配列は、0から始まります。
  printf("%c\n", princess[2]);
  printf("略\n");
  printf("%c\n", princess[12]); // 最後12まで出せば、確認出来ます。

  // [0], [1], ・・・, [12]と、配列の「添字」が変化していくので、
  // 繰り返しのためのfor文を使うと簡単に書けます。
  int i;
  for (i = 0; i <= 12; i++) {
    printf("%d %c\n", i, princess[i]); // %d 整数型の書式指定子
  }
  printf("%s\n", princess); // %s 文字「列」型の書式指定子

  // 検索の考え方
  // 検索対象文字列"shirayukihime"の先頭(0文字目)から、
  // 一文字ずつ、検索文字列"hime"一致するかどうかを比較します。
  // shirayukihime
  // ^^^^
  // ||||
  // vvvv
  // hime
  if (princess[0] == 'h') {
    printf("0文字目が一致しました。\n");
  }
  if (princess[1] == 'i') {
    printf("1文字目が一致しました。\n");
  }
  if (princess[2] == 'm') {
    printf("2文字目が一致しました。\n");
  }
  if (princess[3] == 'e') {
    printf("3文字目が一致しました。\n");
  }
  // 0 文字目から 3 文字目まで 4文字が一致すれば、
  // "hime" が見つかったことになります。

  // 引き続いて、1文字目から一文字ずつ、
  // 検索文字列"hime"一致するかどうかを比較します。
  // shirayukihime
  //  ^^^^
  //  ||||
  //  vvvv
  //  hime
  if (princess[1] == 'h') {
    printf("1文字目が一致しました。\n");
  }
  if (princess[2] == 'i') {
    printf("2文字目が一致しました。\n");
  }
  if (princess[3] == 'm') {
    printf("3文字目が一致しました。\n");
  }
  if (princess[4] == 'e') {
    printf("4文字目が一致しました。\n");
  }
  // 1 文字目から 4 文字目まで 4文字が一致すれば、
  // "hime" が見つかったことになります。

  // 同様に繰り返して、9文字目から
  // 一文字ずつ、検索文字列"hime"一致するかどうかを比較します。
  // shirayukihime
  //          ^^^^
  //          ||||
  //          vvvv
  //          hime
  if (princess[9] == 'h') {
    printf("9文字目が一致しました。\n");
  }
  if (princess[10] == 'i') {
    printf("10文字目が一致しました。\n");
  }
  if (princess[11] == 'm') {
    printf("11文字目が一致しました。\n");
  }
  if (princess[12] == 'e') {
    printf("12文字目が一致しました。\n");
  }
  // 9 文字目から 12 文字目まで 4文字が一致すれば、
  // "hime" が見つかったことになります。

  // 同じ処理を繰り返しているので、
  // for 文で書けば簡単に書けそうです。
  int match;
  for (i = 0; i <= 9; i++) {
    match = 0; // 何文字まで検索文字列と一致しているか？
    if (princess[i + 0] == 'h') {
      match++;
    }
    if (princess[i + 1] == 'i') {
      match++;
    }
    if (princess[i + 2] == 'm') {
      match++;
    }
    if (princess[i + 3] == 'e') {
      match++;
    }
    if (match == 4) {
      printf("%d 文字目から hime が見つかりました。\n", i);
    }
  }

  // そして、
  // if (princess[i+0] == 'h'){ match++; }
  // if (princess[i+1] == 'i'){ match++; }
  // if (princess[i+2] == 'm'){ match++; }
  // if (princess[i+3] == 'e'){ match++; }
  // これらのif文も同じ処理をしていますから、
  // for文で纏めて書けそうです。
  keyword[0] = 'h';
  keyword[1] = 'i';
  keyword[2] = 'm';
  keyword[3] = 'e';
  // とすると
  if (princess[i + 0] == keyword[0]) {
    match++;
  }
  if (princess[i + 1] == keyword[1]) {
    match++;
  }
  if (princess[i + 2] == keyword[2]) {
    match++;
  }
  if (princess[i + 3] == keyword[3]) {
    match++;
  }
  // と書き直せます。

  // よって、
  char keyword[10] = "hime"; // 検索文字列
  int k;                     // 検索文字列用のindex変数
  // とすると、
  for (k = 0; i < 4; k++) {
    if (princess[i + k] == keyword[k]) {
      match++;
    }
  }
  // と書くことが出来ます。

  printf("変数keywordに初期値が設定されているか確認\n");
  printf("keyword[0]: %c\n", keyword[0]);
  printf("keyword[1]: %c\n", keyword[1]);
  printf("keyword[2]: %c\n", keyword[2]);
  printf("keyword[3]: %c\n", keyword[3]);

  printf("変数keywordに初期値が設定されているかfor文で確認\n");
  for (k = 0; k < 4; k++) {
    printf("%c\n", keyword[k]);
  }

  for (i = 0; i <= 9; i++) {
    int match = 0; // 何文字まで検索文字列と一致しているか？
    for (k = 0; k < 4; k++) {
      if (princess[i + k] == keyword[k]) {
        match++;
      }
    }
    if (match == 4) {
      printf("%d 文字目から hime が見つかりました。\n", i);
    }
  }

  // 検索対象文字列、検索文字列が何文字であっても動くように、
  // 文字列の長さを格納する変数を用意すれば、
  // 検索プログラムの完成です。

  printf("完成版のプログラム\n");
  int length;                // 検索対象文字列の長さ
  length = strlen(princess); // strlen関数を用いると長さが取得出来る
  // length => 13
  // 宣言と同時に関数を使って初期値をセットすることも出来ます。
  int keyword_length = strlen(keyword);
  // keyword_length => 4

  for (i = 0; i <= length - keyword_length; i++) {
    int match = 0; // 何文字まで検索文字列と一致しているか？
    for (k = 0; k < keyword_length; k++) {
      if (princess[i + k] == keyword[k]) {
        match++;
      }
    }
    if (match == keyword_length) {
      printf("%d 文字目から %s が見つかりました。\n", i, keyword);
    }
  }

  return 0;
}
