
= サイトの要件定義と要素整理をしてみよう


この章では、サイトを作る際の要件定義と要素の整理について解説します。


== 要件定義とは


制作が始まる前の上流工程として、要件定義という段階があります。Web サイトを制作する際に、このような内容を要件定義したほうが良いです。

 * どんな Web サイトを作るか
 * どんな機能が必要か


ざっくりした内容ではなく、具体的に書くことをオススメします。


== なぜ要件定義


最初からざっくりした考えをまとまらないと、企画資料や制作が途中でぐるぐる変わったりして、何回も同じものを修正・作り直しすることになる可能性があります。



逆に、事前から細かく機能を決めれば「これも入れたい」「それも入れたい」など、作る途中で思いつきのアイディアに影響されず、一気にサイトを作ることが可能です。


== 今回の要件定義について


今回のラブライブ！参加者募集サイトの制作を例として説明すると、

 * どんな Web サイトを作るか
 ** ラブライブ！のアニメで登場した、アイドルコンテスト募集サイト」を作る


今回はすでに設計されたものがあるため、手短く要件定義することができます。



通常、まずはターゲットユーザを定義し、ターゲットユーザにどんな体験を与えたいのかを考えないといけないです。
ここではすでにあったものから推定すれば、もともとサイトを作った人が何を考えたかがわかると思います。
今回の制作は、工数などを考えて、TOP ページとライブ中継ページの2ページだけにすることにしました。
と、このような必要かどうかの判断も、要件定義の一部です。


== 要素とは


ウェブページにあるボタンや画像、テキストなど、様々な情報表示・動作するものが、この Web サイトの「要素」と呼ばれます。



どの要素をどの位置に置くかは、ターゲットユーザを分析した上で設計者よりきちんと考えて最も合理的だと思われる位置に決まります。



ターゲットユーザが製作者が想定した目的に沿ってよく使うボタン・機能をクリックしやすいところに置くや、設計者がユーザに一番伝えたいことを見やすいところに置くなど…いろんなことを考えて「最も合理的」な方向を目指して設計を行うべきです。



今回はすでにあるサイトを作ることなので、「要素や位置が決められた」状態で製作用の企画資料を作れば OK という、深く考えることがいらず、比較的に楽な作業になります。


== 今回の要素整理について


アニメ内のキャプチャからサイトの構成要素を分析してみます。



まず、Web サイトのグローバルメニュに記載されている内容はこちらーー

 * TOP
 * LIVE STAGE
 * OUTLINE
 * SCHEDULE
 * SPECIAL
 * LINK
 * FAQ


1つずつ見ていきます。


=== TOP


字面通り、Web サイトの TOP ページを意味するはずで、よくある機能で、ユーザが Web サイトを見ている時、どのページにいても1クリックで TOP ページへ戻ることができます。



人の閲覧習慣に準じて一番見やすい左上に置いたのは、このサイトの設計者である人に、ターゲットユーザにとって一番大事、もしくはターゲットユーザに一番クリックしてほしいと思われるためです。
また、TOP ページを構成する要素はグローバルメニュ以外、各ページの共通要素もある。



ヘッダにロゴ・メールマガジン・シェア・つぶやき・お問い合わせがあって、フッタには利用規約や権利情報表示などが掲載されている。


=== LIVE STAGE


アニメ内でネット生中継するページだと思われます。そのシーンでは CONTENTS というテキストになっているが、位置的にはこれと同じです。



クリックでページ遷移すると、メニュにあるテキストが変わるという事自体はできなくもないが、実際に必要のない場合がほとんどなので、ここでは全部 LIVE STAGE に統一します。
そして、この LIVE STAGE の中身は、キャプチャから見て推測するとこういった要素で構成されているかと思います。

 * 映像タイトル
 * 出演者
 * 映像生中継
 * 映像情報
 * ユーザコメント
 * 投票
 * 広告スペース


参加するアイドルグループが見る OUTLINE や SCHEDULE などがより左に位置することは、設計者が参加者の他に、ライブをネット上で見るファンも大事にするからだと思われます。



最初に書いた要件定義を見ると、他のページは今回全部作る必要がないため、実はここまで書いて OK 。どこまで資料が必要なのかは、要件定義で明確化されているため、余計な作業を増やして時間を無駄遣いすることがなくなるでしょう。



余興でこのサイトに関して筆者の推測を下に置きます。参考にしてみてください。


=== OUTLINE


テキストで推測すると、たぶんコンテストの概要や募集要項などの内容が記載されています。


=== SCHEDULE


テキストで推測すると、たぶんコンテストの選考スケジュールや催行スケジュールなどの内容が記載されています。


=== SPECIAL


テキストだけで何が掲載されているか推測しにくいけど、たぶん歴代優勝者コメントやコラボキャンペーンなどの情報だと思われます。


=== LINK


関連法人、個人の公式サイトなどが掲載されていると思われます。


=== FAQ


よくある質問やお問い合わせなどの内容が掲載されていると思われます。



以上の要件定義、要素整理に基いて、サイトマップと仕様書などの作成をしていきます。



【ch001@<b>{pic001】
画像ダウンロード：https://www.dropbox.com/s/3vb7ghj0qopau5e/ch001}pic.zip?dl=0


== サイトマップの作成


Web サイトのページ数とページの階層を表示する図がサイトマップです。
サイトマップがあれば、サイトに何ページあるかと、ページとページの関連性などが一見で分かる。それで工数なども推測できます。
ページ数の多いサイトなら、サイトマップがあれば制作もだいぶ早くなるし、ページ漏れのリスクもだいぶ減らすことができます。


== サイトマップの書き方


個人的にオススメなツールはエクセルです。
画像を作るというイメージでパワーポイントがいいかと思う方もいるかもしれないが、実はセル結合したり枠線を描画したりするほうが楽になります。
特に大規模のサイトのサイトマップを書く際に、エクセルは無限に書けるので、非常に使いやすいと思います。
エクセルがない場合は、グーグルドライブのスプレッドシートも最低限な機能揃っていますからおすすめです。



作るときは、階層などを意識して、外部リンクを明確に表示するよう作ったほうがおすすめです。


== 今回のサイトマップについて


第一章で書いた「要件整理」をちゃんとまとまれば、サイトマップはほぼ考えずに作れると思います。
今回作るのは TOP と LIVE STAGE の2ページです。さらに、LIVE STAGE ページ内に、ポップアップ画面を設計しました。
一番上層のページを TOP にして、下層に LIVE STAGE を書きます。他に外部リンクである SNS ボタンをつけて完成です。
今回は極めて簡単な内容だけど、本当は各下層ページに更に下層ページある、ポップアップやエラーページまで、サイトにあらゆる表示可能なページを全部作らないといけないです。
なので、一回ドキュメントを起こす前に、紙で草稿を書くこともおすすめです。



【ch001@<b>{pic002】
画像ダウンロード：https://www.dropbox.com/s/3vb7ghj0qopau5e/ch001}pic.zip?dl=0


== ワイヤーフレームと仕様書の作成


ワイヤーフレームはサイトの各ページごとにある、1ページにある要素の種類・数・大体の位置を示すものです。
仕様書は、それぞれの要素に具体的に何をどう表示するか、動作の演出などを明記するものです。
場合によって、両方をまとめて書くこともあruが、分けて書くこともあります。
サイトの内容が豊かであればあるほど、仕様書の内容が多くなるので分けて書くことをおすすめです。
1ページずつにワイヤーフレームと仕様書は必要なので、ページ数が多ければ多いほど、ワイヤーフレームと仕様書のページ数も多くなります。


== ワイヤーフレームと仕様書の心得


ツール：ワイヤーフレームはパワーポイントでもエクセルでもいいが、仕様書はエクセルをおすすめです。
要素の分類：大枠3種類に分けられるーー画像、テキスト、ボタン。更に動作の要素を入れるとーースクロール、ポップアップなど。色で分けるか、もしくは形で分けるように書くことがおすすめです。
余計な情報を入れない：ワイヤーフレームはあくまで要素がページ内にあることを示すための資料なので、色などはなるべく入れないことがおすすめです。
何故かと言うと、ワイヤーフレームを参考にデザイナがグラフィックと UIの制作を行うので、余計な情報があると資料自体がわかりづらくなり、混乱を招く可能性があります。
どんなデザインがいいのかは、アートディレクタの仕事なので、企画資料としては見やすいようにすることが最優先です。
仕様書は箇条書き：1つの要素、1つの動作に対して、箇条書きする必要があります。仕様書を見るエンジニアさんは、考えずにコーディングできることを目指します。


== 今回のワイヤーフレームと仕様書について


要件定義ですでにわかったのは、今回のページ数も要素も少ないです。
なので作業を早めにするため、ワイヤーフレームと仕様書をまとめて書きました。
1ページずつ見ていきましょう。


=== TOP


共通のヘッダ、グローバルメニュ、フッタ以外、アニメ内では、画像の展示のみに見えます。
画像の表示方法はカルーセルということはわかりますが、下にあるドットがアニメのキャプチャから見るとフッタ内になっているというのが極めて可能性低い設計です。
LIVE STAGE にもドットがフッタ内にあるけど、生中継のページになっているので、実際のサイトでしたら映像にはこういう仕様も取らないはずだと思われます。
なので、考えた結果として、画像のカルーセル表示だけにしました。
推測した結果、トップページの訴求は、「コンテストの盛り上がり」と「歴代受賞者の宣伝」で、華やかな画像をいっぱい見れる設計だと思われます。



【ch001@<b>{pic003】
画像ダウンロード：https://www.dropbox.com/s/3vb7ghj0qopau5e/ch001}pic.zip?dl=0


=== LIVE STAGE


共通要素の他に、一見「ニコニコ動画」の仕様に似ています。
生中継はもちろん映像が中心で、ほかの機能は映像と関連するものになっていると想定している。
更に、映像エリアの隣に広告スペースに見えます。おそらくここに広告が掲載されているでしょう。
ちょっと説明すると、もともと「ニコニコ動画」みたいなコメント機能があると思われますが、今回は工数が足りないためちょっと改造して、「何かをコメントする」という似てる体験をユーザに与えるため SNS コメントという形にしました。



【ch001@<b>{pic004】
画像ダウンロード：https://www.dropbox.com/s/3vb7ghj0qopau5e/ch001}pic.zip?dl=0


=== ほかポップアップ


「サイトマップ」について書いたが、エラーページも想定しました。
ただしエラーが発生しない限り、エラーページも見れないので、検証がほとんどないと思われるため、ここではエラーページの代わりに「まだ作ってない」のポップアップを用意しました。
ほかに、映像コメントの体験を与えるための SNS コメントポップアップと、投票結果再現するための結果ポップアップを作りました。
上記ポップアップは、1ページとして存在しないため、サイトマップでは仕様をページと区別して反映しました。



【ch001@<b>{pic005】
【ch001}pic006】
【ch001@<b>{pic007】
画像ダウンロード：https://www.dropbox.com/s/3vb7ghj0qopau5e/ch001}pic.zip?dl=0

