/* Copyright 2026
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

enum layers {
    _BASE,
    _FN,
    _MD,
    _GIT,
};

enum macro_keycodes {
    RH_COPT = SAFE_RANGE,
    RH_GSFT,
    RH_CSFT,

    /* Markdown */
    HED1,
    HED2,
    HED3,
    TAGGED,
    PYTHON,
    CDFC,
    ALSO,
    DIVIDER,
    TASK,
    BASH,

    /* Git */
    GIT_KEY,
    DDASH,
    GIT_RESET,
    TAG,
    REMOTE,
    UPSTREAM,
    ORIGIN,
    REVERT,
    PUSH,
    ADD,
    STATUS,
    HARD,
    COMMIT,
    REBASE,
    GIT_MAIN,
    CHECKOUT,
    BRANCH,
    PULL,
    MERGE,
    STASH,
    FETCH,
    CLONE,

    LIT_END
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_60_ansi_split_bs_rshift(
    KC_ESC,          KC_1,    KC_2,    KC_3,             KC_4,             KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
    KC_TAB,          KC_Q,    KC_W,    KC_E,             KC_R,             KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
    LCTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,             LT(_GIT, KC_F),   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    LT(_MD, KC_SCLN), KC_QUOT, KC_ENT,
    KC_LSFT,                  KC_Z,    KC_X,             KC_C,             KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_FN),
    LT(_FN, KC_CAPS), KC_LALT, KC_LGUI,                                    KC_SPC,                                _______, RH_COPT, RH_GSFT, RH_CSFT
),

[_FN] = LAYOUT_60_ansi_split_bs_rshift(
    KC_ESC,          KC_F1,   KC_F2,   KC_F3,            KC_F4,            KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  _______,
    _______,         KC_VOLD, KC_MSTP, KC_VOLU,          _______,          _______, KC_END,  KC_PGDN, KC_PGUP, KC_HOME, _______, _______, _______, KC_DEL,
    _______,         KC_MPRV, KC_MPLY, KC_MNXT,          _______,          _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______,
    _______,                  _______, _______,          _______,          _______, _______, _______, _______, _______, _______, QK_BOOT, _______, _______,
    _______,         _______, _______,                                     _______,                               _______, _______, _______, QK_BOOT
),

[_MD] = LAYOUT_60_ansi_split_bs_rshift(
    _______,         HED1,    HED2,    HED3,             _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,         _______, _______, _______,           _______,          TAGGED,  _______, _______, _______, _______, PYTHON,  _______, _______, _______,
    CDFC,            ALSO,    _______, DIVIDER,          _______,          _______, _______, _______, _______, _______, _______, _______, _______,
    _______,                  _______, _______,          TASK,             _______, BASH,    _______, _______, _______, _______, _______, _______, _______,
    _______,         _______, _______,                                     _______,                               _______, _______, _______, _______
),

[_GIT] = LAYOUT_60_ansi_split_bs_rshift(
    GIT_KEY,         _______, _______, _______,           _______,          _______, _______, _______, _______, _______, _______, DDASH,   _______, GIT_RESET, _______,
    TAG,             _______, _______, _______,           REMOTE,           _______, _______, UPSTREAM, _______, ORIGIN,  _______, _______, _______, REVERT,
    PUSH,            ADD,     STATUS,  _______,           _______,          _______, HARD,    _______, _______, _______, _______, _______, COMMIT,
    REBASE,                   _______, _______,           _______,          _______, _______, GIT_MAIN, _______, _______, _______, _______, CHECKOUT, _______,
    BRANCH,          PULL,    MERGE,                                      _______,                               _______, STASH,   FETCH,   CLONE
),
};
// clang-format on

static const char PROGMEM *const lit_table[] = {
    /* markdown */
    PSTR("# "),
    PSTR("## "),
    PSTR("### "),
    PSTR("tagged: #"),
    PSTR("```python" SS_TAP(X_ENTER)),
    PSTR("```"),
    PSTR("See also: "),
    PSTR("---" SS_TAP(X_ENTER)),
    PSTR("- [ ] "),
    PSTR("```bash" SS_TAP(X_ENTER)),

    /* git */
    PSTR("git "),
    PSTR("--"),
    PSTR("reset "),
    PSTR("tag "),
    PSTR("remote "),
    PSTR("upstream "),
    PSTR("origin "),
    PSTR("revert "),
    PSTR("push "),
    PSTR("add "),
    PSTR("status "),
    PSTR("hard "),
    PSTR("commit "),
    PSTR("rebase "),
    PSTR("main "),
    PSTR("checkout "),
    PSTR("branch "),
    PSTR("pull "),
    PSTR("merge "),
    PSTR("stash "),
    PSTR("fetch "),
    PSTR("clone "),
};
_Static_assert((LIT_END - HED1) == ARRAY_SIZE(lit_table), "literal keycodes and lit_table are out of sync");

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RH_COPT:
            if (record->event.pressed) {
                register_mods(MOD_MASK_CTRL | MOD_MASK_ALT);
            } else {
                unregister_mods(MOD_MASK_CTRL | MOD_MASK_ALT);
            }
            return false;
        case RH_GSFT:
            if (record->event.pressed) {
                register_mods(MOD_MASK_GUI | MOD_MASK_SHIFT);
            } else {
                unregister_mods(MOD_MASK_GUI | MOD_MASK_SHIFT);
            }
            return false;
        case RH_CSFT:
            if (record->event.pressed) {
                register_mods(MOD_MASK_CTRL | MOD_MASK_SHIFT);
            } else {
                unregister_mods(MOD_MASK_CTRL | MOD_MASK_SHIFT);
            }
            return false;
        default:
            break;
    }

    if (keycode >= HED1 && keycode < LIT_END && record->event.pressed) {
        send_string_P(lit_table[keycode - HED1]);
        return false;
    }

    return true;
}

#if defined(RGB_MATRIX_ENABLE)
void keyboard_post_init_user(void) {
    rgb_matrix_disable_noeeprom();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (get_highest_layer(state) == _GIT) {
        rgb_matrix_enable_noeeprom();
    } else {
        rgb_matrix_disable_noeeprom();
    }

    return state;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) == _GIT) {
        for (uint8_t i = led_min; i < led_max; i++) {
            rgb_matrix_set_color(i, 0xFF, 0x44, 0x00);
        }
    }

    return false;
}
#endif

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_ESC):
            return true;
        default:
            return false;
    }
}
