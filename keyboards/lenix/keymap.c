/* Copyright 2020 Imam Rafii
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
#include "keycodes.h"
#include "quantum.h"

#define t__s KC_TRNS
#define n__o KC_NO
// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = {
    {KC_MUTE, KC_VOLD, KC_VOLU, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o}, // 0
    {KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL}, // 1
    {KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS, KC_EQL, KC_BSPC}, // 2
    {KC_TAB, KC_J, KC_W, KC_F, KC_P, KC_B, KC_Z, KC_L, KC_U, KC_Y, KC_Q, KC_LBRC, KC_RBRC, KC_BSLS}, // 3
    {KC_BSPC, KC_A, KC_R, KC_S, KC_T, KC_G, KC_H, KC_N, KC_E, KC_I, KC_O, n__o, KC_ENT, n__o},  // 4
    {LSFT_T(KC_COLON), LALT_T(KC_X), LCTL_T(KC_C), KC_D, KC_V, KC_CAPS, \
                KC_K, KC_M, RCTL_T(KC_COMMA), RALT_T(KC_DOT), RSFT_T(KC_SLASH), MO(1), n__o, n__o}, // 5
    {KC_LCTL, KC_LGUI, MO(2), KC_SPC, MO(3), KC_LGUI, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, n__o, n__o, n__o, n__o}, // 6
    {KC_HOME, KC_PGUP, KC_PGDN, KC_END, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o}, // 7
    {KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o}, // 8
    {KC_P7, KC_P8, KC_P9, KC_PPLS, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o}, // 9
    {KC_P4, KC_P5, KC_P6, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o}, //10
    {KC_P1, KC_P2, KC_P3, KC_PENT, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o}, // 11
    {KC_P0, KC_PDOT, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o, n__o} // 12
},
[1] = { // rshift
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 0
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 1
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 2 
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 3
    {t__s, t__s, LSFT(KC_DEL), LCTL(KC_INS), LSFT(KC_INS), t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 4
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 5
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 6
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 7
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 8
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 9
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 10
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 11
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s} // 12
},
[2] = { // lalt
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 0
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 1
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 2
    {t__s, t__s, t__s, t__s, t__s, t__s, LSFT(KC_GRV), LSFT(KC_EQL), LSFT(KC_BSLS), KC_BSLS, LSFT(KC_MINS), t__s, t__s, t__s}, // 3
    {t__s, t__s, t__s, t__s, t__s, t__s, KC_GRV, KC_EQL, KC_QUOT, LSFT(KC_QUOT), KC_MINS, t__s, t__s, t__s}, // 4
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 5
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 6
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 7
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 8
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 9
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 10
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 11
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s} //12
},
[3] = { // ralt
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 0
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 1
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 2
    {t__s, t__s, LSFT(KC_9), LSFT(KC_0), t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 3
    {t__s, LSFT(KC_LBRC), KC_LBRC, KC_RBRC, LSFT(KC_RBRC), t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 4
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 5
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 6
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 7
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 8
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 9
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 10
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s}, // 11
    {t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s, t__s} // 12
}
};
// clang-format on
