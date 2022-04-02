/* Copyright 2021 NachoxMacho
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
* along with this program.  If not, see &lt;http://www.gnu.org/licenses/&gt;.
*/

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┌───┬───┬───┬───┐
     * │ESC│INS│PSc│SLK│PUS│
     * ├───┼───┼───┼───┼───┤
     * │HME│Num│ / │ * │ - │
     * ├───┼───┼───┼───┼───┤
     * │PUP│ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┼───┤ + │
     * │PDN│ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┼───┤
     * │END│ 1 │ 2 │ 3 │   │
     * ├───┼───┴───┼───┤Ent│
     * │MO1│ 0     │ . │   │
     * └───┴───────┴───┴───┘
     */
    [0] = LAYOUT_numpad_6x5(
        KC_ESC,    KC_INS,  KC_PSCR, KC_SCRL, KC_PAUS,
        KC_HOME,   KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
        KC_PGUP,   KC_P7,   KC_P8,   KC_P9,
        KC_PGDN,   KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_END,    KC_P1,   KC_P2,   KC_P3,
        MO(1),       KC_P0,            KC_PDOT, KC_PENT
    ),

    /*
     * ┌───┌───┐───┬───┬───┐
     * │Rst│INS│PSc│SLK│PSE│
     * ├───┼───┘───┼───┼───┤
     * │RGB│Num│ / │ * │ - │
     * ├───┼───┼───┼───┼───┤
     * │RGB│Hom│ ↑ │PgU│   │
     * ├───┼───┼───┼───┤ + │
     * │RGB│ ← │   │ → │   │
     * ├───┼───┼───┼───┤───┤
     * │RGB│End│ ↓ │PgD│   │
     * ├───┼───┴───┼───┤Ent│
     * │MO1│Insert │Del│   │
     * └───┴───────┴───┘───┘
     */
    [1] = LAYOUT_numpad_6x5(
        RESET,   _______, _______, _______, _______,
        RGB_TOG, _______, _______, _______, _______,
        RGB_MOD, KC_HOME, KC_UP,   KC_PGUP,
        RGB_HUI, KC_LEFT, XXXXXXX, KC_RGHT, _______,
        RGB_VAI, KC_END,  KC_DOWN, KC_PGDN,
        _______, KC_INS,           KC_DEL,  _______
    )
};
