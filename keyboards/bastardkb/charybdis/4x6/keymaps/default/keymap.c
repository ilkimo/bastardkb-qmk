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
    LAYER_ACCENTED_LETTERS,
    LAYER_SYMBOL_2
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
#define L_SYM2 TO(LAYER_SYMBOL_2)
#define L4_LSH LT(4,KC_SLSH)
#define M_CTL KC_LCTL
#define M_SFT KC_LSFT
#define M_ALT KC_LALT
#define M_GUI KC_LGUI
#define ZIATILDE S(KC_GRV)
#define GO_MINE TO(LAYER_MINECRAFT)
#define K_RPT QK_REPEAT_KEY

//#define ACENT_E UP(, )

// declare custom keycodes from a safe range, this is can be put also in the layout
enum custom_keycodes {
    LAYER_SYMBOL_SHIFT = SAFE_RANGE,
};

// Tap Dance declarations
enum {
    SL,
    SFT
};

void left_thumb_tap_each(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
    }
}

void left_thumb_tap_finished(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            add_oneshot_mods(MOD_BIT(KC_LSFT));
            break;
        case 2:
            caps_word_toggle();
            break;
        case 3:
            tap_code16(KC_CAPS);
            break;
        default:
    }
}

void left_thumb_tap_reset(tap_dance_state_t *state, void *user_data) {

}

void left_pinky_tap_each(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
    }
}

void left_pinky_tap_finished(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            swap_hands_toggle();
            break;
        case 2:
            caps_word_toggle(); //TODO
            break;
        case 3:
            tap_code16(KC_CAPS); //TODO
            break;
        default:
    }
}

void left_pinky_tap_reset(tap_dance_state_t *state, void *user_data) {

}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [SL] = ACTION_TAP_DANCE_FN_ADVANCED(left_thumb_tap_each, left_thumb_tap_finished, left_thumb_tap_reset),
    [SFT] = ACTION_TAP_DANCE_FN_ADVANCED(left_pinky_tap_each, left_pinky_tap_finished, left_pinky_tap_reset)
};

enum unicode_names {
    BANG,
    IRONY,
    SNEK,
    A_ACUTO,
    A_ACUTO_MAIUSC,
    A_GRAVE_MINUSC,
    E_GRAVE_MAIUSC,
    E_GRAVE_MINUSC,
    E_ACUTO_MAIUSC,
    E_ACUTO_MINUSC,
    I_GRAVE_MAIUSC,
    I_GRAVE_MINUSC,
    O_GRAVE_MAIUSC,
    O_GRAVE_MINUSC,
    U_GRAVE_MAIUSC,
    U_GRAVE_MINUSC,
    EMOJI_LAUGH,
    EMOJI_ROFL,
    SLIGHTLY_SMILING_FACE,
    UPSIDE_DOWN_FACE,
    RED_HEART,
    HEART_EXCLAMATION,
    LOUDLY_CRYING,
    ANXIOUS_FACE,
    CHECK_MARK,
    RED_CROSS,
    MUSCLE,
    EXPLOSION,
    ANGRY,
    PAROLACCE
};

#define ACENT_A UP(A_ACUTO, A_ACUTO_MAIUSC)
#define ACUT_E UP(E_ACUTO_MINUSC, E_ACUTO_MAIUSC)
#define GRAV_E UP(E_GRAVE_MINUSC, E_GRAVE_MAIUSC)
#define ACENT_I UP(I_GRAVE_MINUSC, I_GRAVE_MAIUSC)
#define ACENT_O UP(O_GRAVE_MINUSC, O_GRAVE_MAIUSC)
#define ACENT_U UP(U_GRAVE_MINUSC, U_GRAVE_MAIUSC)
#define LAUGH UP(EMOJI_LAUGH, EMOJI_ROFL)
#define SMILE UP(SLIGHTLY_SMILING_FACE, UPSIDE_DOWN_FACE)
#define HEART UP(RED_HEART, HEART_EXCLAMATION)
#define CRY UP(ANXIOUS_FACE, LOUDLY_CRYING)
#define MARKS UP(CHECK_MARK, RED_CROSS)
#define BICEPS UP(MUSCLE, EXPLOSION)
#define ANGER UP(ANGRY, PAROLACCE)

const uint32_t PROGMEM unicode_map[] = {
    [BANG]  = 0x203D,
    [IRONY] = 0x2E2E,
    [SNEK]  = 0x1F40D,
    [A_ACUTO] = 0x00E0,
    [A_ACUTO_MAIUSC] = 0x00C0,
    [A_GRAVE_MINUSC] = 0x00E0,
    [E_GRAVE_MAIUSC] = 0x00C8,
    [E_GRAVE_MINUSC] = 0x00E8,
    [E_ACUTO_MAIUSC] = 0x00C9,
    [E_ACUTO_MINUSC] = 0x00E9,
    [I_GRAVE_MAIUSC] = 0x00CC,
    [I_GRAVE_MINUSC] = 0x00EC,
    [O_GRAVE_MAIUSC] = 0x00D2,
    [O_GRAVE_MINUSC] = 0x00F2,
    [U_GRAVE_MAIUSC] = 0x00D9,
    [U_GRAVE_MINUSC] = 0x00F9,
    [EMOJI_LAUGH] = 0x1F602,
    [EMOJI_ROFL] = 0x1F923,
    [SLIGHTLY_SMILING_FACE] = 0x1F642,
    [UPSIDE_DOWN_FACE] = 0x1F643,
    [RED_HEART] = 0x2764,
    [HEART_EXCLAMATION] = 0x2763,
    [LOUDLY_CRYING] = 0x1F62D,
    [ANXIOUS_FACE] = 0x1F630,
    [CHECK_MARK] = 0x2705,
    [RED_CROSS] = 0x274C,
    [MUSCLE] = 0x1F4AA,
    [EXPLOSION] = 0x1F4A5,
    [ANGRY] = 0x1F620,
    [PAROLACCE] = 0x1F92C,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   TO(5),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y, TD(SFT), XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      XXXXXXX,  KCTL_A,  KSFT_R,  KALT_S,  KGUI_T,    KC_G,       KC_M,  KGUI_N,  KALT_E,  KSFT_I,  KCTL_O, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      XXXXXXX,    KC_Z,    L1_X,    L2_C,    L3_D,    KC_V,       KC_K,    KC_H, KC_COMM,  KC_DOT,  L4_LSH, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                   KC_SPC,KC_BSPC, XXXXXXX,      TD(SL),  KC_ENT,
                                           KC_ESC, XXXXXXX,       K_RPT
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
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_DOT,    KC_7,    KC_8,    KC_9, KC_EQL, XXXXXXX,
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
       XXXXXXX, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),    S(KC_6), S(KC_7), S(KC_8), KC_EQL, KC_SCLN, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,   M_CTL,   M_SFT, KC_COLN,   M_GUI, KC_BSLS,    KC_QUOT, S(KC_9), S(KC_0), KC_LBRC, KC_RBRC, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,ZIATILDE, KC_SLSH,  KC_DOT, KC_MINS,  KC_GRV,     L_SYM2,KC_TAB,S(KC_COMM),S(KC_DOT),KC_SLSH, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______,
                                             TO(0), _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_MOUSE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, DM_PLY1, DM_REC1, XXXXXXX,    XXXXXXX, DM_REC2, DM_PLY2, XXXXXXX, KC_PSCR, XXXXXXX,
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
       XXXXXXX, XXXXXXX, XXXXXXX, GO_MINE, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,   TO(7),   TO(8),   TO(9), XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,   TO(4),   TO(5),   TO(6), XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX,   TO(1),   TO(2),   TO(3),   TO(5),    XXXXXXX, XXXXXXX,   TO(1),   TO(2),   TO(3), XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______,   TO(0),
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
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, ACENT_U, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, ACENT_A, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,  ACUT_E, ACENT_I, ACENT_O, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,  GRAV_E, XXXXXXX, XXXXXXX, XXXXXXX,
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
       XXXXXXX, XXXXXXX,   ANGER,  BICEPS,   MARKS, XXXXXXX,    XXXXXXX,   LAUGH,   SMILE,   HEART,     CRY, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______,
                                             TO(0), _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_SYMBOL_2] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______,
                                             TO(0), _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};

const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    /* Left hand, matrix positions */
    {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}},
    {{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}},
    {{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}},
    {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}},
    {{2, 9}, {4, 9}, {5, 9}, {1, 9}, {0, 9}, {3, 9}},
    /* Right hand, matrix positions */
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}},
    {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}},
    {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}},
    {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}},
    {{0, 0}, {4, 4}, {0, 0}, {3, 4}, {0, 0}, {5, 4}},
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
    COMBO_ACCENTED,
    COMBO_SYMBOL,
    COMBO_SYMBOL_SHIFT,
    COMBO_EMOJI,
    COMBO_LEADER,
    COMBO_SWAP_HANDS_RIGHT,
    COMBO_SWAP_HANDS_LEFT,
};

const uint16_t PROGMEM accented_letters_combo[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM symbol_layer_shifted_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM symbol_layer_combo[] = {KC_P, KC_F, COMBO_END};
const uint16_t PROGMEM emoji_layer_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM leader_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM swap_hands_right_combo[] = {KC_DOT, KC_COMM, COMBO_END};
const uint16_t PROGMEM swap_hands_left_combo[] = {L1_X, L2_C, COMBO_END};

combo_t key_combos[] = {
    [COMBO_ACCENTED] = COMBO(accented_letters_combo, OSL(LAYER_ACCENTED_LETTERS)),
    [COMBO_SYMBOL] = COMBO(symbol_layer_combo, OSL(LAYER_SYMBOLS)),
    [COMBO_SYMBOL_SHIFT] = COMBO(symbol_layer_shifted_combo, LAYER_SYMBOL_SHIFT),
    [COMBO_EMOJI] = COMBO(emoji_layer_combo, TO(LAYER_EMOJI)),
    [COMBO_LEADER] = COMBO(leader_combo, QK_LEAD),
    [COMBO_SWAP_HANDS_RIGHT] = COMBO(swap_hands_right_combo, SH_TOGG),
    [COMBO_SWAP_HANDS_LEFT] = COMBO(swap_hands_left_combo, SH_TOGG),
};
// END COMBOS

// BEGIN LEADER KEY
void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if(leader_sequence_one_key(KC_S)) {
        // Leader, s => [S]ave vim
        SEND_STRING(SS_TAP(X_ESC));
        SEND_STRING(":w\n");
    } else if(leader_sequence_one_key(KC_E)) {
        // Leader, e => [E]xit vim
        SEND_STRING(SS_TAP(X_ESC));
        SEND_STRING(":q\n");
    } else if(leader_sequence_two_keys(KC_A, KC_C)) {
        // Leader, a, c => Ctrl+A, Ctrl+C
        SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    } else if(leader_sequence_two_keys(KC_S, KC_E)) {
        // Leader, s, e => [S]ave [E]xit vim
        SEND_STRING(SS_TAP(X_ESC));
        SEND_STRING(":wq\n");
    }
    // else if (leader_sequence_two_keys(KC_A, KC_S)) {
        // Leader, a, s => GUI+S
        // tap_code16(LGUI(KC_S));
    //}
}
// END LEADER KEY
// BEGIN MACROS
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) { return false; }
    // Your macros ...
    switch(keycode) {
    case LAYER_SYMBOL_SHIFT: // TODO
        if (record->event.pressed) {
            // when keycode VIM_SAVE_EXIT is pressed!
            //SEND_STRING(SS_TAP(OSM(X_LSFT)));
            //SEND_STRING(SS_TAP(OSL(LAYER_ACCENTED_LETTERS)));
        } else {
            // when keycode VIM_SAVE_EXIT is released!
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
// BEGIN TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(SL):
            return 500;
        default:
            return TAPPING_TERM;
    }
}
// END TAPPING_TERM_PER_KEY
// clang-format on
