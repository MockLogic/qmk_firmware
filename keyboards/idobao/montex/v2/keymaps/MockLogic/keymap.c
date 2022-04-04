/* Copyright 2021 NachoxMacho
*  Copyright 2022 peepeetee
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

#include "rgb_matrix_map.h"

#define _NUM 0
#define _FN1 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┌───┬───┬───┬───┐
     * │ESC│Ins│Psc│Slk│Pas│
     * ├───┼───┼───┼───┼───┤
     * │Hme│Num│ / │ * │ - │
     * ├───┼───┼───┼───┼───┤
     * │PgU│ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┼───┤ + │
     * │PgD│ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┼───┤
     * │End│ 1 │ 2 │ 3 │   │
     * ├───┼───┴───┼───┤Ent│
     * │MO1│ 0     │ . │   │
     * └───┴───────┴───┴───┘
     */
    [_NUM] = LAYOUT_numpad_6x5(
        KC_ESC,    KC_INS,  KC_PSCR, KC_SCRL, KC_PAUS,
        KC_HOME,   KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
        KC_PGUP,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_PGDN,   KC_P4,   KC_P5,   KC_P6,
        KC_END,    KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        MO(1),     KC_P0,            KC_PDOT
    ),

    /*
     * ┌───┌───┐───┬───┬───┐
     * │Rst│Ins│Psc│Slk│Pas│
     * ├───┼───┼───┼───┼───┤
     * │Hme│Num│ / │ * │ - │
     * ├───┼───┼───┼───┼───┤
     * │PgU│ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┼───┤ + │
     * │PgD│ $ │ 5 │ 6 │   │
     * ├───┼───┼───┼───┼───┤
     * │End│ 1 │ 2 │ 3 │   │
     * ├───┼───┴───┼───┤Ent│
     * │MO1│ 0     │ . │   │
     * └───┴───────┴───┴───┘
	 */
    [_FN1] = LAYOUT_numpad_6x5(
        RESET,   _______, _______, _______, RGB_TOG,
        RGB_MOD, _______, _______, _______, _______,
        RGB_SAI, _______, KC_UP, _______, _______,
        RGB_HUI, KC_DLR,  KC_LEFT, KC_RGHT, 
        RGB_VAI, _______, KC_DOWN, _______, KC_RSFT,
        _______, KC_INS,           KC_DEL  
    )

};


#ifdef RGB_MATRIX_ENABLE
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    // NumLock RGB
    if (IS_HOST_LED_ON(USB_LED_NUM_LOCK)) {
        // Do Nothing
    } else {
		rgb_matrix_set_color(LED_NL, RGB_ORANGE);
	}

    // Scroll Lock RGB
    if (IS_HOST_LED_ON(USB_LED_SCROLL_LOCK)) {
		rgb_matrix_set_color(LED_SL, RGB_BLUE);
	}

    // Function Layer RGB
    switch (get_highest_layer(layer_state)) { // special handling per layer
    case _FN1: 
		rgb_matrix_set_color(LED_FN, RGB_PURPLE); // Light up FN Purple
		rgb_matrix_set_color(LED_ENT, RGB_PURPLE); // Light up Enter Purple
		rgb_matrix_set_color(LED_ESC, RGB_RED); // Light up Escape Red
		rgb_matrix_set_color(LED_HM, RGB_YELLOW); // Light up Home Yellow
		rgb_matrix_set_color(LED_PAS, RGB_YELLOW); // Light up Pause Yellow
		rgb_matrix_set_color(LED_PU, RGB_YELLOW); // Light up Page Up Yellow
		rgb_matrix_set_color(LED_PD, RGB_YELLOW); // Light up Page Down Yellow
		rgb_matrix_set_color(LED_END, RGB_YELLOW); // Light up End Yellow
		rgb_matrix_set_color(LED_4, RGB_GREEN); // Light up 4 Green
		rgb_matrix_set_color(LED_0, RGB_GREEN); // Light up 0 Green
		rgb_matrix_set_color(LED_DOT, RGB_GREEN); // Light up . Green
		rgb_matrix_set_color(LED_8, RGB_SPRINGGREEN2); // Light up 8 Spring Green
		rgb_matrix_set_color(LED_5, RGB_SPRINGGREEN2); // Light up 5 Spring Green
		rgb_matrix_set_color(LED_6, RGB_SPRINGGREEN2); // Light up 6 Spring Green
		rgb_matrix_set_color(LED_2, RGB_SPRINGGREEN2); // Light up 2 Spring Green
		break;
		
	default:
        break;
    }


}
#endif
