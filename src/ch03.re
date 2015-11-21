
= HTML で Web サイトの構造を定義する


この章は、Web サイトの実装をしていきます。実装する上で、前章にて解説した注意点や調査する点を思い出しましょう。



はじめに HTML で Web サイトの構造を作っていきます。



HTML はテキストファイルの文章構造を、主にブラウザに対して伝える言語です。


== DOCTYPE


まず始めに DOCTYPE というものを書きます。これは必須となっています。


//emlist[][html]{
<!DOCTYPE html>
//}


@<href>{https://html.spec.whatwg.org/#the-doctype,HTML Standard - 12.1.1 The DOCTYPE} では、@<tt>{<!DOCTYPE} について「大文字小文字問わず」と書かれています。つまり @<tt>{<!doctype} と書いても問題ありません。



その後は、一つ以上のスペースを書きます。とはいえ、スペース一つ書けば問題ないでしょう。



スペースを書いた後は、@<tt>{html>} と書きます。@<tt>{html} の部分も大文字小文字を問いません。



なお、DOCTYPE は過去の経緯から必須となっています。DOCTYPE は省略した場合、ブラウザ側で現在の仕様と違う挙動になるモードを使う傾向があります。


== サイトに関する情報のマークアップ


次に head 要素を書きます。head 要素内には、meta 要素でサイト情報を書いていきます。


//emlist[][html]{
<head></head>
//}


この head 要素内にまずは文字コードの指定をします。特に制限がなければ @<tt>{UTF-8} を書いておくと良いでしょう。


//emlist[][html]{
<meta charset="UTF-8">
//}


次に title 要素を書きます。title 要素はページのタイトルを示す要素です。たとえば、トップページでは以下のように書きます。


//emlist[][html]{
<title>LoveLife! 2nd Tournament</title>
//}


ライブステージページでは、title 要素の内容をライブステージページ用に書きかえます。


//emlist[][html]{
<title>Live stage - LoveLife! 2nd Tournament</title>
//}


次にサイトの説明とキーワードを書きます。サイトの説明は特徴を示すように書きます。



キーワードも、サイトに関連するキーワードのみを並べて書きます。


//emlist[][html]{
<meta name="description" content="ラブライフ！の参加者募集サイトです">
<meta name="keywords" content="特設サイト">
//}


次に viewport の設定です。スマートフォン向けに表示領域を設定する必要があります。次の通り書いておけば、PC 版を相対的に小さくしたような表示となります。


//emlist[][html]{
<meta name="viewport" content="width=device-width">
//}


link 要素で CSS ファイルを読み込みます。今回はライブラリとして Bootstrap を使います。Bootstrap は自分が書いた CSS ファイルより先に読み込ませます。


//emlist[][html]{
<link rel="stylesheet" href="styles/bootstrap.min.css">
<link rel="stylesheet" href="styles/main.css">
//}


script 要素で JavaScript ファイルを読み込みます。今回はトップページのカルーセル実装に lory というライブラリを使います。lory は自分が書いた JavaScript ファイルより先に読み込ませます。



なお lory の読み込み時に、@<tt>{defer} を指定しています。@<tt>{defer} は「非同期にファイルを読み込む」という意味の HTML 属性です。@<tt>{defer} は @<tt>{DOMContentLoaded} という @<strong>{HTML が全て読み込まれたタイミングで実行されるイベント} の前に実行されます。


//emlist[][html]{
<script src="components/lory/dist/lory.min.js" defer></script>
//}


最終的なマークアップは以下の通りになります。


//emlist[][html]{
<head>
    <meta charset="UTF-8">
    <title>LoveLife! 2nd Tournament</title>
    <meta name="description" content="ラブライフ！の参加者募集サイトです">
    <meta name="keywords" content="特設サイト">
    <meta name="viewport" content="width=device-width">
    <link rel="stylesheet" href="styles/bootstrap.min.css">
    <link rel="stylesheet" href="styles/main.css">
    <script src="components/lory/dist/lory.min.js" defer></script>
</head>
//}

== body のマークアップ


head 要素の次は body 要素を書きます。body 要素内には HTML の主となる内容を書いていきます。


//emlist[][html]{
<body></body>
//}


まず始めに、自分が書いた JavaScript ファイルを読み込みます。body の閉じタグ部分に script 要素を追加します。


//emlist[][html]{
<body>
    <script src="scripts/main.js"></script>
</body>
//}

== ヘッダ部分のマークアップ


次にサイトのヘッダ部分をマークアップしていきます。どの部分かを画像で示すと、以下の部分になります。



まず始めに @<tt>{header} 要素の @<tt>{role} 属性値である @<tt>{banner} を説明します。



@<tt>{banner} という値は@<href>{http://momdo.github.io/wai-aria-1.1/#banner,サイト向けの内容を含む領域で、ページ上部に表示されるもの}です。



サイト向けの内容とは、ロゴや広告、サイト内検索などを指します。


//emlist[][html]{
<header class="navbar navbar-default  ll-navbar" role="banner">
    <div class="container-fluid  ll-container">
    </div>
</header>
//}


@<tt>{ll-container} というクラスが指定されている div 要素に注目します。この中には、サイトのロゴ表示をするよう指定しています。



img 要素の alt 属性は「電話で話している相手にも分かるような説明文」を書くと良いでしょう。


//emlist[][html]{
<div class="navbar-header">
    <h1 class="navbar-brand  ll-logo">
        <img src="" alt="LoveLife!">
    </h1>
</div>
//}


ヘッダの右上にあるリンクをマークアップします。こういったリンク集のようなものは ul 要素という「配置順に意味がないリスト」を示すものでマークアップします。


//emlist[][html]{
<ul class="nav navbar-nav navbar-right  ll-nav-links">
    <li><a href="mail-magazine.html">Mail magazine</a></li>
    <li><a href="">SNS</a></li>
    <li><a href="">Share</a></li>
    <li><a href="help.html">Help</a></li>
</ul>
//}


これらを踏まえた、最終的なマークアップは以下の通りになります。


//emlist[][html]{
<header class="navbar navbar-default  ll-navbar" role="banner">
    <div class="container-fluid  ll-container">
        <div class="navbar-header">
            <h1 class="navbar-brand  ll-logo">
                <img src="" alt="LoveLife!">
            </h1>
        </div>

        <ul class="nav navbar-nav navbar-right  ll-nav-links">
            <li><a href="mail-magazine.html">Mail magazine</a></li>
            <li><a href="">SNS</a></li>
            <li><a href="">Share</a></li>
            <li><a href="help.html">Help</a></li>
        </ul>
    </div>
</header>
//}

== ナビゲーション部分のマークアップ


@<tt>{nav} 要素の @<tt>{role} 属性に @<tt>{navigation} という値があります。



これは@<href>{http://momdo.github.io/wai-aria-1.1/#navigation,現在のページや関連するページへ案内する要素に付けられるもの}です。



今回は、ナビゲーション部分が他ページのリンクになるため「関連するページへ案内する」という目的を果たしています。


//emlist[][html]{
<nav class="navbar navbar-inverse  ll-navbar ll-navbar--bg-inverse" role="navigation">
    <div class="container-fluid  ll-container">
    </div>
</nav>
//}


次に、他ページへリンクする要素をマークアップします。これらのリンクは順不同で良いため、ul 要素と li 要素を使ってマークアップします。


//emlist[][html]{
<ul class="nav navbar-nav  ll-nav-links">
    <li class="active"><a href="/">Top</a></li>
    <li><a href="livestage.html">Live stage</a></li>
    <li><a href="outline.html">Outline</a></li>
    <li><a href="schedule.html">Schedule</a></li>
    <li><a href="special.html">Special</a></li>
    <li><a href="link.html">Link</a></li>
    <li><a href="faq.html">Faq</a></li>
</ul>
//}


最終的なマークアップは以下の通りになります。


//emlist[][html]{
<nav class="navbar navbar-inverse  ll-navbar ll-navbar--bg-inverse" role="navigation">
    <div class="container-fluid  ll-container">
        <ul class="nav navbar-nav  ll-nav-links">
            <li class="active"><a href="/">Top</a></li>
            <li><a href="livestage.html">Live stage</a></li>
            <li><a href="outline.html">Outline</a></li>
            <li><a href="schedule.html">Schedule</a></li>
            <li><a href="special.html">Special</a></li>
            <li><a href="link.html">Link</a></li>
            <li><a href="faq.html">Faq</a></li>
        </ul>
    </div>
</nav>
//}

== メイン部分のマークアップ


まず @<tt>{main} 要素というものを書きます。これはサイトの主要な内容を示すものとなります。



@<tt>{main} 要素へ @<tt>{role} 属性の値に @<tt>{main} という値を付けます。これは仕様書の@<href>{http://momdo.github.io/html5/grouping-content.html#the-main-element,4.4.14 main 要素}にも「書くことを勧める」と書かれています。



なお、@<tt>{role} 属性に指定した @<tt>{main} という値は、@<href>{http://momdo.github.io/wai-aria-1.1/#main,サイトの主要な内容}を指しています。一見した場合 @<tt>{main} 要素と用途がかぶっているように見えます。



しかし、Internet Explorer が @<href>{http://caniuse.com/#feat=html5semantic,IE11 までは main 要素をサポートしていない}ため、@<tt>{role} 属性で @<tt>{main} という値も一緒に書く必要があります。


//emlist[][html]{
<main role="main">
</main>
//}


以下の HTML はいくつか @<tt>{js_} と頭についたクラスが付いています。これらはカルーセルの実装時に JavaScript で使うことを想定しています。



そのため、これらのクラスにスタイルを付けることは避けたほうが良いでしょう。後ほどこれらについて "JavaScript で動きを付ける" の節で説明します。


//emlist[][html]{
<div class="js_carousel container-fluid  ll-container">
    <div class="js_frame  ll-carousel-frame">
        <div class="js_slides  ll-carousel-slides">
            <div class="js_slide  ll-carousel-slide">
                <img src="images/image_01.jpg" alt="">
            </div>

            <div class="js_slide  ll-carousel-slide">
                <img src="images/image_02.jpg" alt="">
            </div>
        </div>
    </div>
</div>
//}


以下の HTML も @<tt>{js_} と頭についたクラスが付いています。これはカルーセルの現在位置を示す実装で使うために付けました。


//emlist[][html]{
<ol class="js_carousel-pagination  ll-carousel-pagination">
    <li class="js_carousel-pagination-item  ll-carousel-pagination-item">●</li>
    <li class="js_carousel-pagination-item  ll-carousel-pagination-item">●</li>
</ol>
//}


最終的なマークアップは以下の通りになります。


//emlist[][html]{
<main role="main">
    <div class="js_carousel container-fluid  ll-container">
        <div class="js_frame  ll-carousel-frame">
            <div class="js_slides  ll-carousel-slides">
                <div class="js_slide  ll-carousel-slide">
                    <img src="images/image_01.jpg" alt="">
                </div>

                <div class="js_slide  ll-carousel-slide">
                    <img src="images/image_02.jpg" alt="">
                </div>
            </div>
        </div>
    </div>

    <ol class="js_carousel-pagination  ll-carousel-pagination">
        <li class="js_carousel-pagination-item  ll-carousel-pagination-item">●</li>
        <li class="js_carousel-pagination-item  ll-carousel-pagination-item">●</li>
    </ol>
</main>
//}

== フッタ部分のマークアップ


まず @<tt>{footer} 要素というものを書きます。body 要素直下に書く場合、サイトの情報が @<tt>{footer} 要素へ含まれることを想定します。



また、@<tt>{role} 属性の値に @<tt>{contentinfo} を指定します。こうすることで、@<href>{http://momdo.github.io/wai-aria-1.1/#contentinfo,サイトに関する情報が含まれる領域}ということを示します。


//emlist[][html]{
<footer class="navbar navbar-default  ll-navbar" role="contentinfo">
    <div class="container-fluid  ll-container">
    </div>
</footer>
//}


著作権表示は @<tt>{p} 要素を使ってマークアップします。クラス名で著作権表示と分かるようなクラス名を付けておくのが良いでしょう。


//emlist[][html]{
<p class="nav navbar-text navbar-left  ll-copyright">
    © 2014 LoveLife! 運営事務局
</p>
//}


サイトの補足的情報となるリンクをマークアップします。並び順は順不同で良いため、ul 要素と li 要素を使います。


//emlist[][html]{
<ul class="nav navbar-nav navbar-right">
    <li><a href="privacy-policy.html">Privacy policy</a></li>
    <li><a href="sitemap.html">Sitemap</a></li>
</ul>
//}


最終的なマークアップは以下の通りになります。


//emlist[][html]{
<footer class="navbar navbar-default  ll-navbar" role="contentinfo">
    <div class="container-fluid  ll-container">
        <p class="nav navbar-text navbar-left  ll-copyright">
            © 2014 LoveLife! 運営事務局
        </p>

        <ul class="nav navbar-nav navbar-right">
            <li><a href="privacy-policy.html">Privacy policy</a></li>
            <li><a href="sitemap.html">Sitemap</a></li>
        </ul>
    </div>
</footer>
//}
