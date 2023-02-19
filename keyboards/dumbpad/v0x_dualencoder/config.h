/*
Copyright 2020 imchipwood

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
#pragma once


/* Column/Row IO definitions - dualencoder version is true 4x4 */
#define MATRIX_ROW_PINS { F4, F5, F6, F7 }
#define MATRIX_COL_PINS { D7, E6, B4, B5 }

/* Dual rotary encoders */
#define ENCODERS_PAD_A { C6, D0 }
#define ENCODERS_PAD_B { D4, D1 }

/* Onboard LEDs */
#define LED_00 B3
#define LED_01 B1