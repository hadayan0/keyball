# Contributing

このリポジトリでは、通常開発用の `develop` とリリース用の `main` を分けて運用します。

## ブランチ運用

- `develop`: 通常の開発ブランチ
- `main`: リリースブランチ

機能追加・修正は原則として `develop` に取り込みます。

リリース時は `develop` から `main` へPull Requestを作成します。

## Pull Requestのマージ方針

通常の機能追加・修正PRを `develop` に取り込む場合は、必要に応じてSquash mergeを使って構いません。

一方で、`develop` から `main` へ反映するリリースPRでは、Squash mergeを使いません。

GitHub UIでリリースPRをマージする場合は、`Create a merge commit` を選択します。

## 理由

`develop` から `main` へのリリースPRをSquash mergeすると、`develop` 上の複数コミットが `main` 上の別の1コミットに潰されます。

その結果、Gitの履歴上は `develop` のコミットが `main` に取り込まれていないように見え、次回リリース時に不要なコンフリクトが発生しやすくなります。

`Create a merge commit` を使うと、`main` のマージコミットが `develop` 側の履歴を親として持つため、`develop` の内容が `main` に取り込まれたことをGitが追跡できます。

## リリース後の確認

`main` へのマージ後は、以下を確認します。

- 関連Issueが意図どおりクローズされていること
- 必要なリリースタグが作成されていること
- `main` と `develop` の履歴が不要に分岐していないこと
