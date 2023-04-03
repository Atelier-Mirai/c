#include <limits.h> // 整数の取り得る範囲が定義されています。
#include <stdio.h>
#include <stdlib.h> // qsort
#include <string.h>

#define TRUE 1
#define FALSE 0

// stock_t構造体
typedef struct {
  int id;            //商品ID
  char name[64 - 8]; //商品名
  int quantity;      //在庫数
} stock_t;

// グローバル変数
stock_t stock[11]; // 在庫構造体配列

// 表示関数
void show_item(stock_t s) {
  printf("%3d %-20s %3d\n", s.id, s.name, s.quantity);
}
void show_all_item() {
  int i;
  for (i = 0; i <= 10; i++) {
    printf("%3d %-20s %3d\n", stock[i].id, stock[i].name, stock[i].quantity);
  }
}

void show_all_item_p(stock_t *(p[11])) {
  // printf("stock[10].name: %s\n", stock[10].name);
  // printf("(*p[10]).name : %s\n", (*p[10]).name);
  // printf("p[10]->name   : %s\n", p[10]->name);
  int i;
  for (i = 0; i <= 10; i++) {
    printf("%3d %-20s %3d\n", p[i]->id, p[i]->name, p[i]->quantity);
  }
}

// 設定関数
void set_stock(stock_t *s, int id, char *name, int quantity) {
  (*s).id = id;
  strcpy((*s).name, name);
  (*s).quantity = quantity;
}

// 初期化関数
void init_stock() {
  set_stock(&stock[0], 100, "大福　　", 0);
  set_stock(&stock[1], 101, "いちご　", 10);
  set_stock(&stock[2], 102, "にんじん", 20);
  set_stock(&stock[3], 103, "サンダル", 30);
  set_stock(&stock[4], 104, "ヨット　", 40);
  set_stock(&stock[5], 105, "ごま塩　", 50);
  set_stock(&stock[6], 106, "ロケット", 60);
  set_stock(&stock[7], 107, "七面鳥　", 70);
  set_stock(&stock[8], 108, "蜂　　　", 80);
  set_stock(&stock[9], 109, "くじら　", 90);
  set_stock(&stock[10], 110, "ジュース", 100);
}

// 選択ソート
void selection_sort() {

  stock_t min; // 最小値格納用 構造体

  int sorted; // 今、何番目の要素まで並び替えが終了しているのか。
  int index;
  int i;

  for (sorted = 10; sorted >= 1; sorted--) {
    min.quantity = INT_MAX;
    for (i = 0; i <= sorted; i++) {
      if (min.quantity > stock[i].quantity) {
        min.id = stock[i].id;
        strcpy(min.name, stock[i].name);
        min.quantity = stock[i].quantity;
        index = i;
      }
    }
    // 一番小さい数が後ろになるように、一つずつ詰める
    for (i = index; i < sorted; i++) {
      stock[i].id = stock[i + 1].id;
      strcpy(stock[i].name, stock[i + 1].name);
      stock[i].quantity = stock[i + 1].quantity;
    }
    // 最小値をセットする
    // array[sorted] = min;
    stock[sorted].id = min.id;
    strcpy(stock[sorted].name, min.name);
    stock[sorted].quantity = min.quantity;
  }
}

void pointer_sort(stock_t *(p[11])) {
  printf("pointer_sort\n");
  // 値表示（元）
  printf("address &p[0]    : %p\n", &p[0]);
  printf("address &stock[0]: %p\n", &stock[0]);
  printf("value   p[0]     : %p\n", p[0]);
  // 値表示（参照先）
  printf("stock[10].name: %s\n", stock[10].name);
  printf("(*p[10]).name : %s\n", (*p[10]).name);
  printf("p[10]->name   : %s\n", p[10]->name);

  int min; // 最小値
  stock_t *min_p;

  int sorted; // 今、何番目の要素まで並び替えが終了しているのか。
  int index;
  int i;

  for (sorted = 10; sorted >= 1; sorted--) {
    min = INT_MAX;
    for (i = 0; i <= sorted; i++) {
      if (min > p[i]->quantity) {
        min = p[i]->quantity;
        min_p = p[i];
        index = i;
      }
    }
    // 一番小さい数が後ろになるように、一つずつ詰める
    for (i = index; i < sorted; i++) {
      p[i] = p[i + 1];
    }
    // 最小値をセットする
    // array[sorted] = min;
    p[sorted] = min_p;
  }
}

// 比較関数（大小判断を返す関数）
int compare(const void *a, const void *b) {
  // b > a なら 正の数を返す。(降順)
  return (*(stock_t *)b).quantity - (*(stock_t *)a).quantity;
}

int main(int argc, char const *argv[]) {

  /******************************************************************/
  init_stock();
  // show_all_item();

  /******************************************************************/
  // 選択ソート
  // selection_sort();

  /******************************************************************/
  // ポインタソート
  stock_t *(p[11]); // ポインタ配列 宣言
  // 初期化
  p[0] = &stock[0];
  p[1] = &stock[1];
  p[2] = &stock[2];
  p[3] = &stock[3];
  p[4] = &stock[4];
  p[5] = &stock[5];
  p[6] = &stock[6];
  p[7] = &stock[7];
  p[8] = &stock[8];
  p[9] = &stock[9];
  p[10] = &stock[10];

  printf("main\n");

  printf("address &p[0]    : %p\n", &p[0]);
  // 値表示（元）
  printf("address &stock[0]: %p\n", &stock[0]);
  printf("value   p[0]     : %p\n", p[0]);

  printf("address &p[1]    : %p\n", &p[1]);
  // 値表示（元）
  printf("address &stock[1]: %p\n", &stock[1]);
  printf("value   p[1]     : %p\n", p[1]);

  // 値表示（参照先）
  printf("stock[10].name: %s\n", stock[10].name);
  printf("(*p[10]).name : %s\n", (*p[10]).name);
  printf("p[10]->name   : %s\n", p[10]->name);

  pointer_sort(p);
  int i;
  for (i = 0; i <= 10; i++) {
    printf("value   p[%d]     : %p\n", i, p[i]);
  }
  // ポインタは並び変わっているので、ポインタを基準に表示してみる。
  // show_all_item_p(p);
  // もとの構造体は並び変わっていないので、元のままの表示である。
  // show_all_item();

  /******************************************************************/
  // quick sort
  // 並び替えすると、元の配列が破壊されるため、バックアップを取る
  // for 文で 一要素ずつコピーしても良いが、
  // memcpy 関数を紹介
  stock_t backup[11];
  memcpy(backup, stock,
         11 * sizeof(stock_t)); // stock_t型構造体11要素分をbackupへコピー

  // バックアップされていることの確認
  // show_item(backup[10]);

  // quick sort で構造体を直接並び替える
  // 並び替えたい配列名, 要素数, 配列1要素分のサイズ, 大小比較に用いる関数名
  qsort(stock, 11, sizeof(stock_t), compare);

  // 結果表示
  show_all_item();

  return 0;
}
