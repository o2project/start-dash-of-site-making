
= サイトを実装してみよう


サイトを実装する上での注意点や調査を踏まえた上で実際に実装をしていきます。


== HTML で文章に構造を付ける


はじめに HTML を使ってサイトの実装をしていきましょう。



HTML はただのテキストに「ここは見出しでここは段落だ」と、文章の構造を主にブラウザに対して伝えるための言語です。


=== よく使われる要素

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

=== カルーセルの実装
