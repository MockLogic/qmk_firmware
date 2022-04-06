/* Copyright 2021 Jonavin Eng @Jonavin
   Copyright 2022 gourdo1 <jcblake@outlook.com>
   Messed with by MockLogic 2022
   
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
*/

#ifdef RGB_MATRIX_ENABLE
// Custom GMMK Pro-specific RGB color customizations (defaults found in quantum/color.h)
#define RGB_GODSPEED 0x00, 0xE4, 0xFF     // color for matching keycaps
#define RGB_NAUTILUS 0x00, 0xA4, 0xA9     // Nautilus Font colors
#define RGB_OFFBLUE 0x00, 0x80, 0xFF      // new color: blue with a hint of green
#define RGB_DKRED 0x28, 0x00, 0x00        // new color: dark red
#define RGB_ORANGE2 0xFF, 0x28, 0x00      // fix: reduced green from 80 to 28
#define RGB_PURPLE2 0x80, 0x00, 0xFF      // fix: increased red from 7A to 80
#define RGB_SPRINGGREEN2 0x00, 0xFF, 0x10 // fix: blue was 80, now 10
#define RGB_YELLOW2 0xFF, 0xB0, 0x00      // fix: green was FF, now B0
#define RGB_OFF RGB_BLACK

enum led_location_map {
	LED_TEST01,
	LED_TEST02,
	LED_TEST03,
	LED_TEST04,
	LED_TEST05,
	LED_TEST06,
	LED_TEST07,
	LED_TEST08,
	LED_TEST09,
	LED_TEST10,
	LED_TEST11,
	LED_TEST12,
	LED_TEST13,
	LED_TEST14,
	LED_TEST15,
	LED_TEST16,
	LED_TEST17,
	LED_TEST18,
	LED_TEST19,
	LED_TEST20,
	LED_TEST21,
	LED_TEST22,
	LED_TEST23,
	LED_TEST24,
	LED_TEST25,
	LED_TEST26,
	LED_TEST27,
	LED_TEST28,
	LED_TEST29,
	LED_TEST30,
	LED_TEST31,
	LED_TEST32,
	LED_TEST33,
	LED_TEST34,
	LED_TEST35,
	LED_TEST36,
	LED_TEST37,
	LED_TEST38,
	LED_TEST39,
	LED_TEST40,
	LED_TEST41,
	LED_TEST42,
	LED_TEST43,
	LED_TEST44,
	LED_TEST45,
	LED_TEST46,
	LED_TEST47,
	LED_TEST48,
	LED_TEST49,
	LED_TEST50,
	LED_TEST51,
	LED_TEST52,
	LED_TEST53,
	LED_TEST54,
	LED_TEST55,
	LED_TEST56,
	LED_TEST57,
	LED_TEST58,
	LED_TEST59,
	LED_TEST60,
	LED_TEST61,
	LED_TEST62,
	LED_TEST63,
	LED_TEST64,
	LED_TEST65,
	LED_TEST66,
	LED_TEST67,
	LED_TEST68,
	LED_TEST69,
	LED_TEST70,
	LED_TEST71,
	LED_TEST72,
	LED_TEST73,
	LED_TEST74,
	LED_TEST75,
	LED_TEST76,
	LED_TEST77,
	LED_TEST78,
	LED_TEST79,
	LED_TEST80,
	LED_TEST81,
	LED_TEST82,
	LED_TEST83,
	LED_TEST84,
	LED_TEST85,
	LED_TEST86,
	LED_TEST87,
	LED_TEST89,
	LED_TEST90,
	LED_TEST91,
	LED_TEST92,
	LED_TEST93,
	LED_TEST94,
	LED_TEST95,
	LED_TEST96,
	LED_TEST97,
	LED_TEST98,
	LED_TEST99,
};

/*
// RGB LED locations
enum led_location_map {
    LED_ESC, // 0, ESC
    LED_GRV, // 1, ~
    LED_TAB, // 2, Tab
    LED_CAPS, // 3, Caps
    LED_LSFT, // 4, Sh_L
    LED_LCTL, // 5, Ct_L
    LED_F1, // 6, F1
    LED_1, // 7, 1
    LED_Q, // 8, Q
    LED_A, // 9, A
    LED_Z, // 10, Z
    LED_LWIN, // 11, Win_L
    LED_F2, // 12, F2
    LED_2, // 13, 2
    LED_W, // 14, W
    LED_S, // 15, S
    LED_X, // 16, X
    LED_LALT, // 17, Alt_L
    LED_F3, // 18, F3
    LED_3, // 19, 3
    LED_E, // 20, E
    LED_D, // 21, D
    LED_C, // 22, C
    LED_F4, // 23, F4
    LED_4, // 24, 4
    LED_R, // 25, R
    LED_F, // 26, F
    LED_V, // 27, V
    LED_F5, // 28, F5
    LED_5, // 29, 5
    LED_T, // 30, T
    LED_G, // 31, G
    LED_B, // 32, B
    LED_SPC, // 33, SPACE
    LED_F6, // 34, F6
    LED_6, // 35, 6
    LED_Y, // 36, Y
    LED_H, // 37, H
    LED_N, // 38, N
    LED_F7, // 39, F7
    LED_7, // 40, 7
    LED_U, // 41, U
    LED_J, // 42, J
    LED_M, // 43, M
    LED_F8, // 44, F8
    LED_8, // 45, 8
    LED_I, // 46, I
    LED_K, // 47, K
    LED_COMM, // 48, ,
    LED_RALT, // 49, Alt_R
    LED_F9, // 50, F9
    LED_9, // 51, 9
    LED_O, // 52, O
    LED_L, // 53, L
    LED_DOT, // 54, .
    LED_FN, // 55, FN
    LED_F10, // 56, F10
    LED_0, // 57, 0
    LED_P, // 58, P
    LED_SCLN, // 59, ;
    LED_SLSH, // 60, ?
    LED_F11, // 61, F11
    LED_MINS, // 62, -
    LED_LBRC, // 63, [
    LED_QUOT, // 64, "
    LED_LEAD, // 65, Leader Key
    LED_F12, // 66, F12
    LED_DEL, // 69, DEL
    LED_HOME, // 72, Home
    LED_PGUP, // 75, PgUp
    LED_EQL, // 78, =
    LED_RIGHT, // 79, Right
    LED_BSPC, // 85, BSpc
    LED_PGDN, // 86, PgDn
    LED_RBRC, // 89, ]
    LED_RSFT, // 90, Sh_R
    LED_BSLS, // 93, \
    LED_UP, // 94, Up
    LED_LEFT, // 95, Left
    LED_ENT, // 96, Enter
    LED_DOWN // 97, Down
};

const uint8_t LED_LIST_WASD[] = {
    LED_W,
    LED_A,
    LED_S,
    LED_D
};

const uint8_t LED_LIST_ARROWS[] = {
    LED_LEFT,
    LED_RIGHT,
    LED_UP,
    LED_DOWN
};

const uint8_t LED_LIST_FUNCROW[] = {
    LED_ESC,
    LED_F1,
    LED_F2,
    LED_F3,
    LED_F4,
    LED_F5,
    LED_F6,
    LED_F7,
    LED_F8,
    LED_F9,
    LED_F10,
    LED_F11,
    LED_F12,
    LED_DEL
};

const uint8_t LED_LIST_NUMROW[] = {
    LED_GRV,
    LED_1,
    LED_2,
    LED_3,
    LED_4,
    LED_5,
    LED_6,
    LED_7,
    LED_8,
    LED_9,
    LED_0,
    LED_MINS,
    LED_EQL,
    LED_BSPC
};

const uint8_t LED_LIST_LETTERS[] = {
    LED_1,
    LED_2,
    LED_3,
    LED_4,
    LED_5,
    LED_6,
    LED_7,
    LED_8,
    LED_9,
    LED_0,
    LED_Q,
    LED_W,
    LED_E,
    LED_R,
    LED_T,
    LED_Y,
    LED_U,
    LED_I,
    LED_O,
    LED_P,
    LED_A,
    LED_S,
    LED_D,
    LED_F,
    LED_G,
    LED_H,
    LED_J,
    LED_K,
    LED_L,
    LED_Z,
    LED_X,
    LED_C,
    LED_V,
    LED_B,
    LED_N,
    LED_M
};

const uint8_t LED_LIST_NUMPAD[] = {
    LED_1,
    LED_2,
    LED_3,
    LED_4,
    LED_5,
    LED_6,
    LED_7,
    LED_8,
    LED_9,
    LED_0,
    LED_MINS,
    LED_EQL,
    LED_U,
    LED_I,
    LED_O,
    LED_P,
    LED_J,
    LED_K,
    LED_L,
    LED_SCLN,
    LED_ENT,
    LED_M,
    LED_COMM,
    LED_DOT,
    LED_SLSH,
    LED_END,
    LED_RIGHT
};

const uint8_t LED_SIDE_LEFT[] = {
    LED_L1,
    LED_L2,
    LED_L3,
    LED_L4,
    LED_L5,
    LED_L6,
    LED_L7,
    LED_L8
};

const uint8_t LED_SIDE_RIGHT[] = {
    LED_R1,
    LED_R2,
    LED_R3,
    LED_R4,
    LED_R5,
    LED_R6,
    LED_R7,
    LED_R8
};
*/

#endif