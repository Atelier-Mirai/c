#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// stock_t構造体
typedef struct {
  int id;          //商品ID
  char name[100];  //商品名
  int quantity;    //在庫数
  int delete_flag; //削除ならTRUE
} stock_t;

stock_t *stock; //変数宣言
// stock_t stock[100];

int main(int argc, char const *argv[]) {
  stock_t *temp; // ローカル変数

  stock = (stock_t *)malloc(2 * sizeof(stock_t));
  if (stock != NULL) {
    stock[0].id = 100;
    strcpy(stock[0].name, "いちご");
    stock[0].quantity = 10;

    stock[1].id = 200;
    strcpy(stock[1].name, "にんじん");
    stock[1].quantity = 20;
  }

  printf("%d %s %d\n", stock[0].id, stock[0].name, stock[0].quantity);
  printf("%d %s %d\n", stock[1].id, stock[1].name, stock[1].quantity);
  printf("%d %s %d\n", stock[2].id, stock[2].name, stock[2].quantity);

  temp = (stock_t *)realloc(stock, 3 * sizeof(stock_t));
  if (temp != NULL) {
    stock = temp;
    stock[2].id = 300;
    strcpy(stock[2].name, "サンダル");
    stock[2].quantity = 30;
  }

  printf("%d %s %d\n", stock[0].id, stock[0].name, stock[0].quantity);
  printf("%d %s %d\n", stock[1].id, stock[1].name, stock[1].quantity);
  printf("%d %s %d\n", stock[2].id, stock[2].name, stock[2].quantity);

  free(stock);
  return 0;
}
