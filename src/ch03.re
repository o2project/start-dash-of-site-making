
= トップページ・ライブステージページ共通の構造を作る


いよいよ、サイトを作っていきます。
まずはサイト共通の構造を今回作るトップページとライブステージから洗い出し、それをマークアップしていきます。


== 共通の構造を洗い出し


トップページやライブステージのアニメ画像キャプチャから共通構造を抜き出すと、次に挙げる3つが共通構造となります。

 * ヘッダー
 * グローバルナビゲーション
 * フッター


これら共通構造にサイトの各ページへたどれるリンクを置くことで、どのページからもサイト内にあるページへ行くことができます。
そのため、今回のような多岐に渡る情報を提供するサイトでは、ヘッダー・グローバルナビゲーション・フッターの3つがだいたいあります。



また、ヘッダー・グローバルナビゲーション・フッターを使ったサイト構成は多く見られるため、訪問者も見慣れていることが期待できます。
つまりどこに主となる情報があり、ナビゲーションはどこにあるか、初めてサイトへ来た人にも分かってもらえるという効果も期待できます。



特に今回は主に見てもらいたい層として、スクールアイドルというコンピューター・リテラシーが一定ではない人たちのため、分かりやすさ重視にしたと思われます。



//image[lovelive-screenshot-top][サイトトップ（ラブライブ！第2期 1話より）© プロジェクトラブライブ！]{
//}

//image[lovelive-screenshot-livestage][ライブステージページ（ラブライブ！第2期 3話より）© プロジェクトラブライブ！]{
//}



== ファイル構成


今回作成するサイトのファイル構成を考えていきます。
ファイル構成は次のとおりとなります。@<tt>{index.html}はトップページ、@<tt>{livestage.html}はライブステージ用のHTMLとなります。
ディレクトリーとしては@<tt>{external}・@<tt>{styles}・@<tt>{scripts}・@<tt>{images}の4つがあり、その中に各ファイルを置く想定です。


//emlist{
/
├- index.html
├- livestage.html
├- external
├- styles
│  └ main.css
├- scripts
│  └ index.js
└- images
   ├- image_01.jpg
   └- ...
//}


各ディレクトリーには、以下の規則に則ってファイルを置きます。

 * external
 ** CSS・JavaScript問わず、ライブラリを置くディレクトリ
 * styles
 ** CSSファイルを置くディレクトリ
 * scripts
 ** JavaScriptファイルを置くディレクトリ
 * images
 ** 画像ファイルを置くディレクトリ

== 基本構造のマークアップ


それでは実際にHTMLでサイトの構造を作っていきます。
はじめに@<tt>{DOCTYPE}というものを書きます。この@<tt>{DOCTYPE}ですが、過去の経緯から書くことが必須となっています。



続く@<tt>{html}要素内には@<tt>{head}要素と@<tt>{body}要素が含まれます。
@<tt>{head}要素内には@<tt>{title}要素や@<tt>{meta}要素でサイト情報を書いていきます。
また、CSSやJavaScriptの読み込みも@<tt>{head}要素内でおこないます。



@<tt>{body}要素内にはこのページの主となるものを書いていきます。
現在は@<tt>{main}要素のみ用意しています。この要素はサイトの主要な内容を示すものとなります。



なお@<tt>{main}要素で@<tt>{role}属性の値に@<tt>{main}を指定していますが、これは@<href>{http://caniuse.com/#feat=html5semantic,IE11がmain要素をサポートしていない}ためです。
そのため@<tt>{role}属性で@<tt>{main}を指定して、サイトの主要な内容だということをIE11にも伝える意図で指定しています。



このHTMLを基礎として、肉付けしていきます。


//emlist[][html]{
<!DOCTYPE html>
<html lang="ja">
<head>
  <meta charset="UTF-8">
  <title>LoveLive! 2nd トーナメント</title>
  <meta name="description" content="ラブライブ！の参加者募集サイトです">
  <meta name="keywords" content="ラブライブ,特設サイト">
  <meta name="viewport" content="width=device-width">
  <link rel="stylesheet" href="external/Nico/bootstrap.min.css">
  <link rel="stylesheet" href="styles/main.css">
  <script src="external/lory/lory.min.js" defer></script>
</head>

<body>
<main>
</main>
</body>
</html>
//}

== ヘッダーのマークアップ


基礎部分のマークアップが終わったので、次にヘッダーをマークアップしていきます。
ヘッダーにはサイトのタイトルロゴと、メールマガジンやSNS、ヘルプなどのリンクがあります。



今回はCSSライブラリとして、BootstrapのテーマであるNicoを使っているため、各要素の@<tt>{class}属性にBootstrapで定義されているクラス名を定義します。



なお今回作らないページについては、図のように@<tt>{a}要素の@<tt>{href}属性に@<tt>{#}を入れておきます。
こうすることで、作っていないページを検索するとき、検索が楽になることを狙っています。



またBootstrapにはないクラス名を定義する際、図のように@<tt>{ll-}という接頭辞を付けています（@<strong>{l} ove @<strong>{l} ive）。
これはBootstrapで定義されているクラス名と競合しないように、安全策で接頭辞を付けています。


//emlist[][html]{
<header id="ll-header" class="navbar navbar-default">
  <div class="container-fluid">
    <div class="navbar-header">
      <h1 class="navbar-brand ll-logo">LoveLive!</h1>
    </div>

    <ul class="nav navbar-nav navbar-right">
      <li><a href="#">Mail magazine</a></li>
      <li><a href="#">SNS</a></li>
      <li><a href="#">Share</a></li>
      <li><a href="#">Help</a></li>
    </ul>
  </div>
</header>
//}

//emlist[][html]{
<a href="#">Mail magazine</a>
//}

//emlist[][html]{
<h1 class="navbar-brand ll-logo">LoveLive!</h1>
//}

== グローバルナビゲーションのマークアップ


ヘッダーの次はグローバルナビゲーションをマークアップしていきます。
グローバルナビゲーションは、サイト内の主要なページへリンクしているものです。



はじめに、nav要素で全体を囲みます。nav要素は主要なページへリンクしている箇所で使われる要素となります。
そして、各要素の@<tt>{class}属性にはBootstrapで定義されているクラス名を定義します。
先ほどと同じく、今回作らないページについては、図のように@<tt>{a}要素の@<tt>{href}属性に@<tt>{#}を入れておきます。



また、現在見ているページを示すためのクラス名として、Top部分に@<tt>{ll-active}というクラス名を付けています。
@<tt>{ll-active}内でBootstrapが@<tt>{active}に対してスタイル定義しているところを上書きします。


//emlist[][html]{
<nav id="ll-nav" class="navbar navbar-inverse">
  <div class="container-fluid">
    <ul class="nav navbar-nav">
      <li class="active ll-active"><a href="/">Top</a></li>
      <li><a href="livestage.html">Live stage</a></li>
      <li><a href="#">Outline</a></li>
      <li><a href="#">Schedule</a></li>
      <li><a href="#">Special</a></li>
      <li><a href="#">Link</a></li>
      <li><a href="#">Faq</a></li>
    </ul>
  </div>
</nav>
//}

== フッターのマークアップ


ヘッダー、グローバルナビゲーションと来たので、最後にフッターをマークアップしていきます。
ここには著作権情報やプライバシーポリシー、サイトマップといったリンクを追加します。



また、アニメの画像キャプチャを見ると、フッター部分には「●○○○○」のような表示があります。
これはページネーションといわれる、ある要素内にどれだけの要素が内包されているかを示すものです。
しかし、フッター内にページネーションを含めるのは一般的でないため、特にマークアップしません。


//emlist[][html]{
<footer id="ll-footer" class="navbar navbar-default">
  <div class="container-fluid">
    <p class="nav navbar-text navbar-left">
      このサイトは<a href="http://startdash.o2p.jp/">サイト制作のSTART:DASH!!</a>用に作られたものであり、プロジェクトラブライブ！とは関係ありません。
    </p>

    <ul class="nav navbar-nav navbar-right">
      <li><a href="#">Privacy policy</a></li>
      <li><a href="#">Sitemap</a></li>
    </ul>
  </div>
</footer>
//}

== HTMLのまとめ


ここまでをまとめると、次のHTMLになります。


//emlist[][html]{
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>LoveLive! 2nd トーナメント</title>
  <meta name="description" content="ラブライブ！の参加者募集サイトです">
  <meta name="keywords" content="ラブライブ,特設サイト">
  <meta name="viewport" content="width=device-width">
  <link rel="stylesheet" href="external/Nico/bootstrap.min.css">
  <link rel="stylesheet" href="styles/main.css">
  <script src="external/lory/lory.min.js" defer></script>
</head>

<body>
<header id="ll-header" class="navbar navbar-default">
  <div class="container-fluid">
    <div class="navbar-header">
      <h1 class="navbar-brand ll-logo">LoveLive!</h1>
    </div>

    <ul class="nav navbar-nav navbar-right">
      <li><a href="#">Mail magazine</a></li>
      <li><a href="#">SNS</a></li>
      <li><a href="#">Share</a></li>
      <li><a href="#">Help</a></li>
    </ul>
  </div>
</header>

<nav id="ll-nav" class="navbar navbar-inverse">
  <div class="container-fluid">
    <ul class="nav navbar-nav">
      <li class="active ll-active"><a href="/">Top</a></li>
      <li><a href="livestage.html">Live stage</a></li>
      <li><a href="#">Outline</a></li>
      <li><a href="#">Schedule</a></li>
      <li><a href="#">Special</a></li>
      <li><a href="#">Link</a></li>
      <li><a href="#">Faq</a></li>
    </ul>
  </div>
</nav>

<main>
</main>

<footer id="ll-footer" class="navbar navbar-default">
  <div class="container-fluid">
    <p class="nav navbar-text navbar-left">
      このサイトは<a href="http://startdash.o2p.jp/">サイト制作のSTART:DASH!!</a>用に作られたものであり、プロジェクトラブライブ！とは関係ありません。
    </p>

    <ul class="nav navbar-nav navbar-right">
      <li><a href="#">Privacy policy</a></li>
      <li><a href="#">Sitemap</a></li>
    </ul>
  </div>
</footer>
</body>
</html>
//}


スクリーンショットは次のとおりになります。
Bootstrapを読み込んだ上で、Bootstrapに定義されているクラス名を@<tt>{class}属性へ適宜書いていたため、殺風景ではない見た目になっています。
ただし、見た目がアニメのキャプチャ画像と違うところがあるため、CSSで微調整をしていきます。



//image[common-html][HTMLだけで作ったサイト]{
//}



== ヘッダーの見た目をよくする


はじめに、CSSでヘッダーの下部にある隙間を無くします。
これは@<tt>{margin-bottom: 0;}とするだけで下部の隙間がなくなります。



また、間延びしたようなスタイルとなっているロゴ部分のスタイルを調整します。
これは要素の高さ調整と、@<tt>{margin}・@<tt>{padding}を使って要素内外にある隙間を調整すれば、間延びした見た目ではなくなります。


//emlist[][css]{
/* サイトのヘッダー */
#ll-header {
  margin-bottom: 0;
}

/* サイトのロゴ */
#ll-header .ll-logo {
  height: auto;
  margin-top: 15px;
  padding: 15px;
}
//}

== グローバルナビゲーションの見た目をよくする


次に、グローバルナビゲーションへスタイルを適用します。
グローバルナビゲーションは、Bootstrapのスタイル定義をそのまま使った場合、高さがそれなりにあります。
これをラブライブ参加者募集サイトの見た目に合わせるため、@<tt>{min-height: 0;}と指定して、グローバルナビゲーションの高さを狭めておきます。



また今回のラブライブ参加者募集サイトは、全て大文字でグローバルナビゲーション内の文字が書かれています。
そのためグローバルナビゲーション内の各要素に対し、@<tt>{text-transform: uppercase;}と指定して、グローバルナビゲーション内の文字を全て大文字にします。
他のスタイル定義に関しては、Bootstrapで定義されているスタイルを打ち消すための指定となります。


//emlist[][css]{
/* サイトのグローバルナビゲーション */
#ll-nav {
  min-height: 0;
  margin-bottom: 0;
  border-width: 0;
}

/* サイトのグローバルナビゲーション内の各アイテム */
#ll-nav li {
  margin-right: 0;
}

/* サイトのグローバルナビゲーション内の各リンク */
#ll-nav li > a {
  margin-top: 0;
  margin-bottom: 0;
  border-radius: 0;
  color: #fff;
  text-transform: uppercase;
}
/* 横幅が768px以上のときの設定 */
@media (min-width: 768px) {
  #ll-nav li > a {
    padding: 0.75em 5em;
    border-right: 1px solid #fff;
  }

  #ll-nav li:first-child > a {
    border-left: 1px solid #fff;
  }
}
//}


さらに元のデザインに合わせるため、グローバルナビゲーションで現在開いているページを示すセレクター（@<tt>{.ll-active}）に対し、背景色や前景色を指定します。
次に選択できないことを示すため、@<tt>{cursor: default;}としてマウスカーソルの形を矢印にします。
またリンクをマウスカーソルで押したらリンク先に飛ぶというマウスイベントが起こらないように、@<tt>{pointer-events: none;}の指定でマウスイベント無効化をします。


//emlist[][css]{
/* グローバルナビゲーションの現在位置のスタイルを改善する */
#ll-nav .ll-active > a {
  position: relative;
  cursor: default;
  pointer-events: none;
  background-color: #ff50ac;
  color: #fff;
}
//}


最後に現在開いているページをグローバルナビゲーション上で分かりやすくするため、下部に黄色の線を引きます。
これで、共通構造のマークアップは終わりです。


//emlist[][css]{
/* グローバルナビゲーションの現在位置を示すスタイル */
#ll-nav .ll-active > a::after {
  content: "";
  display: block;
  position: absolute;
  bottom: 0;
  left: 0;
  width: 100%;
  border-bottom: 5px solid #ffdc00;
}
//}

== CSSのまとめ


ここまでをまとめると、次のCSSになります。


//emlist[][css]{
/* サイトのヘッダー */
#ll-header {
  margin-bottom: 0;
}

/* サイトのロゴ */
#ll-header .ll-logo {
  height: auto;
  margin-top: 15px;
  padding: 15px;
}

/* サイトのグローバルナビゲーション */
#ll-nav {
  min-height: 0;
  margin-bottom: 0;
  border-width: 0;
}

/* サイトのグローバルナビゲーション内の各アイテム */
#ll-nav li {
  margin-right: 0;
}

/* サイトのグローバルナビゲーション内の各リンク */
#ll-nav li > a {
  margin-top: 0;
  margin-bottom: 0;
  border-radius: 0;
  color: #fff;
  text-transform: uppercase;
}
/* 横幅が768px以上のときの設定 */
@media (min-width: 768px) {
  #ll-nav li > a {
    padding: 0.75em 5em;
    border-right: 1px solid #fff;
  }

  #ll-nav li:first-child > a {
    border-left: 1px solid #fff;
  }
}

/* グローバルナビゲーションの現在位置を示すスタイル */
#ll-nav .ll-active > a {
  position: relative;
  cursor: default;
  pointer-events: none;
  background-color: #ff50ac;
  color: #fff;
}

/* グローバルナビゲーションの現在位置を示すスタイル */
#ll-nav .ll-active > a::after {
  content: "";
  display: block;
  position: absolute;
  bottom: 0;
  left: 0;
  width: 100%;
  border-bottom: 5px solid #ffdc00;
}
//}


スクリーンショットは次のとおりになります。
細部は違いますが、CSSでいろいろ調整したぶん、元のアニメキャプチャ画像に似てきたと思います。



//image[common-elements][CSSで調整したサイト]{
//}


