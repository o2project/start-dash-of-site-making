
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


CSS を使って、HTML でマークアップしたサイトの見た目を良くしていきます。


=== 準備


まず始めに、HTML 側で CSS ファイルを読み込むようにします。とはいえ、実はもう読み込むようになっています。



それが head 要素内に書いた、以下の記述です。これは Bootstrap と自分が独自に書いた CSS を読み込むような記述になっています。



あとは HTML ファイルを置いたフォルダと同じフォルダに styles というフォルダを作って、その中に bootstrap.min.css と main.css を置けば CSS ファイルが読み込まれます。


//emlist[][html]{
<link rel="stylesheet" href="styles/bootstrap.min.css">
<link rel="stylesheet" href="styles/main.css">
//}

=== なぜ HTML とは別ファイルにするのか


CSS には HTML を書くファイル以外に別途ファイルを作って CSS を書いていくほかに、HTML 内で style 要素を定義してその中に CSS を書いていく(style 要素)方法と、HTML の要素に style 属性を定義してその中に CSS を書いていく(インライン style 属性)方法があります。



HTML 内で style 要素を定義してその中に CSS を書いていく(style 要素)方法の例は以下の通りです。


//emlist[][html]{
<style>
    p {
        color: red;
    }
</style>
//}


HTML の要素に style 属性を定義してその中に CSS を書いていく(インライン style 属性)方法の例は以下の通りです。


//emlist[][html]{
<p style="color: red;">テスト</p>
//}


この中でも CSS を外部ファイル化することが最良な理由としては、二点理由があります。



まず始めに、各ページに link 要素で CSS ファイルを読みこませれば、サイト全体の見た目を変えたいと思った時に CSS ファイルだけを差し替えれば変えられることです。つまり、メンテナンス効率が上がります。



次に、サイト全体の表現を統一しやすいことです。例えば各ページで style 要素内に CSS を書いていく場合、どのページでどのような CSS を書いたか忘れてしまった場合、表現が統一されなくなる確率が高くなります。その点 CSS を別のファイルにして、その中でのみ CSS を書くようにすれば、サイト全体の表現が統一されやすくなります。


=== プロパティと値


CSS では「プロパティ」が「適用させたいスタイル」を示し「値」は「実際に適用させる値」を指します。具体例をソースコードで示すと以下の通りです。


//emlist[][css]{
.test {
    /* プロパティ: 値 */
    /* 背景色: 白 */
    background-color: #fff;
}
//}

=== セレクタについて


セレクタとは「HTML 内の特定の要素に合致するパターン」のことを指します。@<href>{http://standards.mitsue.co.jp/resources/w3c/TR/css3-selectors/#selectors,セレクタ Level 3 の 2. セレクタ}を見ると分かるように多種多様なセレクタがあります。



しかし、よく使うものは限られてます。ここでは、そのよく使う以下のセレクタについて解説していきます。

 * 要素セレクタ
 * ID セレクタ
 * クラスセレクタ
 * 子孫セレクタ
 * 子セレクタ
 * ユーザーアクション擬似クラス

==== 要素セレクタ


指定した要素があるかどうか探してスタイルを適用するものです。


//emlist[][css]{
/* 全ての p 要素 */
p {
    color: #333;
}

/* 全ての h1 要素 */
h1 {
    font-size: 16px;
}
//}

==== ID セレクタ


HTML 内で id 属性を指定した要素に対してスタイルを適用するものです。なお、同一の HTML ファイル内では、同じ id 属性の値を指定することはできません。



以下の HTML の例だと、@<tt>{global-header} と @<tt>{site-title} という ID は他のところでは使えないということになります。


//emlist[][html]{
<header id="global-header">
    <h1 id="site-title">テストテスト</h1>
</header>
//}

//emlist[][css]{
#global-header {
    background-color: #ccc;
}

#site-title {
    color: #333;
}
//}

==== クラスセレクタ


HTML 内で class 属性を指定した要素に対してスタイルを適用するものです。ID セレクタとは違い、同一の HTML ファイル内で同じ class 属性の値を指定することができます。


//emlist[][html]{
<div class="nav-bar"></div>
//}

//emlist[][css]{
.nav-bar {
    background-color: #ccc;
}
//}

==== 子孫セレクタ


子孫要素に対してスタイルを適用するものです。まず子孫要素について説明します。



例えば、以下のような HTML があったとします。この場合 @<tt>{nav-bar} という値が指定されている class 属性が指定されている div 要素から見て、ul 要素は子要素の関係となります。そして、li 要素は孫要素の関係になります。li 要素の中にある a 要素については曾孫要素になります。


//emlist[][html]{
<div class="nav-bar">
    <ul>
        <li><a href="/">トップ</a></li>
        <li><a href="livestage.html">ライブステージ</a></li>
    </ul>
</div>
//}


では、この時に li 要素にのみ文字色を赤にするようなスタイルを適用したいとなった時はどうしたら良いでしょうか？答えは以下のように書きます。



以下の CSS は「.nav-bar の 子要素である ul 要素内にある li 要素に対して、文字色を赤にする」という指定をおこなっています。


//emlist[][css]{
.nav-bar ul li {
    color: red;
}
//}

==== 子セレクタ


子要素に対してスタイルを適用するものです。



先ほどの指定だと @<tt>{nav-bar} という値が指定されている class 属性の孫要素の li 要素全てにスタイルが適用されていましたが、例えば、以下の HTML にあるように li 要素の孫要素の li 要素は文字色を赤くしたくないと思ったとします。


//emlist[][html]{
<div class="nav-bar">
    <ul>
        <li><a href="/">トップ</a></li>
        <li>
            <a href="livestage.html">ライブステージ</a>
            <ul>
                <li><a href="muse.html">μ's</a></li>
                <li><a href="arise.html">A-RISE</a></li>
            </ul>
        </li>
    </ul>
</div>
//}


この場合、以下のように ul と li を結合する文字を半角スペースから大なり括弧に変えると、トップとライブステージという部分だけ文字色が赤くなります。


//emlist[][css]{
.nav-bar ul > li {
    color: red;
}
//}

==== ユーザーアクション擬似クラス


サイトの利用者がおこなった行動に対して、スタイルを適用するものです。@<tt>{:hover}, @<tt>{:active}, @<tt>{:focus} があります。



@<tt>{:hover} はある要素をマウスカーソルなどで示した場合に適用されるものです。例えば、リンクを示す文字列をマウスカーソルで指した場合に、文字色を変えてその要素が今指されているということを利用者に示したりします。



@<tt>{:active} はある要素を選択した時に適用されます。例えば、マウスカーソルである要素を選択して、マウスから指を離すまでは @<tt>{:active} で指定されたスタイルが適用されます。



@<tt>{:focus} はある要素を選択した時に適用されます。@<tt>{:active} と同じ概要になってしまいますが、違うところは、例えば入力フォームを選択した時にスタイルが適用されたり、キーボードで tab キーを押して、リンクを選択した時にスタイルが適用されるということです。


=== スタイル適用の優先度


スタイルの適用には優先度があります。優先度の決め方は、セレクタの数や種類によって決まります。



@<href>{http://momdo.github.io/css2/cascade.html#specificity,6.4.3 セレクタの詳細度を計算する} にあるように、以下の計算をします。

 * style 属性の数を「a」として数える
 * ID セレクタの数を「b」として数える
 * セレクタの中のクラスセレクタ(.foo)、属性セレクタ([id="foo"] など)、擬似クラス(:hover, :active など)の数を「c」として数える
 * 型セレクタ(要素そのものを指定する)、擬似要素(::before, ::after など)の数を「d」として数える


難しそうに思えますが「要素に指定された style 属性が強く、その次に ID セレクタが強い」ということを覚えておけばだいたいなんとかなります(そしてこの二つはむやみやたらに書いてはいけないものというのが分かると思います)。



なお「!important」というものを書くと、この優先度は関係なくなり「!important」が指定されたスタイルが適用されます。


=== 悪いクラス名の名付け方


今回は Bootstrap を使っているので、基本は HTML 側で Boostrap で定義されているクラス名を付けていけば良いのですが、見た目を調整したい場合は HTML にクラスを付けて、CSS 側でスタイル定義をおこなう必要があります。



この際のクラス名の付け方として、良くないクラス名の付け方というものがあります。



例えば、文字の色を赤くしたいと思って、以下のような CSS を書いたとします。


//emlist[][css]{
.red {
    color: red;
}
//}


しかし、これだと style 属性で @<tt>{<div style="color: red">テスト</div>} みたいに書くのと大差ありません。また、赤ではなく黄色くしたいと思った時に CSS のクラス名ごと @<tt>{.red} から @<tt>{.yellow} に書き換える手間が発生します。そして、以下のようになったりします。


//emlist[][css]{
.red {
    color: yellow;
}
//}


そのため、この場合で言うのであれば「なぜ文字色を赤くしたかったのか」を考え、それがエラーということを伝えたいということであれば、以下のようにクラス名を付けるのが良いでしょう。


//emlist[][css]{
.error {
    color: red;
}
//}

=== 良いクラス名の名付け方


では、良いクラス名とはなんでしょうか？



今回 HTML のクラス名の名付け方として @<href>{http://blog.ruedap.com/2013/10/29/block-element-modifier,MindBEMding} という考えかたを採用しています。



これはサイトを構成するそれぞれの要素を独立させて、将来的な仕様変更にもなるべく容易に応えられるように取り入れたものです。



通常 MindBEMding はセレクタ名を以下のように書きます。


//emlist[][css]{
.block__element--modifier {
    /* スタイル定義がここに入る */
}
//}


block にあたる部分は、例えば検索フォームであれば「検索窓と検索するボタンを囲む要素」を指します。element にあたる部分はそれぞれ「検索窓」と「検索するボタン」を指します。modifier にあたる部分は基本の検索フォームからは少し違う見た目を指します。


== JavaScript で動きを付ける


JavaScript を使って、カルーセルを実装していきます。しかし、その前に準備をしていきます。


=== 準備


まず始めに、以下のように全体を @<tt>{(function () { ... \})();} というもので囲みます。



これは、内部に書かれている変数や関数が他のライブラリと競合しないようにするためです。この @<tt>{(function () { ... \})();} を書かないと他のライブラリと競合してしまい、JavaScript が正常に動作しないという事態になります(そしてそのデバッグは大変です)。


//emlist[][js]{
(function () {
    // ここにソースコードを書く
})();
//}


次に @<tt>{addEventListener()} を使って「何か起きたら何かする」という実装をしていきます。



次のようなソースコードがある場合、@<tt>{DOMContentLoaded} が起きたら、function () 内のソースコードを実行するという処理になります。


//emlist[][js]{
document.addEventListener("DOMContentLoaded", function () {
  // ここにソースコードを書く
});
//}


@<tt>{DOMContentLoaded} はブラウザなどが HTML を読み込み解釈し終えた後に起きるイベントです。この際、画像の読み込みは待たないので、他の読み込みが終わったタイミングで起きるイベントに比べて、高速といわれています。



では、カルーセルの実装をおこなっていきます。まずは先ほどの以下の function () 内部に書いていくコードから解説していきます。


//emlist[][js]{
(function () {
    // ここにソースコードを書く
})();
//}

=== カルーセルの初期化


始めに @<tt>{setupCarousel()} という関数を用意します。これは lory を使うために定義する関数となります。



カルーセルライブラリは、だいたい HTML の要素とカルーセルの動作設定を書くと実装できるものが多いので、例えば lory ではなく他のライブラリを使う場合でも、少し手直しをすれば使えることになります。


//emlist[][js]{
function setupCarousel(targetElement, options) {
    return lory(targetElement, options);
}
//}

=== カルーセルの自動表示切り替え


表示される画像を自動で切り替えるために、自動表示切り替え機能を実装します。



他のカルーセルライブラリだと、ライブラリ側でこの自動表示切り替え機能が実装されていることが多いですが、lory は@<href>{https://github.com/meandmax/lory/issues/3,作った人がいらないと考えていて}、実装されていません。



そのため、自分で実装する必要があります。しかし、その実装は簡単です。



以下のように @<tt>{autoplay()} の第一引数に先ほどの setupCarousel で作った lory を渡して、第二引数の delay でどれくらいの間隔で自動で表示切り替えをするか設定します。


//emlist[][js]{
function autoplay(carousel, delay) {
    return setInterval(function() {
        carousel.next();
    }, delay);
}
//}

=== カルーセルが実際に動くようにする


ここまで準備してきましたが、いよいよカルーセルが動くようにしていきます。まず始めに、ここで解説するコードの完成形を見せると、以下のようになります。


//emlist[][js]{
document.addEventListener("DOMContentLoaded", function () {
    var carouselE = document.querySelector(".js_carousel");
    var carousel = setupCarousel(carouselE, {
        infinite: 1
    });

    autoplay(carousel, 5000);
});
//}


まずはじめに @<tt>{querySelector()} について解説していきます。これは引数に取得したい要素を CSS セレクタ形式で指定するというものです。



今回カルーセル実装にあたり @<tt>{.js_carousel} というクラスが付いた要素を元にカルーセル実装をしていくので @<tt>{querySelector()} を使って、要素を取得しています。


//emlist[][js]{
var carouselE = document.querySelector(".js_carousel");
//}


次にカルーセルの有効化をおこないます。先ほど実装した @<tt>{setupCarousel()} に @<tt>{carouselE} と、カルーセルの動作をどのようにするか設定するものを引数として渡します。


//emlist[][js]{
var carousel = setupCarousel(carouselE, {
    infinite: 1
});
//}


そしてカルーセルを5000ミリ秒、つまり5秒ごとに表示される画像を切り替えるようにします。


//emlist[][js]{
autoplay(carousel, 5000);
//}


ここまでのソースコードをまとめると、以下の通りになります。これでカルーセルが実装でき、表示される画像が自動で切り替わるようになりました。


//emlist[][js]{
(function () {
    function autoplay(carousel, delay) {
        return setInterval(function() {
            carousel.next();
        }, delay);
    }

    function setupCarousel(targetElement, options) {
        return lory(targetElement, options);
    }

    document.addEventListener("DOMContentLoaded", function () {
        var carouselE = document.querySelector(".js_carousel");

        var carousel = setupCarousel(carouselE, {
            infinite: 1
        });

        autoplay(carousel, 5000);
    });
})();
//}


なお、対応する HTML は以下の通りとなります。@<tt>{js_carousel} は先ほど出てきましたが、他の @<tt>{js_frame}, @<tt>{js_slides}, @<tt>{js_slide} も lory を動作させるには必須の要素となっています。


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

=== カルーセルの下部のドット実装


始めに @<tt>{setPaginationPoint()} という関数を用意します。これは引数に渡された要素に対して、@<tt>{ll-carousel-pagination-item--current} というクラスを付けるというものです。


//emlist[][js]{
function setPaginationPoint(element) {
    element.classList.add("ll-carousel-pagination-item--current");
}
//}


次に @<tt>{resetPaginationPoint()} という関数を用意します。これは引数に渡された要素達に対して、@<tt>{ll-carousel-pagination-item--current} というクラスを外すというものです。



この @<tt>{resetPaginationPoint()} で付けられた @<tt>{ll-carousel-pagination-item--current} を外して、上記の @<tt>{setPaginationPoint()} で改めてクラスを付け直すという動きを想定しています。


//emlist[][js]{
function resetPaginationPoint(paginationNodeList) {
    Array.prototype.map.call(paginationNodeList, function (node) {
        node.classList.remove("ll-carousel-pagination-item--current");
    });
}
//}


@<tt>{addEventListener()} 内にドット用のソースコードを書いていきます。



まず始めに @<tt>{querySelector()} でページネーションの親要素を取得します。その次に @<tt>{getElementsByClassName()} でドットを囲む要素を取得します。


//emlist[][js]{
var paginationE = document.querySelector(".js_carousel-pagination");
var paginationItemElms = paginationE.getElementsByClassName("js_carousel-pagination-item")
//}


カルーセル下部のドット表示の初期化をおこないます。カルーセルの現在位置を元にドットの表示も切り替えます。


//emlist[][js]{
setPaginationPoint(paginationItemElms[carousel.returnIndex() - 1]);
//}


カルーセル実装の元となる要素で @<tt>{after.lory.slide} というイベントが起きないかを監視します。この @<tt>{after.lory.slide} が起きるタイミングは、カルーセルの表示が切り替わった後に発生します。



@<tt>{after.lory.slide} というイベントが発生したら、カルーセルのドットの表示を切り替えます。


//emlist[][js]{
carouselE.addEventListener("after.lory.slide", function () {
    resetPaginationPoint(paginationItemElms);
    setPaginationPoint(paginationItemElms[carousel.returnIndex() - 1]);
});
//}


ここまでのソースコードをまとめると、以下の通りになります。これでカルーセルの下部のドットが実装でき、カルーセル側の表示切り替えによって、ドットの表示が変わるようになりました。


//emlist[][js]{
(function () {
    function autoplay(carousel, delay) {
        return setInterval(function() {
            carousel.next();
        }, delay);
    }

    function setPaginationPoint(element) {
        element.classList.add("ll-carousel-pagination-item--current");
    }

    function resetPaginationPoint(paginationNodeList) {
        Array.prototype.map.call(paginationNodeList, function (node) {
            node.classList.remove("ll-carousel-pagination-item--current");
        });
    }

    function setupCarousel(targetElement, options) {
        return lory(targetElement, options);
    }

    document.addEventListener("DOMContentLoaded", function () {
        var carouselE = document.querySelector(".js_carousel");
        var paginationE = document.querySelector(".js_carousel-pagination");
        var paginationItemElms = paginationE.getElementsByClassName("js_carousel-pagination-item")

        var carousel = setupCarousel(carouselE, {
            infinite: 1
        });

        setPaginationPoint(paginationItemElms[carousel.returnIndex() - 1]);
        autoplay(carousel, 5000);

        carouselE.addEventListener("after.lory.slide", function () {
            resetPaginationPoint(paginationItemElms);
            setPaginationPoint(paginationItemElms[carousel.returnIndex() - 1]);
        });
    });
})();
//}


対応する HTML は以下の通りとなります。


//emlist[][html]{
<ol class="js_carousel-pagination  ll-carousel-pagination">
    <li class="js_carousel-pagination-item  ll-carousel-pagination-item">●</li>
    <li class="js_carousel-pagination-item  ll-carousel-pagination-item">●</li>
</ol>
//}
