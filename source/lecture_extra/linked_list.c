/**************************************************************************
 * 連結リスト
 * https://ja.wikipedia.org/wiki/連結リスト
 * http://bituse.info/c/39
 *
 * 変数や関数に使われる必要最低限の単語を覚える
 * http://oxynotes.com/?p=8679#7
 *
 * マージソート
 * https://ja.wikipedia.org/wiki/マージソート
 * http://ppp-lab.sakura.ne.jp/ProgrammingPlacePlus/algorithm/sort/007.html
 **************************************************************************/
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  // 線形リスト宣言と、一番最初のノード生成
  list_t *list = (list_t *)malloc(sizeof(list_t));

  // このリストにあるノードは一つだけで、
  // 次の要素はまだ空なのでNULLを入れる（番兵）
  list->next = NULL;
  list->value = 0;

  char answer;
  int number;

  while (1) {
    printf("何をしますか？\n 0.終了、1.追加、2.削除、3.表示\n");
    scanf("%c", &answer);
    while (getchar() != '\n')
      ;

    switch (answer) {
    case '0':
      // 解放
      release_list(list);
      return 0;
    case '1':
      printf("追加する値を入力して下さい> ");
      scanf("%d", &number);
      while (getchar() != '\n')
        ;
      if (insert_node(list, number) == SUCCESS) {
        printf("追加しました\n");
      } else {
        printf("追加用メモリが確保出来ませんでした\n");
      }
      break;
    case '2':
      printf("削除する値を入力して下さい> ");
      scanf("%d", &number);
      while (getchar() != '\n')
        ;
      if (remove_node(list, number) == SUCCESS) {
        printf("削除しました\n");
      } else {
        printf("その値を持つノードは見つかりませんでした\n");
      }
      break;
    case '3':
      if (show_list(list) == NOT_FOUND) {
        printf("まだ何もありません\n");
      }
      break;
    default:
      printf("正しい選択肢を入力して下さい> ");
      break;
    }
  }
}
