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

#include "../../../lib/keyball/keyball.h"

bool is_current_layer_mouse(void);
static char to_1x(uint8_t x);
static const char *format_4d(int8_t d);
void keyball_oled_render_ballinfo_inv(bool is_inverted);
void keyball_oled_render_keyinfo_inv(bool is_inverted);
void keyball_oled_render_layerinfo_inv(bool is_inverted);


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//  [0] = LAYOUT_universal(
//    KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  ,
//    KC_DEL   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_INT3  ,
//    KC_TAB   , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , S(KC_7)  ,
//    MO(1)    , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_RBRC  ,              KC_NUHS, KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RSFT  ,
//    _______  , KC_LCTL  , KC_LALT  , KC_LGUI,LT(1,KC_LANG2),LT(2,KC_SPC),LT(3,KC_LANG1),    KC_BSPC,LT(2,KC_ENT),LT(1,KC_LANG2),KC_RGUI, _______ , KC_RALT  , KC_PSCR
//  ),
//
//  [1] = LAYOUT_universal(
//    S(KC_ESC), S(KC_1)  , KC_LBRC  , S(KC_3)  , S(KC_4)  , S(KC_5)  ,                                  KC_EQL   , S(KC_6)  ,S(KC_QUOT), S(KC_8)  , S(KC_9)  ,S(KC_INT1),
//    S(KC_DEL), S(KC_Q)  , S(KC_W)  , S(KC_E)  , S(KC_R)  , S(KC_T)  ,                                  S(KC_Y)  , S(KC_U)  , S(KC_I)  , S(KC_O)  , S(KC_P)  ,S(KC_INT3),
//    S(KC_TAB), S(KC_A)  , S(KC_S)  , S(KC_D)  , S(KC_F)  , S(KC_G)  ,                                  S(KC_H)  , S(KC_J)  , S(KC_K)  , S(KC_L)  , KC_QUOT  , S(KC_2)  ,
//    _______  , S(KC_Z)  , S(KC_X)  , S(KC_C)  , S(KC_V)  , S(KC_B)  ,S(KC_RBRC),           S(KC_NUHS), S(KC_N)  , S(KC_M)  ,S(KC_COMM), S(KC_DOT),S(KC_SLSH),S(KC_RSFT),
//    _______  ,S(KC_LCTL),S(KC_LALT),S(KC_LGUI), _______  , _______  , _______  ,            _______  , _______  , _______  ,S(KC_RGUI), _______  , S(KC_RALT), _______
//  ),
//
//  [2] = LAYOUT_universal(
//    _______  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
//    _______  , _______  , KC_7     , KC_8     , KC_9     , _______  ,                                  _______  , KC_LEFT  , KC_UP    , KC_RGHT  , _______  , KC_F12   ,
//    _______  , _______  , KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                                  KC_PGUP  , KC_BTN1  , KC_DOWN  , KC_BTN2  , KC_BTN3  , _______  ,
//    _______  , _______  , KC_1     , KC_2     , KC_3     ,S(KC_MINS), S(KC_8)  ,            S(KC_9)  , KC_PGDN  , _______  , _______  , _______  , _______  , _______  ,
//    _______  , _______  , KC_0     , KC_DOT   , _______  , _______  , _______  ,             KC_DEL  , _______  , _______  , _______  , _______  , _______  , _______
//  ),
//
//  [3] = LAYOUT_universal(
//    RGB_TOG  , _______  , _______  , _______  , _______  , _______  ,                                  RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
//    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , _______  ,                                  RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
//    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , _______  ,                                  CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE , KBC_RST  ,
//    _______  , _______  , SCRL_DVD , SCRL_DVI , SCRL_MO  , SCRL_TO  , EEP_RST  ,            EEP_RST  , KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , _______  , _______  ,
//    RESET    , _______  , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , _______  ,            _______  , KC_BSPC  , _______  , _______  , _______  , _______  , RESET
//  ),

  [0] = LAYOUT_universal(
    KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_BSPC  ,
    KC_TAB   , KC_Q     , KC_SCLN  , KC_F     , KC_E     , KC_COMM  ,                                  KC_W     , KC_R     , KC_Y     , KC_T     , KC_P     , KC_LBRC  ,
    KC_LCTL  , KC_I     , KC_A     , KC_U     , KC_O     , KC_DOT   ,                                  KC_G     , KC_H     , KC_J     , KC_K     , KC_L     , KC_ENT   ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_SLSH  , KC_QUOT  ,              TO(2)  , KC_S     , KC_M     , KC_SPC   , KC_D     , KC_B     , KC_RSFT  ,
    MO(3)    , KC_GRV   , KC_LGUI  , KC_LALT  , MO(2)    , KC_MINS  , KC_LANG2 ,              KC_LANG1,KC_N     , _______  , _______  , _______  , KC_INT1  , KC_RCTL
  ),

  [1] = LAYOUT_universal(
    RGB_TOG  , _______  , _______  , _______  , _______  , _______  ,                                  RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , _______  ,                                  RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , _______  ,                                  CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE , KBC_RST  ,
    _______  , _______  , SCRL_DVD , SCRL_DVI , SCRL_MO  , SCRL_TO  , EEP_RST  ,            TO(0)    , KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , _______  , _______  ,
    RESET    , _______  , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , _______  ,            _______  , KC_BSPC  , _______  , _______  , _______  , _______  , RESET
  ),

  [2] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , SCRL_MO  , KC_O     , KC_P     , _______  ,
    _______  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_BTN1  , KC_BTN3  , KC_BTN2  , KC_UP    , _______  ,
    _______  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_N     ,            TO(0)    , KC_M     , KC_COMM  , KC_DOT   , KC_LEFT  , KC_DOWN  , KC_RGHT  ,
    _______  , _______  , _______  , _______  , KC_SPC   , KC_SPC   , KC_N     ,            TO(1)    , KC_N     , _______  , _______  , _______  , KC_RSFT  , _______
  ),

  [3] = LAYOUT_universal(
    KC_INT2  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_DEL   ,
    _______  , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_F11   , KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , KC_F12   ,
    _______  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_INT3  , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , _______  ,
    _______  ,KC_KB_MUTE,KC_KB_VOLUME_UP,KC_KB_VOLUME_DOWN,KC_V,KC_B, KC_N     ,            _______  , KC_RBRC  , KC_NUHS  , KC_PSCR  , KC_SCRL  , KC_PAUS  , _______  ,
    _______  , _______  , _______  , _______  , _______  , KC_SPC   , KC_CAPS  ,            _______  , KC_INS   , _______  , _______  , _______  , KC_APP   , _______
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

static char to_1x(uint8_t x) {
    x &= 0x0f;
    return x < 10 ? x + '0' : x + 'a' - 10;
}

const char PROGMEM code_to_name_hada[] = {
    'a', 'b', 'c', 'd', 'e', 'f',  'g', 'h', 'i',  'j',
    'k', 'l', 'm', 'n', 'o', 'p',  'q', 'r', 's',  't',
    'u', 'v', 'w', 'x', 'y', 'z',  '1', '2', '3',  '4',
    '5', '6', '7', '8', '9', '0',  'R', 'E', 'B',  'T',
    '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`',
    ',', '.', '/',
};

static const char *format_4d(int8_t d) {
    static char buf[5] = {0}; // max width (4) + NUL (1)
    char        lead   = ' ';
    if (d < 0) {
        d    = -d;
        lead = '-';
    }
    buf[3] = (d % 10) + '0';
    d /= 10;
    if (d == 0) {
        buf[2] = lead;
        lead   = ' ';
    } else {
        buf[2] = (d % 10) + '0';
        d /= 10;
    }
    if (d == 0) {
        buf[1] = lead;
        lead   = ' ';
    } else {
        buf[1] = (d % 10) + '0';
        d /= 10;
    }
    buf[0] = lead;
    return buf;
}

void keyball_oled_render_keyinfo_inv(bool is_inverted) {
    // Format: `Key :  R{row}  C{col} K{kc}  '{name}`
    //
    // Where `kc` is lower 8 bit of keycode.
    // Where `name` is readable label for `kc`, valid between 4 and 56.
    //
    // It is aligned to fit with output of keyball_oled_render_ballinfo().
    // For example:
    //
    //     Key :  R2  C3 K06  'c
    //     Ball:   0   0   0   0
    //
    uint8_t keycode = keyball.last_kc;

    oled_write_P(PSTR("Key :  R"), is_inverted);
    oled_write_char(to_1x(keyball.last_pos.row), is_inverted);
    oled_write_P(PSTR("  C"), is_inverted);
    oled_write_char(to_1x(keyball.last_pos.col), is_inverted);
    if (keycode) {
        oled_write_P(PSTR(" K"), is_inverted);
        oled_write_char(to_1x(keycode >> 4), is_inverted);
        oled_write_char(to_1x(keycode), is_inverted);
    } else {
        oled_write_P(PSTR("    "), is_inverted);
    }
    if (keycode >= 4 && keycode < 57) {
        oled_write_P(PSTR("  '"), is_inverted);
        char name = pgm_read_byte(code_to_name_hada + keycode - 4);
        oled_write_char(name, is_inverted);
    } else {
        //oled_advance_page(true);
        oled_write_P(PSTR("    "), is_inverted);
    }
}

void keyball_oled_render_ballinfo_inv(bool is_inverted) {
    // Format: `Ball:{mouse x}{mouse y}{mouse h}{mouse v}`
    //         `    CPI{CPI} S{SCROLL_MODE} D{SCROLL_DIV}`
    //
    // Output example:
    //
    //     Ball: -12  34   0   0
    //
    oled_write_P(PSTR("Ball:"), is_inverted);
    oled_write(format_4d(keyball.last_mouse.x), is_inverted);
    oled_write(format_4d(keyball.last_mouse.y), is_inverted);
    oled_write(format_4d(keyball.last_mouse.h), is_inverted);
    oled_write(format_4d(keyball.last_mouse.v), is_inverted);
    // CPI
    oled_write_P(PSTR("     CPI"), is_inverted);
    oled_write(format_4d(keyball_get_cpi()) + 1, is_inverted);
    oled_write_P(PSTR("00  S"), is_inverted);
    oled_write_char(keyball.scroll_mode ? '1' : '0', is_inverted);
    oled_write_P(PSTR("  D"), is_inverted);
    oled_write_char('0' + keyball_get_scroll_div(), is_inverted);
}

void keyball_oled_render_layerinfo_inv(bool is_inverted) {
    oled_write_P(PSTR("Layer: "), is_inverted);
    oled_write_char(current_layer + '0', is_inverted);
    oled_write_P(PSTR("  "), is_inverted);
}

void keyball_oled_render_scrollinfo_inv(bool is_inverted) {
    oled_write_P(PSTR("Scroll: "), is_inverted);
    oled_write_char(keyball.is_scrolling_h ? '-' : ' ', is_inverted);
    oled_write_char(keyball.is_scrolling_v ? '|' : ' ', is_inverted);
    oled_write_P(PSTR(" "), is_inverted);
}

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo_inv(is_current_layer_mouse());
    keyball_oled_render_ballinfo_inv(is_current_layer_mouse());
    keyball_oled_render_layerinfo_inv(is_current_layer_mouse());
    keyball_oled_render_scrollinfo_inv(is_current_layer_mouse());
}

#endif

const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 122, 128, 255, 64}
);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 122, HSV_RED}
);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 122, 64, 255, 64}
);
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 122, 192, 192, 64}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer1_layer
    ,my_layer2_layer
    ,my_layer3_layer
    ,my_layer4_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

//bool led_update_user(led_t led_state) {
//    rgblight_set_layer_state(0, led_state.caps_lock);
//    return true;
//}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    //rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    current_layer = get_highest_layer(state);
    return state;
}
