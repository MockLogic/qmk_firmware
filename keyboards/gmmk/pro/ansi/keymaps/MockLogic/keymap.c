/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Variations made by MockLogic
Includes Mouse Jiggler from: https://github.com/DIYCharles/MouseJiggler/blob/master/QMK%20firmware/mousejiggler/keymaps/default/keymap.c

*/

#include QMK_KEYBOARD_H

#include "rgb_matrix_map.h"

#define _BASE 0
#define _SPACE 1
#define _FN1 2
#define _MOUSE 3
#define _GAME 4
#define _FN2 5
#define _LEADER 6
#define _RGB 7

// Tap Dance declarations
enum {
	TD_ESC_GM
};

// Custom Key Codes
enum custom_keycodes {
    MRED = SAFE_RANGE,
	MORN,
	MYEL,
	MCRT,
	MGRN,
	MSGN,
	MCYN,
	MAZR,
	MBLU,
	MVLT,
	MMAG,
	MRSE,
	MFAC,
	MFCW,
	MFWHT,
	TJIGGLE,
};


// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for layer toggle
	[TD_ESC_GM] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_ESC, _GAME)
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* Base Layout
     *
     * ,-------------------------------------------------------------------------------------------------------------.
     * | Esc  ||  F1  |  F2  |  F3  |  F4  ||  F5  |  F6  |  F7  |  F8  ||  F9  | F10  | F11  | F12  || Del || Mute |
     * |=============================================================================================================|
     * |  ` ~ |  1 ! |  2 @ |  3 # |  4 $ |  5 % |  6 ^ |  7 & |  8 * |  9 ( |  0 ) |  - _ |  = + |  Backspc || Home |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+----------++------|
     * |   Tab   |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   | [ }  | ] }  |  \ |  || PgUp |
     * |---------+------+------+------+------+------+------+------+------+------+------+------+------+-------++------|
     * |  Capslock  |  A   |  S   |  D   |  F  |  G   |  H   |  J   |  K   |  L   | ; :  | ' "  |    Enter   || PgDn |
     * |------------+------+------+------+-----+------+------+------+------+------+------+------|----+========+------|
     * |    LShift    |  Z   |  X   |  C   |  V   |  B   |  N   |  M   | , <  | . >  | / ?  | RShift ||  Up  || End  |
     * |--------------+------+------+------+------+------+------+------+------+------+------+--+=====++------++======|
     * |  Ctrl  |   Win  |  LAlt  |               Space                  | RAlt |  Fn  | Lead || Left | Down | Rght |
     * `------------------------------------------------------------------------------------------------------------'
     */
	 
    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_FN1), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // Space Cadet Shift overlay. Double tap Esc or re-use Function 9 or 0 to turn off.
    [_SPACE] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        KC_LSPO,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_RSPC, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    // The function keys.
	// Space Cadet Shift is over ridden on this layer.
    [_FN1] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_INS,          _______,
        DM_REC1, DM_PLY1, _______, _______, _______, _______, _______, _______, _______, TG(_SPACE), TG(_SPACE), _______, _______, EEP_RST,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            _______,
        MFCW,    _______, _______, _______, _______, _______, _______, TJIGGLE, _______, _______, _______, _______,          _______,          _______,
        KC_LSFT,          _______, _______, MFAC,    _______, _______, NK_TOGG, _______, _______, _______, _______,          KC_RSFT, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, KC_LEAD, _______, _______, _______
    ),

    // Mouse Layer where arrow keys move the mouse, Right Control is left click, and End is Right click.
    [_MOUSE] = LAYOUT(
        TG(_MOUSE), _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, _______,          _______,
        _______,  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, _______,            KC_NO,  
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, _______,            KC_NO,  
        _______,  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,            _______,          KC_NO,  
        KC_LSFT,             _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, KC_RSFT,   KC_MS_U, KC_BTN2,  
        _______,  _______,   _______,                              _______,                               _______,   _______,   KC_BTN1,   KC_MS_L, KC_MS_D, KC_MS_R
    ),

    // Gaming overlay. Capslock, Spacecadet Shift, Function, and Windows Key all disabled. CapsWord is not disabled!
    [_GAME] = LAYOUT(
        TD(TD_ESC_GM), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        KC_NO,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        KC_LSFT,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_RSFT, _______, _______,
        _______, KC_NO,   _______,                            _______,                            _______, MO(_FN2),   _______,   _______, _______, _______
    ),
	
	// The Gamer function keys.
	// Mostly Transparent to the Gamer level
    [_FN2] = LAYOUT(
        TO(_BASE), KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_INS,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    // Layer used when the Leader key is active. helpful to prevent mistakes, but also for rgb highlights
    [_LEADER] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        KC_NO,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        KC_LSFT,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_RSFT, _______, _______,
        _______, KC_NO,   _______,                            _______,                            _______, KC_NO,   _______,   _______, _______, _______
    ),

    // Layer used to configure RGB settings
	// Left Side of board changes Hue, Saturation, and Brightness. Arrows change mode and speed. Function Keys are color presets.
    [_RGB] = LAYOUT(
       TG(_RGB), MMAG,    MRSE,    MRED,    MORN,    MYEL,    MCRT,    MGRN,    MSGN,    MCYN,    MAZR,    MBLU,    MVLT,    MFWHT,            RGB_TOG,  
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,  
        KC_NO,   RGB_HUD, RGB_HUI, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,  
        KC_NO,   RGB_SAI, RGB_SAD, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,            KC_NO,  
        KC_NO,            RGB_VAI, RGB_VAD, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   RGB_MOD, KC_NO,  
        KC_NO,   KC_NO,   KC_NO,                              KC_NO,                              KC_NO,   KC_NO,   KC_NO,   RGB_SPD, RGB_RMOD, RGB_SPI
    ),

};
// clang-format on

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
	// If the RGB layer is active, change colors.
    if(layer_state_is(_RGB)) {
		if (clockwise) {
          rgb_matrix_increase_hue();
        } else {
          rgb_matrix_decrease_hue();
        }	
	// Otherwise, adjust volume
	} else {
		if (clockwise) {
          tap_code(KC_VOLU);
        } else {
          tap_code(KC_VOLD);
        }
	}
    return true;
}
#endif // ENCODER_ENABLE

#include "features/caps_word.h"
bool fet_cw_on = true;
#include "features/autocorrection.h"
bool fet_ac_on = true;

// Mouse Jiggler
bool mouse_jiggle_mode = false;


bool process_record_user(uint16_t keycode, keyrecord_t* record) {

  // CapsWord
  if (fet_cw_on) {
    if (!process_caps_word(keycode, record)) { return false; }
  }

  // Autocorrection
  if (fet_ac_on) {
    if (!process_autocorrection(keycode, record)) { return false; }
  }
  // Your macros ...

  // RGB Macros
    switch (keycode) {
		
	case MFCW:
        if (record->event.pressed) {
            // when keycode is pressed
            if(fet_cw_on) {
				fet_cw_on = false;
			} else {
				fet_cw_on = true;
			}
        } else {
            // when keycode is released
        }
        break;

	case MFAC:
        if (record->event.pressed) {
            // when keycode is pressed
            if(fet_ac_on) {
				fet_ac_on = false;
			} else {
				fet_ac_on = true;
			}
        } else {
            // when keycode is released
        }
        break;
	
  // RGB Macros
    case MRED:
        if (record->event.pressed) {
            // when keycode is pressed
            rgb_matrix_sethsv(0, 255, 255);
        } else {
            // when keycode is released
        }
        break;

	case MORN:
        if (record->event.pressed) {
            // when keycode is pressed
            rgb_matrix_sethsv(21, 255, 255);
        } else {
            // when keycode is released
        }
        break;
	
	case MYEL:
        if (record->event.pressed) {
            // when keycode is pressed
            rgb_matrix_sethsv(43, 255, 255);
        } else {
            // when keycode is released
        }
        break;
	
	case MCRT:
        if (record->event.pressed) {
            // when keycode is pressed
            rgb_matrix_sethsv(64, 255, 255);
        } else {
            // when keycode is released
        }
        break;

	case MGRN:
        if (record->event.pressed) {
            // when keycode is pressed
            rgb_matrix_sethsv(85, 255, 255);
        } else {
            // when keycode is released
        }
        break;
	
	case MSGN:
        if (record->event.pressed) {
            // when keycode is pressed
            rgb_matrix_sethsv(106, 255, 255);
        } else {
            // when keycode is released
        }
        break;
	
	case MCYN:
        if (record->event.pressed) {
            // when keycode is pressed
            rgb_matrix_sethsv(127, 255, 255);
        } else {
            // when keycode is released
        }
        break;
	
	case MAZR:
        if (record->event.pressed) {
            // when keycode is pressed
            rgb_matrix_sethsv(148, 255, 255);
        } else {
            // when keycode is released
        }
        break;
	
	case MBLU:
        if (record->event.pressed) {
            // when keycode is pressed
            rgb_matrix_sethsv(169, 255, 255);
        } else {
            // when keycode is released
        }
        break;
	
	case MVLT:
        if (record->event.pressed) {
            // when keycode is pressed
            rgb_matrix_sethsv(180, 255, 255);
        } else {
            // when keycode is released
        }
        break;
	
	case MMAG:
        if (record->event.pressed) {
            // when keycode is pressed
            rgb_matrix_sethsv(201, 255, 255);
        } else {
            // when keycode is released
        }
        break;
	
	case MRSE:
        if (record->event.pressed) {
            // when keycode is pressed
            rgb_matrix_sethsv(222, 255, 255);
        } else {
            // when keycode is released
        }
        break;
	
	case MFWHT:
	    if (record->event.pressed) {
            // when keycode is pressed
            rgb_matrix_sethsv(255, 0, 255);
        } else {
            // when keycode is released
        }
        break;
		
	// Mouse Jiggler
    case TJIGGLE:
        if (record->event.pressed) {
            // when keycode is pressed
			if (mouse_jiggle_mode) {
				mouse_jiggle_mode = false;
			} else {
				mouse_jiggle_mode = true;
			}
        } else {
            // when keycode is released
        }
        break;
	}
    return true;	

}

LEADER_EXTERNS();
// Declare a boolean variable to keep track of whether any sequence
// will have been matched.
bool did_leader_succeed;

void matrix_scan_user(void) {
  // Mouse Jiggler
  if (mouse_jiggle_mode) {
    tap_code(KC_MS_UP);
    tap_code(KC_MS_DOWN);
    tap_code(KC_MS_LEFT);
    tap_code(KC_MS_RIGHT);
    tap_code(KC_MS_WH_UP);
    tap_code(KC_MS_WH_DOWN);
  }
  caps_word_task();
  LEADER_DICTIONARY() {
    // Initialize did_leader_succeed as well as leading to be false
    did_leader_succeed = leading = false;
	leader_start();

    // Replace the sequences below with your own sequences.
    SEQ_FOUR_KEYS(KC_G, KC_A, KC_M, KC_E) {
      // When I press KC_LEAD and then GAME, enter game mode
      layer_on(_GAME);
	  did_leader_succeed = true;
    }
    // Note: This is not an array, you don't need to put any commas
    // or semicolons between sequences.
    SEQ_FIVE_KEYS(KC_M, KC_O, KC_U, KC_S, KC_E) {
      // When I press KC_LEAD and then MOUSE, go to mouse layer
	  layer_on(_MOUSE);
	  did_leader_succeed = true;
    }
	SEQ_FIVE_KEYS(KC_C, KC_O, KC_L, KC_O, KC_R) {
      // When I press KC_LEAD and then COLOR
	  rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_LEFT_RIGHT);
	  rgb_matrix_sethsv_noeeprom(255, 255, 255);
	  did_leader_succeed = true;
    }
    SEQ_FIVE_KEYS(KC_W, KC_H, KC_I, KC_T, KC_E) {
      // When I press KC_LEAD and then WHITE
	  rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
	  rgb_matrix_sethsv(35, 40, 102);
	  did_leader_succeed = true;
    }
	
	SEQ_THREE_KEYS(KC_R, KC_G, KC_B) {
      // When I press KC_LEAD and then RGB
      layer_on(_RGB);
	  did_leader_succeed = true;
    }
	
	SEQ_FIVE_KEYS(KC_S, KC_P, KC_A, KC_C, KC_E) {
      // When I press KC_LEAD and then SPACE
      layer_invert(_SPACE);
	  did_leader_succeed = true;
    }
	
	// Call leader_end at the end of the function, instead of at
    // the start. This way, we're sure we have set did_leader_succeed.
	leader_end();
  }
  // Other tasks...
}

void leader_start(void) {
    // Add your code to run when pressing the leader key here
    // rgb_matrix_set_color(LED_LEAD, RGB_PURPLE2); // light up Leader when active? Didn't work
	layer_on(_LEADER);
}
void leader_end(void) {
    // Add your code to run when a leader key sequence ends here
    layer_off(_LEADER);
	if (did_leader_succeed) {
    // It Worked
    } else {
    // It didn't work
    }
}

bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
	case KC_MINS:  // Make Caps Word shift the '-' key to write '_'
      add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_UNDS:
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
}

#ifdef RGB_MATRIX_ENABLE
// Inidcator Lights
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    // CapsLock RGB
    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color(LED_CAPS, RGB_BLUE);
    }
 
    // Function Layer RGB
    switch (get_highest_layer(layer_state)) { // special handling per layer
    case _FN1: 
		rgb_matrix_set_color(LED_FN, RGB_PURPLE); // Light up FN Purple
		rgb_matrix_set_color(LED_LEAD, RGB_BLUE); // Leader Key
		rgb_matrix_set_color(LED_F1, RGB_CHARTREUSE); // F1-F11 Basic Media Controls
		rgb_matrix_set_color(LED_F2, RGB_CHARTREUSE);
		rgb_matrix_set_color(LED_F3, RGB_CHARTREUSE);
		rgb_matrix_set_color(LED_F4, RGB_CHARTREUSE);
		rgb_matrix_set_color(LED_F5, RGB_CHARTREUSE);
		rgb_matrix_set_color(LED_F6, RGB_CHARTREUSE);
		rgb_matrix_set_color(LED_F7, RGB_CHARTREUSE);
		rgb_matrix_set_color(LED_F8, RGB_CHARTREUSE);
		rgb_matrix_set_color(LED_F9, RGB_CHARTREUSE);
		rgb_matrix_set_color(LED_F10, RGB_CHARTREUSE);
		rgb_matrix_set_color(LED_F11, RGB_CHARTREUSE);
		rgb_matrix_set_color(LED_BSLS, RGB_RED); // Reset Key
		rgb_matrix_set_color(LED_BSPC, RGB_RED); // Clear EEPROM
		rgb_matrix_set_color(LED_DEL, RGB_GREEN); // Insert
		rgb_matrix_set_color(LED_GRV, RGB_YELLOW); // Start/Stop Macro Recording 1
		rgb_matrix_set_color(LED_1, RGB_GREEN); // Play Macro Recording 1
		// rgb_matrix_set_color(LED_2, RGB_GREEN); // Macro Recording 2
		if(layer_state_is(_SPACE)) {
		    rgb_matrix_set_color(LED_9, RGB_BLUE); // Space Cadet
            rgb_matrix_set_color(LED_0, RGB_BLUE); // Space Cadet
		} else {
			rgb_matrix_set_color(LED_9, RGB_ORANGE2); // Space Cadet
            rgb_matrix_set_color(LED_0, RGB_ORANGE2); // Space Cadet
		}
        if(keymap_config.nkro) {
		    rgb_matrix_set_color(LED_N, RGB_BLUE); // NKey Rollover
		} else {
			rgb_matrix_set_color(LED_N, RGB_ORANGE2);
		}
		// CapsWord
		if(fet_cw_on) {
			rgb_matrix_set_color(LED_CAPS, RGB_BLUE);
		} else {
			rgb_matrix_set_color(LED_CAPS, RGB_ORANGE2);
		}
		// Autocorrection
        if(fet_ac_on) {
			rgb_matrix_set_color(LED_C, RGB_BLUE);
		} else {
			rgb_matrix_set_color(LED_C, RGB_ORANGE2);
		}
        // Mouse Jiggler
        if(mouse_jiggle_mode) {
            rgb_matrix_set_color(LED_J, RGB_BLUE);
		} else {
			rgb_matrix_set_color(LED_J, RGB_ORANGE2);
		}
    }

    // Game Mode Layer RGB
    switch (get_highest_layer(layer_state)) { // special handling per layer
    case _GAME: 
        rgb_matrix_set_color(LED_LWIN, RGB_DKRED); //light up Winkey red when disabled
		rgb_matrix_set_color(LED_CAPS, RGB_DKRED); //light up Capslock red when disabled
		rgb_matrix_set_color(LED_ESC, RGB_PURPLE); //light up Esc Purple
        rgb_matrix_set_color(LED_W, RGB_GREEN); //light up gaming keys with WSAD higlighted
        rgb_matrix_set_color(LED_S, RGB_GREEN);
        rgb_matrix_set_color(LED_A, RGB_GREEN);
        rgb_matrix_set_color(LED_D, RGB_GREEN);
        rgb_matrix_set_color(LED_Q, RGB_WHITE);
        rgb_matrix_set_color(LED_E, RGB_ORANGE2);
        rgb_matrix_set_color(LED_R, RGB_WHITE);
        rgb_matrix_set_color(LED_TAB, RGB_WHITE);
        rgb_matrix_set_color(LED_F, RGB_WHITE);
        rgb_matrix_set_color(LED_Z, RGB_WHITE);
        rgb_matrix_set_color(LED_X, RGB_WHITE);
        rgb_matrix_set_color(LED_C, RGB_WHITE);
        rgb_matrix_set_color(LED_V, RGB_WHITE);
        rgb_matrix_set_color(LED_SPC, RGB_GREEN);
        rgb_matrix_set_color(LED_LCTL, RGB_WHITE);
        rgb_matrix_set_color(LED_LSFT, RGB_WHITE);
		rgb_matrix_set_color(LED_1, RGB_ORANGE2);
		rgb_matrix_set_color(LED_2, RGB_ORANGE2);
		rgb_matrix_set_color(LED_3, RGB_ORANGE2);
		rgb_matrix_set_color(LED_4, RGB_ORANGE2);
		rgb_matrix_set_color(LED_GRV, RGB_WHITE);
    }

    // Gamer Function Layer RGB
    switch (get_highest_layer(layer_state)) { // special handling per layer
    case _FN2: 
        rgb_matrix_set_color(LED_ESC, RGB_PURPLE); // Light up Esc Purple
	    rgb_matrix_set_color(LED_FN, RGB_PURPLE); // Light up FN Purple
		rgb_matrix_set_color(LED_F1, RGB_CHARTREUSE); // F1-F11 Basic Media Controls
		rgb_matrix_set_color(LED_F2, RGB_CHARTREUSE);
		rgb_matrix_set_color(LED_F3, RGB_CHARTREUSE);
		rgb_matrix_set_color(LED_F4, RGB_CHARTREUSE);
		rgb_matrix_set_color(LED_F5, RGB_CHARTREUSE);
		rgb_matrix_set_color(LED_F6, RGB_CHARTREUSE);
		rgb_matrix_set_color(LED_F7, RGB_CHARTREUSE);
		rgb_matrix_set_color(LED_F8, RGB_CHARTREUSE);
		rgb_matrix_set_color(LED_F9, RGB_CHARTREUSE);
		rgb_matrix_set_color(LED_F10, RGB_CHARTREUSE);
		rgb_matrix_set_color(LED_F11, RGB_CHARTREUSE);
		rgb_matrix_set_color(LED_DEL, RGB_GREEN); // Insert
        if(keymap_config.nkro) {
		    rgb_matrix_set_color(LED_N, RGB_BLUE); // NKey Rollover
		} else {
			rgb_matrix_set_color(LED_N, RGB_ORANGE2);
		}
    }

    // Space Cadet Shift RGB
    switch (get_highest_layer(layer_state)) { // special handling per layer
    case _SPACE:
        rgb_matrix_set_color(LED_LSFT, RGB_BLUE);
        rgb_matrix_set_color(LED_RSFT, RGB_BLUE);
	//	rgb_matrix_set_color(LED_ESC, RGB_PURPLE); //light up Esc Purple
    }
	
	// Leader key active RGB
    switch (get_highest_layer(layer_state)) { // special handling per layer
    case _LEADER:
        rgb_matrix_set_color(LED_LEAD, RGB_BLUE);
    }
	
	// Mouse Mode RGB
    switch (get_highest_layer(layer_state)) { // special handling per layer
    case _MOUSE:
        rgb_matrix_set_color(LED_LEFT, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_RIGHT, RGB_CHARTREUSE);
		rgb_matrix_set_color(LED_UP, RGB_CHARTREUSE);
	    rgb_matrix_set_color(LED_DOWN, RGB_CHARTREUSE);
		rgb_matrix_set_color(LED_LEAD, RGB_GREEN);
		rgb_matrix_set_color(LED_END, RGB_SPRINGGREEN);
		rgb_matrix_set_color(LED_ESC, RGB_PURPLE); //light up Esc Purple
		rgb_matrix_set_color(LED_PGDN, RGB_DKRED);
		rgb_matrix_set_color(LED_PGUP, RGB_DKRED); 
		rgb_matrix_set_color(LED_HOME, RGB_DKRED);
    }
	
	// RGB Control Board
	switch (get_highest_layer(layer_state)) { // special handling per layer
	case _RGB:
        rgb_matrix_set_color(LED_F1, RGB_MAGENTA);
        rgb_matrix_set_color(LED_F2, RGB_PINK);
		rgb_matrix_set_color(LED_F3, RGB_RED);
	    rgb_matrix_set_color(LED_F4, RGB_ORANGE);
		rgb_matrix_set_color(LED_F5, RGB_YELLOW);
		rgb_matrix_set_color(LED_F6, RGB_CHARTREUSE);
		rgb_matrix_set_color(LED_F7, RGB_GREEN);
		rgb_matrix_set_color(LED_F8, RGB_SPRINGGREEN);
		rgb_matrix_set_color(LED_F9, RGB_CYAN);
		rgb_matrix_set_color(LED_F10, RGB_AZURE);
		rgb_matrix_set_color(LED_F11, RGB_BLUE);
		rgb_matrix_set_color(LED_F12, RGB_PURPLE);
		rgb_matrix_set_color(LED_ESC, RGB_PURPLE);
		rgb_matrix_set_color(LED_GRV, RGB_WHITE);
		rgb_matrix_set_color(LED_1, RGB_WHITE);
		rgb_matrix_set_color(LED_2, RGB_WHITE);
		rgb_matrix_set_color(LED_3, RGB_WHITE);
		rgb_matrix_set_color(LED_4, RGB_WHITE);
		rgb_matrix_set_color(LED_R, RGB_WHITE);
		rgb_matrix_set_color(LED_F, RGB_WHITE);
		rgb_matrix_set_color(LED_V, RGB_WHITE);
		rgb_matrix_set_color(LED_E, RGB_BLACK);
		rgb_matrix_set_color(LED_D, RGB_BLACK);
		rgb_matrix_set_color(LED_C, RGB_BLACK);
		rgb_matrix_set_color(LED_Q, RGB_ORANGE);
		rgb_matrix_set_color(LED_W, RGB_PURPLE);
		rgb_matrix_set_color(LED_A, RGB_BLUE);
		rgb_matrix_set_color(LED_S, RGB_AZURE);
		rgb_matrix_set_color(LED_Z, RGB_WHITE);
		rgb_matrix_set_color(LED_X, 100, 100, 100);
		rgb_matrix_set_color(LED_TAB, RGB_BLACK);
		rgb_matrix_set_color(LED_CAPS, RGB_BLACK);
		rgb_matrix_set_color(LED_LSFT, RGB_BLACK);
		rgb_matrix_set_color(LED_LCTL, RGB_BLACK);
		rgb_matrix_set_color(LED_LWIN, RGB_BLACK);
		rgb_matrix_set_color(LED_LALT, RGB_BLACK);
		rgb_matrix_set_color(LED_UP, RGB_BLUE);
		rgb_matrix_set_color(LED_DOWN, RGB_BLUE);
		rgb_matrix_set_color(LED_LEFT, RGB_RED);
		rgb_matrix_set_color(LED_RIGHT, RGB_GREEN);
		rgb_matrix_set_color(LED_DEL, RGB_WHITE);
		// rgb_matrix_set_color(LED_HOME, RGB_WHITE);
		// rgb_matrix_set_color(LED_PGUP, RGB_WHITE);
		// rgb_matrix_set_color(LED_PGDN, RGB_WHITE);
		// rgb_matrix_set_color(LED_END, RGB_WHITE);
    }
}
#endif