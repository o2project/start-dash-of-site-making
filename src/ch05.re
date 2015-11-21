
= JavaScript で動きを付ける


JavaScript で Web サイトに動きをつけていきます。しかし、その前に準備をしていきます。


== 準備


はじめに、JavaScript のソースコード全体を @<tt>{(function () { ... \})();} で囲みます。



理由としては、変数や関数が他のソースコードと競合しないようにするためです。



@<tt>{(function () { ... \})();} を書かなかった場合、他のソースコードと競合してしまい、JavaScript が正常に動作しないことが起こります。


//emlist[][js]{
(function () {
    // ここにソースコードを書く
})();
//}


次に「イベントが起きたら何か実行」という実装をしていきます。方法としては @<tt>{addEventListener()} を使います。



次のソースコードは、@<tt>{DOMContentLoaded} が起きたら、@<tt>{function ()} 内にあるソースコードを実行するという処理です。


//emlist[][js]{
document.addEventListener("DOMContentLoaded", function () {
  // ここにソースコードを書く
});
//}


@<tt>{DOMContentLoaded} はブラウザが HTML を読み込み、解釈し終えた後に起きるイベントです。この時、画像の読み込みは待たないため @<tt>{onload} イベントに比べ高速といわれています。



では、カルーセルの実装をおこなっていきます。まずは @<tt>{function ()} 内部に書くコードから解説していきます。


//emlist[][js]{
(function () {
    // ここにソースコードを書く
})();
//}

== カルーセルの初期化


始めに @<tt>{setupCarousel()} という関数を用意します。これは lory を使うために定義する関数となります。



カルーセルライブラリは、HTML とカルーセルの動作設定を書けば実装できるものが多いです。



たとえば lory ではなく他のライブラリを使う場合でも、少し手直しすれば使えることになります。


//emlist[][js]{
function setupCarousel(targetElement, options) {
    return lory(targetElement, options);
}
//}

== カルーセルの自動表示切り替え


自動表示切り替え機能の実装をしていきます。他のカルーセルライブラリだと、ライブラリ側で自動表示切り替え機能は実装されていることが多いです。



しかし、lory は@<href>{https://github.com/meandmax/lory/issues/3,ライブラリ作者がいらないと考えているため}、実装されていません。



そのため、自分で実装する必要があります。しかし、その実装は簡単です。



次のコードでは @<tt>{autoplay()} の第1引数に、先ほど @<tt>{setupCarousel} から返された @<tt>{lory} を渡しています。第2引数の @<tt>{delay} では表示切り替え間隔を設定します。


//emlist[][js]{
function autoplay(carousel, delay) {
    return setInterval(function() {
        carousel.next();
    }, delay);
}
//}

== カルーセルを実際に動かす


いよいよカルーセルが動くようにしていきます。次のコードはここで解説するコードを完成させたものになります。


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



@<tt>{querySelector()} を使う理由は、@<tt>{.js_carousel} というクラスが付いた要素を取得するためです。


//emlist[][js]{
var carouselE = document.querySelector(".js_carousel");
//}


次にカルーセルの有効化をおこないます。先ほど実装した @<tt>{setupCarousel()} に @<tt>{carouselE} と、カルーセルの動作について設定するものを引数で渡します。


//emlist[][js]{
var carousel = setupCarousel(carouselE, {
    infinite: 1
});
//}


そして5000ミリ秒(5秒)間隔で、表示される画像を切り替えるようにします。


//emlist[][js]{
autoplay(carousel, 5000);
//}


ここまで書いたソースコードをまとめると、次の通りになります。これで自動表示切り替え機能付きカルーセルの実装ができました。


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


なお、対応する HTML は次の通りとなります。@<tt>{js_carousel} 以外に @<tt>{js_frame}, @<tt>{js_slides}, @<tt>{js_slide} も @<tt>{lory} を動かすため必須となります。


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

== カルーセル下部のドットを実装する


はじめに @<tt>{setPaginationPoint()} という関数を用意します。これは引数に渡された要素に対して、@<tt>{ll-carousel-pagination-item--current} クラスを付けるというものです。


//emlist[][js]{
function setPaginationPoint(element) {
    element.classList.add("ll-carousel-pagination-item--current");
}
//}


次に @<tt>{resetPaginationPoint()} という関数を用意します。これは引数に渡された要素達に対して、@<tt>{ll-carousel-pagination-item--current} クラスを外すというものです。



これで、すでに付けられた @<tt>{ll-carousel-pagination-item--current} は無くし、前述の @<tt>{setPaginationPoint()} で改めてクラスを付けます。


//emlist[][js]{
function resetPaginationPoint(paginationNodeList) {
    Array.prototype.map.call(paginationNodeList, function (node) {
        node.classList.remove("ll-carousel-pagination-item--current");
    });
}
//}


@<tt>{addEventListener()} 内にドット用のソースコードを書いていきます。



まず始めに @<tt>{querySelector()} でページネーションの親要素を取得します。その次に @<tt>{getElementsByClassName()} でより絞り込んで要素を取得します。


//emlist[][js]{
var paginationE = document.querySelector(".js_carousel-pagination");
var paginationItemElms = paginationE.getElementsByClassName("js_carousel-pagination-item")
//}


カルーセル下部のドット表示を初期化します。カルーセルの現在位置を元に表示調整します。


//emlist[][js]{
setPaginationPoint(paginationItemElms[carousel.returnIndex() - 1]);
//}


カルーセル実装の元となる要素で @<tt>{after.lory.slide} というイベントが起きないか監視します。@<tt>{after.lory.slide} の起きるタイミングは、カルーセル表示が切り替わった後に発生します。



@<tt>{after.lory.slide} というイベントが発生したら、カルーセルのドット表示を切り替えます。


//emlist[][js]{
carouselE.addEventListener("after.lory.slide", function () {
    resetPaginationPoint(paginationItemElms);
    setPaginationPoint(paginationItemElms[carousel.returnIndex() - 1]);
});
//}


今まで書いたソースコードをまとめると、次の通りになります。これでカルーセル下部のドット表示が実装できました。


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
