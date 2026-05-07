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

#define _MAC  0
#define _FN   1
#define _WIN  2
#define _MD   4
#define _GIT  5
#define _TOP  6

enum macro_keycodes {
    RH_COPT = SAFE_RANGE,
    RH_GSFT,
    RH_CSFT,

    /* START OF MACROS: Markdown */
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
    GIT_RESET, /* Git layer: R1 */
    TAG,
    REMOTE,
    UPSTREAM,
    ORIGIN,
    REVERT, /* Git layer: R2 */
    PUSH,
    ADD,
    STATUS,
    HARD,
    COMMIT, /* Git layer: R3 */
    REBASE,
    GIT_MAIN,
    CHECKOUT, /* Git layer: R4 */
    BRANCH,
    PULL,
    MERGE,
    STASH,
    FETCH,
    CLONE, /* Git layer: R5 */

    /* Space cadet */
    NOT,
    MATH,
    EXP,
    MUL,
    SSCRIPT,
    SUM, /* R1 */
    AND,
    OR,
    UNION,
    INTERSECTION,
    SUBSET,
    SUPERSET,
    FORALL,
    INFTY,
    EXISTS,
    PARTIAL,
    LBRACE,
    RBRACE,
    BEGIN,
    LX_FALSE,
    LX_TRUE,
    PROVES,
    DASHV,
    LX_UP,
    LX_DOWN,
    LX_LEFT,
    LX_RGHT,
    IFF,
    PRIME,
    LX_END,
    LLCORNER,
    ULCORNER,
    NEQ,
    SIMEQ,
    EQUIV,
    LEQ,
    GEQ,
    ELLIPSIS,
    FRAC,
    DEL_SPC,

    LIT_END /* Literal end */
};

#define BASE_LAYOUT(LEFT_ALT, LEFT_GUI) \
    LAYOUT_ansi_82( \
        KC_ESC,          KC_F1,   KC_F2,   KC_F3,            KC_F4,            KC_F5,   KC_F6,    KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,            C(S(G(KC_4))), C(G(KC_Q)), \
        KC_GRV,          KC_1,    KC_2,    KC_3,             KC_4,             KC_5,    KC_6,     KC_7,    KC_8,     KC_9,    KC_0,    KC_MINS, KC_EQL,            KC_BSPC,        KC_INS, \
        KC_TAB,          KC_Q,    KC_W,    KC_E,             KC_R,             KC_T,    KC_Y,     KC_U,    KC_I,     KC_O,    KC_P,    KC_LBRC, KC_RBRC,           KC_BSLS,        KC_DEL, \
        LCTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,             LT(_GIT, KC_F),   KC_G,    KC_H,     KC_J,    KC_K,     KC_L,    LT(_MD, KC_SCLN), KC_QUOT,       KC_ENT,         KC_HOME, \
        KC_LSFT,                   KC_Z,    KC_X,             KC_C,             KC_V,    KC_B,     KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH,                    MO(_TOP),       KC_UP, \
        LT(_FN, KC_CAPS), LEFT_ALT, LEFT_GUI,                                  KC_SPC,                                 RH_COPT, RH_GSFT, RH_CSFT, KC_LEFT, KC_DOWN, KC_RGHT \
    )

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_MAC] = BASE_LAYOUT(KC_LALT, KC_LGUI), /* Mac base */

[_FN] = LAYOUT_ansi_82( /* FN */
    _______,         KC_BRID, KC_BRIU, KC_MCTL,          KC_LPAD,          _______, _______,  KC_MPRV, KC_MPLY,  KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,           _______,        _______,
    _______,         _______, _______, _______,           _______,           _______, _______,  _______, _______,   _______, _______, _______, _______,           _______,        _______,
    _______,         KC_VOLD, KC_MSTP, KC_VOLU,          _______,           _______, _______,  _______, _______,   _______, _______, _______, _______,           _______,        _______,
    _______,         KC_MPRV, KC_MPLY, KC_MNXT,          _______,           _______, KC_LEFT,  KC_DOWN, KC_UP,    KC_RGHT, _______, _______,                   _______,        _______,
    _______,                  _______, _______,           _______,           _______, _______,  _______,    _______, _______, _______, _______,                  _______,        _______,
    _______,         _______, _______,                                    _______,                                 _______, _______, QK_BOOT,   _______, _______, _______),

[_WIN] = BASE_LAYOUT(KC_LGUI, KC_LALT), /* Windows base on layer 2 */

[_MD] = LAYOUT_ansi_82( /* Markdown */
    _______,         _______, _______, _______,           _______,           _______, _______,  _______, _______,   _______, _______, _______, _______,           _______,        _______,
    _______,         HED1,    HED2,    HED3,             _______,           _______, _______,  _______, _______,   _______, _______, _______, _______,           _______,        _______,
    _______,         _______, _______, _______,           _______,           TAGGED,  _______,  _______, _______,   _______, PYTHON,  _______, _______,           _______,        _______,
    CDFC,            ALSO,    _______, DIVIDER,          _______,           _______, _______,  _______, _______,   _______, _______, _______,                   _______,        _______,
    _______,                  _______, _______,           TASK,              _______,  BASH,     _______, _______,   _______, _______, _______,                  _______,        _______,
    _______,         _______, _______,                                    _______,                                 _______, _______, _______,  _______, _______, _______),

[_GIT] = LAYOUT_ansi_82( /* Git */
    _______,         _______, _______, _______,           _______,           _______, _______,  _______,  _______,   _______, _______, _______, _______,           _______,        _______,
    GIT_KEY,         _______, _______, _______,           _______,           _______, _______,  _______,  _______,   _______, _______, DDASH,   _______,           GIT_RESET,      _______,
    TAG,             _______, _______, _______,           REMOTE,            _______, _______,  UPSTREAM, _______,   ORIGIN,  _______, _______, _______,           REVERT,         _______,
    PUSH,            ADD,     STATUS,  _______,           _______,           _______, HARD,     _______,  _______,   _______, _______, _______,                   COMMIT,         _______,
    REBASE,                   _______, _______,           _______,           _______, _______,  GIT_MAIN, _______,   _______, _______, _______,                  CHECKOUT,       _______,
    BRANCH,          PULL,    MERGE,                                     _______,                                 STASH,   FETCH,   CLONE,    _______, _______, _______),

[_TOP] = LAYOUT_ansi_82( /* Cadet / LaTeX */
    _______,         _______,  _______,  _______,         _______,           _______, _______,  _______,  _______,   _______, _______, _______, _______,           _______,        _______,
    _______,         NOT,      _______,  _______,         MATH,              _______, EXP,      _______,  MUL,       _______, _______, SSCRIPT, SUM,               _______,        _______,
    _______,         AND,      OR,       UNION,           INTERSECTION,      SUBSET,  SUPERSET, FORALL,  INFTY,     EXISTS,  PARTIAL, LBRACE,  RBRACE,            _______,        _______,
    BEGIN,           LX_FALSE, LX_TRUE,  PROVES,          DASHV,             LX_UP,   LX_DOWN,  LX_LEFT, LX_RGHT,   IFF,     _______, PRIME,                     LX_END,         _______,
    _______,                   LLCORNER, ULCORNER,        NEQ,               SIMEQ,   EQUIV,    LEQ,     GEQ,       _______, ELLIPSIS, FRAC,                    _______,        _______,
    _______,         _______,  _______,                                     DEL_SPC,                                 _______, _______, _______,  _______, _______, _______),
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

    /* LaTeX */
    PSTR("\\neg "),
    PSTR("$$" SS_TAP(X_LEFT)),
    PSTR("^{}" SS_TAP(X_LEFT)),
    PSTR("\\cdot "),
    PSTR("_{}" SS_TAP(X_LEFT)),
    PSTR("\\sum"),
    PSTR("\\land "),
    PSTR("\\lor "),
    PSTR("\\cup "),
    PSTR("\\cap "),
    PSTR("\\subset "),
    PSTR("\\supset "),
    PSTR("\\forall "),
    PSTR("\\infty "),
    PSTR("\\exists "),
    PSTR("\\partial "),
    PSTR("\\{ "),
    PSTR("\\} "),
    PSTR("\\begin{}" SS_TAP(X_LEFT)),
    PSTR("\\top "),
    PSTR("\\bot "),
    PSTR("\\vdash "),
    PSTR("\\dashv "),
    PSTR("\\uparrow "),
    PSTR("\\downarrow "),
    PSTR("\\leftarrow "),
    PSTR("\\rightarrow "),
    PSTR("\\iff "),
    PSTR("\\prime "),
    PSTR("\\end{}" SS_TAP(X_LEFT)),
    PSTR("\\llcorner "),
    PSTR("\\ulcorner "),
    PSTR("\\neq "),
    PSTR("\\simeq "),
    PSTR("\\equiv "),
    PSTR("\\leq "),
    PSTR("\\geq "),
    PSTR("\\ldots "),
    PSTR("\\frac{}{}" SS_TAP(X_LEFT)),
    PSTR(SS_TAP(X_BSPC) SS_TAP(X_RIGHT)),
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

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_MAC]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_WIN]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_MD]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_GIT]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_TOP]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_ESC):
            return true;
        default:
            return false;
    }
}
