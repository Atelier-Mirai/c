/*****************************************************************************
 * sqlite3 データベースを
 * C 言語で 操作する
 *
 * 環境構築
 * http://cbbandtqb.seesaa.net/article/259881291.html
 *
 * サンプルプログラム
 * http://home.a00.itscom.net/hatada/db/sqlite/sqlite01.html
 *
 * SQLite3 ダウンロード先
 * https://www.sqlite.org/download.html
 *
 * SQLite3 を GUIで操作
 * DB Browser for SQLite
 * http://forest.watch.impress.co.jp/library/software/sqldbbrowser/
 *
 * １週間で学ぶIT基礎の基礎ITpro　忙しいあなたのためのSQL入門
 * http://itpro.nikkeibp.co.jp/article/COLUMN/20061213/256848/
 *****************************************************************************/
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

// 抽出結果が返るコールバック関数
int callback(void *not_used, int argc, char *argv[], char *column_name[]) {
  int i;
  for (i = 0; i < argc; i++) {
    printf("%-8s : %-8s\n", column_name[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0; // success
}

int main(int argc, char const *argv[]) {
  sqlite3 *db;         // データベース db へのポインタを宣言
  char *error_message; // エラーメッセージ

  // データベースファイルを開く　
  // （もしファイルがなければ新規作成する）
  int rc = sqlite3_open("stock_db.db", &db);

  // // テーブル生成SQL文
  // char *create_sql　= "create table stock(id integer not null, name text not
  // null, age integer not null)";
  // // テーブルを生成
  // rc = sqlite3_exec(db, create_sql, 0, 0, &error_message );

  // データ追加
  sqlite3_exec(db, "insert into stock values(0,'いちご',10)", 0, 0,
               &error_message);
  sqlite3_exec(db, "insert into stock values(1,'人参',20)", 0, 0,
               &error_message);
  sqlite3_exec(db, "insert into stock values(2,'サンダル',30)", 0, 0,
               &error_message);

  // stockテーブルの全項目を列挙
  rc = sqlite3_exec(db, "select * from stock", callback, 0, &error_message);

  // データベースを閉じる
  sqlite3_close(db);
}
