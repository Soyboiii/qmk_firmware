/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NORDIC
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

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_PLAY_NEXT] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MNXT), // Tap once for play, twice for next
    [TD_MUTE_PREV] = ACTION_TAP_DANCE_DOUBLE(KC_MUTE, KC_MPRV)  // Tap once for mute, twice for previous
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

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty                                                                                 *  Lower
 * ,-----------------------------------------------------------------------------------.  *  ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |  *  |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  å   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|  *  |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtrl|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |  *  |      |      |      | DskL | DskR | MS_1 | MS_2 |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|  *  |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |  *  |      | WH_L | WH_D | WH_U | WH_L | MS_3 | App  |ISO ~ |ISO | |   ø  |   æ  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|  *  |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | RAlt | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |  *  |      |      |      |      |      |     Del     |      | Home |Pg Up |Pg Dn | End  |
 * `-----------------------------------------------------------------------------------'  *  `-----------------------------------------------------------------------------------'

 * Adjust                                                                                 *  Raise
 * ,-----------------------------------------------------------------------------------.  *  ,-----------------------------------------------------------------------------------.
 * | Reset|      |      |  AE  |  😄 |  😅  |  😊  | 🙃  | 😋   |  Win |  OO  |  AA  |  *  |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|  *  |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  AA  |ClkOn |ClkOff|  😎 |  🤓  |  💖  | 💯  |  👀  |  Lnx |  OO  |  AE  |  *  |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|  *  |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |MsSpd1|MsSpd2|MsSpd3|  🎉 |  ✨  |  💣  | 🔥   |  🏳️‍🌈 |  Mac |      |Sleep |  *  |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Insert|PrtSrc|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|  *  |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |  *  |      |      |      |      |      |    Space    |      |MutPrv| Vol- | Vol+ |PlyNxt|
 * `-----------------------------------------------------------------------------------'  *  `-----------------------------------------------------------------------------------'
 */     
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_ESC, KC_RALT, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),


[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN,           KC_RPRN,           XP(UNI_aa,UNI_AA),
    _______, _______, _______, DESK_L,  DESK_R,  KC_BTN1, KC_BTN2, KC_UNDS,    KC_PLUS,    KC_LCBR,           KC_RCBR,           KC_PIPE,
    _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_BTN3, KC_APP,  S(KC_NUHS), S(KC_NUBS), XP(UNI_oo,UNI_OO), XP(UNI_ae,UNI_AE), _______,
    _______, _______, _______, _______, _______, KC_DEL,  KC_DEL,  _______,    KC_HOME,    KC_PGDN,           KC_PGUP,           KC_END
),


[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_INS, KC_PSCR, _______,
    _______, _______, _______, _______, _______, KC_SPC, KC_SPC, _______, TD(TD_MUTE_PREV), KC_VOLD, KC_VOLU, TD(TD_PLAY_NEXT)
),


[_ADJUST] = LAYOUT_planck_grid(
    RESET,       _______, _______, ALT_ae,  X(UNI_SMILE), X(UNI_SMISW), X(UNI_SMIBH), X(UNI_SMIUP), X(UNI_SAVOR),  UC_M_WC, ALT_oo,    ALT_aa,
    _______,     ALT_aa,  CK_ON,   CK_OFF,  X(UNI_SUNGL), X(UNI_NERDG), X(UNI_SPHRT), X(UNI_HNDRD), X(UNI_EYES),   UC_M_LN, ALT_oo,    ALT_ae,
    MO(_NORDIC), KC_ACL0, KC_ACL1, KC_ACL2, X(UNI_PARTY), X(UNI_SPARK), X(UNI_BOMB),  X(UNI_FIRE),  UNI_PRIDE,  UC_M_MA, _______,  KC_SLEP,
    _______,     _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,  _______
),


[_NORDIC] = LAYOUT_planck_grid(
    _______, _______, _______,   ALT_AE,  _______, _______, _______, _______, _______,  _______, ALT_OO,    ALT_AA,
    _______, ALT_AA,  _______, _______, _______, _______, _______, _______, _______,  _______, ALT_OO,    ALT_AE,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,  _______
)

};

// songs go here
#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
  float gb_song[][2]         = SONG(GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

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

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
