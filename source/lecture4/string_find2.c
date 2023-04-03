/**************************************************************************
 * 文字列の検索
 **************************************************************************/
#include <stdio.h>
#include <string.h>

// string中にkeywordが含まれていれば、何文字目から始まるかを、
// 含まれていなければ、-1 を返す
int find_keyword(char const *keyword, char const *princess) {
  int i, k;
  int length = strlen(princess);
  int keyword_length = strlen(keyword);

  for (i = 0; i <= length - keyword_length; i++) {
    int match = 0; // 何文字まで検索文字列と一致しているか？
    for (k = 0; k < keyword_length; k++) {
      if (princess[i + k] == keyword[k]) {
        match++;
      }
    }
    if (match == keyword_length) {
      return i;
    }
  }
  return -1;
}

int main(int argc, char const *argv[]) {
  char princess[20] = "しらゆきひめ";
  char keyword[20] = "しらゆき";
  printf("%d\n", find_keyword(keyword, princess));

  return 0;
}
