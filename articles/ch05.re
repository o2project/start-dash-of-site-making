
= ライブステージページを作る


第3章で作ったHTMLを元に、この章ではライブステージページを作っていきます。
第4章と同じく@<tt>{main}要素の中身をマークアップしていきます。


== 動画部分のマークアップ


はじめに動画部分のマークアップをしていきます。
アーティスト名と曲名部分へスタイルを適用させるため、それぞれ@<tt>{span}要素で括ります。



YouTubeの動画をページ内に埋め込みます。
ウィンドウ幅や高さを変えたとき、YouTubeの動画が表示領域からはみ出すのを防ぐため、@<tt>{iframe}要素を@<tt>{div}要素で囲います。
この@<tt>{div}要素にはのちほどスタイルを適用します。


//emlist[][html]{
<div class="col-md-6">
  <h2 class="ll-video-title-and-artist">
    <span class="ll-video-artist">μ's</span><span class="ll-video-title">Angelic Angel</span>
  </h2>
  <div class="ll-live-video-wrapper">
    <iframe width="560" height="315" src="https://www.youtube.com/embed/oWIE7GwJu3c" frameborder="0" allowfullscreen></iframe>
  </div>
</div>
//}

== 動画情報部分のマークアップ


次に動画情報部分のマークアップをしていきます。
今回はコメント部分のみを実装します。実装方法としてはTwitterのハッシュタグ検索ウィジェットを使っていきます。


//emlist[][html]{
<div class="col-md-3 col-sm-6 ll-video-detail">
  <ul class="nav nav-tabs nav-justified ll-video-tabs">
    <li><a href="">Status</a></li>
    <li><a href="">Like</a></li>
    <li class="active"><a href="">Comment</a></li>
    <li><a href="">Settings</a></li>
  </ul>

  <a class="twitter-timeline" data-dnt="true" href="https://twitter.com/hashtag/%E3%83%A9%E3%83%96%E3%83%A9%E3%82%A4%E3%83%96" data-widget-id="620242924207386625">#ラブライブ のツイート</a>
</div>
//}

== 広告部分のマークアップ


次に広告部分のマークアップをしていきます。
基本はBootstrapで定義されているクラス名をHTMLに書いていくのみとなります。


//emlist[][html]{
<div class="col-md-3 col-sm-6 ll-livestage-ad">
  <h2 class="ll-ad-title">
    Ad
  </h2>

  <div class="list-group">
    <a href="https://github.com/kubosho/Nico" class="list-group-item">
      <div class="list-group-item-heading">
        Nico
      </div>

      <p class="list-group-item-text">
        "Nico" a fork of "Honoka" which is a Bootstrap theme.
      </p>
    </a>

    <a href="https://github.com/kubosho/kotori" class="list-group-item">
      <div class="list-group-item-heading">
        Kotori
      </div>

      <p class="list-group-item-text">
        A tool that automatically format and evaluate for CSS.
      </p>
    </a>
  </div>
</div>
//}


最後にライブステージページで書いたHTMLを、次のHTMLで全体を囲ったら完成です。


//emlist[][html]{
<div class="container-fluid">
  <div class="row">
  </div>
</div>
//}

== HTMLのまとめ


ライブステージのHTMLをまとめると次のとおりになります。


//emlist[][html]{
<div class="container-fluid">
  <div class="row">
    <div class="col-md-6">
      <h2 class="ll-video-title-and-artist">
        <span class="ll-video-artist">μ's</span><span class="ll-video-title">Angelic Angel</span>
      </h2>
      <div class="ll-live-video-wrapper">
        <iframe width="560" height="315" src="https://www.youtube.com/embed/oWIE7GwJu3c" frameborder="0" allowfullscreen></iframe>
      </div>
    </div>

    <div class="col-md-3 col-sm-6 ll-video-detail">
      <ul class="nav nav-tabs nav-justified ll-video-tabs">
        <li><a href="">Status</a></li>
        <li><a href="">Like</a></li>
        <li class="active"><a href="">Comment</a></li>
        <li><a href="">Settings</a></li>
      </ul>

      <a class="twitter-timeline" data-dnt="true" href="https://twitter.com/hashtag/%E3%83%A9%E3%83%96%E3%83%A9%E3%82%A4%E3%83%96" data-widget-id="620242924207386625">#ラブライブ のツイート</a>
    </div>

    <div class="col-md-3 col-sm-6 ll-livestage-ad">
      <h2 class="ll-ad-title">
        Ad
      </h2>

      <div class="list-group">
        <a href="https://github.com/kubosho/Nico" class="list-group-item">
          <div class="list-group-item-heading">
            Nico
          </div>

          <p class="list-group-item-text">
            "Nico" a fork of "Honoka" which is a Bootstrap theme.
          </p>
        </a>

        <a href="https://github.com/kubosho/kotori" class="list-group-item">
          <div class="list-group-item-heading">
            Kotori
          </div>

          <p class="list-group-item-text">
            A tool that automatically format and evaluate for CSS.
          </p>
        </a>
      </div>
    </div>
  </div>
</div>
//}

== ライブステージページ全体の見た目を整える


HTMLのマークアップが終わったので、スタイルの適用をしていきます。
はじめにライブステージページ全体へ関わるスタイルを適用します。



ライブステージページの@<tt>{main}要素に対し、@<tt>{padding}や@<tt>{background-color}を指定することでライブステージページの見た目に近づけていきます。
また見出しにもスタイルを適用することで、より元の見た目に近づけていきます。


//emlist[][css]{
/* ライブステージ：コンテンツ */
#ll-livestage-page main {
  padding: 1em 0;
  background-color: #dcdcdc;
}

/* ライブステージページ：見出し */
.ll-video-title-and-artist,
.ll-ad-title {
  margin-top: 0;
  margin-bottom: 16px;
}
//}

== アーティスト名と曲名部分の見た目を整える


次にアーティスト名と曲名部分の見た目を整えていきます。
アーティスト名部分は背景が白で上下に黄色い線が引かれているという見た目です。
こちらは再現が容易です。



また曲名の左右にある括弧は特にHTML内へ書いておく必要がないため、@<tt>{::before}と@<tt>{::after}という擬似要素を使ってCSS側で追加します。


//emlist[][css]{
/* ライブステージページ：アーティスト名 */
.ll-video-artist {
  padding: 3px 0.5em;
  border-top: 2px solid #ffdc00;
  border-bottom: 2px solid #ffdc00;
  background-color: #fff;
}

/* ライブステージページ：曲名 */
.ll-video-title::before {
  content: "【";
}

.ll-video-title::after {
  content: "】";
}
//}

== 動画部分の見た目を整える


次に動画部分の見た目を整えます。
動画部分はブラウザーの描画領域を狭めたときに潰れて表示されないようします。


//emlist[][css]{
/* ライブステージページ：動画部分をレスポンシブにする */
.ll-live-video-wrapper {
    position: relative;
    height: 0;
    padding-bottom: 56.25%;
    padding-top: 25px;
}

.ll-live-video-wrapper iframe {
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
}
//}

== 動画詳細部分の見た目を整える


次に動画詳細部分の見た目を整えます。
動画詳細部分はグローバルナビゲーションとほぼ同じ見た目になっています。


//emlist[][css]{
/* ライブステージページ：動画の詳細 */
.ll-video-detail {
  margin: 1em 0;
}
@media (min-width: 992px) {
  .ll-video-detail {
    margin: 0;
  }
}

/* ライブステージページ：動画の詳細タブ */
.ll-video-tabs {
  background-color: #ff50ac;
}

.ll-video-tabs > li > a {
  margin-bottom: 0 !important;
  text-transform: uppercase;
}

.ll-video-tabs > li > a:link,
.ll-video-tabs > li > a:visited {
  color: #fff;
}

.ll-video-tabs > li > a:hover,
.ll-video-tabs > li > a:focus {
  color: #ff188b;
}

.ll-video-tabs > li.active > a {
  color: #555;
}
//}

== 動画詳細部分の見た目を各描画領域ごとに整える


次に動画詳細部分の見た目を各描画領域ごとに整えます。
特にタブ内の文字は描画領域を小さくしていくとタブからはみ出すため、細かく調整していきます。


//emlist[][css]{
/* ライブステージページ：動画の情報タブの各描画領域ごとのスタイル定義 */
@media (min-width: 768px) {
  .ll-video-tabs > li > a {
    padding: 5px 0;
    border-bottom: 0;
    border-right: 1px solid #fff;
  }

  .ll-video-tabs > li:last-child > a {
    border-right: 0;
  }

  .ll-video-tabs > li > a:focus,
  .ll-video-tabs > li > a:hover {
    background-color: #ff92cb;
    color: #fff;
  }

  .ll-video-tabs > li.active > a {
    border-bottom: 0;
    background-color: #ff50ac;
    color: #fff;
  }

  .ll-video-tabs > li.active > a::after {
    content: "";
    display: block;
    position: absolute;
    bottom: 0;
    left: 0;
    width: 100%;
    border-bottom: 3px solid #ffdc00;
  }
}
@media (min-width: 992px) {
  .ll-video-tabs > li > a {
    font-size: 0.8125em;
  }
}
@media (min-width: 1000px) {
  .ll-video-tabs > li > a {
    font-size: 0.875em;
  }
}
//}

== 広告部分の見た目を整える


最後に広告部分の見た目を整えます。
ここはある程度Bootstrapによって整えられているので、最低限のスタイルを適用するだけです。


//emlist[][css]{
/* ライブステージページ：広告 */
.ll-livestage-ad {
  margin: 1em 0;
}
@media (min-width: 992px) {
  .ll-livestage-ad {
    margin: 0;
  }
}
//}

== CSSのまとめ


ライブステージのCSSをまとめると次のとおりになります。


//emlist[][css]{
/* ライブステージ：コンテンツ */
#ll-livestage-page main {
  padding: 1em 0;
  background-color: #dcdcdc;
}

/* ライブステージページ：見出し */
.ll-video-title-and-artist,
.ll-ad-title {
  margin-top: 0;
  margin-bottom: 16px;
}
//}