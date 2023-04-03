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
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

// 関数プロトタイプ宣言
list_t *merge(list_t *a, list_t *b);
list_t *merge_sort_recursive(list_t *list);
void merge_sort(list_t *list);

int main(int argc, char const *argv[]) {
  // 線形リスト宣言と、一番最初のノード生成
  list_t *list = (list_t *)malloc(sizeof(list_t));

  // このリストにあるノードは一つだけで、
  // 次の要素はまだ空なのでNULLを入れる（番兵）
  list->next = NULL;
  list->value = 0;

  // 初期値投入
  insert_node(list, 30);
  insert_node(list, 20);
  insert_node(list, 80);
  insert_node(list, 90);
  insert_node(list, 50);
  insert_node(list, 10);
  insert_node(list, 70);
  insert_node(list, 0);
  insert_node(list, 90);
  insert_node(list, 20);

  printf("並び替え前\n");
  show_list(list);

  // マージソート
  merge_sort(list);

  printf("並び替え後\n");
  show_list(list);

  // 解放
  release_list(list);

  return 0;
}

// マージ（併合）
list_t *merge(list_t *a, list_t *b) {
  // printf("merge\n");

  list_t result;       // *result ではない!!
  list_t *w = &result; // work 変数

  // リストをマージ
  while (a != NULL && b != NULL) {
    // printf("a->value: %d b->value: %d\n", a->value, b->value);

    // 昇順にソートするので、小さい方の要素を結果を優先する
    if (a->value <= b->value) { // == の場合は先頭を優先すると安定なソートになる
      w->next = a;
      w = w->next;
      a = a->next;
    } else {
      w->next = b;
      w = w->next;
      b = b->next;
    }
  }
  // printf("a: %p b: %p\n", a, b);

  // 残っている要素を、末尾へ連結
  if (a == NULL) {
    w->next = b;
  } else {
    w->next = a;
  }
  // printf("a: %p b: %p w: %p\n", a, b, w);
  // printf("result.next: %p\n", result.next);
  return result.next;
}

// マージソート (再帰部分、昇順)
list_t *merge_sort_recursive(list_t *list) {
  // printf("recursive\n");

  list_t *a;
  list_t *b;
  list_t *w; // work 変数

  // 要素が１つしかなければ終了
  if (list == NULL || list->next == NULL) {
    // printf("list one: %p\n", list);
    return list;
  }

  // ２つのリストに分割するため、リストの中心を探す
  a = list;
  b = list->next;

  // printf("a: %p b: %p\n", a, b);
  if (b != NULL) {
    b = b->next;
  }

  while (b != NULL) {
    a = a->next;
    b = b->next;
    if (b != NULL) {
      b = b->next;
    }
  }

  // リストを前半と後半に分離
  w = a->next;
  a->next = NULL;

  // printf("list: %p w: %p\n", list, w);
  // 前半と後半のリストをマージする
  return merge(merge_sort_recursive(list), merge_sort_recursive(w));
}

// マージソート (昇順)
void merge_sort(list_t *list) {
  list_t *result;

  if (list == NULL) {
    return;
  }

  // printf("%p\n", list->next);

  // リスト全体を対象にする
  result = merge_sort_recursive(list->next);

  list->next = result;
}
