/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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
#include "features/achordion.h"

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_ARROWS,
    LAYER_NUMBERS,
    LAYER_SYMBOLS,
    LAYER_MOUSE,
    LAYER_NAVIGATION,
    LAYER_MINECRAFT,
    LAYER_EMOJI,
    LAYER_ACCENTED_LETTERS
};

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)

// 'K' stands for Kimo
#define KCTL_A MT(MOD_LCTL,KC_A)
#define KSFT_R MT(MOD_LSFT,KC_R)
#define KALT_S MT(MOD_LALT,KC_S)
#define KGUI_T MT(MOD_LGUI,KC_T)
#define KGUI_N MT(MOD_LGUI,KC_N)
#define KALT_E MT(MOD_LALT,KC_E)
#define KSFT_I MT(MOD_LSFT,KC_I)
#define KCTL_O MT(MOD_LCTL,KC_O)
#define L1_X LT(1,KC_X)
#define L2_C LT(2,KC_C)
#define L3_D LT(3,KC_D)
#define L4_LSH LT(4,KC_SLSH)
#define M_CTL KC_LCTL
#define M_SFT KC_LSFT
#define M_ALT KC_LALT
#define M_GUI KC_LGUI
#define ZIATILDE S(KC_GRV)
#define GO_MINE TO(LAYER_MINECRAFT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      XXXXXXX,  KCTL_A,  KSFT_R,  KALT_S,  KGUI_T,    KC_G,       KC_M,  KGUI_N,  KALT_E,  KSFT_I,  KCTL_O, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      XXXXXXX,    KC_Z,    L1_X,    L2_C,    L3_D,    KC_V,       KC_K,    KC_H, KC_COMM,  KC_DOT,  L4_LSH, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                   KC_SPC,KC_BSPC, XXXXXXX,      M_SFT,  KC_ENT,
                                           KC_ESC, XXXXXXX,      QK_REPEAT_KEY
 //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_ARROWS] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,   M_CTL,   M_SFT,   M_ALT,   M_GUI,  KC_F11,     KC_F12, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______,  KC_DEL, _______,    _______, _______,
                                             TO(0), _______,    QK_AREP
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NUMBERS] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_DOT,    KC_7,    KC_8,    KC_9, KC_PEQL, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,   M_CTL,   M_SFT,   M_ALT,   M_GUI, XXXXXXX,    KC_PPLS,    KC_4,    KC_5,    KC_6, KC_MINS, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, KC_COLN, XXXXXXX, KC_DOT, XXXXXXX,    KC_PAST,    KC_1,    KC_2,    KC_3, KC_PSLS, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, KC_0,
                                             TO(0), _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_SYMBOLS] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),    S(KC_6), S(KC_7), S(KC_8), KC_PEQL, KC_SCLN, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,   M_CTL,   M_SFT, KC_COLN,   M_GUI, KC_BSLS,    KC_QUOT, S(KC_9), S(KC_0), KC_LBRC, KC_RBRC, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,ZIATILDE, KC_SLSH,  KC_DOT, KC_MINS,  KC_GRV,    KC_CAPS,KC_TAB,S(KC_COMM),S(KC_DOT),KC_SLSH, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______,
                                             TO(0), _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_MOUSE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, DM_PLY1, DM_REC1, XXXXXXX,    XXXXXXX, DM_REC2, DM_PLY2, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,   M_CTL,   M_SFT,   M_ALT,   M_GUI, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______,
                                             TO(0), _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NAVIGATION] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, GO_MINE, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX,   TO(1),   TO(2),   TO(3),   TO(5),    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   TO(4), XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______,
                                             TO(0), _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_MINECRAFT] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LCTL,    KC_Q,    KC_W,    KC_E,    KC_T,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LCTL,   KC_F3,   KC_F4,   KC_F5,    KC_G,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______,   TO(0), _______,    _______, _______,
                                            KC_ESC, _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_ACCENTED_LETTERS] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,    KC_A,    KC_C,    KC_C,    KC_E,    KC_N,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______,
                                             TO(0), _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_EMOJI] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,    KC_E,    KC_M,    KC_O,    KC_J,    KC_I,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______,
                                             TO(0), _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};

// declare custom keycodes from a safe range, this is can be put also in the layout
enum custom_keycodes {
    VIM_SAVE = SAFE_RANGE,
    VIM_SAVE_EXIT,
};

// BEGIN ALT KEY MAPPINGS
uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    bool shifted = (mods & MOD_MASK_SHIFT);  // Was Shift held?
    bool controlled = (mods & MOD_MASK_CTRL);  // Was Control held?
    //bool modded = (mods & MOD_MASK_GUI);  // Was Mod held?
    //bool alted = (mods & MOD_MASK_ALT);  // Was Alt held?

    switch(keycode) {
    case KC_U: return C(KC_R);  // 'u' maps Ctrl + r. This is for the vim undo-redo
    case KC_TAB:
            if(shifted) {
                return KC_TAB;
            } else {
                return S(KC_TAB);
            }
    case KC_R:
            if(controlled) {
                return KC_U; // Ctrl+'r' maps to 'u'. This is for the vim undo-redo
            } else {
                return KC_TRNS;
            }
    case KC_Y:
        if(controlled) {
            return C(KC_Z);
        } else {
            return KC_TRNS;
        }
    case KC_Z:
        if(controlled) {
            return C(KC_Y);
        } else {
            return KC_TRNS;
        }
    default: return KC_TRNS;  // Defer to default definitions.
    }
}
// END ALT KEY MAPPINGS

// BEGIN COMBOS
enum combo_events {
    COMBO_NAVIGATION,
    COMBO_ACCENTED,
    COMBO_SYMBOL,
    COMBO_SYMBOL_SHIFT,
    COMBO_EMOJI,
    COMBO_VIM_SAVE,
    COMBO_VIM_SAVE_EXIT,
};

const uint16_t PROGMEM navigation_combo[] = {KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM accented_letters_combo[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM symbol_layer_shifted_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM symbol_layer_combo[] = {KC_P, KC_F, COMBO_END};
const uint16_t PROGMEM emoji_layer_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM vim_save_combo[] = {KC_F, KC_P, KC_L, COMBO_END};
const uint16_t PROGMEM vim_save_exit_all_combo[] = {KC_F, KC_P, KC_L, KC_U, COMBO_END};

combo_t key_combos[] = {
    [COMBO_NAVIGATION] = COMBO(navigation_combo, TO(LAYER_NAVIGATION)),
    [COMBO_ACCENTED] = COMBO(accented_letters_combo, OSL(LAYER_ACCENTED_LETTERS)),
    [COMBO_SYMBOL] = COMBO(symbol_layer_combo, OSL(LAYER_SYMBOLS)),
    [COMBO_SYMBOL_SHIFT] = COMBO(symbol_layer_shifted_combo, OSM(MOD_LSFT)),
    [COMBO_EMOJI] = COMBO(emoji_layer_combo, TO(LAYER_EMOJI)),
    [COMBO_VIM_SAVE] = COMBO(vim_save_combo, VIM_SAVE),
    //[COMBO_VIM_SAVE_EXIT] = COMBO(emoji_layer_combo, TO(LAYER_EMOJI)),
};
// END COMBOS

// BEGIN MACROS
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) { return false; }
    // Your macros ...
    switch(keycode) {
    case VIM_SAVE:
        if (record->event.pressed) {
            // when keycode VIM_SAVE is pressed!
            SEND_STRING(SS_TAP(X_ESC));
            SEND_STRING(SS_DOWN(X_LSFT));
            SEND_STRING(SS_TAP(X_SCLN));
            SEND_STRING(SS_UP(X_LSFT));
            SEND_STRING(SS_TAP(X_W));
            SEND_STRING(SS_TAP(X_ENT));
        } else {
            // when keycode QMKBEST is released
        }
        break;
    }

    return true;
}
// END MACROS

// BEGIN ACHORDION
bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
    // Exceptionally consider the following chords as holds, even though they
    // are on the same hand in Dvorak.
    switch(tap_hold_keycode) {
        case KCTL_A:
        if(other_keycode == KC_Z
            || other_keycode == L1_X
            || other_keycode == L2_C
            || other_keycode == L3_D
            || other_keycode == KC_V
            || other_keycode == KGUI_T
            || other_keycode == KC_F
        ) { return true; }
        break;
        case KSFT_R:
        if(other_keycode == KC_Z
            || other_keycode == L1_X
            || other_keycode == L2_C
            || other_keycode == L3_D
            || other_keycode == KC_V
        ) { return true; }
        break;
        case KALT_S:
        if(other_keycode == KC_Z
            || other_keycode == L1_X
            || other_keycode == L2_C
            || other_keycode == L3_D
            || other_keycode == KC_V
        ) { return true; }
        break;
        case KGUI_T:
        if(other_keycode == KC_Z
            || other_keycode == L1_X
            || other_keycode == L2_C
            || other_keycode == L3_D
            || other_keycode == KC_V
            || other_keycode == KC_P
            || other_keycode == KC_W
            || other_keycode == KC_F
        ) { return true; }
        break;
        case KGUI_N:
        if(other_keycode == KC_K
            || other_keycode == KC_H
            || other_keycode == KC_COMM
            || other_keycode == KC_DOT
            || other_keycode == L4_LSH
            || other_keycode == KC_ENT
        ) { return true; }
        break;
        case KALT_E:
        if(other_keycode == KC_K
            || other_keycode == KC_H
            || other_keycode == KC_COMM
            || other_keycode == KC_DOT
            || other_keycode == L4_LSH
        ) { return true; }
        break;
        //case KSFT_I:
        //break;
        case KCTL_O:
        if(other_keycode == KC_K
            || other_keycode == KC_H
            || other_keycode == KC_COMM
            || other_keycode == KC_DOT
            || other_keycode == L4_LSH
        ) {
            return true;
        } else if(other_keycode == KC_F) {
            return false;
        }
        break;
        case L1_X:
        return true;
        case L2_C:
        return true;
        case L3_D:
        return true;
        case L4_LSH:
        return true;
    }

    // Also allow same-hand holds when the other key is in the rows below the
    // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
    //if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 4) { return true; }

    // Otherwise, follow the opposite hands rule.
    return achordion_opposite_hands(tap_hold_record, other_record);
}

void matrix_scan_user(void) {
    achordion_task();
}

uint16_t achordion_streak_timeout(uint16_t tap_hold_keycode) {
    if(IS_QK_LAYER_TAP(tap_hold_keycode)) {
        return 0;  // Disable streak detection on layer-tap keys.
    }

    switch(tap_hold_keycode) {
    case L1_X:
    case L2_C:
    case L3_D:
        return 50;
    }

    return 240;  // Default of 100 ms.
}
// END ACHORDION

// clang-format on
