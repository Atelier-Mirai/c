
= コンピュータの仕組み


コンピュータって、どんな仕組みになっていて動くのでしょう。今回は、コンピュータを形作る機械部分（ハード）とそれを動かす命令群（ソフト）、そして命令を作るプログラミング言語についての紹介です。


== ハード編


ハードとは、hardware。英語を直訳すると、「硬い物」＝「パソコンを構成する様々な機器」のことです。  


=== ＣＰＵ


  Central（中央） Processing（処理） Unit（装置）の略。
  パソコンの頭脳で、様々な命令を処理します。
  キーボードから、どのキーが押されたか？ 画面のどこにどういう色を出すのか？ など、いろいろな計算をしたり、絵を描いたり、みんなコンピュータにとっては命令です。



  人に喩えると、「頭」の部分です。



  CPUを作っている会社として、米国インテル社が有名です。
  CPUの速さの単位はGHz(ギガヘルツ)です。
  1GHzのCPUの場合、1秒間に10億回の足し算・引き算ができます。
  速ければ速いほどいいですが、最近のパソコンは性能が上がってきています。@<br>{}
  動画や画像処理、３Ｄゲーム等の用途であればともかく、ワープロやインターネットをするには、どれでも同じです。@<br>{}
  中古を購入する場合であれば、ここ2，3年以内のものがお薦めです。


=== メモリ


  メモリは、記憶（memory）です。@<br>{}
  CPUへの様々な命令を蓄えておいたり、CPUが命令を実行する際に必要となるデータを蓄えておく場所です。



  人に喩えると、「作業机」です。@<br>{}
  単位は、GB(ギガバイト)。８ＧＢか１６ＧＢあると快適です。  


=== ストレージ


  SSD(ソリッドステートドライブ)やHDD(ハードディスクドライブ)の総称です。



  いろいろなプログラムやデータを保存する場所です。@<br>{}
  人にたとえると、「倉庫」です。  



  SSDは記憶装置として半導体素子メモリを用いた補助記憶装置です。@<br>{}
  HDDは磁性体を塗布した円盤を高速回転し、磁気ヘッドを移動することで、情報を記録し読み出す補助記憶装置です。@<br>{}
  SSDは、HDDに比べると、物理的な稼働箇所がないため、読み出し書き込みの速度が速く、また省電力で静かです。反面HDDに比べると少し割高です。  (Wikipediaより)  



  iPhone/iPadでは、SSDが使われています。単位はＧＢ（ギガバイト）。64GBが主流です。  



  テレビを録画するためには、価格が安いことからハードディスクが用いられています。単位はＴＢ（テラバイト）。１ＴＢでおおよそ２４時間録画したとして９日分の動画を保存できます。  


=== 光学ドライブ


  ＣＤやＤＶＤドライブの総称です。
  インターネットの普及に伴い、ソフトや動画、音楽はダウンロードして愉しむものとなりましたが、昔のパソコンには標準で装備されていました。@<br>{}
  ＣＤやＤＶＤの読み取りや書き込みをする際に用います。


=== マザーボード


  以上の、ＣＰＵ、メモリ、ストレージ、光学ドライブを取り付けるための基盤です。
  これにケースと電源を追加すれば、パソコンのできあがりです。


= ソフト編


  「コンピュータ、ソフトなければ、ただの箱」といいますね。@<br>{}
  ソフト（software）は、ハードウェアに対して用います。



  一般に使われているソフトという言葉の意味は、「コンピュータである機能を実現するための命令を集めたもの」という意味合いで使われています。パソコンソフトはこういった意味です。@<br>{}
  より広い意味では、パソコンを使いこなす知識やノウハウをも含めた意味で用います。



  それでは、狭い意味でのソフトを扱っていきましょう。@<br>{}
  ソフトは、大別すると、ＯＳとアプリケーションソフトに分けられます。  


== ＯＳ（OperatingSystem）


  OSとは、オペレーティング・システムの略です。パソコンを動かすために基本となる様々な機能を担当しているソフトで、そのため基本ソフトとも呼ばれます。



  具体的には、@<br>{}
1. メモリやディスク、入出力や周辺機器などのハードウェアの管理を行う。@<br>{}
2. 利用者（ユーザー）がパソコンを操作するためのプログラム（ユーザーインターフェース）の提供する。
3. ファイルを開いたり、画面に表示したりなど、どのアプリケーションソフトにも共通する処理を、それぞれのアプリケーションソフトに提供する。



  などの機能を提供しています。



macOS や iOS, UNIX（ユニックス）/Linux（リナックス）, Windows（ウィンドウズ）などがあります。


== アプリケーションソフト


  アプリケーションソフトとは、コンピュータを使って特定の目的を果たすために作られたソフトウェアのことです。 オペレーティングシステムなどの基本ソフトウエアに対して、 応用ソフトウエアとも呼ばれます。



  具体的には、
  ワープロソフト、表計算ソフト、ブラウザやメールソフト、
  お絵かきソフト、家計簿ソフト、ゲームソフトなどなどです。



  プログラム開発に用いるエディタやコンパイラなども、アプリケーションソフトです。


== プログラミング言語


コンピュータはよく人に喩えられます。中国語では「電脳」といいます。@<br>{}
コンピュータは、原理的には、人の論理的な思考のすべてが可能です。  



コンピュータの特色は、@<br>{}
* 高速に計算できる！！（一秒間に数十億回も！！）@<br>{}
* 繰り返しが得意！！（１日でも１年でも飽きることなく同じことを繰り返します）@<br>{}
* 博覧強記！！（絶対忘れません！！）@<br>{}
* 命令どおりに動く（逆に言うと、気を回したり機転を利かすことはできないのですが、膨大な計算の結果、ＡＩ（人工知能）は人間らしく見えます）  



コンピュータに、何かさせたいと思ったら、命令をする必要があります。@<br>{}
例えば、

 * ３＋８を計算せよ
 * 半径３ｃｍの赤い円を描け
 * 440 Hz(ラ) の音を出せ



などです。どうやったら命令できるのでしょう？@<br>{}
人間がコンピュータに命令を指示するために作られた言語が、プログラミング言語です。@<br>{}
よく使われているところでは、Ruby（ルビー）、C（シー）、Java（ジャバ）などがあります。
Wikipediaに分かりやすく説明がありますのでお読み下さい。@<href>{https://ja.wikipedia.org/wiki/プログラミング言語,プログラミング言語}


=== Ruby


Ruby（ルビー）は、まつもとゆきひろ（通称 Matz）により開発されたオブジェクト指向スクリプト言語です。日本で開発されたプログラミング言語として初めて国際電気標準会議で国際規格に認証されました。
開発者のまつもとゆきひろは、「Rubyの言語仕様策定において最も重視しているのはストレスなくプログラミングを楽しむことである (enjoy programming)」と述べています。(Wikipediaより)



Web界隈で広く使われており、フレームワーク @<b>{Ruby on Rails} も有名です。



たとえば、１から１０までの合計の数を求めるには、


//emlist[][ruby]{
  answer = 0
  (1..10).each do |n|
      answer += n
  end
  print answer
//}


と書くとanswer 55が求められます。


=== Ｃ言語


略してＣ（しー）。FORTRANなどのプログラミング言語に比べて、効率がよく、より機械に近いところまで書き表すことができることから、主流となり、UNIXにおける標準開発環境です。


//emlist[][c]{
  int n;
  int answer = 0;
    for(n = 1; n <= 10; n++){
        answer += n;
    }
  printf("%d\n", answer);
//}


同じ、１から１０までの合計を求めるプログラムですが、何となく、違いが感じられますか？


=== Java


Java(ジャバ)は組み込みシステムや携帯機器（携帯電話・PHSやPDA・スマートフォン等）のシステムから、企業の情報システムを担う大規模なデータベース、サーバ、スーパーコンピュータまで、多くの分野で使用されている。(Wikipediaより)


//emlist[][Java]{
  int answer = 0;
  for(int n = 1; n <= 10; n++){
    answer += n;
  }
  System.out.println("%d\n", answer);
//}