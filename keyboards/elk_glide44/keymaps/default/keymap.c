/* Copyright 2020 psychobmx
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_jp.h"

// Defines the keycodes used by our macros in process_record_user
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO

#define KC_ALPS LALT(KC_PSCR)      // Alt + PrintScreen
#define KC_CAD  LCTL(LALT(KC_DEL)) // Control+Alt+Delete
#define KC_CAI  LCTL(LALT(KC_INS)) // Control+Alt+Insert
#define KC_CPDN LCTL(KC_PGDN)      // ctl + pgdown
#define KC_CPUP LCTL(KC_PGUP)      // ctl + pgup
#define KC_ALUP LALT(KC_UP)        // alt + up

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * ,------------------------------------------      ,-----------------------------------------.
   * |  Tab |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  |  -=  |
   * |------+------+------+------+------+------|------|------+------+------+------+------+------|
   * | LCTRL|   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |  ; + |  : * |
   * |------+------+------+------+------+------|------|------+------+------+------+------+------|
   * |LShift|   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |  , < |  . > |  / ? |Shift |
   * `------+------+------+------+------+------|-------|------+------+------+------+------+------'
   *                        |  Win | LOWER|Space |   |Enter |RAISE |  Alt |
   *                        `--------------------'   `--------------------'
   */
 [_QWERTY] = LAYOUT( \
       KC_TAB,  KC_Q,    KC_W,    KC_E,      KC_R,    KC_T,            KC_Y,    KC_U,     KC_I,     KC_O,     KC_P, KC_MINS, \
       KC_RCTL, KC_A,    KC_S,    KC_D,      KC_F,    KC_G,KC_XXXXX,   KC_H,    KC_J,     KC_K,     KC_L,  KC_SCLN, JP_COLN, \
       KC_LSFT, KC_Z,    KC_X,    KC_C,      KC_V,    KC_B,KC_XXXXX,   KC_N,    KC_M,  KC_COMM,   KC_DOT,  KC_SLSH, KC_RSFT, \
                               KC_LGUI,     LOWER,   KC_SPC,         KC_ENT,   RAISE,  KC_RALT \

  ),
  /*
   * ,------------------------------------------      ,-----------------------------------------.
   * |  Esc |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |  \   |
   * |------+------+------+------+------+------|------|------+------+------+------+------+------|
   * |  Tab |  F1  |  F2  |  F3  |  F4  |  F5  |      | Left | Down |  Up  |Right | XXXX |  |   |
   * |------+------+------+------+------+------|------|------+------+------+------+------+------|
   * |      |  F6  |  F7  |  F8  |  F9  | F10  |      |  F11 |  F12 | XXXX | XXXX |  \   |  _   |
   * `------+------+------+------+------+------|------|------+------+------+------+------+------'
   *                        |  Win | LOWER|Space |   |Enter |RAISE |  Alt |
   *                        `--------------------'   `--------------------'
   */
   [_LOWER] = LAYOUT( \
    KC_ESC,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,      KC_7,    KC_8,     KC_9,    KC_0,  JP_YEN,\
    KC______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,KC_XXXXX, KC_LEFT,   KC_DOWN,   KC_UP,  KC_RGHT,KC_XXXXX, JP_PIPE,\
    KC______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,KC_XXXXX,  KC_F11,    KC_F12,KC_XXXXX, KC_XXXXX, JP_BSLS, JP_UNDS, \
                               KC______,KC______, KC_BSPC,         KC______,  KC______,KC______ \
  ),
  /*
   * ,------------------------------------------      ,-----------------------------------------.
   * |  E/J |   !  |   "  |   #  |   $  |   %  |      |   &  |   '  |   (  |   )  |  ^   |  ~   |
   * |------+------+------+------+------+------|------|------+------+------+------+------+------|
   * |  Esc |KC_CAD|KC_CAI| XXXX | CPgUp|  [   |      |   ]  | INS  | Home | PgUp |   @  |  `   |
   * |------+------+------+------+------+------|------|------+------+------+------+------+------|
   * |      | AL+UP| XXXX | XXXX | CPgDn|  {   |      |   }  | DEL  | END  | PgDn |  Ps  | AlPs |
   * `------+------+------+------+------+------|------|------+------+------+------+------+------'
   *                        |  Win | LOWER| Bksp |  |Enter |RAISE |  Alt |
   *                        `--------------------'  `--------------------'
   */
  [_RAISE] = LAYOUT( \
     JP_ZHTG, KC_EXLM,  JP_DQT, KC_HASH,  KC_DLR, KC_PERC,          JP_AMPR,  JP_QUOT,  JP_LPRN, JP_RPRN, JP_CIRC,  JP_TILD,\
    KC______,  KC_CAD,  KC_CAI,KC_XXXXX, KC_CPUP, JP_LBRC,KC_XXXXX, JP_RBRC,   KC_INS,  KC_HOME, KC_PGUP,   JP_AT,   JP_GRV,\
    KC______, KC_ALUP,KC_XXXXX,KC_XXXXX, KC_CPDN, JP_LCBR,KC_XXXXX, JP_RCBR,   KC_DEL,   KC_END, KC_PGDN, KC_PSCR,  KC_ALPS,\
                               KC______,KC______, KC_BSPC,          KC______, KC______,  KC______ \
  ),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }
            return false;
            break;
    }
    return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}
