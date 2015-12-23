= トップページを作る

第3章では共通の構造部分を作っていきました。
そこではヘッダーやフッターなどはマークアップしましたが、@<tt>{main}要素の中身は空だったと思います。
この章では@<tt>{index.html}の空のままだった@<tt>{main}要素内をHTMLでマークアップしていきます。

== main要素にトップページと分かるようなIDを付ける

はじめに@<tt>{main}要素へトップページと分かるようなIDを@<list>{toppage-main-html}のとおりに付けます。

//list[toppage-main-html][main要素にトップページと分かるようなIDを付ける]{
<main id="ll-top-page-contents">
</main>
//}

== カルーセル部分のマークアップ

カルーセル部分のマークアップをしていきます。
あらためてカルーセルの説明をするとNikeなどで使われている「注目させたい複数の画像などをつぎつぎと横にスライド表示する」ものです。

今回カルーセルの実装にslickというライブラリを使います。slick用として@<list>{carousel-html}のHTMLを用意します。
とはいっても切り替え表示させる画像を@<tt>{js-slides ll-slides}というクラスを付けた@<tt>{div}要素で囲むだけです。
接頭辞に@<tt>{js-}と付けているクラスはJavaScriptから取得することを明確にするため付けています（@<list>{carousel-html}）。

//list[carousel-html][カルーセルのHTML]{
<div class="js-slides ll-slides">
  <img src="images/image_01.jpg" alt="ラブライブ！ 2nd グランプリ μ's">
  <img src="images/image_02.jpg" alt="ラブライブ！ 1st グランプリ A-RISE">
</div>
//}

== ページネーション部分のマークアップ

カルーセルと連携したページネーション部分のマークアップをしていきます。
ページネーションを画像で示すと、@<img>{pagination}の赤丸部分になります。

//image[pagination][ページネーション（ラブライブ！第2期 1話より）© プロジェクトラブライブ！]{
//}

アニメではフッター部分に入っているページネーションですが、フッター内にページネーションを含める実装はあまり見ません。
そのため@<tt>{main}要素内へ、ページネーションを含めるようにします。

ページネーションは表示される順番が決まっているため、意図的に順序づけられた項目リストを示す@<tt>{ol}要素を使います。
ページネーションは後ほどCSSでスタイルを適用したり、JavaScriptでカルーセルと連携させたりします（@<list>{pagination-html}）。

//list[pagination-html][ページネーションのHTML]{
<ol class="js-slides-pagination ll-slides-pagination">
  <li>●</li>
  <li>●</li>
</ol>
//}

== ここまでのHTMLまとめ

トップページのHTMLについてはこれで完成です。
ここまでのHTMLをまとめると@<list>{toppage-html}のとおりになります。

//list[toppage-html][トップページのHTML]{
<main id="ll-top-page-contents">
  <div class="js-slides ll-slides">
    <img src="images/image_01.jpg" alt="ラブライブ！ 2nd グランプリ μ's">
    <img src="images/image_02.jpg" alt="ラブライブ！ 1st グランプリ A-RISE">
  </div>

  <ol class="js-slides-pagination ll-slides-pagination">
    <li>●</li>
    <li>●</li>
  </ol>
</main>
//}

== main要素の見た目を整える

HTMLによるマークアップが終わったらCSSで見た目を整えていきます。
まずトップページの@<tt>{main}要素に対し元の見た目へ近づかせるため、背景色を適用します（@<list>{main-css}）。

//list[main-css][main要素の見た目を整える]{
/* トップページ：コンテンツ */
#ll-top-page-contents {
  background-color: #dcdcdc;
}
//}

== カルーセルの見た目を整える

カルーセルに使う要素の見た目を整えます。
スタイル定義は簡単でウィンドウの描画領域が狭いときに画像をはみ出させないよう、@<tt>{max-width}というプロパティで要素幅の最大値を指定します（@<list>{carousel-css}）。

//list[carousel-css][カルーセルのCSS]{
/* トップページ：カルーセル内の画像 */
.ll-slides img {
  max-width: 100%;
}
//}

== ページネーションの見た目を整える

カルーセルと連携させるページネーションの見た目を整えます。

ページネーションのマークアップに@<tt>{ol}要素を使っているため、●の左横に数字が表示されています。
左横の数字の表示を消すために@<tt>{.ll-slides-pagination}に対して@<tt>{list-style-type: none;}と指定します。

あとはページネーションを中央寄せかつ横並びに表示したり、前景色の指定をします（@<list>{pagination-css}）。

//list[pagination-css][ページネーションのCSS]{
/* トップページ：カルーセル連携ページネーションの外枠 */
.ll-slides-pagination {
  margin: 0;
  list-style-type: none;
  text-align: center;
}

/* トップページ：カルーセル連携ページネーションの各要素 */
.ll-slides-pagination li {
  display: inline-block;
  color: #ff64b1;
}

/* トップページ：カルーセル連携ページネーションの現在のページを示す要素 */
.ll-slides-pagination .ll-active {
  color: #fff;
}
//}

=== トップページのCSS

ここまでをまとめると、@<list>{toppage-css}のCSSになります。

//list[toppage-css][トップページのCSS]{
/* トップページ：コンテンツ */
#ll-top-page-contents {
  background-color: #dcdcdc;
}

/* トップページ：カルーセル内の画像 */
.ll-slides img {
  max-width: 100%;
}

/* トップページ：カルーセル連携ページネーションの外枠 */
.ll-slides-pagination {
  margin: 0;
  list-style-type: none;
  text-align: center;
}

/* トップページ：カルーセル連携ページネーションの各要素 */
.ll-slides-pagination li {
  display: inline-block;
  color: #ff64b1;
}

/* トップページ：カルーセル連携ページネーションの現在のページを示す要素 */
.ll-slides-pagination .ll-active {
  color: #fff;
}
//}

== JavaScriptを使ってカルーセルの実装をする

トップページのHTMLマークアップやCSSによるスタイル適用が終わったので、JavaScriptを使ってカルーセルの実装をします。
@<tt>{index.html}が置いてあるディレクトリーと同じ場所に@<tt>{scripts}ディレクトリーを作り、JavaScriptファイルを@<tt>{main.js}という名前で作ります。

JavaScriptを書き始める前に、処理の流れを洗い出しておきしょう。
今回は次の流れでカルーセルやカルーセルと連携したページネーション（以下ページネーション）を実装していきます。

 1. 他のJavaScriptと競合しないようにする
 1. カルーセルのためにHTML要素を取得する
 1. カルーセルの実装をする
 1. ページネーションの実装をする
 1. カルーセルが動くようにする
 1. ページネーションが動くようにする
 1. カルーセル表示が切り替わったときの処理を設定する

処理の流れを洗い出したところで、上から順に説明します。

== 他のJavaScriptと競合しないようにする

はじめに定義した変数や関数が他のJavaScriptに干渉しないよう、JavaScriptのソースコード全体を無名関数で囲みます。
JavaScriptは宣言した変数や関数の有効範囲（スコープ）が関数単位で閉じられるため無名関数を使います。
無名関数は@<tt>{function() {\}}と書きます。ここから無名関数の全体を@<tt>{()}で囲み最後に@<tt>{()}を付けることでJavaScriptを即時実行します。
つまり@<tt>{(function() {\})();}となります。こうすると無名関数内で宣言した変数や関数が他のJavaScriptへ干渉するのを防げます。
このように無名関数で全体を囲み即時に実行する関数のことを即時関数と呼びます。

=== jQueryを使う

jQueryを使う場合は@<tt>{(function() { ... \})();}の前に@<tt>{$}を書いて最後の@<tt>{()}を削除します。
つまり@<tt>{$(function() { ... \});}となります。
@<tt>{$}を書く理由はブラウザーがHTMLを読み込んで解釈した後にJavaScriptを実行させるためです。
HTMLを解釈した後にJavaScriptの実行をしない場合、JavaScript内でHTMLの要素を取得できない可能性があります。
また最後の@<tt>{()}を削除した理由は、@<tt>{$}というのはjQueryの関数だからです。
@<tt>{$}関数の引数として関数を指定するため、最後の@<tt>{()}がいらなくなります。

=== "use strict";

@<tt>{$(function() { ... \});}の中に@<tt>{"use　strict";}という文字列を書いています。
これはJavaScriptをコーディングする上でミスしやすい部分をエラーとして検出してくれるものです。
将来に備えていくつかの単語を自由に使えなくする（たとえば@<tt>{let}や@<tt>{yield}など）効果があるため、@<tt>{"use　strict";}は書いても損はありません。

ここまでをまとめると次のソースコードになります。
上に書いたことはなかなか覚えづらいので、JavaScriptを書くときにjQueryを使う場合は@<list>{mainjs}のとおりに書くと覚えておけば大丈夫です。

//list[mainjs][他のJavaScriptと競合しないようにする]{
$(function() {
  "use strict";

  // ここにソースコードを書いていく
});
//}

== カルーセルのためにHTMLの要素を取得する

JavaScriptでHTMLの要素を扱えるようにします。
これはjQueryの@<tt>{$}関数を使って、HTMLの要素をJavaScriptから取得します。

準備の節では、ブラウザーがJavaScriptをHTMLの解釈後に実行するため@<tt>{$}関数を使いました。
ここではHTMLの要素をJavaScriptで利用できるようにするため@<tt>{$}関数を使います。
jQueryの@<tt>{$}関数はこのように万能なものとなります（@<list>{get-html}）。

//list[get-html][jQueryの$関数を使ってHTMLの要素を取得する]{
var carouselElm = $(".js-slides");
var paginationElm = $(".js-slides-pagination");
var paginationItemElms = $(".js-slides-pagination li");
//}

== カルーセルの実装をする

HTMLの要素を取得したらカルーセルの実装をしていきます。
今回カルーセルの実装をする上でslickというライブラリを使っていきます。
このslickを使えるよう初期化する関数と、いま表示しているページがどこか示すための関数を実装していきます。

まずカルーセルの元になる@<tt>{Carousel}関数から説明します。
@<tt>{Carousel}関数はパラメーターとして、次のふたつがあります。

 * カルーセルの要素を示す@<tt>{carouselElm}
 * カルーセルの設定を示す@<tt>{config}

これらのパラメーターを元に@<tt>{Carousel}関数でslickが使えるようにします。

次に@<tt>{getCurrentIndex}を説明します。これはページネーションで使う関数となります。
@<tt>{getCurrentIndex}はカルーセルでいま表示しているページがどこか示す数字を返す関数です。
この実装にはslickで定義されている@<tt>{slickCurrentSlide}という関数を使います（@<list>{implement-carousel}）。

//list[implement-carousel][slickを使ってカルーセルを実装する]{
function Carousel(carouselElm, config) {
  this.carouselElm = carouselElm;
  carouselElm.slick(config);
}

Carousel.prototype.getCurrentIndex = function() {
  return this.carouselElm.slick("slickCurrentSlide");
};
//}

カルーセルの実装が終わったところで、現在どのページを表示しているのか視覚的に分かりやすくするページネーションの実装をしていきます。

== ページネーションの実装をする

ページネーションの元になる@<tt>{CarouselPagination}関数を実装します。
@<tt>{CarouselPagination}関数ではパラメーターとして、次の3つがあります。

 * ページネーションの要素を示す@<tt>{paginationElm}
 * ページネーション内の要素を示す@<tt>{paginationItemElms}
 * アクティブなページを示す@<tt>{activePageName}

これらのパラメーターを元に@<tt>{CarouselPagination}関数でページネーションが使えるようにします。
あとはカルーセルの表示を切り替えるときに@<tt>{activatePage}関数と@<tt>{deactivatePage}関数を呼び出してページネーションの表示を変えられるようにします（@<list>{implement-pagination}）。

//list[implement-pagination][ページネーションを実装する]{
function CarouselPagination(paginationElm, paginationItemElms, activePageName) {
  this.activePageName = activePageName;
  this.paginationElm = paginationElm;
  this.paginationItemElms = paginationItemElms;
}

CarouselPagination.prototype.activatePage = function(index) {
  this.paginationItemElms[index].classList.add(this.activePageName);
};

CarouselPagination.prototype.deactivatePage = function() {
  var _this = this;

  Array.prototype.map.call(this.paginationItemElms, function(paginationItemE) {
    paginationItemE.classList.remove(_this.activePageName);
  });
};
//}

== カルーセルが動くようにする

先ほど実装したカルーセルを@<list>{run-carousel}のとおり呼び出して動くようにします。
カルーセルの設定として3項目設定します。

 * autoplay：カルーセルを自動的にページ送りするか
 * autoplaySpeed：カルーセルの自動ページ送りを何秒おきにするか
 * arrows：前・次へボタンを表示するか

//list[run-carousel][カルーセルが動くようにする]{
var carousel = new Carousel(carouselElm, {
  autoplay: true,
  autoplaySpeed: 5000,
  arrows: false
});
//}

== ページネーションが動くようにする

カルーセルと同じように、実装したページネーションを@<list>{run-pagination}のように呼び出してページネーションを動かします。
ページネーションの初期設定として、ページネーションのはじめの@<tt>{li}要素に現在アクティブであることを示すクラス名が付くようにします。

//list[run-pagination][ページネーションが動くようにする]{
var carouselPagination = new CarouselPagination(paginationElm, paginationItemElms,
"ll-active");
carouselPagination.activatePage(carousel.getCurrentIndex());
//}

== カルーセル表示が切り替わったときの処理を設定する

カルーセル表示が切り替わったときに、連動してページネーションの表示を切り替えるようにします。
この実装にはslickで定義されている@<tt>{afterChange}というイベントをjQueryの@<tt>{on}関数を使って検知できるようにします（@<list>{on-afterchange-carousel}）。

//list[on-afterchange-carousel][カルーセル表示が切り替わったときの処理]{
carouselElm.on("afterChange", function() {
  carouselPagination.deactivatePage();
  carouselPagination.activatePage(carousel.getCurrentIndex());
});
//}

== トップページのJavaScriptまとめ

これまでのJavaScriptをまとめると@<list>{toppage-javascript}のとおりになります。
次のコードでは関数などの書き順が説明した順番と違います。
しかしこの書き順で書いたほうが自分は見やすいと感じるため、あえて書き順を変えています。

//list[toppage-javascript][トップページのJavaScript]{
$(function() {
  "use strict";

  //////////////////////////////////////////////////

  function Carousel(carouselElm, config) {
    this.carouselElm = carouselElm;
    carouselElm.slick(config);
  }

  Carousel.prototype.getCurrentIndex = function() {
    return this.carouselElm.slick("slickCurrentSlide");
  };

  //////////////////////////////////////////////////

  function CarouselPagination(paginationElm, paginationItemElms, activePageName) {
    this.activePageName = activePageName;
    this.paginationElm = paginationElm;
    this.paginationItemElms = paginationItemElms;
  }

  CarouselPagination.prototype.activatePage = function(index) {
    this.paginationItemElms[index].classList.add(this.activePageName);
  };

  CarouselPagination.prototype.deactivatePage = function() {
    var _this = this;

    Array.prototype.map.call(this.paginationItemElms, function(paginationItemE) {
      paginationItemE.classList.remove(_this.activePageName);
    });
  };

  //////////////////////////////////////////////////

  var carouselElm = $(".js-slides");
  var paginationElm = $(".js-slides-pagination");
  var paginationItemElms = $(".js-slides-pagination li");

  var carousel = new Carousel(carouselElm, {
    autoplay: true,
    autoplaySpeed: 5000,
    arrows: false
  });

  var carouselPagination = new CarouselPagination(paginationElm,
  paginationItemElms, "ll-active");
  carouselPagination.activatePage(carousel.getCurrentIndex());

  carouselElm.on("afterChange", function() {
    carouselPagination.deactivatePage();
    carouselPagination.activatePage(carousel.getCurrentIndex());
  });
});
//}

トップページのスクリーンショットは@<img>{top}のとおりになります。

//image[top][完成したトップページ][scale=0.19]{
//}
