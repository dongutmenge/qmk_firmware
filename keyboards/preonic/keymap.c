#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _BL,
  _FL,
  _NL,
  _ML
};

enum preonic_keycodes {
  BL = SAFE_RANGE,
  FL,
  NL,
  ML,
  M_S1,
  M_S2,
  M_S3,
  M_GD,
  M_EM,
  M_SB,
  M_WWW,
  M_XYZ,
  M_MOB,
  M_ADDR,
  M_SHRUG,
  M_WORK,
  M_PWORK
};

enum custom_keycodes {
  MS1 = SAFE_RANGE,
  MS2,
  MS3,
  MGD,
  MEM,
  MSB,
  MWWW,
  MXYZ,
  MMOB,
  MADDR,
  MSHRUG,
  MWORK,
  MPWORK
};


// Light LEDs white when caps lock is active.
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_WHITE}       // Light 4 LEDs, starting with LED 6
);
// Light LEDs red when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_OFF}
);
// Light LEDs blue when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_RED}
);
// Light LEDs green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_BLUE}
);
// Light LEDs green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_GREEN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(

    my_layer1_layer,
    my_capslock_layer,   // Overrides caps layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer,    // Overrides other layers
    my_layer4_layer     // Overrides other layers

);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}


bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(1, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BL));
    rgblight_set_layer_state(2, layer_state_cmp(state, _FL));
    rgblight_set_layer_state(3, layer_state_cmp(state, _NL));
    rgblight_set_layer_state(4, layer_state_cmp(state, _ML));
    return state;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* base
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BL] = LAYOUT_preonic_grid(
  KC_MINS,           KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_BSPC,
  KC_TAB,            KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_DEL,
  QK_GESC,           KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
  LM(_FL, MOD_LSFT), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
  KC_LCTL, KC_LGUI,  KC_LALT, KC_LSFT, TT(_FL), TT(_NL), KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* function
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_FL] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NO,   KC_NO,   KC_NO,   KC_MINS, KC_EQL,  KC_BSPC,
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_NO,   KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
  KC_CAPS, KC_NO,   KC_NO,   KC_NO,   KC_FIND, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_PGUP,
  KC_TRNS, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, TO(_BL), KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_END,  KC_PGDN,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* num
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_NL] = LAYOUT_preonic_grid(
  KC_GRV,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, KC_HOME, KC_BSPC,
  KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,   KC_NO,   KC_P7,  KC_P8,   KC_P9,   KC_PPLS, KC_END,  KC_DEL,
  KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_NO,   KC_P4,  KC_P5,   KC_P6,   KC_PCMM, KC_LPRN, KC_RPRN,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TO(_BL), KC_P1,  KC_P2,   KC_P3,   KC_PEQL, KC_LBRC, KC_RBRC,
  MO(_ML), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0,  KC_PDOT, KC_PENT, KC_LT,   KC_GT
),

/* macro
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_ML] = LAYOUT_preonic_grid(
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO, KC_NO, KC_NO, M_MOB,   KC_NO,
  KC_NO,   KC_NO,   M_WWW,   QK_BOOT, KC_NO,   KC_NO,   KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,   M_SHRUG,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_MAKE, M_GD,    M_ADDR, KC_NO, KC_NO, KC_NO, M_PWORK, M_WORK,
  KC_NO,   KC_NO,   M_XYZ,   KC_NO,   KC_NO,   M_SB,    KC_NO,  M_EM,  M_S1,  M_S2,  M_S3,    KC_NO,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case BL:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_BL);
          }
          return false;
          break;
        case FL:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_FL);
          }
          return false;
          break;
        case NL:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_NL);
          }
          return false;
          break;
        case ML:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_ML);
          }
          return false;
          break;
        case M_S1:
          if (record->event.pressed) {
              // when keycode QMKBEST is pressed
              SEND_STRING("192.168.16.");
          } else {
              // when keycode QMKBEST is released
          }
          break;
        case M_S2:
          if (record->event.pressed) {
              // when keycode QMKBEST is pressed
              SEND_STRING("192.168.26.");
          } else {
              // when keycode QMKBEST is released
          }
          break;
        case M_S3:
          if (record->event.pressed) {
              // when keycode QMKBEST is pressed
              SEND_STRING("192.168.27.");
          } else {
              // when keycode QMKBEST is released
          }
          break;
        case M_GD:
          if (record->event.pressed) {
              // when keycode QMKBEST is pressed
              SEND_STRING("192.168.17.");
          } else {
              // when keycode QMKBEST is released
          }
          break;
        case M_EM:
          if (record->event.pressed) {
              // when keycode QMKBEST is pressed
              SEND_STRING("192.168.20.");
          } else {
              // when keycode QMKBEST is released
          }
          break;
        case M_SB:
          if (record->event.pressed) {
              // when keycode QMKBEST is pressed
              SEND_STRING("192.168.25.");
          } else {
              // when keycode QMKBEST is released
          }
          break;
        case M_WWW:
          if (record->event.pressed) {
              // when keycode QMKBEST is pressed
              SEND_STRING("worldwideliam@gmail.com");
          } else {
              // when keycode QMKBEST is released
          }
          break;
        case M_XYZ:
          if (record->event.pressed) {
              // when keycode QMKBEST is pressed
              SEND_STRING("mail@liamkennedy.xyz");
          } else {
              // when keycode QMKBEST is released
          }
          break;
        case M_MOB:
          if (record->event.pressed) {
              // when keycode QMKBEST is pressed
              SEND_STRING("0410881599");
          } else {
              // when keycode QMKBEST is released
          }
          break;
        case M_ADDR:
          if (record->event.pressed) {
              // when keycode QMKBEST is pressed
              SEND_STRING("29 Ridgmont Circuit, Thornton, NSW 2322");
          } else {
              // when keycode QMKBEST is released
          }
          break;
        case M_SHRUG:
          if (record->event.pressed) {
              // when keycode QMKBEST is pressed
              SEND_STRING("¯\\_(ツ)_/¯");
          } else {
              // when keycode QMKBEST is released
          }
          break;
        case M_WORK:
          if (record->event.pressed) {
              // when keycode QMKBEST is pressed
              SEND_STRING("liam.kennedy@altoimaging.com.au");
          } else {
              // when keycode QMKBEST is released
          }
          break;
        case M_PWORK:
          if (record->event.pressed) {
              // when keycode QMKBEST is pressed
              SEND_STRING("!23Qwe!23Qwe");
          } else {
              // when keycode QMKBEST is released
          }
          break;


      }
    return true;
};
