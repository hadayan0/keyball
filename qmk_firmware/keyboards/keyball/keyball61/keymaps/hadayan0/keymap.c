/*
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

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "keymap_jp.h"

#include "../../../lib/keyball/keyball.h"

bool is_current_layer_mouse(void);

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_BSPC  ,
    KC_TAB   , KC_Q     , KC_LANG2 , KC_LANG1 , KC_E     , KC_COMM  ,                                  KC_W     , KC_R     , KC_Y     , KC_T     , KC_P     , KC_SPC   ,
    KC_LCTL  , KC_I     , KC_A     , KC_U     , KC_O     , KC_DOT   ,                                  KC_G     , KC_H     , KC_J     , KC_K     , KC_L     , KC_ENT   ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_SLSH  , JP_COLN  ,            TO(2)    , KC_S     , KC_BTN1  , KC_BTN3  , KC_BTN2  , SCRL_MO  , KC_D     ,
    MO(3)    , JP_AT    , KC_LGUI  , KC_LALT  , KC_MINS  , KC_N     , KC_F     ,            KC_B     , KC_M     , _______  , _______  , _______  , KC_RSFT  , KC_RCTL
  ),

  [1] = LAYOUT_universal(
    _______  , KC_NUM   , KC_KP_7  , KC_KP_8  , KC_KP_9  , KC_PSLS  ,                                  _______  , _______  , _______  , _______  , _______  , RESET    ,
    _______  , KC_PDOT  , KC_KP_4  , KC_KP_5  , KC_KP_6  , KC_PAST  ,                                  _______  , _______  , _______  , _______  , _______  , KBC_SAVE ,
    _______  , KC_KP_0  , KC_KP_1  , KC_KP_2  , KC_KP_3  , KC_PMNS  ,                                  CPI_I100 , SCRL_DVI , RGB_HUI  , RGB_SAI  , RGB_VAI  , RGB_MOD  ,
    _______  , _______  , _______  , _______  , _______  , KC_PPLS  , KC_PENT  ,            TO(0)    , CPI_D100 , SCRL_DVD , RGB_HUD  , RGB_SAD  , RGB_VAD  , RGB_TOG  ,
    _______  , _______  , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , _______  ,            KC_RGUI  , KC_RALT  , _______  , _______  , _______  , _______  , _______
  ),

  [2] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , SCRL_MO  , KC_O     , KC_P     , _______  ,
    _______  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_BTN1  , KC_BTN3  , KC_BTN2  , KC_UP    , _______  ,
    _______  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_N     ,            TO(0)    , KC_M     , KC_COMM  , KC_DOT   , KC_LEFT  , KC_DOWN  , KC_RGHT  ,
    _______  , _______  , _______  , _______  , KC_SPC   , KC_SPC   , KC_N     ,            TO(1)    , KC_N     , _______  , _______  , _______  , KC_RSFT  , _______
  ),

  [3] = LAYOUT_universal(
    JP_ZKHK  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_DEL   ,
    _______  , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_F11   , KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , KC_F12   ,
    _______  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  JP_YEN   , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , _______  ,
    _______  ,KC_KB_MUTE,KC_KB_VOLUME_UP,KC_KB_VOLUME_DOWN,KC_V,KC_B, KC_N     ,            _______  , JP_LBRC  , JP_RBRC  , KC_PSCR  , KC_SCRL  , KC_PAUS  , _______  ,
    _______  , _______  , _______  , _______  , _______  , KC_SPC   , KC_CAPS  ,            JP_KANA  , KC_INS   , _______  , _______  , _______  , KC_APP   , _______
  ),
};
// clang-format on

uint8_t current_layer = 0;

bool is_current_layer_mouse(void) {
  return current_layer == 2;
}

//layer_state_t layer_state_set_user(layer_state_t state) {
//    return state;
//}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    //current_layer = get_highest_layer(state);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void keyball_oled_render_layerinfo(bool is_inverted) {
    oled_write_P(PSTR("Layer: "), is_inverted);
    oled_write_char(current_layer + '0', is_inverted);
    oled_write_P(PSTR("  "), is_inverted);
}

void keyball_oled_render_scrollinfo(bool is_inverted) {
    oled_write_P(PSTR("Scroll: "), is_inverted);
    oled_write_char(keyball.is_scrolling_h ? '-' : ' ', is_inverted);
    oled_write_char(keyball.is_scrolling_v ? '|' : ' ', is_inverted);
    oled_write_P(PSTR(" "), is_inverted);
}

void keyball_oled_render_systeminfo(bool is_inverted) {
    oled_write_P(PSTR("B:"), is_inverted);
    oled_write_char(keyball.this_have_ball ? '1' : '0', is_inverted);
    oled_write_P(PSTR(" E:"), is_inverted);
    oled_write_char(keyball.that_enable ? '1' : '0', is_inverted);
    oled_write_P(PSTR(" L:"), is_inverted);
    oled_write_char(is_keyboard_left() ? '1' : '0', is_inverted);
    oled_write_P(PSTR(" M:"), is_inverted);
    oled_write_char(is_keyboard_master() ? '1' : '0', is_inverted);
    oled_write_P(PSTR("      "), is_inverted);
}

void oledkit_render_info_user(void) {
    //keyball_oled_render_keyinfo(is_current_layer_mouse());
    keyball_oled_render_systeminfo(is_current_layer_mouse());
    if (is_keyboard_master()) {
        keyball_oled_render_ballinfo(is_current_layer_mouse());
        keyball_oled_render_layerinfo(is_current_layer_mouse());
        keyball_oled_render_scrollinfo(is_current_layer_mouse());
    } else {
        oled_advance_page(true);
    }
}

#endif

#define LEDNO_FRONT_L 0,29
#define LEDNO_FRONT_R 44,27
#define LEDNO_BACK 29, 15
//#define LEDNO_LEFT_UNDER  29, 8
//#define LEDNO_RIGHT_UNDER 37, 7
//#define LEDNO_ALL 0,80
#define HSV_CYAN_DARK   128, 255, 48
#define HSV_RED_DARK      0, 255, 48
#define HSV_GREEN_DARK   64, 255, 48
#define HSV_YELLOW_DARK  43, 255, 48
#define HSV_PURPLE_DARK 192, 192, 48

// for debug
//const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//    {0,20, HSV_CYAN}
//);
//const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//    {20,20, HSV_RED}
//);
//const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//    {40,20, HSV_GREEN}
//);
//const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//    {60,20, HSV_PURPLE}
//);

//const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//    {LEDNO_ALL, HSV_CYAN_DARK}
//);
//const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//    {LEDNO_ALL, HSV_RED}
//);
//const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//    {LEDNO_ALL, HSV_GREEN_DARK}
//);
//const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//    {LEDNO_ALL, HSV_PURPLE_DARK}
//);

//const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//    {LEDNO_BACK, HSV_CYAN}
//);
//const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//    {LEDNO_BACK, HSV_RED}
//);
//const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//    {LEDNO_BACK, HSV_YELLOW}
//);
//const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//    {LEDNO_BACK, HSV_PURPLE}
//);

const rgblight_segment_t PROGMEM my_layer1_layer_l[] = RGBLIGHT_LAYER_SEGMENTS(
    {LEDNO_FRONT_L, HSV_CYAN_DARK}
);
const rgblight_segment_t PROGMEM my_layer2_layer_l[] = RGBLIGHT_LAYER_SEGMENTS(
    {LEDNO_FRONT_L, HSV_RED_DARK}
);
const rgblight_segment_t PROGMEM my_layer3_layer_l[] = RGBLIGHT_LAYER_SEGMENTS(
    {LEDNO_FRONT_L, HSV_YELLOW_DARK}
);
const rgblight_segment_t PROGMEM my_layer4_layer_l[] = RGBLIGHT_LAYER_SEGMENTS(
    {LEDNO_FRONT_L, HSV_PURPLE_DARK}
);

const rgblight_segment_t PROGMEM my_layer1_layer_r[] = RGBLIGHT_LAYER_SEGMENTS(
    {LEDNO_FRONT_R, HSV_CYAN_DARK}
);
const rgblight_segment_t PROGMEM my_layer2_layer_r[] = RGBLIGHT_LAYER_SEGMENTS(
    {LEDNO_FRONT_R, HSV_RED_DARK}
);
const rgblight_segment_t PROGMEM my_layer3_layer_r[] = RGBLIGHT_LAYER_SEGMENTS(
    {LEDNO_FRONT_R, HSV_YELLOW_DARK}
);
const rgblight_segment_t PROGMEM my_layer4_layer_r[] = RGBLIGHT_LAYER_SEGMENTS(
    {LEDNO_FRONT_R, HSV_PURPLE_DARK}
);

//const rgblight_segment_t PROGMEM my_layer1_layer_l[] = RGBLIGHT_LAYER_SEGMENTS(
//    {LEDNO_LEFT_UNDER, HSV_CYAN}
//);
//const rgblight_segment_t PROGMEM my_layer2_layer_l[] = RGBLIGHT_LAYER_SEGMENTS(
//    {LEDNO_LEFT_UNDER, HSV_RED}
//);
//const rgblight_segment_t PROGMEM my_layer3_layer_l[] = RGBLIGHT_LAYER_SEGMENTS(
//    {LEDNO_LEFT_UNDER, HSV_YELLOW}
//);
//const rgblight_segment_t PROGMEM my_layer4_layer_l[] = RGBLIGHT_LAYER_SEGMENTS(
//    {LEDNO_LEFT_UNDER, HSV_PURPLE}
//);
//
//const rgblight_segment_t PROGMEM my_layer1_layer_r[] = RGBLIGHT_LAYER_SEGMENTS(
//    {LEDNO_RIGHT_UNDER, HSV_CYAN}
//);
//const rgblight_segment_t PROGMEM my_layer2_layer_r[] = RGBLIGHT_LAYER_SEGMENTS(
//    {LEDNO_RIGHT_UNDER, HSV_RED}
//);
//const rgblight_segment_t PROGMEM my_layer3_layer_r[] = RGBLIGHT_LAYER_SEGMENTS(
//    {LEDNO_RIGHT_UNDER, HSV_YELLOW}
//);
//const rgblight_segment_t PROGMEM my_layer4_layer_r[] = RGBLIGHT_LAYER_SEGMENTS(
//    {LEDNO_RIGHT_UNDER, HSV_PURPLE}
//);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    //my_layer1_layer
    //,my_layer2_layer
    //,my_layer3_layer
    //,my_layer4_layer
    my_layer1_layer_l
    ,my_layer2_layer_l
    ,my_layer3_layer_l
    ,my_layer4_layer_l
    ,my_layer1_layer_r
    ,my_layer2_layer_r
    ,my_layer3_layer_r
    ,my_layer4_layer_r
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    rgblight_set_layer_state(0, 1);
}

//bool led_update_user(led_t led_state) {
//    rgblight_set_layer_state(0, led_state.caps_lock);
//    return true;
//}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    rgblight_set_layer_state(4, layer_state_cmp(state, 0));
    rgblight_set_layer_state(5, layer_state_cmp(state, 1));
    rgblight_set_layer_state(6, layer_state_cmp(state, 2));
    rgblight_set_layer_state(7, layer_state_cmp(state, 3));
    current_layer = get_highest_layer(state);
    return state;
}
