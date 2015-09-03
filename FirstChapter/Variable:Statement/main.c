//この講座はc言語を一度学んだことある人向けです。もしくは初心者でも高みを目指す人向けです。
//難しいと思ったりつまずいたと思ったら、他の文献を参考にしつつ理解を深めていただきたいです。


// -------------   main関数   ------------------------------
/*
 c言語や多くの言語はmain関数が最も始めに呼ばれる関数として使われる。
 すなわちmain関数はプログラムを開始したら一番最初に呼ばれる関数である。
 */

// ---------------  変数  ----------------------------------
/*
 変数とは、プログラム上で一時的に記憶したい値を保存する箱だと思えば良い。
 変数はRAM上に保存される。一般的にはPCのメインメモリである。
 (HDDではなく、メインメモリである。それに対してファイル等はHDDに記憶される。)
 c言語で変数は関数の一番始めに宣言する。
 変数には型と呼ばれるものがある。
 型の種類は主に
 整数型として、(bool), char, short, int
 実数型として、float, double
 型には大きさがありどの程度メモリを使用するかは処理系によるが、
 整数型は　(bool) < char < short < int
 実数型は float < double
 である。
 (boolに()がついているのはc言語で標準的にはサポートされていない型であるからである。)
 整数型、実数型と呼ぶように、格納される値は、(bool), char, short, intは整数。
 float, doubleは実数である。
 boolは1か0、charは文字、shortは小さい整数、intはある程度大きな整数に使う。
 しかし、今はRAMの容量も大きくなってPCを使う文にはメモリの節約は考えなくなってきた。
 そこで整数型は基本的にはintを使うことを意識しましょう。
 (charが文字に使われる理由は、文字を表現するのに適したバイト数であるからである。詳しいことを知りたければ後で調べるといいかも。)
 また、整数型にはunsignedをつけることができる。unsignedは型の負要素がないものと考えて正の要素のみで大きな値を表現することができるオプションと考えて貰えば良い。
 */

//----------------  文  ------------------------------------
/*
 プログラムは基本的に文と呼ばれる命令を並べて書いていく。
 文は基本的には1行であり文の終わりにはセミコロン(;)をつける。
 また、ブロックという形で文を表現することもできる。
 中かっこ({})で囲まれた命令は1つの文と考えても過言でない。
 (後で紹介するが、関数もまた呼び出し側では文となる。)
 cはオブジェクト指向言語ではない。
 簡単なデータ構造を便利な関数群を使って処理させていくというアプローチを取る。
 文を使って関数を作り、それをまた新しい文として利用する。すなわち、文で文を綺麗に作っていくのが良いコーディングである。
 */

//----------------  基本構文  ---------------------------------
/*
 多くのプログラミング言語でも存在するが、cには関数ではない基本的な構文のようなものが存在する。
 それが、条件分岐文(if/if else/else文)、繰り返し文(do while文、while文、for文)である。
 この基本構文についてはコードを参考にして探検することで覚えて欲しい。
 それから、命令ではない文はコメント文と言って
 //の後や */
 /*と*/
/*で囲むようにする。
 */


//実際にコードを書いてみる。

//#include "stdio.h" はコマンドプロンプト/shellなどからの入出力をサポートするライブラリを導入する、リンカに対する指令だと思えば良い。
#include "stdio.h"

int main() {
  unsigned int i; //負の要素なしの整数型intの宣言 セミコロンで終わるのでこれも文である。
  double d; //実数型doubleの宣言。
  i = 100; //変数への代入 iに100を入れる。(100 = iという記述はダメ、左のものに右のものを格納すると考える)
  d = 10.1;
  
  if (i==100) { //もしiが100なら直下の文を実行する。という条件文 イコールは==で書く。
    printf("hello world.\n"); //iは100であるからこれが実行される。
  } else if(i > 100) { //上の条件文を満たさない時、もしiが100より大きければ、直下の文を実行する
    printf("こちらは実行されません。\n");
  } else { //どの条件にも満たさない時、直下の文を実行する
    printf("こちらも実行されません。\n");
  }
  
  do { //条件を見る前に文を実行する。
    printf("do while\n");
    d = d - 1.0;
  } while (d >= 0 && d <= 10); //この条件を満たす間はまたdo文を実行する。
  
  d = 10.1;
  
  while (d >= 0 && d <= 10) { //始めに条件を見て、この条件を満たす間直下の文を繰り返す。
    printf("while\n");
    d = d - 1.0;
  }
  
  for (/* 初期処理 */i=0; /* 条件 */i<10; /* 後処理 */i++) {
    printf("for %d\n", i);
  }
  
  return 0;
}