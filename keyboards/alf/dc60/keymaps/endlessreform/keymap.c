/* Copyright 2022 Jacob Keisling
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
#define _NAV 1
#define _MD 2
#define _TOP 3
#define _GREEK 4
#define _GIT 5

// Macro definitions. All are in (R: row, C: key) order
enum custom_keycodes {
    // Markdown layer
    TAGGED = SAFE_RANGE,
    H1, H2, H3,
    CDFC, ALSO, DIVIDER, MARROW,
    TASK, MERMAID,

    // Space Cadet TOP layer
    NOT, MATH, EXP, MUL, SSCRIPT, SUM,
    LTX_CDFC, QQUAD, AND, OR, UNION, INTERSECTION, SUBSET, SUPERSET, FORALL, INFTY, EXISTS, PARTIAL, LCORNER, RCORNER,
    BEGIN, FALSE, TRUE, VDASH, DASHV, UP, DOWN, LEFT, RIGHT, IFF, PRIME,
    LLCORNER, ULCORNER, NEQ, SIMEQ, EQUIV, LEQ, GEQ, ELLIPSIS, FRAC,
    SPC,

    // Space Cadet GREEK layer
    QED, TIMES, EMPTY,
    THETA, OMEGA, EPSILON, RHO, TAU, UPSILON, PSI, IOTA, OMICRON, PI,
    ALPHA, SIGMA, DELTA, PHI, GAMMA, ETA, KAPPA, LAMBDA,
    ZETA, XI, CHI, BETA, NU, MU,

    // Git layer
    GIT_KEY, DDASH, RM,
    TAG, REMOTE, UPSTREAM, INIT, ORIGIN, REVERT,
    PUSH, STATUS, DEVELOP, GLOBAL, LOG, COMMIT,
    REBASE, MAIN, CHECKOUT, ADD,
    BRANCH, PULL, MERGE, STASH, FETCH, CLONE
};

/*
TAP DANCE
*/
enum { TD_PROVES_MODELS = 0, TD_LEFT_ARROW, TD_RIGHT_ARROW, TD_GIT_M };

void proves_models(qk_tap_dance_state_t *state, void *user_data) {
    // Double tap: \models
    if (state->count >= 2) {
        SEND_STRING("\\models ");
        reset_tap_dance(state);
    } else {
        SEND_STRING("\\vdash ");
        reset_tap_dance(state);
    }
}

void right_arrow(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        SEND_STRING("\\twoheadrightarrow ");
        reset_tap_dance(state);
    } else {
        SEND_STRING("\\rightarrow ");
        reset_tap_dance(state);
    }
}

void left_arrow(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        SEND_STRING("\\twoheadleftarrow ");
        reset_tap_dance(state);
    } else {
        SEND_STRING("\\leftarrow ");
        reset_tap_dance(state);
    }
}

void td_git_m(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        SEND_STRING("master ");
        reset_tap_dance(state);
    } else {
        SEND_STRING("main ");
        reset_tap_dance(state);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_PROVES_MODELS] = ACTION_TAP_DANCE_FN(proves_models),
    [TD_LEFT_ARROW]    = ACTION_TAP_DANCE_FN(left_arrow),
    [TD_RIGHT_ARROW]   = ACTION_TAP_DANCE_FN(right_arrow),
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
        KC_LSFT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, LCAG_T(KC_COMM), LCA_T(KC_DOT), LAG_T(KC_SLSH), MO(_TOP), KC_UP, MO(_GREEK),
        LT(_NAV, KC_CAPS), KC_LGUI, KC_LALT, KC_SPACE, KC_SPACE, KC_SPACE, KC_RALT, LGUI(KC_LSFT), LGUI(KC_LSFT), LGUI(KC_LSFT), LCTL(KC_LSFT)
    ),

    [_NAV] = LAYOUT_all(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______,
        _______, KC_VOLD, KC_MSTP, KC_VOLU, _______, _______, KC_END, KC_PGDN, KC_PGUP, KC_HOME, _______, _______, _______, KC_DEL,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, _______,
        _______, KC_LSFT, _______, _______, CMB_TOG, _______, _______, _______, AG_TOGG, _______, _______, _______, KC_CAPS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_MAKE, QK_BOOT
    ),

    [_MD] = LAYOUT_all(
        _______, H1, H2, H3, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, TAGGED, _______, _______, _______, _______, _______, _______, _______, _______,
        CDFC, _______, ALSO, DIVIDER, _______, KC_LPRN, KC_RPRN, _______, MARROW, _______, _______, _______, _______,
        _______, _______, _______, _______, TASK, _______, _______, _______, MERMAID, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_TOP] = LAYOUT_all(
        _______, NOT, _______, _______, MATH, _______, EXP, _______, MUL, _______, _______, SSCRIPT, SUM, LTX_CDFC, _______,
        QQUAD, AND, OR, INTERSECTION, UNION, SUBSET, SUPERSET, FORALL, INFTY, EXISTS, PARTIAL, LCORNER, RCORNER, _______,
        BEGIN, FALSE, TRUE, TD(TD_PROVES_MODELS), DASHV, UP, DOWN, TD(TD_LEFT_ARROW), TD(TD_RIGHT_ARROW), IFF, _______, PRIME, _______, _______,
        _______, LLCORNER, ULCORNER, NEQ, SIMEQ, EQUIV, LEQ, GEQ, _______, ELLIPSIS, FRAC, _______, _______,
        _______, _______, _______, _______, SPC, SPC, SPC, _______, _______, _______, _______, _______
    ),

    [_GREEK] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, QED, _______, TIMES, _______, EMPTY, _______, _______, _______, _______,
        _______, THETA, OMEGA, EPSILON, RHO, TAU, UPSILON, PSI, IOTA, OMICRON, PI, _______, _______, _______,
        _______, ALPHA, SIGMA, DELTA, PHI, GAMMA, ETA, _______, KAPPA, LAMBDA, _______, _______, _______,
        _______, _______, ZETA, XI, CHI, _______, BETA, NU, MU, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, SPC, SPC, SPC, _______, _______, _______, _______, _______
    ),

    [_GIT] = LAYOUT_all(
        GIT_KEY, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DDASH, _______, _______, RM,
        TAG, _______, _______, _______, REMOTE, _______, _______, UPSTREAM, INIT, ORIGIN, _______, _______, _______, REVERT,
        PUSH, _______, STATUS, DEVELOP, _______, GLOBAL, _______, _______, _______, LOG, _______, _______, COMMIT,
        REBASE, _______, _______, _______, _______, _______, _______, _______, TD(TD_GIT_M), _______, _______, _______, CHECKOUT, CHECKOUT, ADD,
        BRANCH, PULL, MERGE, SPC, SPC, SPC, STASH, STASH, FETCH, FETCH, CLONE
    ),
};

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void leader_start_user(void) {
    // Do nothing when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_O, KC_U)) {
        // Leader, **O**s, **U**pdate
        SEND_STRING("sudo pacman -Syu")
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Markdown macros
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

        // Space Cadet TOP  macros
        case NOT:
            if (record->event.pressed) {
                SEND_STRING("\\neg ");
            }
            break;
        case EXP:
            if (record->event.pressed) {
                SEND_STRING("^{}" SS_TAP(X_LEFT));
            }
            break;
        case MUL:
            if (record->event.pressed) {
                SEND_STRING("\\cdot ");
            }
            break;
        case SSCRIPT:
            if (record->event.pressed) {
                SEND_STRING("_{}" SS_TAP(X_LEFT));
            }
            break;
        case SUM:
            if (record->event.pressed) {
                SEND_STRING("\\sum");
            }
            break;
        case LTX_CDFC:
            if (record->event.pressed) {
                SEND_STRING("\\texttt{}" SS_TAP(X_LEFT));
            }
            break;
        case QQUAD:
            if (record->event.pressed) {
                SEND_STRING("\\qquad ");
            } else {
            }
            break;
        case AND:
            if (record->event.pressed) {
                SEND_STRING("\\land ");
            } else {
            }
            break;
        case OR:
            if (record->event.pressed) {
                SEND_STRING("\\lor ");
            } else {
            }
            break;
        case UNION:
            if (record->event.pressed) {
                SEND_STRING("\\cup ");
            } else {
            }
            break;
        case INTERSECTION:
            if (record->event.pressed) {
                SEND_STRING("\\cap ");
            } else {
            }
            break;
        case SUBSET:
            if (record->event.pressed) {
                SEND_STRING("\\subset ");
            } else {
            }
            break;
        case SUPERSET:
            if (record->event.pressed) {
                SEND_STRING("\\superset ");
            } else {
            }
            break;
        case FORALL:
            if (record->event.pressed) {
                SEND_STRING("\\forall ");
            } else {
            }
            break;
        case INFTY:
            if (record->event.pressed) {
                SEND_STRING("\\infty ");
            } else {
            }
            break;
        case EXISTS:
            if (record->event.pressed) {
                SEND_STRING("\\exists ");
            } else {
            }
            break;
        case PARTIAL:
            if (record->event.pressed) {
                SEND_STRING("\\partial ");
            } else {
            }
            break;
        case LCORNER:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\llcorner ");
                } else {
                    SEND_STRING("\\ulcorner ");
                }
            }
            break;
        case RCORNER:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\lrcorner ");
                } else {
                    SEND_STRING("\\urcorner ");
                }
            }
            break;
        case BEGIN:
            if (record->event.pressed) {
            } else {
                SEND_STRING("\\begin{}" SS_TAP(X_LEFT));
            }
            break;
        case TRUE:
            if (record->event.pressed) {
                SEND_STRING("\\top ");
            } else {
            }
            break;
        case FALSE:
            if (record->event.pressed) {
                SEND_STRING("\\bot ");
            } else {
            }
            break;
        case VDASH:
            if (record->event.pressed) {
                SEND_STRING("\\vdash ");
            } else {
            }
            break;
        case DASHV:
            if (record->event.pressed) {
                SEND_STRING("\\dashv ");
            } else {
            }
            break;
        case UP:
            if (record->event.pressed) {
                SEND_STRING("\\uparrow ");
            } else {
            }
            break;
        case DOWN:
            if (record->event.pressed) {
                SEND_STRING("\\downarrow ");
            } else {
            }
            break;
        case LEFT:
            if (record->event.pressed) {
                SEND_STRING("\\leftarrow ");
            } else {
            }
            break;
        case RIGHT:
            if (record->event.pressed) {
                SEND_STRING("\\rightarrow ");
            } else {
            }
            break;
        case IFF:
            if (record->event.pressed) {
                SEND_STRING("\\iff ");
            } else {
            }
            break;
        case PRIME:
            if (record->event.pressed) {
                SEND_STRING("\\prime ");
            } else {
            }
            break;
        case LLCORNER:
            if (record->event.pressed) {
                SEND_STRING("\\llcorner ");
            } else {
            }
            break;
        case ULCORNER:
            if (record->event.pressed) {
                SEND_STRING("\\ulcorner ");
            } else {
            }
            break;
        case NEQ:
            if (record->event.pressed) {
                SEND_STRING("\\neq ");
            } else {
            }
            break;
        case SIMEQ:
            if (record->event.pressed) {
                SEND_STRING("\\simeq ");
            } else {
            }
            break;
        case EQUIV:
            if (record->event.pressed) {
                SEND_STRING("\\equiv ");
            } else {
            }
            break;
        case LEQ:
            if (record->event.pressed) {
                SEND_STRING("\\leq ");
            } else {
            }
            break;
        case GEQ:
            if (record->event.pressed) {
                SEND_STRING("\\geq ");
            } else {
            }
            break;
        case ELLIPSIS:
            if (record->event.pressed) {
                SEND_STRING("\\dots");
            }
            break;
        case FRAC:
            if (record->event.pressed) {
                SEND_STRING("\\frac{}" SS_TAP(X_LEFT));
            }
            break;
        case SPC:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_RIGHT));
            }
            break;

        // Space Cadet GREEK macros
        case QED:
            if (record->event.pressed) {
                SEND_STRING("\\square ");
            }
            break;
        case TIMES:
            if (record->event.pressed) {
                SEND_STRING("\\times ");
            }
            break;
        case EMPTY:
            if (record->event.pressed) {
                SEND_STRING("\\emptyset ");
            }
            break;
        case THETA:
            if (record->event.pressed) {
                // Capital theta
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Theta ");
                } else {
                    SEND_STRING("\\theta ");
                }
            }
            break;
        case OMEGA:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Omega ");
                } else {
                    SEND_STRING("\\omega ");
                }
            }
            break;
        case EPSILON:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Epsilon ");
                } else {
                    SEND_STRING("\\epsilon ");
                }
            }
            break;
        case RHO:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Rho ");
                } else {
                    SEND_STRING("\\rho ");
                }
            }
            break;
        case TAU:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Tau ");
                } else {
                    SEND_STRING("\\tau ");
                }
            }
            break;
        case UPSILON:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Upsilon ");
                } else {
                    SEND_STRING("\\upsilon ");
                }
            }
            break;
        case PSI:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Psi ");
                } else {
                    SEND_STRING("\\psi ");
                }
            }
            break;
        case IOTA:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Iota ");
                } else {
                    SEND_STRING("\\iota ");
                }
            }
            break;
        case OMICRON:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Omicron ");
                } else {
                    SEND_STRING("\\omicron ");
                }
            }
            break;
        case PI:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Pi ");
                } else {
                    SEND_STRING("\\pi ");
                }
            }
            break;

        case ALPHA:
            if (record->event.pressed) {
                // Capital alpha
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Alpha ");
                } else {
                    SEND_STRING("\\alpha ");
                }
            }
            break;
        case SIGMA:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Sigma ");
                } else {
                    SEND_STRING("\\sigma ");
                }
            }
            break;
        case DELTA:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Delta ");
                } else {
                    SEND_STRING("\\delta ");
                }
            }
            break;
        case PHI:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Phi ");
                } else {
                    SEND_STRING("\\phi ");
                }
            }
            break;
        case GAMMA:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Gamma ");
                } else {
                    SEND_STRING("\\gamma ");
                }
            }
            break;
        case ETA:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Eta ");
                } else {
                    SEND_STRING("\\eta ");
                }
            }
            break;
        case KAPPA:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Kappa ");
                } else {
                    SEND_STRING("\\kappa ");
                }
            }
            break;
        case LAMBDA:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Lambda ");
                } else {
                    SEND_STRING("\\lambda ");
                }
            }
            break;

        case ZETA:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Zeta ");
                } else {
                    SEND_STRING("\\zeta ");
                }
            }
            break;
        case XI:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Xi ");
                } else {
                    SEND_STRING("\\xi ");
                }
            }
            break;
        case CHI:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Chi ");
                } else {
                    SEND_STRING("\\Chi ");
                }
            }
            break;
        case BETA:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Beta ");
                } else {
                    SEND_STRING("\\beta ");
                }
            }
            break;
        case NU:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Nu ");
                } else {
                    SEND_STRING("\\nu ");
                }
            }
            break;
        case MU:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING("\\Mu ");
                } else {
                    SEND_STRING("\\mu ");
                }
            }
            break;
        case GIT_KEY:
            if (record->event.pressed) {
                SEND_STRING("git ");
            } else {
            }
            break;
        case DDASH:
            if (record->event.pressed) {
                SEND_STRING("--");
            } else {
            }
            break;
        case RM:
            if (record->event.pressed) {
                SEND_STRING("rm ");
            } else {
            }
            break;
        case TAG:
            if (record->event.pressed) {
                SEND_STRING("tag ");
            } else {
            }
            break;
        case REMOTE:
            if (record->event.pressed) {
                SEND_STRING("remote ");
            } else {
            }
            break;
        case UPSTREAM:
            if (record->event.pressed) {
                SEND_STRING("upstream ");
            } else {
            }
            break;
        case INIT:
            if (record->event.pressed) {
                SEND_STRING("init ");
            } else {
            }
            break;
        case ORIGIN:
            if (record->event.pressed) {
                SEND_STRING("origin ");
            } else {
            }
            break;
        case REVERT:
            if (record->event.pressed) {
                SEND_STRING("revert ");
            } else {
            }
            break;
        case PUSH:
            if (record->event.pressed) {
                SEND_STRING("push ");
            } else {
            }
            break;
        case STATUS:
            if (record->event.pressed) {
                SEND_STRING("status");
            } else {
            }
            break;
        case DEVELOP:
            if (record->event.pressed) {
                SEND_STRING("develop ");
            } else {
            }
            break;
        case GLOBAL:
            if (record->event.pressed) {
                SEND_STRING("global ");
            } else {
            }
            break;
        case LOG:
            if (record->event.pressed) {
                SEND_STRING("log ");
            } else {
            }
            break;
        case COMMIT:
            if (record->event.pressed) {
                SEND_STRING("commit ");
            } else {
            }
            break;
        case REBASE:
            if (record->event.pressed) {
                SEND_STRING("rebase ");
            } else {
            }
            break;
        case CHECKOUT:
            if (record->event.pressed) {
                SEND_STRING("checkout ");
            } else {
            }
            break;
        case ADD:
            if (record->event.pressed) {
                SEND_STRING("add ");
            } else {
            }
            break;
        case BRANCH:
            if (record->event.pressed) {
                SEND_STRING("branch ");
            } else {
            }
            break;
        case PULL:
            if (record->event.pressed) {
                SEND_STRING("pull ");
            } else {
            }
            break;
        case MERGE:
            if (record->event.pressed) {
                SEND_STRING("merge ");
            } else {
            }
            break;
        case STASH:
            if (record->event.pressed) {
                SEND_STRING("stash ");
            } else {
            }
            break;
        case FETCH:
            if (record->event.pressed) {
                SEND_STRING("fetch ");
            } else {
            }
            break;
        case CLONE:
            if (record->event.pressed) {
                SEND_STRING("clone ");
            } else {
            }
            break;
    }
    return true;
}
