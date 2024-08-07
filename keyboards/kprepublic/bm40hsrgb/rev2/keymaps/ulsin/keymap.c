/* Copyright 2020 tominabox1
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

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  ALT_aa,
  ALT_ae,
  ALT_oo,
  ALT_AA,
  ALT_AE,
  ALT_OO,
  DESK_L,
  DESK_R,
  UNI_PRIDE
};

enum unicode_names {
    UNI_aa,
    UNI_oo,
    UNI_ae,
    UNI_AA,
    UNI_OO,
    UNI_AE,
    UNI_SMILE,
    UNI_SMISW,
    UNI_SMIBH,
    UNI_SMIUP,
    UNI_SAVOR,
    UNI_SUNGL,
    UNI_NERDG,
    UNI_SPHRT,
    UNI_HNDRD,
    UNI_EYES,
    UNI_FIRE,
    UNI_PARTY,
    UNI_SPARK,
    UNI_BOMB
};

enum {
    TD_PLAY_NEXT,
    TD_MUTE_PREV
};

const uint32_t PROGMEM unicode_map[] = {
    [UNI_aa]  = 0x00E5,  // å
    [UNI_AA]  = 0x00C5,  // Å
    [UNI_oo]  = 0x00F8,  // ø
    [UNI_OO]  = 0x00D8,  // Ø
    [UNI_ae]  = 0x00E6,  // æ
    [UNI_AE]  = 0x00C6,  // Æ

    [UNI_SMILE]  = 0x1F604,  // 😄
    [UNI_SMISW]  = 0x1F605,  // 😅
    [UNI_SMIBH]  = 0x1F60A,  // 😊
    [UNI_SMIUP]  = 0x1F643,  // 🙃
    [UNI_SAVOR]  = 0x1F60B,  // 😋
    [UNI_SUNGL]  = 0x1F60E,  // 😎
    [UNI_NERDG]  = 0x1F913,  // 🤓
    [UNI_SPHRT]  = 0x1F496,  // 💖
    [UNI_HNDRD]  = 0x1F4AF,  // 💯
    [UNI_EYES]   = 0x1F440,  // 👀
    [UNI_FIRE]   = 0x1F525,  // 🔥
    [UNI_PARTY]  = 0x1F389,  // 🎉
    [UNI_SPARK]  = 0x2728,   // ✨
    [UNI_BOMB]   = 0x1F4A3,  // 💣
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BLTog| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12_1x2uC(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_ESC, RGB_TOG, KC_LGUI, KC_LALT, TL_LOWR, KC_SPC,  TL_UPPR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12_1x2uC(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, UP(UNI_aa,UNI_AA),
    _______,  _______,   _______,   DESK_L,   DESK_R,   _______,   _______,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, _______,   _______,   _______,   _______,  _______,  _______,  S(KC_NUHS), S(KC_NUBS), UP(UNI_oo,UNI_OO), UP(UNI_ae,UNI_AE),  _______,
    _______, _______, _______, _______, _______, KC_DEL, _______,    KC_HOME,    KC_PGDN, KC_PGUP, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12_1x2uC(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_INS, KC_PSCR, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12_1x2uC(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, _______ ,
    _______, QK_UNICODE_MODE_WINCOMPOSE, QK_UNICODE_MODE_LINUX, QK_UNICODE_MODE_MACOS, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

// macros goes here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_SLEP:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(gb_song);
          register_code(KC_SLEP);
        #endif
      }
      return false;
      break;
    case DESK_L:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_LEFT))));
      }
      return false;
      break;
    case DESK_R:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_RGHT))));
      }
      return false;
      break;
    case UNI_PRIDE:
      if (record->event.pressed) {
        send_unicode_string("🏳️‍🌈");
      }
      return false;
      break;
    case ALT_aa:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_3) SS_TAP(X_KP_4)));
      }
      return false;
      break;
        case ALT_oo:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_TAP(X_KP_8)));
      }
      return false;
      break;
        case ALT_ae:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_5)));
      }
      return false;
      break;
          case ALT_AA:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_3)));
      }
      return false;
      break;
        case ALT_OO:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_6)));
      }
      return false;
      break;
        case ALT_AE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_6)));
      }
      return false;
      break;
  }
  return true;
}