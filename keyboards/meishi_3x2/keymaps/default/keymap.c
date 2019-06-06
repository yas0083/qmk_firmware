/* Copyright 2017 Biacco42
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
#include QMK_KEYBOARD_H

#define _BASE 0
#define _LOWER 1

enum custom_keycodes {
    BASE = SAFE_RANGE,
    LOWER
};

const uint16_t PROGMEM
keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        LOWER, \
        LCTL(KC_Z), \
        LCTL(KC_C), \
        LCTL(KC_V)
    ),
    [_LOWER] = LAYOUT(
        XXXXXXX, \
        LCTL(KC_Y),
        LCTL(KC_X),
        LCTL(KC_A)
    )
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}


const uint16_t PROGMEM
fn_actions[] = {

};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BASE:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL << _BASE);
            }
            return false;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
            }
            return false;
    }
    return true;
}

void led_set_user(uint8_t usb_led) {

}
