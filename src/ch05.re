
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



これにより、すでに付けられた @<tt>{ll-carousel-pagination-item--current} を無くし、上記の @<tt>{setPaginationPoint()} で改めてクラスを付け直すという動きを想定しています。


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
