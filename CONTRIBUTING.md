ここでは「サイト制作の START:DASH!!」に貢献するためのヒントを書いていきます。

## 「サイト制作のSTART:DASH!!」とは

「サイト制作のSTART:DASH!!」は「ラブライブ！の参加者募集サイトの構成と作り方を具体的に説明する」というコンセプトで、アニメ内に出てきたラブライブ！募集サイトの作り方について書く本です。

## 「サイト制作のSTART:DASH!!」に主に関わっている人

- [kubosho](https://github.com/kubosho)
  - 執筆者(実装段階の章を担当)
  - 特設サイトの実装
- [fruitsnoodle](https://github.com/fruitsnoodle)
  - 執筆者(企画段階の章を担当)
  - 特設サイトの企画
- [GiantRobot](http://www.pixiv.net/member_illust.php?id=1223059)
  - 表紙イラスト担当

## 「サイト制作のSTART:DASH!!」の対象読者について

- ラブライブ！に興味がある人
- サイト制作に興味がある人
  - HTML や CSS をちょっとは知っているが、一つのサイトを作りきるまでは知識が足りない人

## 「サイト制作のSTART:DASH!!」の様々なやりとりについて

何か決めないといけなかったり、新規に執筆する際は、[Issues](https://github.com/o2project/start-dash-of-site-making/issues?state=open) から Issue を立てて、その Issue 内でやりとりをします。

## 新たな章や節を追加する際のガイドライン

1. まず Issue を立てます。タイトルは「[ChX-x] 章や節のタイトル」という形式にします。(例: [Ch1-1] ほにゃららについて)
  - 必ず「writing」というラベルをつけます。
1. 新たにブランチを作ります。ブランチ名は「writing/id/:issue-id」という形式にします。
1. 執筆します。
1. Pull Request を master に対して出します。出来るかぎりレビューしてからマージという形をとります。

## 誤字脱字を直す際のガイドライン

- 誤字脱字を直す際は、Issue を立てていただれば、こちら側で直します。
- Pull Request を出していただける場合は、出来るだけ branch を別で作って、そちらで直していただけると幸いです。あとは、特に問いません。ありがとうございます！

## コミットメッセージについて

[azu/release-changelog](https://github.com/azu/release-changelog) により、[CHANGELOG.md](CHANGELOG.md) を自動生成するため、以下のルールに沿った形で書くことを推奨します。

[conventional-changelog/CONVENTIONS.md at master · ajoslin/conventional-changelog](https://github.com/ajoslin/conventional-changelog/blob/master/CONVENTIONS.md)

[azu/promises-book](https://github.com/azu/promises-book)と同じく `feat`, `write`, `fix`, `docs` をコミットメッセージ内に含めることにより、CHANGELOG に含まれる対象になります。

とはいえ、分からない場合はとりあえず `chore` を使うと良いです。
