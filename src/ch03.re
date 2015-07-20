
= サイトを実装してみよう


ここでは、サイトを実装する上での注意点や調査を踏まえた上で、実際にトップページの実装をしていきます。


== HTML で文章に構造を付ける


はじめに HTML を使ってサイトの実装をしていきましょう。



HTML はただのテキストに「ここは見出しでここは段落だ」と、文章の構造を主にブラウザに対して伝えるための言語です。


=== DOCTYPE


まず始めに DOCTYPE というものを書きます。これは必須となっています。


//emlist[][html]{
<!DOCTYPE html>
//}


@<href>{https://html.spec.whatwg.org/#the-doctype,HTML Standard の 12.1.1 The DOCTYPE} を見てみると、まず始めの @<tt>{<!DOCTYPE} は「大文字小文字問わず」と書かれています。つまり @<tt>{<!doctype} と書いても問題ありません。



その後は、一つ以上のスペースを書きます。とはいえ、スペース一つ書けば問題ないでしょう。



スペースを書いた後は、@<tt>{html>} と書きます。@<tt>{html} の部分も大文字小文字を問いません。



つまり上記のコードは以下のように書いても問題ないです。


//emlist[][html]{
<!doctype html>
//}


なお、DOCTYPE は過去の経緯から必須となっています。DOCTYPE を省略した場合、ブラウザ側では現在の仕様と違う挙動をするモードを使う傾向にあるため、DOCTYPE を上記のように書くと、これは新しいページということをブラウザ側が分かってくれます。


=== サイトに関する情報のマークアップ


次に head 要素というものを書きます。これは、この要素内にサイトの情報を書いていくための要素となります。


//emlist[][html]{
<head></head>
//}


この head 要素内にまずは文字コードの指定をします。特に制限がなければ @<tt>{UTF-8} と書いておくのが良いでしょう。


//emlist[][html]{
<meta charset="UTF-8">
//}


次に title 要素を書きます。ページのタイトルを示す要素で、ブラウザのタブ部分にも表示されるものです。今回のラブライフ！募集サイトという要件では、以下のように書くと良いでしょう。


//emlist[][html]{
<title>LoveLife! 2nd Tournament</title>
//}


ライブステージのページでは、以下のように title 要素の内容を書き換えると良いでしょう。


//emlist[][html]{
<title>Live stage - LoveLife! 2nd Tournament</title>
//}


次にサイトの説明と、サイトを示すキーワードを書きます。サイトの説明のほうはあまり長く書かず、簡潔にサイトの特徴を示す文を書くと良いでしょう。



キーワードについても、サイトにより関連しているキーワードを並べるのが良いでしょう。


//emlist[][html]{
<meta name="description" content="ラブライフ！の参加者募集サイトです">
<meta name="keywords" content="特設サイト">
//}


次に viewport の設定です。スマートフォン向けに表示領域を設定する必要があるのですが、だいたいは以下のように書いておけば、PC 版を相対的に小さくしたような表示になります。


//emlist[][html]{
<meta name="viewport" content="width=device-width">
//}


link 要素で CSS ファイルを読み込みます。今回は Bootstrap を基本として CSS を書いていくため、Bootstrap を先に読み込むようにし、その後自分が書いた CSS ファイルを読み込むようにします。


//emlist[][html]{
<link rel="stylesheet" href="styles/bootstrap.min.css">
<link rel="stylesheet" href="styles/main.css">
//}


script 要素で JavaScript ファイルを読み込みます。今回トップページのカルーセルの実装で使う lory というライブラリを先に読み込むようにし、その後自分が書いた JavaScript ファイルを読み込むようにします。



なお lory を読み込む際に @<tt>{defer} というのを指定しています。@<tt>{defer} は「非同期にファイルを読み込む」ことを指します。実行のタイミングは DOMContentLoaded という「HTML が全て読み込まれたタイミングで実行されるイベント」の前におこなわれます。


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

=== body のマークアップ


head 要素を書いた後は body 要素を書きます。body 要素内には HTML の主となる内容を書いていきます。


//emlist[][html]{
<body></body>
//}


他の内容を書く前に、body の閉じタグの前に自分が書いた JavaScript ファイルを読み込むようにします。


//emlist[][html]{
<body>
    <script src="scripts/main.js"></script>
</body>
//}

=== ヘッダー部分のマークアップ


次にサイトのヘッダー部分をマークアップしていきます。どの部分かを画像で示すと、以下の部分になります。



まず始めに @<tt>{header} 要素に付けられれている @<tt>{role} 属性の値である @<tt>{banner} について、説明します。



@<tt>{banner} という値は@<href>{http://momdo.github.io/wai-aria-1.1/#banner,サイト向けの内容を含む領域で、ページの上部に表示されるもの}です。



サイト向けの内容とは、ロゴやサイトの広告、サイト内の検索などを指します。


//emlist[][html]{
<header class="navbar navbar-default  ll-navbar" role="banner">
    <div class="container-fluid  ll-container">
    </div>
</header>
//}


次に @<tt>{ll-container} とクラスが指定されている要素の中に入れる要素を見てみます。ここでは、サイトのロゴを表示するように指定しています。



img 要素の alt 属性には「電話で話している相手にも分かるような説明文」を書くと良いでしょう。


//emlist[][html]{
<div class="navbar-header">
    <h1 class="navbar-brand  ll-logo">
        <img src="" alt="LoveLife!">
    </h1>
</div>
//}


ヘッダーの右上にあるリンクをマークアップします。こういったリンク集のようなものは ul 要素という「配置順に意味を持たないリスト」を示すものでマークアップします。


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

=== ナビゲーション部分のマークアップ


@<tt>{nav} 要素の @<tt>{role} 属性に @<tt>{navigation} という値があります。



これは@<href>{http://momdo.github.io/wai-aria-1.1/#navigation,現在のページや関連するページへ案内するための要素に付けられるもの}です。



今回の場合、このナビゲーション部分が他のページへのリンクになっているので「関連するページへ案内する」という目的を果たしているといえます。


//emlist[][html]{
<nav class="navbar navbar-inverse  ll-navbar ll-navbar--bg-inverse" role="navigation">
    <div class="container-fluid  ll-container">
    </div>
</nav>
//}


次に、他のページへリンクする要素をマークアップします。これらのリンクは順不同で良いため、ul 要素と li 要素を使ってマークアップしていきます。


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

=== メイン部分のマークアップ


まず @<tt>{main} 要素というものを書きます。これはサイトの主要な内容を示すものとなります。



先ほどから何度もでてきていますが @<tt>{main} 要素にも @<tt>{role} 属性の値として @<tt>{main} という値を付けます。これは仕様書の@<href>{http://momdo.github.io/html5/grouping-content.html#the-main-element,4.4.14 main要素}にも「書くことを勧める」と書かれています。



なお、@<tt>{role} 属性の @<tt>{main} という値は、@<href>{http://momdo.github.io/wai-aria-1.1/#main,サイトの主要な内容のこと}を指しており、一見すると @<tt>{main} 要素と用途がかぶっているのですが、Internet Explorer が @<href>{http://caniuse.com/#feat=html5semantic,IE11 までは main 要素をサポートしていない}ため、@<tt>{role} 属性で @<tt>{main} という値も一緒に書く必要があります。


//emlist[][html]{
<main role="main">
</main>
//}


以下の HTML にはいくつか @<tt>{js_} と頭についたクラスが付いています。これらはカルーセルの実装時に JavaScript で使うことを想定しています。



そのため、これらのクラスにスタイルを付けることは避けたほうが良いでしょう。



これらのクラスの使いどころは「JavaScript で動きを付ける」で説明します。


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


以下の HTML にも @<tt>{js_} と頭についたクラスが付いています。これはカルーセルの現在位置を示す実装をする際に JavaScript で使うことを想定して付けています。


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

=== フッター部分のマークアップ


まず @<tt>{footer} 要素というものを書きます。body 要素の直下に書く場合、サイトに関する情報が中に含まれることを想定します。



また、それを示すために、@<tt>{role} 属性の値として @<tt>{contentinfo} を指定しています。



これは@<href>{http://momdo.github.io/wai-aria-1.1/#contentinfo,サイトに関する情報を含む領域}を指します。


//emlist[][html]{
<footer class="navbar navbar-default  ll-navbar" role="contentinfo">
    <div class="container-fluid  ll-container">
    </div>
</footer>
//}


著作権表示は @<tt>{p} 要素を使ってマークアップします。クラス名で著作権表示と分かるようなクラス名を付けておくと良いでしょう。


//emlist[][html]{
<p class="nav navbar-text navbar-left  ll-copyright">
    © 2014 LoveLife! 運営事務局
</p>
//}


サイトに関する補足的なリンクは、並び順は順不同で良いため、ul 要素と li 要素を使ってマークアップしていきます。


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

== CSS で見た目を良くする

=== Bootstrap を読み込む

=== クラス名の設計


クラス名の設計として、一つのクラス名だけを付ける単一クラス設計と、複数のクラス名を付ける複数クラス設計があります。



例えば下のような見た目の要素があったとします。



[ここにスクリーンショット]



この場合、単一クラス設計の HTML と CSS の例は以下の通りになります。



@<strong>{HTML}


//emlist[][html]{
<ul class="prefix-tabs">
    <li class="prefix-tab--active">選択されているタブ</li>
    <li class="prefix-tab">選択されていないタブ</li>
</ul>
//}


@<strong>{CSS}


//emlist[][css]{
.prefix-tabs {}

.prefix-tab {}

.prefix-tab--active {}
//}


一方、複数クラス設計の HTML と CSS の例は以下の通りになります。



@<strong>{HTML}


//emlist[][html]{
<ul class="prefix-tabs">
    <li class="prefix-tab prefix-tab--active">選択されているタブ</li>
    <li class="prefix-tab">選択されていないタブ</li>
</ul>
//}


@<strong>{CSS}


//emlist[][css]{
.prefix-tabs {}

.prefix-tab {}

.prefix-tab--active {}
//}


この二つは、作るサイトの特性や使うライブラリによって使い分けが必要になります。



今回みたいに Bootstrap を基盤にする場合、Bootstrap 自体が複数のクラスを組み合わせて見た目を調整していくものとなっているので、複数クラス設計にしたほうが良いです。


=== クラス名の名付け方


今回 HTML のセレクタ名の名付け方として @<href>{http://blog.ruedap.com/2013/10/29/block-element-modifier,MindBEMding} という考えかたを採用しています。



これはサイトを構成するそれぞれの要素を独立させて、将来的な仕様変更にもなるべく容易に応えられるように取り入れたものです。



通常 MindBEMding はセレクタ名を以下のように書きます。


//emlist[][css]{
.block__element--modifier {
    /* スタイル定義がここに入る */
}
//}


block にあたる部分は、例えば検索フォームであれば「検索窓と検索するボタンを囲む要素」を指します。element にあたる部分はそれぞれ「検索窓」と「検索するボタン」を指します。modifier にあたる部分は基本の検索フォームからは少し違う見た目を指します。



基本は HTML 側で Bootstrap で定義されているクラス名を付けていけば良いのですが、見た目を調整したい場合は独自にスタイル定義をおこなう必要があります。


=== 注意点


グローバルナビゲーションの CSS を以下のようにすると、確かに望んだ見た目にはなります。


//emlist[][css]{
.navbar-default .navbar-nav > .active > a,
.navbar-default .navbar-nav > .active > a:focus,
.navbar-default .navbar-nav > .active > a:hover {
    border-bottom: 5px solid #ffdc00;
}
//}


しかし、他のグローバルナビゲーションのリンクの下部に謎の隙間が空くことになります。


== JavaScript で動きを付ける

=== カルーセル実装

=== カルーセルの下部のドット実装
