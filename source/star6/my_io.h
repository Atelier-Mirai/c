#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define FAIL -1

/****************************************************/
/* 関数名    : get_hex                              */
/* 機能説明　: 8桁の2進数をssに取得する             */
/* 引数　　　: ss 数字を格納したい配列              */
/*             digit 桁数                           */
/* 返り値　　: SUCCESS:数字が入力された時           */
/*             FAIL   :数字以外が入力された時       */
/* 備考      : 動作確認用にprintf文を入れているが、 */
/*           : 実際には、コメントアウトすること     */
/****************************************************/
int get_hex(char ss[], int digit) {
  int ch;
  int cnt = 0;
  while ((ch = getchar()) != EOF) {
    printf("ch = %d\n", ch);
    if (cnt == 0 && ch == '\n') {
      printf("一文字以上入れてください\n");
      return FAIL;
    }

    // 16進数0~9 or a~fでないなら、
    //  isxdigitでも良い
    if (!(('0' <= ch && ch <= '9') || ('a' <= ch && ch <= 'f'))) {
      if (ch == '\n' || ch == EOF) {
        return SUCCESS;
      }
      printf("１６進数を入力して ch = %x\n", ch);
      // そうでないならエラー表示
      printf("１６進 cnt = %d\n", cnt);
      while ((ch = getchar()) != '\n') {
        printf("ch = %x \n", ch);
        ; //読み飛ばし
      }
      printf("0 / 1 を入力して while 後まで来ました。\n");

      return 2;                //エラーコード2を返す
    } else if (cnt >= digit) { // 9bit以降読み飛ばし
      printf("5桁以降読み飛ばします\n");
      printf("cnt = %d digit = %d\n", cnt, digit);
      while (getchar() != '\n') {
        ; //読み飛ばし
      }
      printf("5桁以降読み飛ばしました\n");
      return SUCCESS;
    } else if (cnt != 0 && ch == '\n') {
      printf("正常終了します\n");
      return SUCCESS;
    } else {
      ss[cnt] = ch;
      cnt++;
    }
  }
  return SUCCESS;
}

/*********************************************************/
/* 関数名    : disp_sary()                               */
/* 機能説明　: 文字配列の内容を表示する                  */
/* 引数　　　:                                           */
/* 返り値　　:                                           */
/*********************************************************/
void disp_sary(char array[], int array_size, char *array_name) {
  int i;
  for (i = 0; i < array_size; i++) {
    printf("%s[%d] = %x\n", array_name, i, array[i]);
  }
}

/*********************************************************/
/* 関数名    : disp_iary()                               */
/* 機能説明　: int配列の内容を表示する                   */
/* 引数　　　:                                           */
/* 返り値　　:                                           */
/*********************************************************/
void disp_iary(int array[], int array_size, char *array_name) {
  int i;
  for (i = 0; i < array_size; i++) {
    printf("%s[%d] = %d\n", array_name, i, array[i]);
  }
}

/*********************************************************/
/* 関数名    : init_sary()                               */
/* 機能説明　: 文字配列を初期化する                      */
/* 引数　　　:                                           */
/* 返り値　　:                                           */
/*********************************************************/
void init_sary(char array[], int array_size) {
  int i;
  for (i = 0; i < array_size; i++) {
    array[i] = '\0';
  }
}

/*********************************************************/
/* 関数名    : init_iary()                               */
/* 機能説明　: int配列を初期化する                       */
/* 引数　　　:                                           */
/* 返り値　　:                                           */
/*********************************************************/
void init_iary(int array[], int array_size) {
  int i;
  for (i = 0; i < array_size; i++) {
    array[i] = 0;
  }
}

/*********************************************************/
/* 関数名    : htod(char ss)                             */
/* 機能説明　: 16進数を10進数に変換する                  */
/* 引数　　　: char ss[] 16進数の文字列                  */
/* 返り値　　: 10進数                                    */
/*********************************************************/
int htod(char ss[]) {
  int i = 0;
  int sum = 0;
  while (ss[i] != '\0') {
    if (isalpha(ss[i])) {
      sum = sum * 16 + (ss[i] - 'a' + 10);
      i++;
      // sum = sum * 16 + (ss[i++] - 'a' + 10);
      // と一行に書けるが分かりやすさのために
      // 二行で書いている
    } else {
      // '0'を引くことで、文字から数値へ変換できる
      sum = sum * 16 + (ss[i] - '0');
      i++;
    }
  }
  return sum;
}

/*********************************************************/
/* 関数名    : btod(char ss)                             */
/* 機能説明　: 2進数を10進数に変換する                   */
/* 引数　　　: char ss[] 2進数の文字列                   */
/* 返り値　　: 10進数                                    */
/*********************************************************/
int btod(char ss[]) {
  int i = 0;
  int sum = 0;
  while (ss[i] != '\0') {
    sum = sum * 2 + (ss[i] - '0');
    i++;
  }
  return sum;
}

/*********************************************************/
/* 関数名    : disp_bin(unsigned char num)               */
/* 機能説明　: 10進数を2進数として表示する               */
/* 引数　　　: unsigned char num (0-255)                 */
/* 返り値　　: void                                      */
/*********************************************************/
void disp_bin(unsigned char num) {
  int i, mask;
  for (i = 7; i >= 0; i--) {
    mask = 0x01 << i; // bit & 演算用のマスク
    printf("%d", (num & mask) >> i);
  }
  printf("\n");
}

/*********************************************************/
/* 関数名    : get_str(char ss)                           */
/* 機能説明　: キーボードからlen文字の文字を取得、       */
/*             ssに格納する                              */
/* 引数　　　: char ss[] 入力した文字を格納する配列      */
/*           : len 何文字分格納するか指定する            */
/* 返り値　　: キーボードから入力した文字数              */
/*********************************************************/
int get_str(char ss[], int len) {
  int i = 0;
  int ch = getchar();
  while (1) {
    if (ch == '\n') {
      ss[i] = '\0';
      break; //ループから抜け終了
    }
    if (i >= len) { // 10文字以上入ったら? 例)abcdefghij\0
      while (getchar() != '\n')
        ; //読み飛ばし
      return FAIL;
    } else {
      // ss[i++] = ch;  と一行で書くことも出来る
      ss[i] = ch;
      i++;
      ch = getchar();
    }
  }
  return i;
}

/*********************************************************/
/* 関数名    : get_num                                    */
/* 機能説明　: キーボードから数を取得、整数値として返す。*/
/*           : 負数対応                                  */
/* 引数　　　:                                           */
/* 返り値　　: 戻り値は数値                              */
/*********************************************************/
int get_num(int *error_flag) {
  int num = 0;
  int ch;
  int sign_flag = 1; // 正の数なら1, 負の数なら-1

  while ((ch = getchar()) != '\n') {
    if (ch == '-') {
      if (sign_flag == 1) {
        sign_flag = -1;
      } else {
        *error_flag = FAIL;
        return FAIL;
      }
    } else if (!('0' <= ch && ch <= '9')) {
      *error_flag = FAIL; //エラーを設定
      return FAIL;
    } else {
      num = num * 10 + ch - '0';
    }
  }

  *error_flag = SUCCESS;
  return sign_flag * num;
}

/*********************************************************/
/* 関数名    : get_str_num                               */
/* 機能説明　: キーボードから数を取得、文字列として返す。*/
/*             負数対応                                  */
/* 引数　　　: なし                                      */
/* 返り値　　: 戻り値は数値                              */
/*********************************************************/
int get_str_num(char num[]) {
  int ch;
  int sign_flag = 1;
  int digit = 0;
  while ((ch = getchar()) != '\n') {
    if (ch == '-') {
      if (sign_flag == 1) {
        sign_flag = -1;
        num[digit] = '-';
        digit++;
      } else {
        return FAIL;
      }
    } else if (!('0' <= ch && ch <= '9')) {
      return FAIL;
    } else {
      num[digit] = ch;
      digit++;
    }
  }
  num[digit] = '\0';
  return SUCCESS;
}

/*********************************************************/
/* 関数名    : get_float                                 */
/* 機能説明　: キーボードから浮動小数点数を取得、        */
/*             実数値として返す。負数対応                */
/* 引数　　　: なし                                      */
/* 返り値　　: 戻り値は数値                              */
/*********************************************************/
int get_float(void) {
  float number = 0.0;          // 読み込んだ実数
  char ch;                     // 一文字読み込み用
  int sign_flag = 1;           // 負数なら-1;
  int floating_point_flag = 0; // 小数点があらわれたら１
  int numeric_flag = 0;        // 数になったら１
  int fraction_part = 1;       // 小数点以下の桁数

  ch = getchar();
  if (ch == '\n') {
    return FAIL;
  } else if (ch == '-') { // 負数なら
    sign_flag = -1;
  } else if (ch == '.') {
    floating_point_flag = 1;
  } else if (isdigit(ch)) {
    fraction_part = ch - '0';
    numeric_flag = 1; //数が入力されたのでフラグを立てる
  } else {
    numeric_flag = 0;
  }

  while ((ch = getchar()) != '\n') {
    if (isdigit(ch)) {
      numeric_flag = 1;
      if (floating_point_flag != 1) {
        fraction_part = fraction_part * 10 + (ch - '0');
      } else if (floating_point_flag == 1) {
        fraction_part = fraction_part + (ch - '0') * pow(10, -fraction_part);
        fraction_part++;
      }
    } else if (ch == '.') {
      if (floating_point_flag != 1) {
        floating_point_flag = 1; //小数点フラグを立てる
        fraction_part = 1;
      } else {
        return FAIL;
      }
    } else {
      return FAIL;
    }
  }

  return sign_flag * fraction_part;
}

/*********************************************************/
/* 関数名    : get_line                                  */
/* 機能説明　: キーボードから一行入力し、ssに格納する    */
/* 引数　　　: ss 文字列格納用配列                       */
/*             string_length 何文字入力するのか          */
/* 返り値　　: なし                                      */
/*********************************************************/
void get_line(char ss[], int string_length) {
  int i = 0;
  char ch;

  while ((ch = getchar()) != '\n') {
    ss[i] = ch;
    if (i == string_length) {
      while (getchar() == '\n')
        ; // 読み飛ばす
    } else {
      i++;
    }
  }
  ss[i] = '\0'; //文字列の最後は'\0'
}

/*********************************************************/
/* 関数名    : get_day()                                 */
/* 機能説明　: キーボードから入力された文字が            */
/*             YYYYMMDD形式であるか判定する。            */
/* 引数　　　: なし                                      */
/* 返り値　　: 日付形式ならばYYYYMMDD形式でlong型で返す。*/
/*             エラーなら-1                              */
/*********************************************************/
long get_day(void) {
  long date;
  int year = 0;
  int month = 0;
  int day = 0;
  int last_day[12 + 1] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int ch;
  int i = 0; //カウンタ

  //入力
  while ((ch = getchar()) != '\n') {
    if (!isdigit(ch) || i >= 8) {
      while (getchar() != '\n')
        ;          //読み飛ばし
      return FAIL; //エラー値を返す
    }

    if (i < 4) {
      year = year * 10 + ch - '0';
      i++;
    } else if (i < 6) {
      month = month * 10 + ch - '0';
      i++;
    } else if (i < 8) {
      day = day * 10 + ch - '0';
      i++;
    }
  }

  //条件判定
  if (!(1 <= month && month <= 12)) {
    return FAIL;
  }
  if ((year % 4 == 0 && year % 100 != 100) || year % 400 == 0) {
    last_day[2] = 29; // 閏年の2月は29日まである
  }
  if (!(1 <= day && day <= last_day[month])) {
    return FAIL;
  }

  return (long)year * 10000 + (long)month * 100 + (long)day;
}
