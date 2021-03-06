/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

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

#ifndef CONFIG_H
#define CONFIG_H


/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0F0F
#define DEVICE_VER      0x0001
/* in python2: list(u"whatever".encode('utf-16-le')) */
/*   at most 32 characters or the ugly hack in usb_main.c borks */
#define MANUFACTURER "TMK"
#define USBSTR_MANUFACTURER    'T', '\x00', 'M', '\x00', 'K', '\x00', ' ', '\x00'
#define PRODUCT "WhiteFox/TMK"
#define USBSTR_PRODUCT         'W', '\x00', 'h', '\x00', 'i', '\x00', 't', '\x00', 'e', '\x00', 'F', '\x00', 'o', '\x00', 'x', '\x00', ' ', '\x00'

/* key matrix size */
#define MATRIX_ROWS 9
#define MATRIX_COLS 8

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    6

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

// Copy from my ErgoDox settings
#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    5
#define MOUSEKEY_MAX_SPEED      4
#define MOUSEKEY_WHEEL_DELAY    0

#define TAPPING_TOGGLE 1

// Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap
// #def LOCKING_SUPPORT_ENABLE

// Locking resynchronize hack
// #def LOCKING_RESYNC_ENABLE

#endif
