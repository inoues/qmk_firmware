#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif


extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

//KC_QUOT : : and +
//KC_LBRC : @ and `
//KC_EQL  : ^ and ~
//KC_RO   : \ and _ (EN mark and UNder score)
//KC_JYEN : \ and | (EN mark and Vertical Line)
//KC_RBRC : [ and {
//KC_BSLS : ] and }
#define JP_DQT  LSFT(KC_2) // "
#define KC_ALPS LALT(KC_PSCR) // Alt + PrintScreen
#define KC_CAD  LCTL(LALT(KC_DEL)) // Control+Alt+Delete

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,------------------------------------------.
 * |  E/J |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -    |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+-------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  @ `  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+-------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  : *  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+-------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |¥ _ / S|
 * `-----------------------------------------/       /     \      \------------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP|  APP |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT( \
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, \
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_RBRC ,  KC_BSLS ,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_RO), \
                             KC_LALT, KC_LGUI,LOWER, KC_SPC,   KC_ENT,   RAISE,   KC_BSPC, KC_APP \
),
/* LOWER
 * ,-----------------------------------------.                    ,------------------------------------------.
 * | ESC  |      |      |      |      |      |                    |      |      |      |      |      |       |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+-------|
 * |  !   | "    |   #  |  $   |  %   |  &   |                    |   '  |   (  |   )  |   -  |  ^   |   \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+-------|
 * |      |   1  |   2  |   3  |   4  |   5  |-------.    ,-------|      |   {  |   }  |   =  |   ~  |   |   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+-------|
 * |LShift|   6  |   7  |   8  |   9  |   0  |-------|    |-------|      |   [  |   ]  |      |      |\ _ / S|
 * `-----------------------------------------/       /     \      \------------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP|  APP |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_LOWER] = LAYOUT( \
  KC_ESC , _______, _______, _______, _______, _______,                      KC_PPLS, KC_7,      KC_8,     KC_9,  KC_EQL,    KC_JYEN, \
  KC_EXLM, sdfad, KC_HASH, KC_DLR, KC_PERC, KC_AMPR,                      KC_PMNS, KC_4,      KC_5,     KC_6, XXXXXXX,    _______, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PAST, KC_1,      KC_2,     KC_3, XXXXXXX,    XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   _______, _______,  KC_PSLS, KC_RBRC,  KC_BSLS,  KC_PEQL, XXXXXXX,    _______, \
                             _______, _______, _______,  _______, _______,  _______, _______, _______ \
),
/* RAISE
 * ,-----------------------------------------.                    ,------------------------------------------.
 * | ESC  |      |      |      |      |      |                    |      |      |      |      |      |       |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+-------|
 * | Tab  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+-------|
 * |LCTRL |   ←  |   ↑  |  ↓   |   →  |      |-------.    ,-------| CAD  |  INS | Home | PgUp | Ps   | F12   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+-------|
 * |LShift|  E/J | ESC  |M_LBTN|M_RBTN|      |-------|    |-------| ESC  |  DEL |  END | PgDn | AlPs |¥ _ / S|
 * `-----------------------------------------/       /     \      \------------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP|  APP |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT( \
  KC_ESC ,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______,   KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,                    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  _______, KC_LEFT,   KC_UP, KC_DOWN,KC_RGHT, XXXXXXX,                    KC_CAD,  KC_INS, KC_HOME, KC_PGUP, KC_PSCR,  KC_F12, \
  _______, KC_GRV,   KC_ESC, KC_BTN1, KC_BTN2, XXXXXXX, _______, _______, KC_ESC,  KC_DEL,  KC_END, KC_PGDN, KC_ALPS, _______, \
                             _______, _______, _______, _______, _______,  _______, _______, _______\
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP|  APP |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};

int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

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
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
  }
  return true;
}
