/* Copyright 2025 Jacob Keisling
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
/* See QMK combo docs "Dictionary Management" */
/*#include "g/keymap_combo.h"*/
#define _BASE 0
#define _MAC 1
#define _FN 2
#define _MD 3
#define _GIT 4
#define _TOP 5
#define _GREEK 6

#include "quantum.h"

// Macro definitions. All are in (R: row, C: key) order
enum custom_keycodes {
    MAC_TOGGLE = SAFE_RANGE,

    /* START OF MACROS: Markdown */
    H1, H2, H3,
    TAGGED, PYTHON,
    CDFC, ALSO, DIVIDER,
    TASK, BASH,

    /* Git */
    GIT_KEY, DDASH, GIT_RESET, GIT_GUD,
    TAG, REMOTE, UPSTREAM, INIT, ORIGIN, REVERT,
    PUSH, STATUS, DEVELOP, HARD, COMMIT,
    REBASE, MAIN, CHECKOUT, ADD,
    BRANCH, PULL, MERGE, STASH, FETCH, CLONE,

    /* Space Cadet TOP layer */
    NOT, MATH, EXP, MUL, SSCRIPT, SUM,
    AND, OR, UNION, INTERSECTION, SUBSET, SUPERSET, FORALL, INFTY, EXISTS, PARTIAL, LBRACE, RBRACE,
    BEGIN, LX_FALSE, LX_TRUE, VDASH, DASHV, LX_UP, LX_DOWN, LX_LEFT, LX_RIGHT, IFF, PRIME,
    NEQ, SIMEQ, EQUIV, LEQ, GEQ, ELLIPSIS, FRAC,
    LX_SPC,

    // Space Cadet GREEK layer
    QED, TIMES, EMPTY,
    LIT_END,

    // Non-lit table: Cadet TOP layer
    LLCORNER, ULCORNER, 

    // Non-lit table: Cadet GREEK shifted keys
    THETA, OMEGA, EPSILON, RHO, TAU, UPSILON, PSI, IOTA, OMICRON, PI,
    ALPHA, SIGMA, DELTA, PHI, GAMMA, ETA, KAPPA, LAMBDA,
    ZETA, XI, CHI, BETA, NU, MU
};

/*
TAP DANCE
*/
enum { TD_GIT_M = 0 };

void td_git_m(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        SEND_STRING("master ");
        reset_tap_dance(state);
    } else {
        SEND_STRING("main ");
        reset_tap_dance(state);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_GIT_M]   = ACTION_TAP_DANCE_FN(td_git_m),
};

/*
MAIN
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    Keys per row:
    - R1: 15
    - R2: 14
    - R3: 13
    - R4: 13
    - R5: 07
    */
    [_BASE] = LAYOUT_all(
        QK_LEAD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
        LCTL_T(KC_ESC), KC_A, KC_S, KC_D, LT(_GIT, KC_F), KC_G, KC_H, KC_J, KC_K, KC_L, LT(_MD, KC_SCLN), KC_QUOT, KC_ENT,
        KC_LSFT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MO(_TOP), KC_UP, MO(_GREEK),
        LT(_FN, KC_CAPS), KC_LGUI, KC_LALT, KC_SPACE, KC_SPACE, KC_SPACE, KC_RALT, KC_RALT, S(KC_LGUI), S(KC_LGUI), S(KC_LCTL)
    ),

    [_MAC] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______,
        _______, KC_LALT, KC_LGUI, _______, _______, _______, LCA_T(KC_LEFT), LCA_T(KC_LEFT), LSG_T(KC_RIGHT), LSG_T(KC_RIGHT), _______
    ),

    [_FN] = LAYOUT_all(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______,
        _______, KC_VOLD, KC_MSTP, KC_VOLU, _______, _______, KC_END, KC_PGDN, KC_PGUP, KC_HOME, _______, _______, _______, KC_DEL,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, _______,
        _______, KC_LSFT, _______, _______, CM_TOGG, _______, _______, _______, MAC_TOGGLE, _______, _______, _______, KC_CAPS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_MAKE, QK_BOOT
    ),

    [_MD] = LAYOUT_all(
        _______, H1, H2, H3, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, TAGGED, _______, _______, _______, _______, PYTHON, _______, _______, _______,
        CDFC, ALSO, _______, DIVIDER, _______, KC_LPRN, KC_RPRN, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, TASK, _______, BASH, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    // yes, it's bizarre that these keys are swapped in here vs actual scan order. I don't know why either
    [_GIT] = LAYOUT_all(
        GIT_KEY, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DDASH, _______, GIT_RESET, GIT_GUD, 
        TAG, _______, _______, _______, REMOTE, _______, _______, UPSTREAM, INIT, ORIGIN, _______, _______, _______, REVERT,
        PUSH, ADD, STATUS, DEVELOP, _______, _______, HARD, _______, _______, _______, _______, _______, COMMIT,
        REBASE, _______, _______, _______, _______, _______, _______, _______, TD(TD_GIT_M), _______, _______, _______, CHECKOUT, CHECKOUT, ADD,
        BRANCH, PULL, MERGE, _______, _______, _______, STASH, STASH, FETCH, FETCH, CLONE
    ),

    [_TOP] = LAYOUT_all(
        _______, NOT, _______, _______, MATH, _______, EXP, _______, MUL, _______, _______, SSCRIPT, SUM, _______, _______,
        _______, AND, OR, INTERSECTION, UNION, SUBSET, SUPERSET, FORALL, INFTY, EXISTS, PARTIAL, LBRACE, RBRACE, _______,
        BEGIN, LX_FALSE, LX_TRUE, VDASH, DASHV, LX_UP, LX_DOWN, LX_LEFT, LX_RIGHT, IFF, _______, PRIME, _______, _______,
        _______, LLCORNER, ULCORNER, NEQ, SIMEQ, EQUIV, LEQ, GEQ, _______, ELLIPSIS, FRAC, _______, _______,
        _______, _______, _______, _______, LX_SPC, LX_SPC, LX_SPC, _______, _______, _______, _______, _______
    ),

    [_GREEK] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, QED, _______, TIMES, _______, EMPTY, _______, _______, _______, _______,
        _______, THETA, OMEGA, EPSILON, RHO, TAU, UPSILON, PSI, IOTA, OMICRON, PI, _______, _______, _______,
        _______, ALPHA, SIGMA, DELTA, PHI, GAMMA, ETA, _______, KAPPA, LAMBDA, _______, _______, _______,
        _______, _______, ZETA, XI, CHI, _______, BETA, NU, MU, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, LX_SPC, LX_SPC, LX_SPC, _______, _______, _______, _______, _______
    ),
};

// The stupid way that actually works on AVR
// At least it's all in one place and the order is clear

static const char lit_0[] PROGMEM = "# ";
static const char lit_1[] PROGMEM = "## ";
static const char lit_2[] PROGMEM = "### ";
static const char lit_3[] PROGMEM = "tagged: #";
static const char lit_4[] PROGMEM = "```python" SS_TAP(X_ENTER);
static const char lit_5[] PROGMEM = "```";
static const char lit_6[] PROGMEM = "See also:" SS_TAP(X_ENTER);
static const char lit_7[] PROGMEM = "---" SS_TAP(X_ENTER);
static const char lit_8[] PROGMEM = "- [ ] ";
static const char lit_9[] PROGMEM = "```bash" SS_TAP(X_ENTER);
static const char lit_10[] PROGMEM = "git ";
static const char lit_11[] PROGMEM = "--";
static const char lit_12[] PROGMEM = "reset ";
static const char lit_13[] PROGMEM = "gud ";
static const char lit_14[] PROGMEM = "tag ";
static const char lit_15[] PROGMEM = "remote ";
static const char lit_16[] PROGMEM = "upstream ";
static const char lit_17[] PROGMEM = "init ";
static const char lit_18[] PROGMEM = "origin ";
static const char lit_19[] PROGMEM = "revert ";
static const char lit_20[] PROGMEM = "push ";
static const char lit_21[] PROGMEM = "status ";
static const char lit_22[] PROGMEM = "develop ";
static const char lit_23[] PROGMEM = "hard ";
static const char lit_24[] PROGMEM = "commit ";
static const char lit_25[] PROGMEM = "rebase ";
static const char lit_26[] PROGMEM = "main ";
static const char lit_27[] PROGMEM = "checkout ";
static const char lit_28[] PROGMEM = "add ";
static const char lit_29[] PROGMEM = "branch ";
static const char lit_30[] PROGMEM = "pull ";
static const char lit_31[] PROGMEM = "merge ";
static const char lit_32[] PROGMEM = "stash ";
static const char lit_33[] PROGMEM = "fetch ";
static const char lit_34[] PROGMEM = "clone ";
static const char lit_35[] PROGMEM = "\\neg ";
static const char lit_36[] PROGMEM = "$$" SS_TAP(X_LEFT);
static const char lit_37[] PROGMEM = "^{}" SS_TAP(X_LEFT);
static const char lit_38[] PROGMEM = "\\cdot ";
static const char lit_39[] PROGMEM = "_{}" SS_TAP(X_LEFT);
static const char lit_40[] PROGMEM = "\\sum";
static const char lit_41[] PROGMEM = "\\land ";
static const char lit_42[] PROGMEM = "\\lor ";
static const char lit_43[] PROGMEM = "\\cup ";
static const char lit_44[] PROGMEM = "\\cap ";
static const char lit_45[] PROGMEM = "\\subset ";
static const char lit_46[] PROGMEM = "\\supset ";
static const char lit_47[] PROGMEM = "\\forall ";
static const char lit_48[] PROGMEM = "\\infty ";
static const char lit_49[] PROGMEM = "\\exists ";
static const char lit_50[] PROGMEM = "\\partial ";
static const char lit_51[] PROGMEM = "\\{ ";
static const char lit_52[] PROGMEM = "\\} ";
static const char lit_53[] PROGMEM = "\\begin{}" SS_TAP(X_LEFT);
static const char lit_54[] PROGMEM = "\\bot ";
static const char lit_55[] PROGMEM = "\\top ";
static const char lit_56[] PROGMEM = "\\vdash ";
static const char lit_57[] PROGMEM = "\\dashv ";
static const char lit_58[] PROGMEM = "\\uparrow ";
static const char lit_59[] PROGMEM = "\\downarrow ";
static const char lit_60[] PROGMEM = "\\leftarrow ";
static const char lit_61[] PROGMEM = "\\rightarrow ";
static const char lit_62[] PROGMEM = "\\iff ";
static const char lit_63[] PROGMEM = "\\prime ";
static const char lit_64[] PROGMEM = SS_TAP(X_BSPC) SS_TAP(X_RIGHT);
static const char lit_65[] PROGMEM = "\\llcorner ";
static const char lit_66[] PROGMEM = "\\ulcorner ";
static const char lit_67[] PROGMEM = "\\neq ";
static const char lit_68[] PROGMEM = "\\simeq ";
static const char lit_69[] PROGMEM = "\\equiv ";
static const char lit_70[] PROGMEM = "\\leq ";
static const char lit_71[] PROGMEM = "\\geq ";
static const char lit_72[] PROGMEM = "\\ldots ";
static const char lit_73[] PROGMEM = "\\frac{}{}" SS_TAP(X_LEFT);
static const char lit_74[] PROGMEM = "\\square ";
static const char lit_75[] PROGMEM = "\\times ";
static const char lit_76[] PROGMEM = "\\emptyset ";

static const char* const lit_table[] PROGMEM = {
    lit_0, lit_1, lit_2, lit_3, lit_4, lit_5, lit_6, lit_7, lit_8, lit_9,
    lit_10, lit_11, lit_12, lit_13, lit_14, lit_15, lit_16, lit_17, lit_18, lit_19,
    lit_20, lit_21, lit_22, lit_23, lit_24, lit_25, lit_26, lit_27, lit_28, lit_29,
    lit_30, lit_31, lit_32, lit_33, lit_34, lit_35, lit_36, lit_37, lit_38, lit_39,
    lit_40, lit_41, lit_42, lit_43, lit_44, lit_45, lit_46, lit_47, lit_48, lit_49,
    lit_50, lit_51, lit_52, lit_53, lit_54, lit_55, lit_56, lit_57, lit_58, lit_59,
    lit_60, lit_61, lit_62, lit_63, lit_64, lit_65, lit_66, lit_67, lit_68, lit_69,
    lit_70, lit_71, lit_72, lit_73, lit_74, lit_75, lit_76
};


void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void leader_start_user(void) {
    // Do nothing when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_O, KC_U)) {
        // Leader, **O**s, **U**pdate
        SEND_STRING("sudo pacman -Syu");
    }
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
    } else if (keycode >= H1 && keycode < LIT_END && record->event.pressed) {
        send_string_P((char*)pgm_read_ptr(&lit_table[keycode - H1]));
        return false;
    } else {
        switch (keycode) {
            case THETA:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Theta ");
                    } else {
                        SEND_STRING("\\theta ");
                    }
                }
                return false;

            case OMEGA:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Omega ");
                    } else {
                        SEND_STRING("\\omega ");
                    }
                }
                return false;

            case EPSILON:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Epsilon ");
                    } else {
                        SEND_STRING("\\epsilon ");
                    }
                }
                return false;

            case RHO:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Rho ");
                    } else {
                        SEND_STRING("\\rho ");
                    }
                }
                return false;

            case TAU:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Tau ");
                    } else {
                        SEND_STRING("\\tau ");
                    }
                }
                return false;

            case UPSILON:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Upsilon ");
                    } else {
                        SEND_STRING("\\upsilon ");
                    }
                }
                return false;

            case PSI:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Psi ");
                    } else {
                        SEND_STRING("\\psi ");
                    }
                }
                return false;

            case IOTA:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Iota ");
                    } else {
                        SEND_STRING("\\iota ");
                    }
                }
                return false;

            case OMICRON:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Omicron ");
                    } else {
                        SEND_STRING("\\omicron ");
                    }
                }
                return false;

            case PI:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Pi ");
                    } else {
                        SEND_STRING("\\pi ");
                    }
                }
                return false;

            case ALPHA:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Alpha ");
                    } else {
                        SEND_STRING("\\alpha ");
                    }
                }
                return false;

            case SIGMA:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Sigma ");
                    } else {
                        SEND_STRING("\\sigma ");
                    }
                }
                return false;

            case DELTA:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Delta ");
                    } else {
                        SEND_STRING("\\delta ");
                    }
                }
                return false;

            case PHI:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Phi ");
                    } else {
                        SEND_STRING("\\phi ");
                    }
                }
                return false;

            case GAMMA:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Gamma ");
                    } else {
                        SEND_STRING("\\gamma ");
                    }
                }
                return false;

            case ETA:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Eta ");
                    } else {
                        SEND_STRING("\\eta ");
                    }
                }
                return false;

            case KAPPA:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Kappa ");
                    } else {
                        SEND_STRING("\\kappa ");
                    }
                }
                return false;

            case LAMBDA:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Lambda ");
                    } else {
                        SEND_STRING("\\lambda ");
                    }
                }
                return false;

            case ZETA:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Zeta ");
                    } else {
                        SEND_STRING("\\zeta ");
                    }
                }
                return false;

            case XI:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Xi ");
                    } else {
                        SEND_STRING("\\xi ");
                    }
                }
                return false;

            case CHI:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Chi ");
                    } else {
                        SEND_STRING("\\chi ");
                    }
                }
                return false;

            case BETA:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Beta ");
                    } else {
                        SEND_STRING("\\beta ");
                    }
                }
                return false;

            case NU:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Nu ");
                    } else {
                        SEND_STRING("\\nu ");
                    }
                }
                return false;

            case MU:
                if (record->event.pressed) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        clear_mods();
                        SEND_STRING("\\Mu ");
                    } else {
                        SEND_STRING("\\mu ");
                    }
                }
                return false;
        }

        return true;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_ESC):  // your home-row Ctrl/Esc key
            return true;      // treat as HOLD immediately if another key is pressed
        default:
            return false;
    }
}