/* Copyright 2018 Daisuke Kobayashi
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

enum {
  _WIN,
  _LOWER,
  _RAISE,
  _FUNC
};

#define KC_KNA  KC_LANG1
#define KC_EISU KC_LANG2
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define FN      MO(_FUNC)
#define WIN     DF(_WIN)

#define KC_ALPS LALT(KC_PSCR)      // Alt + PrintScreen
#define KC_CAD  LCTL(LALT(KC_DEL)) // Control+Alt+Delete
#define KC_CAI  LCTL(LALT(KC_INS)) // Control+Alt+Insert
#define KC_WINL LGUI(KC_LEFT)      // Win + left
#define KC_WINR LGUI(KC_RIGHT)     // Win + right
#define KC_CPDN LCTL(KC_PGDN)      // ctl + pgdown
#define KC_CPUP LCTL(KC_PGUP)      // ctl + pgup
#define KC_ALUP LALT(KC_UP)        // alt + up


#define KC_LOWR LT(_LOWER, KC_MHEN)    // タップで無変換     ホールドでLower
#define KC_RASE LT(_RAISE, KC_HENK)    // タップで変換       ホールドでRaise


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* WIN
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |  Tab |   Q  |   W  |   E  |   R  |   T  | XXXX |   | XXXX |   Y  |   U  |   I  |   O  |   P  |  -=  |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | LCTRL|   A  |   S  |   D  |   F  |   G  | XXXX |   | XXXX |   H  |   J  |   K  |   L  |  ; + |  : * |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |LShift|   Z  |   X  |   C  |   V  |   B  | XXXX |   | XXXX |   N  |   M  |  , < |  . > |  / ? |Shift |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |  Fn  | XXXX | XXXX |  Win | LOWER|Space |Space |   | Enter|Enter |RAISE |  Alt | XXXX | XXXX | XXXX |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [_WIN] = LAYOUT( \
     KC_TAB, KC_Q,    KC_W,    KC_E,      KC_R,    KC_T,  XXXXXXX,       XXXXXXX,    KC_Y,    KC_U,     KC_I,     KC_O,     KC_P, KC_MINS, \
    KC_RCTL, KC_A,    KC_S,    KC_D,      KC_F,    KC_G,  XXXXXXX,       XXXXXXX,    KC_H,    KC_J,     KC_K,     KC_L,  KC_SCLN, JP_COLN, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,      KC_V,    KC_B,  XXXXXXX,       XXXXXXX,    KC_N,    KC_M,  KC_COMM,   KC_DOT,  KC_SLSH, KC_RSFT, \
    FN     , XXXXXXX, XXXXXXX, KC_LGUI,KC_LOWR,  KC_SPC,   KC_SPC,        KC_ENT,  KC_ENT, KC_RASE,  KC_LALT,  XXXXXXX,  XXXXXXX, XXXXXXX  \
  ),

  /* LOWER
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |  Esc |   1  |   2  |   3  |   4  |   5  |      |   |      |   6  |   7  |   8  |   9  |   0  |  \   |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |  Tab |  F1  |  F2  |  F3  |  F4  |  F5  |      |   |      | Left | Down |  Up  |Right | XXXX |  |   |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |  F6  |  F7  |  F8  |  F9  | F10  |      |   |      |  F11 |  F12 | XXXX | XXXX |   \  |  _   |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [_LOWER] = LAYOUT( \
     KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______,      _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_JYEN, \
     KC_TAB,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______,      _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, JP_PIPE, \
    _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,      _______,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, JP_BSLS, JP_UNDS, \
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______  \
  ),

  /* RAISE
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |  E/J |   !  |   "  |   #  |   $  |   %  |      |   |      |   &  |   '  |   (  |   )  |  ^   |  ~   |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |  Esc | C+A+D|KC_CAI|      | CPgUp|  [   |      |   |      |  ]   | INS  | Home | PgUp |   @  |  `   |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      | AL+UP| AL+UP|      | CPgDn|  {   |      |   |      |  }   | DEL  | END  | PgDn |  Ps  | AlPs |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |      | Bksp | Bksp |   |      |      |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [_RAISE] = LAYOUT( \
    JP_ZHTG, KC_EXLM,  JP_DQT, KC_HASH,  KC_DLR, KC_PERC, _______,      _______, JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN, JP_CIRC, JP_TILD, \
     KC_TAB,  KC_CAD,  KC_CAI, XXXXXXX, KC_CPUP, JP_LBRC, _______,      _______, JP_RBRC,  KC_INS, KC_HOME, KC_PGUP,   JP_AT,  JP_GRV, \
    _______, KC_ALUP, XXXXXXX, XXXXXXX, KC_CPDN, JP_LCBR, _______,      _______, JP_RCBR,  KC_DEL,  KC_END, KC_PGDN, KC_PSCR, KC_ALPS, \
    _______, _______, _______, _______, _______, KC_BSPC, KC_BSPC,      _______, _______, _______, _______, _______, _______, _______  \
  ),

  /* FUNC
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |Reset | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |   | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      | XXXX | XXXX | XXXX | XXXX | XXXX |   | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | Caps |      | XXXX | XXXX | XXXX | XXXX | XXXX |   | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [_FUNC] = LAYOUT( \
    RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    KC_CAPS, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______  \
  )
};

