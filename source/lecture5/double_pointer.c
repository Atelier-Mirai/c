#include <stdio.h>
#include <string.h>

#define MAXITEM 20

char *str;
// ポインタの配列の宣言
char const *princesses[3] = {"Shirayukihime", "Kaguyahime", "Mononokehime"};

//「ポインタのポインタ」の宣言
char **p1, **p2, **p3;
int i, j;

// 「ポインタのポインタ」にポインタの配列の先頭番地を設定
p1 = p2 = p3 = princesses;

// 例1「ポインタのポインタ」の値を変えずに相対的に文字列を出力
for (i = 0; i < 3; i++) {
  printf("%s\n", *(p1 + i));
}

// 例2「ポインタのポインタ」の値そのものを更新して絶対的に文字列を出力
for (i = 0; i < 3; i++) {
  printf("%s\n", *p2);
  ++p2;
}

// 例3「ポインタのポインタ」を使って、1文字ずつ出力する
for (i = 0; i < 3; i++) {
  j = 0;
  while (*(*p3 + j) != '\0') {
    printf("%c", *(*p3 + j));
    j++;
  }
  printf("\n");
  ++p3;
})
