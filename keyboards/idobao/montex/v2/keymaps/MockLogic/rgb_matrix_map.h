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
#define RGB_GODSPEED 0x00, 0xE4, 0xFF     // color for matching keycaps
#define RGB_NAUTILUS 0x00, 0xA4, 0xA9     // Nautilus Font colors
#define RGB_OFFBLUE 0x00, 0x80, 0xFF      // new color: blue with a hint of green
#define RGB_DKRED 0x28, 0x00, 0x00        // new color: dark red
#define RGB_ORANGE2 0xFF, 0x28, 0x00      // fix: reduced green from 80 to 28
#define RGB_PURPLE2 0x80, 0x00, 0xFF      // fix: increased red from 7A to 80
#define RGB_SPRINGGREEN2 0x00, 0xFF, 0x10 // fix: blue was 80, now 10
#define RGB_YELLOW2 0xFF, 0xB0, 0x00      // fix: green was FF, now B0
#define RGB_OFF RGB_BLACK

// RGB LED locations
enum led_location_map {
	LED_B1, // Back Light
	LED_B2, // Back Light
	LED_B3, // Back Light
	LED_B4, // Back Light
	LED_INS, // Insert
	LED_PRS, // Print Screen
	LED_ESC, // Escape
	LED_FN, // Function
	LED_0, // 0
	LED_DOT, // .
	LED_ENT, // Enter
	LED_3, // 3
	LED_2, // 2
	LED_1, // 1
	LED_END, // End
	LED_PD, // Page Down
	LED_4, // 4
	LED_5, // 5
	LED_6, // 6
	LED_ADD, // Add
	LED_9, // 9
	LED_8, // 8
	LED_7, // 7
	LED_PU, // Page Up
	LED_HM, // Home
	LED_NL, // Number Lock
	LED_DV, // Divide
	LED_MPY, // Multiply
	LED_SUB, // Subtract
	LED_PAS, // Pause
	LED_SL // Scroll Lock
};
#endif