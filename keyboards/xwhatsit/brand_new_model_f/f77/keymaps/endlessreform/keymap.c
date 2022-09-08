/* Copyright 2020 Purdea Andrei
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _NAV,
    _MD
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    // Markdown layer
    TAGGED = SAFE_RANGE,
    H1, H2, H3, MATH,
    CDFC, ALSO, DIVIDER, MARROW,
    TASK, MERMAID
};

enum unicode_names {
    BANG, IRONY, EN, EM,
    MARU, BATSU, DEGREE, CROSS,
    MAC_OPT, MAC_CMD, SFT, CHICAGO
};

const uint32_t PROGMEM unicode_map[] = {
    [BANG]    = 0x203D,  // ‽
    [IRONY]   = 0x2E2E,  // ⸮    
    [EM]      = 0x2014,  // —    
    [EN]      = 0x2013,  // –    
    [BATSU]   = 0x2716,  // ✖    
    [CROSS]   = 0x2626,  // ☦
    [MARU]    = 0x3007,  // 〇    
    [DEGREE]  = 0x00B0,  // °  
    [MAC_CMD] = 0x2318,  // ⌘
    [MAC_OPT] = 0x2325,  // ⌥
    [SFT]     = 0x21E7,  // ⇧
    [CHICAGO] = 0x2736,  // ✶
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT_ansi_hhkb_split_shift_split_backspace(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,      XP(0,1), XP(4,5), XP(8,9),
        KC_TAB,    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,          XP(2,3), XP(6,7), XP(10,11),
        LCTL_T(KC_ESC),KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, LT(_MD, KC_SCLN), KC_QUOT, KC_ENT,    DM_REC1, DM_RSTP, DM_REC2,
        KC_LSFT,         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, HPT_TOG,     DM_PLY1, KC_UP,   DM_PLY2,
        LT(_NAV, KC_CAPS), KC_LGUI, KC_LALT,                      KC_SPC,  KC_RALT, LSFT(KC_LGUI), LSFT(KC_RCTRL), KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [_NAV] = LAYOUT_ansi_hhkb_split_shift_split_backspace(
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,   KC_F9, KC_F10,    KC_F11, KC_F12, KC_INS, KC_DEL,              KC_HOME, KC_UP,   KC_PGUP,
        KC_NO,      KC_VOLD, KC_MSTP, KC_VOLU, KC_NO, KC_NO, KC_END, KC_PGDN, KC_PGUP, KC_HOME, KC_END, KC_UP, KC_NO, KC_DEL,            KC_LEFT, KC_NO,   KC_RIGHT,
        _______,     KC_MPRV, KC_MPLY, KC_MNXT, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_LEFT, LALT(KC_LEFT), LALT(KC_RIGHT), KC_END,  KC_DOWN, KC_PGDN,
        _______,         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, AG_TOGG, KC_NO, KC_NO, KC_NO, _______, _______,                KC_INS,  KC_NO,   KC_DEL,
        _______, KC_NO, _______,                             _______,                           _______, KC_NO, RESET,                  KC_NO,   KC_NO,   KC_NO
    ),
    [_MD] = LAYOUT_ansi_hhkb_split_shift_split_backspace(
        _______, H1, H2, H3, MATH,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______, _______,
        _______,     _______, _______, _______, _______, TAGGED, _______, UC_MOD, _______, _______, _______, _______, _______, _______,     _______, _______, _______,
        CDFC,            _______, ALSO, DIVIDER, _______, KC_LPRN, KC_RPRN, _______, MARROW, _______, _______, _______, _______,            _______, _______, _______,
        _______,             _______, _______, TASK, _______, _______, _______, MERMAID, _______, _______, _______, _______, _______,       _______, _______, _______,
        _______, _______, _______,                             _______,                                       _______, _______, _______,    _______, _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case H1:
            if (record->event.pressed) {
                SEND_STRING("# ");
            }
            break;
        case H2:
            if (record->event.pressed) {
                SEND_STRING("## ");
            }
            break;
        case H3:
            if (record->event.pressed) {
                SEND_STRING("### ");
            }
            break;
        case MATH:
            if (record->event.pressed) {
                SEND_STRING("$$" SS_TAP(X_LEFT));
            }
            break;
        case TAGGED:
            if (record->event.pressed) {
                SEND_STRING("tagged: ");
            }
            break;
        case CDFC:
            if (record->event.pressed) {
                SEND_STRING("```");
            }
            break;
        case ALSO:
            if (record->event.pressed) {
                SEND_STRING("See also:" SS_TAP(X_ENTER));
            }
            break;
        case DIVIDER:
            if (record->event.pressed) {
                SEND_STRING("---" SS_TAP(X_ENTER));
            }
            break;
        case MARROW:
            if (record->event.pressed) {
                SEND_STRING("-->");
            }
            break;
        case TASK:
            if (record->event.pressed) {
                // Press
                SEND_STRING("- [ ] ");
            } else {
                // Release
            }
            break;
        case MERMAID:
            if (record->event.pressed) {
                // Press
                SEND_STRING("```mermaid" SS_TAP(X_ENTER));
            } else {
                // Release
            }
            break;
    }
    return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
