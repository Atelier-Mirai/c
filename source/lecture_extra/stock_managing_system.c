#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define FAIL 0

#define NOT_FOUND -1
#define COLUMN_MAX 3
#define NAME_MAX 64
#define BUFFER_MAX 256

// stock_t型 構造体
typedef struct {
  int id;              // 商品ID
  char name[NAME_MAX]; // 商品名
  int quantity;        // 数量
  int delete_flag;     // 削除フラグ(削除ならTRUE)
} stock_t;

// グローバル変数
stock_t *stock;                       // 後程mallocでメモリ確保
int item_count;                       // 取り扱っている品目数
char const *DB_NAME = "stock_db.txt"; // データベース ファイル名

// プロトタイプ宣言

// メニュー表示
void menu();
// 1-numまでの数のキー入力
int read_number(int num);
// キー入力待ち
void hit_any_key();
// 受け取った構造体のメンバーを表示する
void show_item(stock_t stock);
// 在庫一覧表示
void show_list();
// 商品ID検索
void search_item_by_id();
// 商品名検索
void search_item_by_name();
// id で検索。該当する構造体の添え字(index)を返す
int find_by_id(int id);
// 在庫数量セット
void set_quantity();
// 新商品登録
void create_new_item();
// 旧商品削除
void destroy_old_item();
// 商品名編集
void edit_item_name();
// ファイルから読み込んだレコードを、構造体に格納する
// 戻り値は、レコード数
int load_data_file(char const *filename);
// 構造体をファイルに書き出す
// 戻り値は、SUCCESS / FAIL
int save_data_file(char const *filename);
// strを区切り文字で分離、outlistに格納する
int split(char *str, char const *delimiter, char *outlist[]);
// string中にkeywordが含まれていれば、何文字目から始まるかを、
// 含まれていなければ、NOT_FOUND を返す
int find(char const *keyword, char const *princess);

// メニュー表示
void menu() {
  printf("\n");
  printf("\n### 在庫管理システム ###\n");
  printf("\n");
  printf("１）商品一覧\n");
  printf("２）商品IDで在庫数を検索\n");
  printf("３）商品在庫数の増減\n");
  printf("４）新商品の登録\n");
  printf("５）旧商品の削除\n");
  printf("６）商品名の編集\n");
  printf("７）データの保存\n");
  printf("８）商品名で在庫数を検索\n");
  printf("９）プログラム終了\n");
  printf("\n");
  printf("メニュー選択(1-9) > ");
}

// 1-numまでの数のキー入力
int read_number(int num) {
  int n;
  do {
    scanf("%d", &n);
    while (getchar() != '\n')
      ;
  } while (!(1 <= n && n <= num));
  return n;
}

// キー入力待ち
void hit_any_key() {
  printf("\nHit Enter key.\n");
  while (getchar() != '\n')
    ;
}

// 受け取った構造体のメンバーを表示する
void show_item(stock_t stock) {
  //    if (!stock[i].delete_flag){
  if (stock.delete_flag == FALSE) {
    printf("%3d %-20s %3d\n", stock.id, stock.name, stock.quantity);
  }
}

// 在庫一覧表示
void show_list() {
  printf("\n### 在庫一覧 ###\n");
  printf("\n");
  printf(" ID 商品名              数量\n");
  int i;
  for (i = 0; i < item_count; i++) {
    show_item(stock[i]);
  }
  hit_any_key();
}

// 商品ID検索
void search_item_by_id() {
  int index, id;
  printf("\n### 商品ID検索 ###\n");
  printf("商品IDを入力してください > ");
  scanf("%d", &id);
  while (getchar() != '\n')
    ;

  // index = find_by_id(id);
  // if (index != NOT_FOUND){
  if ((index = find_by_id(id)) != NOT_FOUND) {
    show_item(stock[index]);
  } else {
    printf("該当するIDの商品はありませんでした。\n");
  }
  hit_any_key();
}

// id で検索。該当する構造体の添え字(index)を返す
int find_by_id(int id) {
  int i;
  for (i = 0; i < item_count; i++) {
    if (stock[i].id == id && stock[i].delete_flag == FALSE) {
      return i;
    }
  }
  return NOT_FOUND;
}

// 在庫数量セット
void set_quantity() {
  int index, id, quantity;
  printf("\n### 在庫数増減 ###\n");
  printf("\n");
  printf("商品IDを入力してください > ");
  scanf("%d", &id);
  while (getchar() != '\n')
    ;

  if ((index = find_by_id(id)) != NOT_FOUND) {
    printf("在庫数を入力してください > ");
    scanf("%d", &quantity);
    while (getchar() != '\n')
      ;
    stock[index].quantity = quantity;
  } else {
    printf("該当するIDの商品はありませんでした。\n");
  }
  hit_any_key();
}

// 新商品登録
void create_new_item() {
  stock_t *temp;
  int id, quantity;
  char name[NAME_MAX];

  printf("\n### 新商品登録 ###\n");
  // 構造体は、0 - item_count-1 までの、item_count 個 mallocでメモリ確保している
  // item_count+1 個 メモリを再確保(realloc)する
  temp = (stock_t *)realloc(stock, (item_count + 1) * sizeof(stock_t));
  // printf("stock: %p\n", stock);
  // printf("temp : %p\n", temp);
  if (temp != NULL) {
    // printf("realloc success\n");
    // printf("temp: %p\n", temp);
    stock = temp;
    // printf("stock: %p\n", stock);

    // メモリが確保出来たので、新商品を登録する
    do {
      printf("商品IDを入力してください > ");
      scanf("%d", &id);
      while (getchar() != '\n')
        ;
    } while (find_by_id(id) != NOT_FOUND); // id 重複チェック

    printf("商品名を入力してください > ");
    scanf("%s", name);
    while (getchar() != '\n')
      ;

    printf("在庫数量を入力してください > ");
    scanf("%d", &quantity);
    while (getchar() != '\n')
      ;

    stock[item_count].id = id;
    strcpy(stock[item_count].name, name);
    stock[item_count].quantity = quantity;
    item_count++;
  } else {
    printf("新商品を登録するためのメモリが確保出来ませんでした\n");
  }
  hit_any_key();
}

// 旧商品削除
void destroy_old_item() {
  int index, id;
  char answer;

  printf("\n### 旧商品削除 ###\n");

  printf("商品IDを入力してください > ");
  scanf("%d", &id);
  while (getchar() != '\n')
    ;

  if ((index = find_by_id(id)) != NOT_FOUND) {
    show_item(stock[index]);
    printf("この商品を削除しますか？(y/n) > ");
    scanf("%c", &answer);
    while (getchar() != '\n')
      ;
    if (answer == 'y' || answer == 'Y') {
      stock[index].delete_flag = TRUE;
      printf("削除しました。\n");
    }
  } else {
    printf("該当するIDの商品はありませんでした。\n");
  }

  hit_any_key();
}

// 商品名編集
void edit_item_name() {
  int index, id;
  char name[NAME_MAX];

  printf("\n### 商品名変更 ###\n");

  printf("商品IDを入力してください > ");
  scanf("%d", &id);
  while (getchar() != '\n')
    ;

  if ((index = find_by_id(id)) != NOT_FOUND) {
    printf("変更後の商品名を入力してください > ");
    scanf("%s", name);
    while (getchar() != '\n')
      ;
    strcpy(stock[index].name, name);
  } else {
    printf("該当するIDの商品はありませんでした。\n");
  }

  hit_any_key();
}

// ファイルから読み込んだレコードを、構造体に格納する
// 戻り値は、レコード数
int load_data_file(char const *filename) {
  // 変数宣言
  FILE *fp = NULL;
  char buffer[BUFFER_MAX];
  int line_count; // 行数

  // 読み取りモードでファイルを開く
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Can't read '%s'\n", filename);
    exit(1);
  }

  // 行数の取得
  line_count = 0;
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    line_count++;
  }

  // メモリの動的確保
  stock = (stock_t *)malloc(line_count * sizeof(stock_t));

  if (stock == NULL) {
    printf("Can't allocate memory. 'stock' is NULL.\n");
    fclose(fp);
    exit(1);
  }

  // シーク位置を先頭に戻す
  fseek(fp, 0L, SEEK_SET);

  // データの読み込み
  int i = 0;
  char *outlist[COLUMN_MAX];
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    // 一行分bufferに読み込んだので、分離して、構造体に格納する
    split(buffer, ",", outlist);
    stock[i].id = atoi(outlist[0]);       // id
    strcpy(stock[i].name, outlist[1]);    // name
    stock[i].quantity = atoi(outlist[2]); // quantity
    stock[i].delete_flag = FALSE;         // delete_flag
    i++;
  }

  // ファイルクローズ
  fclose(fp);

  // 読み込んだ行数を返す(=構造体の要素数)
  return i;
}

// 構造体をファイルに書き出す
// 戻り値は、SUCCESS / FAIL
int save_data_file(char const *filename) {
  // 変数宣言
  FILE *fp = NULL;
  int i;

  // 書き込みモードでファイルを開く
  fp = fopen(filename, "w");
  if (fp == NULL) {
    printf("Can't write '%s'\n", filename);
    return FAIL;
  }

  // 削除フラグが立っていないデータを書き出す
  for (i = 0; i < item_count; i++) {
    if (stock[i].delete_flag == FALSE) {
      fprintf(fp, "%d,%s,%d\n", stock[i].id, stock[i].name, stock[i].quantity);
    }
  }

  // ファイルクローズ
  fclose(fp);

  return SUCCESS;
}

// strを区切り文字で分離、outlistに格納する
int split(char *str, char const *delimiter, char *outlist[]) {
  char *token;
  int count = 0;

  token = strtok(str, delimiter);
  while (token != NULL && count < COLUMN_MAX) {
    outlist[count++] = token;
    token = strtok(NULL, delimiter);
  }

  return count;
}

// 商品ID検索
void search_item_by_name() {
  int i;
  char keyword[NAME_MAX];
  int flag = FALSE;

  printf("\n### 商品名検索 ###\n");
  printf("商品名を入力してください > ");
  scanf("%s", keyword);
  while (getchar() != '\n')
    ;

  for (i = 0; i < item_count; i++) {
    if ((find(keyword, stock[i].name)) != NOT_FOUND) {
      show_item(stock[i]);
      flag = TRUE;
    }
  }
  if (flag == FALSE) {
    printf("該当する商品はありませんでした。\n");
  }
  hit_any_key();
}

// string中にkeywordが含まれていれば、何文字目から始まるかを、
// 含まれていなければ、NOT_FOUND を返す
int find(char const *keyword, char const *princess) {
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
  return NOT_FOUND;
}

int main(int argc, char const *argv[]) {
  int i, count;

  // データファイルの読み込み
  item_count = load_data_file(DB_NAME);

  // メニュー表示繰り返し
  while (1) {
    menu();
    switch (read_number(9)) {
    case 1:
      show_list();
      break;
    case 2:
      search_item_by_id();
      break;
    case 3:
      set_quantity();
      break;
    case 4:
      create_new_item();
      break;
    case 5:
      destroy_old_item();
      break;
    case 6:
      edit_item_name();
      break;
    case 7:
      if (save_data_file(DB_NAME) == SUCCESS) {
        printf("データを保存しました");
      };
      break;
    case 8:
      search_item_by_name();
      break;
    case 9:
      printf("プログラムを終了します\n");
      // malloc で確保した領域の解放
      free(stock);
      exit(1);
      break;
    }
  }

  return 0;
}
