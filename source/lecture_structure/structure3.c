/**************************************************************************
 * 構造体(structure) その３
 **************************************************************************/
#include <stdio.h>
#include <string.h>

// user型構造体の宣言
// （一般的にはmain関数の外側に書きます)
typedef struct {
  char name[20];
  int score[4]; // 国語、算数、理科、社会の得点
  int total;    // 合計点数
} student;

// 構造体の要素（メンバー）が配列である場合もあります。

/**************************************************************************
 * 機能：生徒構造体型の得点計算を行う
 * 引数：student *  (生徒構造体ポインタ型 を引数に取る)
 * 戻り値：なし （void）
 **************************************************************************/
void calculate_score(student *person) {
  int i, sum = 0;
  for (i = 0; i < 4; i++) {
    sum += person->score[i];
    // sum += (*person).score[i];
    // と書いても同じです。
  }
  person->total = sum;
  // (*person).total = sum;
  // と書いても同じです。
}

int main(int argc, char const *argv[]) {

  // 変数宣言
  student personA;

  // 値の代入
  strcpy(personA.name, "daisuke"); // 名前は大助
  personA.score[0] = 50;           // 国語の点数
  personA.score[1] = 80;           // 算数の点数
  personA.score[2] = 70;           // 理科の点数
  personA.score[3] = 60;           // 社会の点数

  // 変数宣言と同時に初期値を与えることも出来ます。
  student personB = {"hanako", {90, 60, 50, 70}};

  // student型構造体の変数、person のアドレスを渡している点に着目して下さい。
  // 得点を計算してくれる関数calculate_scoreに、
  // personA, B のアドレスを渡し、得点を計算させる。
  calculate_score(&personA);
  calculate_score(&personB);

  // 得点情報の表示
  printf("%s さんの合計点は %d 点です。\n", personA.name, personA.total);
  printf("%s さんの合計点は %d 点です。\n", personB.name, personB.total);

  return 0;
}
