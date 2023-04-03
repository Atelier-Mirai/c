= データベース

== 在庫管理システム

@<href>{https://ja.wikipedia.org/wiki/ウォーターフォール・モデル,ウォーターフォール・モデル}


ウォーターフォール・モデルは、ソフトウェア工学では非常に古くからある、もっともポピュラーな開発モデル。


//quote{
  プロジェクトによって工程の定義に差はあるが、開発プロジェクトを時系列に、「要求定義」「外部設計（概要設計）」「内部設計（詳細設計）」「開発（プログラミング）」「テスト」「運用」などの作業工程（局面、フェーズ）にトップダウンで分割する。線表（ガントチャート）を使用してこれらの工程を一度で終わらせる計画を立て進捗管理をする。原則として前工程が完了しないと次工程に進まない（設計中にプログラミングを開始するなどの並行作業は行わない）事で、前工程の成果物の品質を確保し、前工程への後戻り（手戻り）を最小限にする。ウォーターフォール・モデルの利点は、工程の進捗管理がしやすいことである。
//}

 * 在庫管理システム

//list[][][file=source/lecture_extra/stock_db.txt,1]{
//}
//list[][][file=source/lecture_extra/stock_managing_system.c,1]{
//}

 * 構造体の並び替え

//list[][][file=source/lecture_extra/stock_sort.c,1]{
//}

== データベース

@<href>{https://ja.wikipedia.org/wiki/データベース,データベース}

//quote{
  データベース（英: database, DB）とは、検索や蓄積が容易にできるよう整理された情報の集まり。 通常はコンピュータによって実現されたものを指すが、紙の住所録などをデータベースと呼ぶ場合もある。 狭義には、データベース管理システム (Database Management System, DBMS) またはそれが扱う対象のことをいう。(Wikipediaより)
//}


@<href>{https://ja.wikipedia.org/wiki/CRUD,CRUD}

//quote{
  CRUD（クラッド）とは、ほとんど全てのコンピュータソフトウェアが持つ永続性[1]の4つの基本機能のイニシャルを並べた用語。その4つとは、Create（生成）、Read（読み取り）、Update（更新）、Delete（削除）である。ユーザインタフェースが備えるべき機能（情報の参照/検索/更新）を指す用語としても使われる。(Wikipediaより)
//}


@<href>{https://ja.wikipedia.org/wiki/ACID_(コンピュータ科学),ACID}

//quote{
  ACIDとは、信頼性のあるトランザクションシステムの持つべき性質として1970年代後半にジム・グレイが定義した概念で、これ以上分解してはならないという意味の原子性（英: atomicity、不可分性）、一貫性（英: consistency）、独立性（英: isolation）、および永続性（英: durability）は、トランザクション処理の信頼性を保証するために求められる性質であるとする考え方である。(Wikipediaより)
//}



== SQLite


様々なデータベースがあります。
ここでは、初心者向けに学習しやすいSQLiteをご紹介します。


@<href>{http://www.dbonline.jp/sqlite/,SQLite入門}   (http://www.dbonline.jp/sqlite/) で学習されて下さい。

== SQL文 サンプル

//output[][]{
select * from stock;
select name from stock;
select * from stock order by quantity;
select * from stock order by quantity desc;
select * from stock where quantity > 100;
select * from stock where id >= 300 and quantity > 0;
select * from stock where id >= 300 and quantity > 0 order by quantity desc;
select * from stock where name like "%卵%";
select * from stock where name like "卵%";
select * from stock where name like "%卵";
select * from stock;

-- insert into stock values(400, "キャベツ", 123);
-- insert into stock values(401, "白菜", 234);
select * from stock;

-- insert into stock(name, quantity) values("玉ねぎ", 345);

select * from stock where id > 400;

-- INSERT INTO stock DEFAULT VALUES;

select * from stock;

--UPDATE stock SET quantity = 50 WHERE id = 400;
-- select * from stock where id = 400;

-- UPDATE stock SET name = "愛知県産キャベツ" WHERE id = 400;
-- select * from stock where id = 400;

--UPDATE stock SET quantity = 100 WHERE id = 400;
--UPDATE stock SET quantity = 1000;

--DELETE FROM stock WHERE id=300;
DELETE FROM stock;
select * from stock;

insert into invoice(company, tel) values("田中産業", "03-xxxx-xxxx");
insert into invoice(company, tel) values("丸八青果", "06-xxxx-xxxx");
insert into invoice(company, tel) values("伊藤農園", "052-xxxx-xxxx");

select * from invoice;
//}

== C言語でのデータベース操作例

//list[][][file=source/lecture_extra/sqlite3_sample.c,1]{
//}
