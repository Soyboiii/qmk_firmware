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
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  DESK_L,
  DESK_R
};

enum unicode_names {
    UNI_aa,
    UNI_oo,
    UNI_ae,
    UNI_AA,
    UNI_OO,
    UNI_AE
};

enum {
    TD_LCBR_RCBR,
    TD_LBR_RBR,
    TD_TILD_GRV
};

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_LCBR_RCBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_TILD_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_TILD, KC_GRV),
    [TD_LBR_RBR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC)
};

const uint32_t PROGMEM unicode_map[] = {
    [UNI_aa]  = 0x00E5,  //
    [UNI_AA] = 0x00C5,  //
    [UNI_oo]  = 0x00F8, //
    [UNI_OO]  = 0x00D8, //
    [UNI_ae]  = 0x00E6, //
    [UNI_AE]  = 0x00C6, //
};

#define LOWER LT(_LOWER, KC_TAB)
#define RAISE LT(_RAISE, KC_ENT)

#define HOME_A SFT_T(KC_A)
#define HOME_S ALT_T(KC_S)
#define HOME_D CTL_T(KC_D) 
#define HOME_F GUI_T(KC_F) 
#define HOME_J RGUI_T(KC_J) 
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_QU RSFT_T(KC_QUOT)

// TODO
// Make number layer one shot, and nav layer toggle 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty                                                                                 *  Lower
 * ,-----------------------------------------------------------------------------------.  *  ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |      |      |   Y  |   U  |   I  |   O  |   P  |  *  | Home |Pg Up |Pg Dn | End  | MS_2 |      |      |      |      |      |      |  å   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|  *  |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |      |      |   H  |   J  |   K  |   L  |   ;  |  *  | Left | Down |  Up  |Right | MS_1 |      |      |      |      |      |   ø  |  æ   |
 * |Shift |  Alt | Ctrl |  Gui |      |      |      |      |  Gui | Ctrl |  Alt |Shift |  *  |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|  *  |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |      |      |   N  |   M  |   ,  |   .  |   /  |  *  | WH_L | WH_D | WH_U | WH_L | MS_3 |      |      |      |Mute  | Vol+ | Vol- | Play |
 * |------+------+------+------+------+------+------+------+------+------+------+------|  *  |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Esc  | Tab  |Space |      |      | Bksp |Enter | Del  |      |      |  *  |      |      |      |      |  Del |      |      | Esc  |      |      |      |      |
 * |      |      |      |Lower |      |      |      |      |Raise |      |      |      |  *  |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'  *  `-----------------------------------------------------------------------------------'

 * Adjust                                                                                 *  Raise
 * ,-----------------------------------------------------------------------------------.  *  ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |  F7  |  F8  |  F9  |  F10 |  F11 |  *  |   1  |   2  |   3  |   4  |   5  |      |      |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|  *  |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F6  |ClkOn |ClkOff|      |  Esc |      |      |PrtSc |      |      |      |  F12 |     |   !  |   @  |   #  |  [ ] |   :  |      |      |   +  |   *  |   ^  |   (  |   )  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|  *  |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Reset|MsSpd1|MsSpd2|MsSpd3|      |      |      |Insert|      |      |      |Sleep |  *  |   _  |  ~ ' |   %  |  { } |   ;  |      |      |   -  |   =  |   &  |   |  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|  *  |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |  *  |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'  *  `-----------------------------------------------------------------------------------'
 */     
[_QWERTY] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, XXXXXXX, XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   
    HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G, XXXXXXX, XXXXXXX, KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_QU,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    XXXXXXX, XXXXXXX,  KC_ESC, LOWER, KC_SPC, XXXXXXX, XXXXXXX, KC_BSPC, RAISE,   KC_DEL,  XXXXXXX,   XXXXXXX
),


[_LOWER] = LAYOUT_planck_grid(
    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BTN2, _______, _______, _______, _______, _______, _______, XP(UNI_aa,UNI_AA),
    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BTN1, _______, _______, _______, DESK_L,  DESK_R, XP(UNI_oo,UNI_OO), XP(UNI_ae,UNI_AE),
    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_D, KC_BTN3, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,
    _______, _______, _______, _______, KC_DEL,  _______, _______, KC_ESC,  _______, _______, _______, _______
),


[_RAISE] = LAYOUT_planck_grid(
    KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_EXLM, KC_AT,   KC_HASH, TD(TD_LBR_RBR), S(KC_SCLN), _______, _______, KC_PLUS, KC_ASTR,  KC_CIRC, KC_LPRN, KC_RPRN,
    KC_UNDS, TD(TD_TILD_GRV), KC_PERC, TD(TD_LCBR_RCBR),  KC_SCLN, _______, _______, KC_MINS, KC_EQL,  KC_AMPR, KC_PIPE, KC_BSLS,
    _______, _______, _______, _______, KC_DEL, _______, _______, KC_ESC, _______, _______, _______, _______
),


[_ADJUST] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,
    KC_F6,   CK_ON,   CK_OFF,  _______, _______, _______, _______, KC_PSCR, _______,  _______, _______, KC_F12,
    RESET,   KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, KC_INS,  _______,  _______, _______, KC_SLEP,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
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
