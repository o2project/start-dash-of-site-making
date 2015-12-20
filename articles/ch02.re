= サイト開発の準備

この章ではラブライブ！参加者募集サイトを実装する前の準備について書きます。

== 必要なツールの準備

はじめに、ラブライブ！参加者募集サイトの実装で必要なツールを準備します。
最低限必要なものを列挙していくと以下のものがあります。

 * ソースコードを書くためのエディターもしくはIDE
 * 表示確認用のブラウザー
 * 作業履歴を記録するためのバージョン管理ソフト

これらについて、ひとつずつ説明していきます。

=== エディターもしくはIDE

はじめに、ソースコードを書くためのエディターもしくはIDE（統合開発環境）を用意します。
エディターとIDEですが、エディターはIDEと比べて自分で設定できる部分が多いです。
そのため拡張性はエディターのほうが高いです。その分エディターの設定に時間がかかってしまうこともあります。
IDEはインストールしたときからある程度の設定がされています。その代わりエディターと比べて拡張性は低いです。

なのでより自分好みの設定にしたい場合はエディターを、設定をいろいろいじるのが面倒な場合はIDEを使うといいです。

エディターはWindowsとOS X共にAtom@<fn>{atom}やSublime Text@<fn>{sublimetext}がよく使われています。
IDEはWebStorm@<fn>{webstorm}やNetBeans@<fn>{netbeans}、Visual Studio Community Edition@<fn>{visualstudio}がよく使われています。
//footnote[atom][https://atom.io/]
//footnote[sublimetext][http://www.sublimetext.com/3]
//footnote[webstorm][https://www.jetbrains.com/webstorm/]
//footnote[netbeans][https://ja.netbeans.org/]
//footnote[visualstudio][https://www.visualstudio.com/ja-jp/products/visual-studio-community-vs.aspx]

=== ブラウザー

次に、サイトを表示確認するためにブラウザーの用意をします。
WindowsやOS Xの最新バージョンには次のブラウザーが最初からインストールされています。

 * Windows
 ** Edge、Internet Explorer
 * OS X
 ** Safari

しかしサイト開発ではこれらのブラウザーだけではなく、他のブラウザーでも表示を確認する必要があります。
他にインストールしておいたほうがいいブラウザーは、Google ChromeやMozilla Firefoxがあります。
Google ChromeやMozilla Firefoxは、最初からインストールされているブラウザーと比較した場合でも遜色ないもしくは上回るシェアがあります。
つまりEdgeやInternet Explorer、Safariだけではサイトを見る人の環境をカバーし切れないため、他のブラウザーもインストールしておく必要があります。

また開発者向けに提供されている開発版をインストールしたほうが、事前に次期バージョンでハマりそうな点が分かるのでおすすめです。

=== GitとGitHub

最後に、作業履歴を管理するためGitとGitHubを使います。
たとえば突然PCがブルースクリーンになってしまい、予期しないシャットダウンをしなければいけなくなったとします。
そのときGitに作業履歴が残っていれば、かなり前の作業まで遡ってしまうことが少なくなります。
GitはSourceTree@<fn>{sourcetree}をダウンロードして使うのがいいでしょう。もしGitについてあまり知らない場合は、拙著のSteins;Git@<fn>{steinsgit}を読んでみてください。
//footnote[sourcetree][https://ja.atlassian.com/software/sourcetree/overview]
//footnote[steinsgit][http://o2project.github.io/steins-git]

== 分からないことがあったときには？

サイトの実装をしていくうちに、分からないところが出てくる場合もあります。

たとえば「固有名詞が何を示すものなのか分からない」「必要とされている機能を実現する方法が分からない」「なぜエラーになるのか分からない」が挙げられます。

そういった際どのように解決するかを書きます。

=== 検索する

まずは検索します。検索したときに結果が出やすい手法はいくつかあります。

はじめに「CSSで背景色をつけるやり方」と検索するより、「CSS 背景色 やり方」のように単語で区切るほうが検索結果の件数は増えます。
検索エンジンは「CSSで背景色をつけるやり方」のような文章が苦手です。
そのため文章よりも単語ごとに区切ったほうが検索結果の件数は増えます。

また、より入門的な内容を探したい場合「○○ とは」で検索するのがいいです。
理由は入門的な記事のタイトルが「○○ とは」と書く傾向にあるためです。
たとえばJavaScriptの初心者向け記事を探したい場合は「JavaScript とは」といった感じで検索します。

次に、JavaScriptでエラーメッセージが出力された場合、エラーメッセージをそのまま検索することです。
エラーメッセージをそのまま検索することで、解決方法が出てきやすいです。
しかしだいたい英語なので、そこは頑張って内容を読み取るしかないです。

最後に、Google検索結果内の「検索ツール - 期間指定」を使ってなるべく新しい情報のみ検索します。
CSSやJavaScriptは2011年以前の情報があまり役に立ちません。
期間を絞ることで新しい情報にたどりつきやすくします。

しかし、初期状態では期間設定の使い勝手があまりよくありません。
具体的には期間設定が「1ヶ月」の後は「1年」となってしまうため「3ヶ月以内」などは指定できません。
これに関してはAdd Search Options@<fn>{search-options}というGoogle Chrome拡張機能を使います。
この拡張機能を使うことにより、期間指定に「3ヶ月以内」と「6ヶ月以内」が増えます。
//footnote[search-options][https://chrome.google.com/webstore/detail/add-search-options/kaifgnoibnjldmdkkfogenbfbfgcbiao]

=== 周りの人に聞く

検索をしてもいい情報に巡りあえないことがあります。その場合、周りに聞ければ聞いたほうがいいです。

聞く前にまずは検索したり問題の概要をまとめます。これにより聞く側にとらせる時間が少なくなります。
聞き方としてはおそらく解答にかかるであろう時間を予測して、「『○○』について聞きたいのですが、×分ほど時間はありますか」と聞くのがいいです。
この「○○」に入る言葉は、たとえば「ある機能の実装方法」ということが入ると思います。

また聞く相手を間違えないようにします。
たとえばプログラムのことをエンジニア以外に聞いても、ほとんどの場合は求める回答が返ってこないと思います。

== ファイル構成

それではいよいよサイト作成に入っていきます。はじめにファイル構成を考えます。
今回作成するサイトのファイル構成を考えると@<list>{file-structure}のようになります。
@<tt>{index.html}はトップページ、@<tt>{livestage.html}はライブステージページ用のHTMLとなります。
ディレクトリーとしては@<tt>{external}・@<tt>{styles}・@<tt>{scripts}・@<tt>{images}の4つがあり、その中に各ファイルを置く想定です。

//list[file-structure][今回のファイル構成]{
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

各ディレクトリーには、次の規則に則ってファイルを置きます。

 * external
 ** CSS・JavaScript問わず、ライブラリを置くディレクトリー
 * styles
 ** CSSファイルを置くディレクトリー
 * scripts
 ** JavaScriptファイルを置くディレクトリー
 * images
 ** 画像ファイルを置くディレクトリー

== ライブラリ選定

ファイル構成を決めたところで、今回のサイトを実装するにあたって必要なCSSやJavaScriptのライブラリ選定をおこないます。

=== ライブラリとは

ライブラリという聞き慣れない単語が出て「??」となった人もいるかもしれません。
選定の前にライブラリについて説明します。

ライブラリは、汎用性が高いプログラムを他のプログラムからも使えるようにひとまとまりとしたものです。
たとえばCSSであればBootstrap、JavaScriptでいえばjQueryなどがライブラリです。
いまあなたが見ているこの文章も、自動的に日本語の文章をチェックするtextlint@<fn>{textlint}というライブラリを使い、自動校正しながら書いています。
//footnote[textlint][https://github.com/textlint/textlint]

=== ライブラリを選ぶ基準

ライブラリについて説明したところで、自分がライブラリを選ぶときの基準について、いくつか書きます。

==== 利用実績

はじめに、そのライブラリが広く使われているかを見ます。
広く使われていれば、ライブラリを使う上で何か困って検索をしたときに情報が出てきやすいためです。

たとえばCSSのライブラリであるBootstrap@<fn>{bootstrap}だとページ下部にBootstrapを使ったサイト一覧が掲載されています。
JavaScriptのライブラリであるjQuery@<fn>{jquery}はAmazon上にてjQueryで検索@<fn>{jquery-amazon}するとjQuery関連の本が大量に表示されます。
//footnote[bootstrap][http://getbootstrap.com/]
//footnote[jquery][http://jquery.com/]
//footnote[jquery-amazon][Amazonの「jQuery」の検索結果：http://www.amazon.co.jp/s/field-keywords=jquery]

このように、利用実績やライブラリについて本が書かれているかということをまず見ます。

==== IssueやPull Request、最新コミット日時

次に、GitHub上にあるIssueやPull Requestの件数と最新コミット日時です。
利用実績で見るのは公開されてからある程度時間が経過し、広く使われるようになったライブラリのみ使える判断材料です。
つまり定番と言われるライブラリに対してのみ判断材料として使えます。

そこでIssueやPull Requestの件数と最新コミット日時を見ます。
たとえば最新コミット日が6か月前だった場合、IssueやPull Requestの多さは「放置されているから」ということになります。
放置されたライブラリを使う場合、自分達でなんとかしないといけなくなる場面が増えてしまいます。

自分達でなんとかするのであればいいですが、そうでない場合は活発なライブラリを選ぶのがいいです。

==== ソースコードの流れを把握しやすい

次に、ソースコードの流れを把握しやすいか見ます。
何か困ったときにドキュメントを見ますが、それでも解決できない場合はソースコードを読む必要があるためです。
そのときにソースコードの流れを把握できなかった場合、解決方法が見つからずつらくなります。

全体把握しやすいライブラリとしてたとえばBackbone.js@<fn>{backbone}が挙げられます。
ソースコード@<fn>{backbone-source}はまとまりの単位が小さいため流れを追いやすいです。
ソースコードの行数も1,877行（2015/7/10現在）なので全体を読もうと思えば読めます。
//footnote[backbone][http://backbonejs.org/]
//footnote[backbone-source][https://github.com/jashkenas/backbone/blob/master/backbone.js]

==== ドキュメントがそろっている

最後に、ドキュメントがあり、かつ読みやすいかを見ます。もちろん両方そろっているのが好ましいです。
両方そろっている例としてはflipsnap.js@<fn>{flipsnap}が挙げられます。
//footnote[flipsnap][http://hokaccha.github.io/js-flipsnap/]

flipsnap.jsはドキュメントに次の項目がよくまとまっています。そのため使い方に困らないライブラリとなっています。

 * どういった環境に対応しているか
 * どのような準備をすれば動作するようになるか
 * 使い方の例

== ライブラリの選定CSS編

ここまでライブラリ選定時の基準について書いてきました。ここからは実際にライブラリ選定をしていきます。
はじめにCSSのライブラリから選定していきます。

今回CSSのライブラリはBootstrapのテーマであるNico@<fn>{nico}を使います。
//footnote[nico][http://nico.kubosho.com/]

選定した理由としては、今回デザイナーがいない中ラブライブ！参加者募集サイトの見た目をアニメに近づけたいという思いがありました。
ラブライブ！参加者募集サイトは、Bootstrapを使って作られたサイトの見た目に似ているためBootstrapを使うことにしました。

ラブライブ！参加者募集サイトはピンク系の配色なのですが、Bootstrap本体はピンク系の配色ではありません。
なので今回のためにHonokaというBootstrapテーマ@<fn>{honoka}を元に、NicoというBootstrapのテーマを作りました。
//footnote[honoka][http://honokak.osaka/]

NicoはGitHubからダウンロードします。
@<tt>{https://github.com/kubosho/Nico/releases/latest}にアクセスするとNicoの最新バージョンが表示されます。
Downloadsを見ると@<img>{nico}のようにzipファイルがあるのでクリックしてダウンロードします。
ダウンロードが終わったらzipを展開して、中のファイルを@<tt>{external}ディレクトリー内に入れておきます。

//image[nico][Nicoのダウンロード]{
//}

== ライブラリの選定JavaScript編

次にJavaScriptのライブラリを選定していきます。
今回JavaScript側で実装する機能として、カルーセルがあります。

カルーセルはNike@<fn>{nike}などで使われている「注目させたい複数の画像などをつぎつぎと横にスライド表示する」ものです。
このカルーセルを実現するためのライブラリはslick@<fn>{slick}にします。
slickを使うためにjQueryも使います。
//footnote[nike][http://www.nike.com/jp/ja_jp/]
//footnote[slick][http://kenwheeler.github.io/slick/]

選定した理由は2つあります。
ひとつめとして、ドキュメントがそろっておりカルーセルを実装するときに困らないためです。これによりやりたいことがすぐ実現できます。
ふたつめとして、slickは開発が活発なことです。ただ互換性がない更新も起こるので最新版に更新する際は注意が必要です。

それではslickをダウンロードします。
@<tt>{http://kenwheeler.github.io/slick/}にアクセスしたらページ上部の「get it now」をクリックします。
すると「Download Now」というボタンが表示されるのでボタンをクリックします（@<img>{slick}）。
するとzipファイルがダウンロードされるので、zipを展開して中のファイルを@<tt>{external}ディレクトリー内に入れておきます。

//image[slick][slickのダウンロード]{
//}

続いてjQueryもダウンロードします。
@<tt>{https://jquery.com/}にアクセスしたら「Download jQuery」と書かれたボタンをクリックします（@<img>{jquery-01}）。

//image[jquery-01][jQueryのダウンロード]{
//}

ボタンを押すと各種jQueryがダウンロードできるページに遷移します。
何種類かリンクがあるうち「Download the compressed, production jQuery」というリンクを右クリックして「リンク先を保存」をクリックします（@<img>{jquery-02}）。
保存先は@<tt>{external}ディレクトリー内に保存します。

//image[jquery-02][production jQueryのリンク]{
//}

これでライブラリの選定が終わりました。次章からはサイトの実装をしていきます。
