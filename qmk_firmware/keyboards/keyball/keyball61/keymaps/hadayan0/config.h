/*
This is the c configuration file for the keymap

Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#ifdef RGBLIGHT_ENABLE
//#    define RGBLIGHT_EFFECT_BREATHING
//#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
//#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//#    define RGBLIGHT_EFFECT_SNAKE
//#    define RGBLIGHT_EFFECT_KNIGHT
//#    define RGBLIGHT_EFFECT_CHRISTMAS
//#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
//#    define RGBLIGHT_EFFECT_RGB_TEST
//#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_TWINKLE

// レイヤーごとに上面LEDの色を上書きする。
#    define RGBLIGHT_LAYERS
#endif

#define TAP_CODE_DELAY 5

// 高解像度スクロールを有効化する場合は、以下2つをコメントアウト解除する。
// その場合、QMK 0.22.14 に高解像度スクロール対応をbackportした
// hadayan0/qmk_firmware の `hadayan0/hires-scroll-backport-0.22.14`
// branch を使用する必要がある。
//#define POINTING_DEVICE_HIRES_SCROLL_ENABLE
//#define WHEEL_EXTENDED_REPORT

#define KEYBALL_AUTO_SCROLLSNAP_ENABLE 1
// 利用者ごとに好みが分かれるため、斜めスクロール判定の調整値は
// keymap側で上書きしておく。現時点ではライブラリ既定値と同じ。
// スクロール入力が止まったあと、どれだけ経ったら判定状態をリセットするか(ms)。
#define KEYBALL_AUTO_SCROLLSNAP_RESET_TIMER 300
// 縦/横どちらかに寄っていると確定するまでの時間(ms)。小さいほど斜めスクロールになりづらい。
#define KEYBALL_AUTO_SCROLLSNAP_CONFIRM_TIMER 10
// 縦/横どちらかに寄っていると見なす比率。大きいほど斜め扱いになりやすく、小さいほど縦横固定しやすい。
#define KEYBALL_AUTO_SCROLLSNAP_RATIO 2

//#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 2

// ファーム容量削減のため、ワンショットキー(OSM/OSL)を無効化する。
// RemapでOSM/OSLを使う場合は、この定義をコメントアウトする。
#define NO_ACTION_ONESHOT
