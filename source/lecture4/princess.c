#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char princess[20] = "shirayukihime";
  int i;
  int length;
  length = strlen(princess);

  for (i = 0; i < length; i++) {
    printf("%d %c\n", i, princess[i]);
  }

  char key[] = "hime"; // 検索文字列
  int key_length = strlen(key);
  int k;
  int clear = 0; // 何文字まで検索できているか？

  for (i = 0; i < length; i++) { // もとの検索文字列のループ
    for (k = 0; k < key_length; k++) {
      if (key[k] == princess[k + i]) {
        clear++;
        if (clear == key_length) {
          printf("%d 文字目に発見\n", i + 1);
          clear = 0;
          break;
        }
      } else {
        clear = 0;
      }
    }
  }

  return 0;
}
