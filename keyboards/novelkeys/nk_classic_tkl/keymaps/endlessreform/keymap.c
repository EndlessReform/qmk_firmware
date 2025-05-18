/* Copyright 2024 Yiancar-Designs
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
#define _MAC 1
#define _FN 2
#define _MD 4
#define _GIT 5

enum macro_keycodes {
    /* Base layers*/
    RETRO_RGB = QK_USER_0,
    MAC_TOGGLE,

    /* Markdown */
    HED1, HED2, HED3,
    TAGGED, PYTHON,
    CDFC, ALSO, DIVIDER,
    TASK, BASH,

    /* Git */
    GIT_KEY, DDASH, GIT_RESET, // Git layer: R1
    TAG, REMOTE, UPSTREAM, ORIGIN, REVERT, // Git layer: R2
    PUSH, ADD, STATUS, HARD, COMMIT, // Git layer: R3
    REBASE, GIT_MAIN, CHECKOUT, // Git layer: R4
    BRANCH, PULL, MERGE, STASH, FETCH, CLONE, // Git layer: R5

    LIT_END // Literal end
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_tkl_ansi_tsangan( /* Base */
    KC_ESC,  KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           C(S(G(KC_4))), C(G(KC_Q)), KC_PAUS,
    KC_GRV,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INS,  KC_HOME, KC_PGUP,
    KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  KC_END,  KC_PGDN,
    LCTL_T(KC_ESC), KC_A,    KC_S,   KC_D,   LT(_GIT, KC_F), KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    LT(_MD, KC_SCLN), KC_QUOT,          KC_ENT,
    KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,                   KC_UP,
    LT(_FN, KC_CAPS), KC_LGUI, KC_LALT,                KC_SPC,                                            KC_RALT, S(KC_LGUI),   S(KC_LCTL), KC_LEFT, KC_DOWN, KC_RGHT),

[_MAC] = LAYOUT_tkl_ansi_tsangan( /* scratch, controlled by VIA */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,                   _______,
    _______, KC_LALT, KC_LGUI,                   _______,                                            C(KC_LALT), _______, _______, _______, _______, _______),

[_FN] = LAYOUT_tkl_ansi_tsangan( /* FN */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_VOLD, KC_MSTP, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, 
    _______, RM_TOGG, RM_NEXT, RM_HUED, RM_HUEU, RM_SATD, RM_SATU, MAC_TOGGLE, _______, RM_SPDD, RM_SPDU,          _______,                   _______,
    _______, _______, _______,                   RETRO_RGB,                                            _______, _______, QK_BOOT, _______, _______, _______),


[3] = LAYOUT_tkl_ansi_tsangan( /* scratch, controlled by VIA */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,                   _______,
    _______, _______, _______,                   _______,                                            _______, _______, _______, _______, _______, _______),

[_MD] = LAYOUT_tkl_ansi_tsangan( /* MD, controlled by VIA */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
    _______, HED1,    HED2,    HED3,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, TAGGED,  _______, _______, _______, _______, PYTHON,  _______, _______, _______, _______, _______, _______,
    CDFC,    ALSO,    _______, DIVIDER, _______, _______, _______, _______, _______, _______, _______,  _______,_______,
    _______, _______, _______, TASK,    _______, BASH,    _______, _______, _______, _______, _______,          _______,                   _______,
    _______, _______, _______,                   _______,                                            _______, _______, _______, _______, _______, _______),

[_GIT] = LAYOUT_tkl_ansi_tsangan( /* GIT, start of non-via layers */
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,            _______, _______, _______,
    GIT_KEY, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, DDASH,   _______, GIT_RESET, _______, _______, _______,
    TAG,     _______, _______, _______, REMOTE,  _______, _______, UPSTREAM, _______, ORIGIN, _______, _______, _______, REVERT,   _______, _______, _______,
    PUSH,    ADD,     STATUS,  _______, _______, _______, HARD, _______,  _______, _______, _______, _______,    COMMIT,
    REBASE,  _______, _______, _______, _______, _______, _______, GIT_MAIN,  _______, _______, _______,          CHECKOUT,           _______,
    BRANCH,  PULL,    MERGE,                   _______,                                               STASH, FETCH, CLONE,  _______, _______, _______),

};

static const char PROGMEM *const lit_table[] = {
    /* markdown */
    PSTR("# "), PSTR("## "), PSTR("### "),
    PSTR("tagged: #"), PSTR("```python" SS_TAP(X_ENTER)),
    PSTR("```"), PSTR("See also: "), PSTR("---" SS_TAP(X_ENTER)),
    PSTR("- [ ] "), PSTR("```bash" SS_TAP(X_ENTER)),

    /* git */
    PSTR("git "), PSTR("--"), PSTR("reset "),
    PSTR("tag "), PSTR("remote "), PSTR("upstream "), PSTR("origin "), PSTR("revert "),
    PSTR("push "), PSTR("add "), PSTR("status "), PSTR("hard "), PSTR("commit "),
    PSTR("rebase "), PSTR("main "), PSTR("checkout "),
    PSTR("branch "), PSTR("pull "), PSTR("merge "), PSTR("stash "), PSTR("fetch "), PSTR("clone "), // r5
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = 50; i <= 55; i++) {
            rgb_matrix_set_color(i, 255, 86, 0);
        }
    } else if ((rgb_matrix_get_mode() == RGB_MATRIX_TYPING_HEATMAP) || (rgb_matrix_get_mode() == RGB_MATRIX_DIGITAL_RAIN)) {
        for (uint8_t i = 50; i <= 55; i++) {
            rgb_matrix_set_color(i, 0, 0, 0);
        }
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == MAC_TOGGLE && record->event.pressed) {
        // swap between MAC and BASE layers persistently
        if (get_highest_layer(default_layer_state) == _MAC) {
            set_single_persistent_default_layer(_BASE);
        } else {
            set_single_persistent_default_layer(_MAC);
        }
        return false;
    } else if (keycode >= HED1 && keycode < LIT_END && record->event.pressed) {
        send_string_P(lit_table[keycode - HED1]);
        return false;
    } else if (keycode == RETRO_RGB) {
        if (record->event.pressed) {
            switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_INDICATOR);
                }
                break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                }
                break;
            }
        }
        return false; // Skip all further processing of this key
    } else {
        return true; // Process all other keycodes normally
    }
}
