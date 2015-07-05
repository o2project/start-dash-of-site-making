サイト制作の START:DASH!!
===

それは僕たちの語られなかった制作秘話――

「ラブライブ！の参加者募集サイトの構成と作り方を具体的に説明する」というコンセプトの本です。

執筆方法
---

現時点では `draft` ディレクトリ配下に Markdown 形式でファイルを設置し、そのファイルを編集していきます。

ファイルを追加した場合は `settings/catalog.yml` にも追加したファイルの名前を書いておくのを忘れないようにしてください。

全ての章や節が Markdown で書き終わった時点で `src` 配下の Re:VIEW 形式のファイルを直接編集するようにしていきます。

コンパイル方法
---

まずはじめに以下のコマンドを実行します。

```bash
rake md2review
```

これは後ほど `*.re` 形式のファイルを直接編集する段階になったらいらなくなる作業ですが、現段階では必要な作業となります。

その後、出力したいファイルに応じて以下のコマンドを実行します。

### HTML へのコンパイル

```bash
rake html
```

### ePub へのコンパイル

```bash
rake epub
```

### PDF へのコンパイル

PDF を出力する場合は、事前に TeX のインストールが必要です。

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

状況によって、下記のいずれかのライセンスが適用されます。

### サンプルコード

MIT License

### 文章

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="クリエイティブ・コモンズ・ライセンス" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a><br /><a xmlns:cc="http://creativecommons.org/ns#" href="https://o2p.jp" property="cc:attributionName" rel="cc:attributionURL">O2 Project</a> 作『<span xmlns:dct="http://purl.org/dc/terms/" href="http://purl.org/dc/dcmitype/Text" property="dct:title" rel="dct:type">サイト制作の START:DASH!!</span>』は<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">クリエイティブ・コモンズ 表示 - 非営利 - 継承 4.0 国際 ライセンス</a>で提供されています。<br />
<a xmlns:dct="http://purl.org/dc/terms/" href="http://www.lovelive-anime.jp/" rel="dct:source">http://www.lovelive-anime.jp/</a> にある作品に基づいている。
