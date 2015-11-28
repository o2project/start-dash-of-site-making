サイト制作のSTART:DASH!!
===

[![Build Status](http://img.shields.io/travis/o2project/start-dash-of-site-making.svg)](https://travis-ci.org/o2project/start-dash-of-site-making)

それは僕たちの語られなかった制作秘話──

「ラブライブ！参加者募集サイトの構成と作り方を具体的に説明する」同人誌です。C89 3日目 東ム39bで頒布します。

執筆方法
---

現時点では`draft`ディレクトリ配下にMarkdown形式でファイルを追加・編集していきます。
ファイル追加の際、`settings/catalog.yml`にもファイルの名前を追加しておきます。
全ての章や節がMarkdownで書き終わったら、`src` 以下にあるRe:VIEW形式のファイルを直接編集していきます。

コンパイル前の準備
---

まずは何らかの方法でRubyをインストールします。おすすめはrbenv + ruby-buildの構成です。
次にbundlerをインストールします。インストールが終わったら`bundle install`を以下の通りに実行します。

```bash
gem install bundler
bundle install --path vendor/bundle
```

コンパイル方法
---

まずはじめに以下のコマンドを実行します。

```bash
rake md2review
```

これは後ほど`*.re`形式のファイルを直接編集する段階になったらいらなくなる作業ですが、現段階では必要な作業となります。
その後、出力したいファイルに応じて以下のコマンドを実行します。

### HTMLへのコンパイル

```bash
rake html
```

### ePubへのコンパイル

```bash
rake epub
```

### PDFへのコンパイル

PDFを出力する場合、事前にTeXのインストールが必要です。

```bash
rake pdf
```

著者
---

- [kubosho](https://github.com/kubosho)
- [fruitsnoodle](https://github.com/fruitsnoodle)

表紙イラスト
---

- [GiantRobot](http://www.pixiv.net/member.php?id=1223059)

ライセンス
---

状況によって、いずれかのライセンスが適用されます。

### サンプルコード

MIT License

### 文章

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="クリエイティブ・コモンズ・ライセンス" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a><br /><a xmlns:cc="http://creativecommons.org/ns#" href="https://o2p.jp" property="cc:attributionName" rel="cc:attributionURL">O2 Project</a> 作『<span xmlns:dct="http://purl.org/dc/terms/" href="http://purl.org/dc/dcmitype/Text" property="dct:title" rel="dct:type">サイト制作の START:DASH!!</span>』は<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">クリエイティブ・コモンズ 表示 - 非営利 - 継承 4.0 国際 ライセンス</a>で提供されています。<br />
<a xmlns:dct="http://purl.org/dc/terms/" href="http://www.lovelive-anime.jp/" rel="dct:source">http://www.lovelive-anime.jp/</a> にある作品に基づいている。
