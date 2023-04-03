/**************************************************************************
 * 構造体(structure) その４
 **************************************************************************/
#include <stdio.h>
#include <string.h>

// user型構造体の宣言
// （一般的にはmain関数の外側に書きます)
typedef struct {
  char name[20];
  int age;
} user;

// 構造体型の戻り値を返す関数を作ることも出来ます。

/**************************************************************************
 * 機能：名前と年齢を引数として受け取り、user型の構造体を返す
 * 引数：char const *  文字定数ポインタ型（参照する型・指し示す型）
 *       int
 * 戻り値：user構造体型
 **************************************************************************/
user make_person(char const *name, int age) {
  user human;
  strcpy(human.name, name);
  human.age = age;
  return human;
}

int main(int argc, char const *argv[]) {

  // 変数宣言
  // 構造体型の戻り値を返す関数から
  // 戻り値を受け取れるように、
  // user型の変数personを宣言します。
  user person;

  // 名前と年齢を引数として受け取り、user型の構造体を返す関数を呼び出す。
  // 結果をpersonに受け取る（代入する）
  person = make_person("taro", 30);

  // 利用者情報の表示
  printf("%s さんの年齢は %d 歳です。\n", person.name, person.age);

  return 0;
}
