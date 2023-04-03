/**************************************************************************
 * 構造体(structure) その１
 **************************************************************************/
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  // 変数宣言
  char name[20]; // 利用者の名前
  int age;       // 利用者の年齢
  // 値の代入
  strcpy(name, "taro");
  age = 30;
  // 利用者情報の表示
  printf("---通常の変数での名前と年齢の表示\n");
  printf("%s さんの年齢は %d 歳です。\n", name, age);

  // このように名前、年齢などのように異なるデータ型を、一緒に扱いたい場合があります。
  // 文字「列」型や整数型の様に、「利用者」型があったら便利です。

  // char型やint型は、C言語標準で用意されていた型ですが、
  // プログラマが、新しい「型」を創造することも可能です。
  // 既存のデータ型を組み合わせて作られた新しい「型」のことを、
  // 「構造体」と呼びます。

  // 利用者型 構造体 そのものの定義
  struct user {
    char name[20];
    int age;
  }; // 最後に ; (セミコロン)があることに注意

  // 利用者型変数 personA, personB の宣言
  struct user personA, personB;
  // 値の代入
  // personA.name のように personB と name の間に . (ドット)
  // があることに着目して下さい。
  // 構造体の要素（＝メンバ変数）にアクセスするには、.(ドット演算子)を用います。
  // personA「の」name
  // というように、「.」を「の」と読み替えると理解しやすいと思います。
  strcpy(personA.name, "taro");
  // personA.name = "taro";// 書けない
  personA.age = 30;
  strcpy(personB.name, "hanako");
  personB.age = 28;
  // 利用者情報の表示
  printf("---初めての構造体\n");
  printf("%s さんの年齢は %d 歳です。\n", personA.name, personA.age);
  printf("%s さんの年齢は %d 歳です。\n", personB.name, personB.age);

  // 変数宣言の都度、struct user と書くのは、手間です。
  // せっかく user 型を作成したのですから、
  // user person1, person2 として使いたいものです。

  // typedef (type define)キーワードの使い方
  // 先の構造体の宣言との相違点に着目して下さい。
  typedef struct {
    char name[20];
    int age;
  } user;

  // 利用者型の変数 person1, person2の宣言
  user person1, person2;
  // 値の代入
  strcpy(person1.name, "taro");
  person1.age = 30;
  strcpy(person2.name, "hanako");
  person2.age = 28;
  // 利用者情報の表示
  printf("---typedefを使って構造体を宣言した場合\n");
  printf("%s さんの年齢は %d 歳です。\n", person1.name, person1.age);
  printf("%s さんの年齢は %d 歳です。\n", person2.name, person2.age);

  // 宣言と同時に初期値をセットすることも出来ます。
  user person3 = {"jiro", 20};
  printf("---宣言と同時に初期値をセット\n");
  printf("%s さんの年齢は %d 歳です。\n", person3.name, person3.age);

  // 構造体の配列を作ることも出来ます。

  // 構造体の配列の変数宣言
  user person[3]; // user型の配列変数personを宣言
                  // 添字は0-2 まで大きさ3の配列
  // 値の代入
  strcpy(person[0].name, "zero");
  person[0].age = 0;
  strcpy(person[1].name, "ichiro");
  person[1].age = 10;
  strcpy(person[2].name, "jiro");
  person[2].age = 20;
  // 利用者情報の表示
  printf("---構造体の配列\n");
  printf("%s さんの年齢は %d 歳です。\n", person[0].name, person[0].age);
  printf("%s さんの年齢は %d 歳です。\n", person[1].name, person[1].age);
  printf("%s さんの年齢は %d 歳です。\n", person[2].name, person[2].age);

  // for文を使うことも出来ます。
  int i;
  printf("---for文で表示\n");
  for (i = 0; i < 3; i++) {
    printf("%s さんの年齢は %d 歳です。\n", person[i].name, person[i].age);
  }

  // 構造体のコピー
  int num1, num2;
  num1 = 10;
  num2 = num1; // num2 には num1 がコピーされて 10 になります。

  // 構造体も同様にコピーすることが出来ます。
  person[2] = person[1];
  printf("---構造体のコピー\n");
  printf("%s さんの年齢は %d 歳です。\n", person[1].name, person[1].age);
  printf("%s さんの年齢は %d 歳です。\n", person[2].name, person[2].age);

  return 0;
}
