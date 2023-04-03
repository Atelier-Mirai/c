= C言語

//abstract{
組み込み系やOSを中心に様々なところでＣ言語は使われています。
//}

#@# * [環境構築](contents/environment.md)
#@# * [Ｃ言語とは](contents/history_of_c.md)
#@# * [データ型](contents/data_type.md)
#@# * [書式指定子](contents/format_type.md)
#@# * [コラム](contents/column.md)
#@#   * [コンピュータを創った人々](contents/scientist.md)
#@#   * [コンピュータの仕組み1](contents/structure_of_the_computer.md)
#@#   * [コンピュータの仕組み2](contents/structure_of_the_computer2.md)
#@#   * [コンピュータ５大機能と動作原理](contents/computer_and_programming1.md)
#@#   * [プログラム開発の手順](contents/computer_and_programming2.md)
#@#   * [アルゴリズム＋データ構造](contents/algorithm.md)
#@#   * [単位のお話](contents/talk_unit.md)
#@#   * [画素の話](contents/picture.md)
#@#   * [タッチタイピング](contents/touch_typing.md)
#@#   * [ショートカットキー](contents/shortcut.md)
#@#   * [Unix コマンド](contents/unix_command.md)


== 暮らしに生きるコンピュータ

== コンピュータを作った人

== Ｃ言語とは


== 開発環境の整備

それでは、Ｃ言語でのプログラミングを始めていきましょう。

そのためには、開発のための環境を整備する必要があります。
まず必要なものは「コンピュータ」です。
Mac がお勧めですが、Windows, Linux など、適宜お使いください。

次にクラウド上でプログラミングするか、ローカル環境でプログラミングするか、大きく二つに分かれます。
ブラウザを開いてお手軽に作成できる @<href>{https://paiza.io/ja/projects/new,paiza.io} は、本書のような入門用のプログラミングには最適です。より学習が進み、本格的に開発するための環境としては @<href>{https://aws.amazon.com/jp/cloud9/,AWS Cloud9} などがあります。

また、ご自身のコンピュータに、エディタやＣ言語のコンパイラをインストールし、ローカル環境で開発する方法もございます。エディタとしては、Atom, Zed, VS Code などを、Ｃコンパイラとしては gcc や MinGW などがございます。公式サイトや先達の方々が記されたサイト等を参考に適宜環境整備なさってください。

それでは、初めてのプログラミング、始めていきましょう。



== 初めてのプログラム


Hello World!!
プログラムの扉を開きましょう。
ようこそ、世界！！



//list[][][file=source/lecture1/hello.c,1]{
//}


== データ型
== 書式指定子



== 繰り返し処理

=== プログラムを構成する３つの要素
 * 逐次・順次
 * 反復・繰り返し
 * 判断・条件分岐



C言語には反復のために、３つの構文が用意されています。
 * for文
 * while文
 * do-while文



while文が基本です。



for文      繰返し回数が分かっている時
while文    繰返し回数が不明の時 (前判定)
do-while文 　　　　　　　　　　 (後判定)



//list[][][file=source/lecture2/loop.c,1]{
//}


== break / continue


//list[][][file=source/lecture2/break_continue.c,1]{
//}


== 条件分岐

条件分岐のための構文として、
* if 文
* switch 文
が用意されています。



//list[][][file=source/lecture3/vegetable.c,1]{
//}


== 配列


配列は、基本的なデータ構造です。



いくつもの変数を纏めて取り扱えると、繰り返し処理などで活用することが出来、とっても便利です。

 * 一次元配列
//list[][][file=source/lecture3/score1.c,1]{
//}
 * 二次元配列
//list[][][file=source/lecture3/score2.c,1]{
//}


== 文字列


C 言語では、文字列は、文字の配列として扱います。



//list[][][file=source/lecture3/string.c,1]{
//}


== ファイルの取り扱い・文字の検索


ファイルの各種モード

//table[tbl1][]{
モード	文字列	補足説明
-----------------
読み取りモード	@<tt>{"r"}	ファイルが存在しなければエラー
書き込みモード	@<tt>{"w"}	ファイルが存在しなければ新規作成。ファイルが存在すれば上書き
追記モード	@<tt>{"a"}	ファイルが存在しなければ新規作成。ファイルが存在すれば追記
//}

== 宣言など

//list[][][file=source/lecture4/file_handling.c,1]{
//}

== ファイルの読み込み

//list[][][file=source/lecture4/file_handling.c,1]{
//}

== ファイルの書き込み


//list[][][file=source/lecture4/file_handling.c,1]{
//}

== 得点ファイルを読み込んで、合計点・平均点を求める


//list[][][file=source/lecture4/file_score.c,1]{
//}


== 文字の検索


詳細なアルゴリズム解説付
//list[][][file=source/lecture4/string_find.c,1]{
//}



関数化
//list[][][file=source/lecture4/string_find2.c,1]{
//}


== 文字の置換


//list[][][file=source/lecture4/string_replace.c,1]{
//}


== ファイルでの文字の検索


//list[][][file=source/lecture4/file_find.c,1]{
//}


== ポインタ

@<href>{https://www.amazon.co.jp/dp/4774111422/,C言語ポインタ完全制覇-標準プログラマーズライブラリ}
に詳細が記載されているので、読むと良いです。


== ポインタの基礎


//list[][][file=source/lecture5/pointer.c,1]{
//}
//list[][][file=source/lecture5/pointer2.c,1]{
//}
//list[][][file=source/lecture5/pointer3.c,1]{
//}
//list[][][file=source/lecture5/pointer4.c,1]{
//}
//list[][][file=source/lecture5/pointer5.c,1]{
//}


== ポインタと関数


//list[][][file=source/lecture5/p_and_f.c,1]{
//}
//list[][][file=source/lecture5/p_and_f2.c,1]{
//}
//list[][][file=source/lecture5/p_and_f3.c,1]{
//}


#@# == ポインタのポインタ（ダブルポインタ）
#@#
#@#
#@# @<href>{http://www9.plala.or.jp/sgwr-t/c/sec10-4.html,こちら}にも詳細な説明があります。
#@#
#@#
#@#
#@# //list[][][file=source/lecture5/double_pointer.c,1]{
#@# //}
#@#

== 棒取りゲーム

=== 様々な演算子


C 言語には様々な演算子が用意されています。


@<href>{http://www.bohyoh.com/CandCPP/C/operator.html,演算子一覧表}

 * 演算子を用いたプログラムの例

//list[][][file=source/lecture6/bin_game.c,1]{
//}

== 構造体の基本
名前、年齢などのように異なるデータ型を、一緒に扱いたい場合があります。
文字「列」型や整数型の様に、「利用者」型があったら便利です。<br>
char型やint型は、C言語標準で用意されていた型ですが、プログラマが、新しい「型」を創造することも可能です。<br>
既存のデータ型を組み合わせて作られた新しい「型」のことを、「構造体」と呼びます。
//list[][][file=source/lecture_structure/structure.c,1]{
//}
//list[][][file=source/lecture_structure/structure2.c,1]{
//}
//list[][][file=source/lecture_structure/structure3.c,1]{
//}
//list[][][file=source/lecture_structure/structure4.c,1]{
//}


== 四角形型の構造体
iPhone では画面表示にrectangle型を用いたプログラミングが可能です。
ここでは、そのイメージを示します。
//list[][][file=source/lecture_structure/structure_iphone_rectangle.c,1]{
//}


== 三角形の面積 (ヘロンの公式)
//list[][][file=source/lecture_structure/structure_triangle.c,1]{
//}


== マージソート
プログラム = アルゴリズム + データ構造

ここでは、データ構造として、連結リストを紹介します。
また、アルゴリズムとして、マージソートを紹介します。

@<href>{https://ja.wikipedia.org/wiki/連結リスト,連結リスト}

//quote{
  連結リスト（Linked list）は、最も基本的なデータ構造の1つである。
  一連のノードが、任意のデータフィールド群を持ち、1つか2つの参照（リンク）により次（および前）のノードを指している。連結リストの主な利点は、リスト上のノードを様々な順番で検索可能な点である。連結リストは自己参照型のデータ型であり、同じデータ型の別のノードへのリンク（またはポインタ）を含んでいる。連結リストは場所が分かっていれば、ノードの挿入や削除を定数時間で行うことができる。連結リストにはいくつかの種類があり、片方向リスト、双方向リスト、線形リスト、循環リストなどがある。(Wikipediaより)
//}

@<href>{https://ja.wikipedia.org/wiki/マージソート,マージソート}

//quote{
  マージソートは、ソートのアルゴリズムで、既に整列してある複数個の列を1個の列にマージする際に、小さいものから先に新しい列に並べれば、新しい列も整列されている、というボトムアップの分割統治法による。大きい列を多数の列に分割し、そのそれぞれをマージする作業は並列化できる。(Wikipediaより)
//}

=== 連結リスト
//list[][][file=source/lecture_extra/linked_list.h,1]{
//}
//list[][][file=source/lecture_extra/linked_list.c,1]{
//}

=== マージソート
//list[][][file=source/lecture_extra/merge_sort.c,1]{
//}
