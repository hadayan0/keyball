# hadayan0 keyball

このリポジトリは、オリジナルの Keyball に対して hadayan0 向けの設定と機能差分を追加したものです。

主な変更対象は Keyball61 の `hadayan0` keymap です。

## オリジナルとの差分

### レイヤー3によるスクロール自動有効化を削除

レイヤー3へ移動しただけでスクロールモードが自動有効化される処理を削除しています。

スクロールモードの切り替えは、keymap上の明示的なキー操作に任せます。

関連PR: [#22 fix: remove layer-3 scroll auto-toggle](https://github.com/hadayan0/keyball/pull/22)

### レイヤーごとの上面LED色切り替え

アクティブなレイヤーに応じて、左右の上面LED色を切り替えます。

レイヤーごとの色は以下です。

- Layer 0: シアン
- Layer 1: 赤
- Layer 2: 黄
- Layer 3: 紫

関連PR: [#23 feat: レイヤーごとのLED色設定を追加](https://github.com/hadayan0/keyball/pull/23)

### スクロール方向の自動判定

`SSNP_FRE` 中のスクロール入力をジェスチャ単位で判定し、縦固定・横固定・斜め自由スクロールを自動選択します。

`SSNP_VRT` / `SSNP_HOR` は明示的な固定モードとして扱い、自動判定では上書きしません。

OLEDには自動判定状態を表示し、縦固定候補・横固定候補・自動固定・斜め確定などを確認できるようにしています。

関連PR: [#25 feat: スクロール方向の自動判定を追加](https://github.com/hadayan0/keyball/pull/25)

### 右master時のOLED表示向き修正

OLEDの回転判定を master / secondary 基準ではなく、物理的な左右基準に変更しています。

右側を master として使う場合でも、OLEDが正しい向きで表示されるようにします。

あわせて、右側 master 時に secondary 側のロゴ表示位置が寄らないように調整しています。

関連PR: [#27 fix: 右master時のOLED表示向きを修正](https://github.com/hadayan0/keyball/pull/27)

### 底面LED向けRGB効果の有効化

Remapで設定したRGB制御キーから利用できるRGBアニメーション効果を追加しています。

有効化している効果は以下です。

- Breathing
- Rainbow Swirl
- Twinkle

上面LEDはレイヤー色切り替えを優先するため、RGBアニメーションは主に底面LEDで見える想定です。

関連PR: [#30 底面LED向けのRGB効果を追加](https://github.com/hadayan0/keyball/pull/30)
