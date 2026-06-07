# Keyball Series

![Keyball61](./keyball61/doc/rev1/images/kb61_001.jpg)

Keyball series is keyboard family which have 100% track ball.

Keyboards in the family are:

* Available
    * Keyball39: split + 39 keys + a track ball
    * Keyball44: split + 44 keys + a track ball
    * Keyball61: split + 61 keys + a track ball
* Unavailable
    * Keyball46 (first one!)
    * One47

## Where to Buy

|Keyboard   |Shirogane Lab / 白銀ラボ                                   |Yushakobo / 遊舎工房                       |
|-----------|-------------------------------------------|-----------------------------------------------------------|
|Keyball39  |<https://shiroganelab.com/products/keyball39> |<https://shop.yushakobo.jp/products/5357>  |
|Keyball44  |<https://shiroganelab.com/products/keyball44> |<https://shop.yushakobo.jp/products/8337>  |
|Keyball61  |<https://shiroganelab.com/products/keyball61> |<https://shop.yushakobo.jp/products/5358>  |

## Build Guide

*   Keyball39:
    [English/英語](/keyball39/doc/rev1/buildguide_en.md),
    [日本語/Japanese](./keyball39/doc/rev1/buildguide_jp.md)
*   Keyball44:
    [English/英語](./keyball44/doc/rev1/buildguide_en.md),
    [日本語/Japanese](./keyball44/doc/rev1/buildguide_jp.md)
*   Keyball61:
    [English/英語](./keyball61/doc/rev1/buildguide_en.md),
    [日本語/Japanese](./keyball61/doc/rev1/buildguide_jp.md)

## Firmware

See [document for firmware source code](./qmk_firmware/keyboards/keyball/readme.md).

### Pre-compiled Firmwares

(TO BE DOCUMENTED)

## hadayan0 Customizations

このリポジトリでは、オリジナルの Keyball に対して hadayan0 向けの設定と機能差分を追加しています。

主な変更対象は Keyball61 ですが、keymapだけでなく、Keyball共通処理やKeyball61固有処理にも変更を含みます。

### hadayan0 keymapの特徴

Keyball61向けに `hadayan0` keymapを追加しています。

このkeymapは、レイヤーLED、スクロール、OLED、RGB効果などの利用者向け設定をまとめたものです。

主な有効化機能は以下です。

- VIA / Remap対応
- OLED表示
- RGBLIGHT
- 音量・ミュートキー対応

また、RGB制御、CPI変更、スクロール設定、Keyball設定の保存/リセット用キーを配置しています。

関連PR: [#21 Chore/recreate hadayan0 from via](https://github.com/hadayan0/keyball/pull/21)

### レイヤーごとの上面LED色

アクティブなレイヤーに応じて、左右の上面LED色を切り替えます。

レイヤーごとの色は以下です。

- Layer 0: シアン
- Layer 1: 赤
- Layer 2: 黄
- Layer 3: 紫

関連PR: [#23 feat: レイヤーごとのLED色設定を追加](https://github.com/hadayan0/keyball/pull/23)

### 底面LED向けRGB効果

Remapで設定したRGB制御キーから、RGBアニメーション効果を利用できます。

有効化している効果は以下です。

- Twinkle

上面LEDはレイヤー色切り替えを優先するため、RGBアニメーションは主に底面LEDで見える想定です。

関連PR: [#30 底面LED向けのRGB効果を追加](https://github.com/hadayan0/keyball/pull/30)

### 音量・ミュートキー対応

Remapで割り当てた `Mute` / `Vol-` / `Vol+` がWindowsへ送信できるように、`EXTRAKEY_ENABLE` を有効化しています。

ファーム容量確保のため、One Shotキー機能は無効化しています。Remapで `OSM` / `OSL` を使う場合は、`NO_ACTION_ONESHOT` の見直しが必要です。

関連PR: [#36 Windows向け音量・ミュートキーを有効化する](https://github.com/hadayan0/keyball/pull/36)

### スクロール操作

スクロールモードは、keymap上の明示的なキー操作で切り替えます。

オリジナルとの差分として、レイヤー3へ移動しただけでスクロールモードが自動有効化される処理は削除しています。

関連PR: [#22 fix: remove layer-3 scroll auto-toggle](https://github.com/hadayan0/keyball/pull/22)

## Keyball共通処理の変更

### スクロール方向の自動判定

`SSNP_FRE` 中のスクロール入力をジェスチャ単位で判定し、縦固定・横固定・斜め自由スクロールを自動選択します。

`SSNP_VRT` / `SSNP_HOR` は明示的な固定モードとして扱い、自動判定では上書きしません。

OLEDには自動判定状態を表示し、縦固定候補・横固定候補・自動固定・斜め確定などを確認できるようにしています。

関連PR: [#25 feat: スクロール方向の自動判定を追加](https://github.com/hadayan0/keyball/pull/25)

### OLED表示

OLEDの表示情報として、キー入力、トラックボール情報、レイヤー情報を表示します。

スクロール方向の自動判定が有効な場合は、判定状態もOLED上で確認できます。

関連PR: [#21 Chore/recreate hadayan0 from via](https://github.com/hadayan0/keyball/pull/21), [#25 feat: スクロール方向の自動判定を追加](https://github.com/hadayan0/keyball/pull/25)

### 右master時のOLED表示向き修正

OLEDの回転判定を master / secondary 基準ではなく、物理的な左右基準に変更しています。

右側を master として使う場合でも、OLEDが正しい向きで表示されるようにします。

あわせて、右側 master 時に secondary 側のロゴ表示位置が寄らないように調整しています。

関連PR: [#27 fix: 右master時のOLED表示向きを修正](https://github.com/hadayan0/keyball/pull/27)

## その他の変更

### ビルド互換性

`pressing_keys` の初期化で使う空白表示文字を、静的初期化子として扱えるように修正しています。

ユーザー向け機能差ではありませんが、hadayan0版のビルドを成立させるための差分です。

関連PR: [#20 fix: make BL valid for static initialization](https://github.com/hadayan0/keyball/pull/20)
