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
#include "g/keymap_combo.h"

// Make 7 underscores syntactic sugar for KC_TRANS
// #define _______ KC_TRNS
#define XXXXXXX KC_NO

// Layer shorthand
enum layers {
    _BASE,
    _GAME,
    _LOWER,
    _RAISE,
    _NAV,
    _MD
};

// Shorten keycodes for readability
#define LT_MSCL LT(_MD, KC_SCLN)
#define LT_NBSP LT(_NAV, KC_BSPC)
#define LT_NCAP LT(_NAV, KC_CAPS)
#define MT_WSFT_CAPS MT(MOD_LGUI | MOD_LSFT, KC_CAPS)

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  CDFC = SAFE_RANGE,
  // Extended punctuation
  DBRL, DBRR,
  PIPE, SPIP,
  // Markdown
  H1, H2, H3,
  TAGGED,
  SEEALSO, GRAPH, MARROW,
  CHECK, MERMAID,
};

/*
TAP DANCE
*/
enum { TD_GAME = 0 };

void td_game(tap_dance_state_t *state, void *user_data) {
  if (state->count >= 2) {
    set_single_persistent_default_layer(_BASE);
    reset_tap_dance(state);
  } else {
    set_single_persistent_default_layer(_GAME);
    reset_tap_dance(state);
  }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_GAME] = ACTION_TAP_DANCE_LAYER_MOVE(KC_A, _GAME)
};

/*
MAIN
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_GRV,         KC_1,   KC_2,   KC_3,   KC_4,      KC_5,   KC_END,  KC_PGDN,  KC_PGUP,  KC_HOME,  KC_6,   KC_7,     KC_8,   KC_9,   KC_0,   KC_DEL,
    KC_TAB,         KC_Q,   KC_W,   KC_E,   KC_R,      KC_T,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_Y,   KC_U,     KC_I,   KC_O,   KC_P,   KC_BSPC,
    LCTL_T(KC_ESC), KC_A,   KC_S,   KC_D,   KC_F,      KC_G,   KC_F5,   KC_F6,    KC_F7,    KC_F8,    KC_H,   KC_J,     KC_K,   KC_L,   LT_MSCL,KC_QUOT,
    KC_LSFT,        KC_Z,   KC_X,   KC_C,   KC_V,      KC_B,   KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_N,   KC_M,     KC_COMM,KC_DOT, KC_SLSH,KC_ENT,
    LT_NCAP,        KC_LGUI,KC_LALT,TO(_GAME),MO(_LOWER),LT_NBSP,KC_LEFT, KC_DOWN,  KC_UP,    KC_RIGHT, KC_SPC, MO(_RAISE),LCTL(KC_LALT),  KC_RALT,LGUI(KC_LSFT),LCTL(KC_LSFT)
  ),

  [_GAME] = LAYOUT(
    _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  TO(_BASE),  _______,  KC_SPC,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),

  [_LOWER] = LAYOUT(
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_NUM, KC_SLSH,KC_ASTR,KC_MINS,_______,
    KC_GRV, KC_F9,  KC_F10, KC_F11, KC_F12, KC_A,   _______,_______,_______,_______,KC_B,   KC_7,   KC_8,   KC_9,   KC_ASTR,KC_EQL,
    _______,KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_C,   _______,_______,_______,_______,KC_D,   KC_4,   KC_5,   KC_6,   KC_PLUS,KC_MINS,
    KC_BSLS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_E,   _______,_______,_______,_______,KC_F,   KC_1,   KC_2,   KC_3,   _______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_X,   KC_0,   KC_COMM,KC_DOT, _______,QK_BOOT
  ),

  [_RAISE] = LAYOUT(
    XXXXXXX,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_UNDS,_______,
    KC_TILD,_______,_______,_______,_______,DBRL   ,_______,_______,_______,_______,DBRR   ,KC_AMPR,KC_ASTR,KC_LPRN,_______,_______,
    CDFC,   _______,_______,_______,_______,KC_LPRN,PIPE   ,_______,_______,SPIP   ,KC_RPRN,KC_DLR, KC_PERC,KC_CIRC,KC_EQL,KC_UNDS,
    KC_PIPE,KC_LBRC,KC_RBRC,KC_LCBR,KC_RCBR,_______,_______,_______,_______,_______,_______,KC_EXLM,KC_AT,  KC_HASH,_______,_______,
    _______,_______,_______,_______,_______,KC_DEL ,_______,_______,_______,_______,_______,_______,_______,_______,_______,XXXXXXX
  ),

  [_NAV] = LAYOUT(
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,KC_VOLD,KC_MSTP,KC_VOLU,_______,_______,_______,_______,_______,_______,KC_END, KC_PGDN,KC_PGUP,KC_HOME,_______,_______,
    _______,KC_MPRV,KC_MPLY,KC_MNXT,_______,_______,_______,_______,_______,_______,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,LALT(KC_LEFT),LALT(KC_RIGHT),
    _______,_______,_______,QK_COMBO_TOGGLE,_______,_______,_______,_______,_______,_______,LCTL(LSFT(KC_LEFT)),LSFT(KC_HOME),LSFT(KC_END),LCTL(LSFT(KC_RIGHT)),_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
  ),

  [_MD] = LAYOUT(
    _______,H1,     H2,     H3,     _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,TAGGED, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    CDFC,   _______,SEEALSO,_______,_______,GRAPH,  _______,_______,_______,_______,_______,_______,_______,MARROW, _______,_______,
    _______,_______,_______,CHECK,  _______,_______,_______,_______,_______,_______,_______,MERMAID,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
  ),
};

/*
MACROS
*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CDFC:
      if (record->event.pressed) {
        SEND_STRING("```");
      }
      break;
    case DBRL:
      if (record->event.pressed) {
        SEND_STRING("[[");
      } else {
      }
      break;
    case DBRR:
      if (record->event.pressed) {
        SEND_STRING("]]");
      } else {
      }
      break;
    case PIPE:
      if (record->event.pressed) {
        SEND_STRING("%>%");
      }
      break;
    case SPIP:
      if (record->event.pressed) {
        SEND_STRING("%<>%");
      }
      break;
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
    case TAGGED:
      if (record->event.pressed) {
        SEND_STRING("Tagged: ");
      }
      break;
    case SEEALSO:
      if (record->event.pressed) {
        SEND_STRING("## See also"SS_TAP(X_ENTER));
      }
      break;
    case GRAPH:
      if (record->event.pressed) {
        SEND_STRING("graph ");
      }
      break;
    case MARROW:
      if (record->event.pressed) {
        SEND_STRING("--> ");
      }
      break;
    case CHECK:
      if (record->event.pressed) {
        SEND_STRING("- [ ] ");
      }
      break;
    case MERMAID:
      if (record->event.pressed) {
        SEND_STRING("```mermaid"SS_TAP(X_ENTER));
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
