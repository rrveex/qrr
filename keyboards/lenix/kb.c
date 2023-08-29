/* Copyright 2021 Mark Story
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

#include "quantum.h"
#include "keycodes.h"
#include "report.h"
#include "string.h"
#include "stdio.h"

const key_override_t koRaltI = ko_make_basic(MOD_BIT(KC_RIGHT_ALT), KC_R, RALT(KC_I));
const key_override_t koRaltS = ko_make_basic(MOD_BIT(KC_RIGHT_ALT), LSFT_T(KC_COLON), RALT(KC_Q));
const key_override_t koRaltJ = ko_make_basic(MOD_BIT(KC_RIGHT_ALT), KC_J, RALT(KC_Q));

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &koRaltI, &koRaltS, &koRaltJ,
    NULL // Null terminate the array of overrides!
};

const uint16_t COMBO_LEN = 8;

const uint16_t PROGMEM cmbJW[] = {KC_J, KC_W, COMBO_END};
const uint16_t PROGMEM cmbYQ[] = {KC_Y, KC_Q, COMBO_END};
const uint16_t PROGMEM cmbWF[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM cmbUY[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM cmbJP[] = {KC_J, KC_P, COMBO_END};
const uint16_t PROGMEM cmbLQ[] = {KC_L, KC_Q, COMBO_END};
const uint16_t PROGMEM cmbJB[] = {KC_J, KC_B, COMBO_END};
const uint16_t PROGMEM cmbZQ[] = {KC_Z, KC_Q, COMBO_END};

combo_t key_combos[] = {
    COMBO(cmbJW, LCTL(KC_W)), // close_tab
    COMBO(cmbYQ, LCTL(KC_W)), // close_tab
    COMBO(cmbWF, KC_BTN3),    // middle
    COMBO(cmbUY, KC_BTN3),    // middle
    COMBO(cmbJP, KC_BTN1),    // left
    COMBO(cmbLQ, KC_BTN1),    // left
    COMBO(cmbJB, KC_BTN2),    // right
    COMBO(cmbZQ, KC_BTN2),    // right
};

// #define COMBO_LEN (sizeof(key_combos) / sizeof(combo_t))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // switch (keycode) {
    //     case M0:
    //         do_scan();
    //         break;
    // }
    return true;
}
