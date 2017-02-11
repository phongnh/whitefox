/*
Copyright 2017 Phong Nguyen <nhphong1406@gmail.com>

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
#include "keymap_common.h"
#include "led_controller.h"

#define BASE_LAYER  0
#define MEDIA_LAYER 1
#define MOUSE_LAYER 2

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,------------------------------------------------------------------------------.
     * |Esc |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |BkSpace |  ` |
     * |------------------------------------------------------------------------------|
     * |Tab   |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |   \  | Del|
     * |------------------------------------------------------------------------------|
     * |CLK/MOU|  A |  S |  D |  F |  G |  H |  J |  K |  L |  ; |  ' |     Enter|Home|
     * |------------------------------------------------------------------------------|
     * |Shift    |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / |  Shift | Up |End |
     * |------------------------------------------------------------------------------|
     * |Ctrl | Gui | Alt |             Space            |Alt |Menu|FN1 |Left|Down|Rght|
     * `------------------------------------------------------------------------------'
     */
    [BASE_LAYER] = KEYMAP( \
        ESC,  1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    MINS, EQL,  BSPC, BSPC, GRV,  \
        TAB,  Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    LBRC, RBRC, BSLS,       DEL,  \
        FN2,  A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN, QUOT, NUHS, ENT,        HOME, \
        LSFT, NUBS, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH, RSFT, UP,         END,  \
        LCTL, LGUI, LALT,                 SPC,                FN3,  FN4,  FN1,  LEFT, DOWN,       RGHT  \
    ),
    /* Layer 1: Media Layer
     * ,------------------------------------------------------------------------------.
     * |SLEP| F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 |F10 |F11 |F12 |        |WAKE|
     * |------------------------------------------------------------------------------|
     * |      |EJCT|MSEL|MAIL|    |    |    |    |SLCK|PAUS|PSCR|F14 |F15 |      | Ins|
     * |------------------------------------------------------------------------------|
     * |       |PREV|PLAY|NEXT|MYCM|    |    |    |    |    |    |    |          |PgUp|
     * |------------------------------------------------------------------------------|
     * |         |RWD |FWD |CALC|    |BTLD|    |MUTE|VOLD|VOLU|LEDS|        |    |PgDn|
     * |------------------------------------------------------------------------------|
     * |     |     |     |                              |    |    |    |    |    |    |
     * `------------------------------------------------------------------------------'
     */
    [MEDIA_LAYER] = KEYMAP( \
        SLEP, F1,   F2,   F3,   F4,   F5,   F6,         F7,   F8,   F9,   F10,  F11,  F12,  TRNS, TRNS, WAKE, \
        TRNS, EJCT, MSEL, MAIL, TRNS, TRNS, TRNS,       TRNS, SLCK, PAUS, PSCR, F14,  F15,  TRNS,       INS,  \
        TRNS, MPRV, MPLY, MNXT, MYCM, TRNS, TRNS,       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       PGUP, \
        TRNS, TRNS, MRWD, MFFD, CALC, TRNS, BOOTLOADER, TRNS, MUTE, VOLD, VOLU, FN5,  TRNS, TRNS,       PGDN, \
        TRNS, TRNS, TRNS,                   TRNS,                   TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS  \
    ),
    /* Layer 2: Mouse Layer
     * ,------------------------------------------------------------------------------.
     * |    |    |    |    |    |    |    |    |    |    |    |    |    |        |    |
     * |------------------------------------------------------------------------------|
     * |      |Mclk| MU |Rclk|    |    |    |Rclk| WU |Mclk|    |    |    |      |    |
     * |------------------------------------------------------------------------------|
     * |       | ML | MD | MR |Lclk|    |Lclk| WL | WD | WR |    |    |  RClick  |    |
     * |------------------------------------------------------------------------------|
     * |         |    |    |    |    |    |    |    |    |    |    |        |    |    |
     * |------------------------------------------------------------------------------|
     * |     |     |     |            LClick            |    |    |    |    |    |    |
     * `------------------------------------------------------------------------------'
     */
    [MOUSE_LAYER] = KEYMAP( \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, BTN3, MS_U, BTN2, TRNS, TRNS, TRNS, BTN2, WH_U, BTN3, TRNS, TRNS, TRNS, TRNS,       TRNS, \
        TRNS, MS_L, MS_D, MS_R, BTN1, TRNS, BTN1, WH_L, WH_D, WH_R, TRNS, TRNS, TRNS, BTN2,       TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS, \
        TRNS, TRNS, TRNS,                BTN1,                TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS  \
    ),
};

/* Give numbers some descriptive names */
#define ACTION_TOGGLE_LEDS 1

const action_t fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(MEDIA_LAYER),
    [2] = ACTION_LAYER_TAP_KEY(MOUSE_LAYER, KC_CAPSLOCK),
    [3] = ACTION_MODS_KEY(MOD_RALT, KC_APP),
    [4] = ACTION_MODS_KEY(MOD_RCTL, KC_MENU),
    [5] = ACTION_FUNCTION(ACTION_TOGGLE_LEDS),
};

/* custom action function */
void action_function(keyrecord_t* record, uint8_t id, uint8_t opt)
{
    (void)opt;
    switch (id) {
    case ACTION_TOGGLE_LEDS:
        if (record->event.pressed) {
            // signal the LED controller thread
            chMBPost(&led_mailbox, LED_MSG_ALL_TOGGLE, TIME_IMMEDIATE);
        }
        break;
    }
}

bool fn_led_status = 0;

void hook_layer_change(uint32_t layer_state) {
    uint8_t layer = biton32(layer_state);
    switch (layer) {
        case BASE_LAYER:
            if (fn_led_status) {
                chMBPost(&led_mailbox, LED_MSG_FN_OFF, TIME_IMMEDIATE);
                fn_led_status = 0;
            }
            break;
        case MEDIA_LAYER:
            if (!fn_led_status) {
                chMBPost(&led_mailbox, LED_MSG_FN_ON, TIME_IMMEDIATE);
                fn_led_status = 1;
            }
            break;
        case MOUSE_LAYER:
            if (fn_led_status) {
                chMBPost(&led_mailbox, LED_MSG_FN_OFF, TIME_IMMEDIATE);
                fn_led_status = 0;
            }
            break;
        default:
            // none
            break;
    }
}
