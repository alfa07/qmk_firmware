// Copyright 2021 Christian Eiden, cykedev
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

#define CM_SPAL  LGUI_T(KC_SPC)
#define CM_SPAR  RGUI_T(KC_SPC)

#define SH_ENL  LSFT_T(KC_ENT)
#define SH_ENR  RSFT_T(KC_ENT)

#define SYM     MO(_SYMBOL)
#define ADJ     MO(_ADJUST)

#define QWERT   DF(_QWERTY)
#define COLEM   DF(_COLEMAK)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

#define LT1_BS LT(1, KC_BSPC)

#define LT2_GRV LT(2, KC_GRV)
#define LT2_RBRC LT(2, KC_RBRC)

enum layer_names {
  _QWERTY,
  _COLEMAK,
  _SYMBOL,
  _ADJUST
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6_5(
  /* QWERTY
   * .-----------------------------------------.                                  .-----------------------------------------.
   * | =    |   1  |   2  |   3  |   4  |   5  |                                  |   6  |   7  |   8  |   9  |   0  |  -   |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |                                  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Ctrl | GuiA | AltS | SftD | CtlF |   G  |                                  |   H  | CtlJ | SftK | AltL | Gui; |  '   |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | LS/) |   Z  |   X  |   C  |   V  |   B  |                                  |   N  |   M  |   ,  |   .  |   /  | RS/) |
   * '-----------------------------------------/                                  \-----------------------------------------'
   *               |  ADJ |   -  |    /  SYM  /---------------.    .---------------\  SYM  \    |  +   | ADJ  |
   *               |      |      |   /       /  Cmd  / Shift /      \ Shift \  Cmd  \       \   |      |      |
   *               '-------------'  '-------/ Space / Enter /        \ Enter \ Space \-------'  '-------------'
   *                                       /---------------/          \---------------\
   *                                      /  Ctrl  / Alt  /            \  Alt  \  Ctrl \
   *                                     /        /      /              \       \       \
   *                                    '---------------'                '---------------'
   */
   KC_EQL,  KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
   KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
   KC_ESC,  HOME_A , HOME_S , HOME_D , HOME_F , KC_G   ,                                     KC_H   , HOME_J , HOME_K , HOME_L , HOME_SCLN, KC_QUOT,
   KC_LSPO, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                                     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSPC,
                     LT2_GRV, KC_MINS,          LT1_BS , CM_SPAL, SH_ENL , SH_ENR , CM_SPAR, SYM    ,          KC_LBRC ,LT2_RBRC,
                                                         KC_LCTL, KC_LALT, KC_RALT, KC_RCTL
   ),
  [_COLEMAK] = LAYOUT_5x6_5(
  /* COLEMAK
   * .-----------------------------------------.                                  .-----------------------------------------.
   * | Esc  |   1  |   2  |   3  |   4  |   5  |                                  |   6  |   7  |   8  |   9  |   0  |  Bsp |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   F  |   P  |   G  |                                  |   J  |   L  |   U  |   Y  |   ;  |  \   |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Ctrl |   A  |   R  |   S  |   T  |   D  |                                  |   H  |   N  |   E  |   I  |   O  |  '   |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Shft |   Z  |   X  |   C  |   V  |   B  |                                  |   K  |   M  |   ,  |   .  |   /  | Shft |
   * '-----------------------------------------/                                  \-----------------------------------------'
   *               |  ADJ |   -  |    /  SYM  /---------------.    .---------------\  SYM  \    |   +  | ADJ  |
   *               |      |      |   /       /  Cmd  / Shift /      \ Shift \  Cmd  \       \   |      |      |
   *               '-------------'  '-------/ Space / Enter /        \ Enter \ Space \-------'  '-------------'
   *                                       /---------------/          \---------------\
   *                                      /  Alt  / Ctrl  /            \  Ctrl \  Alt  \
   *                                     /       /       /              \       \       \
   *                                    '---------------'                '---------------'
   */
   KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
   KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   ,                                     KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_BSLS,
   KC_LCTL, KC_A   , KC_R   , KC_S   , KC_T   , KC_D   ,                                     KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT,
   KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                                     KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                     ADJ    , KC_MINS,          SYM    , CM_SPAL, SH_ENL , SH_ENR , CM_SPAR, SYM    ,          KC_EQL , ADJ    ,
                                                         KC_LALT, KC_LCTL, KC_RCTL, KC_RALT
   ),
  [_SYMBOL] = LAYOUT_5x6_5(
  /* SYMBOL
   * .-----------------------------------------.                                  .-----------------------------------------.
   * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |                                  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |   !  |   @  |   [  |   ]  |   +  |                                  |      |      |  up  |      |      |  F12 |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |   &  |   |  |   (  |   )  |   -  |                                  |      | left | down | right|  ?   |      |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |   *  |   /  |   {  |   }  |   =  |                                  |      |      |      |      |      |      |
   * '-----------------------------------------/                                  \-----------------------------------------'
   *               |      |      |    /       /---------------.    .---------------\       \    |      |      |
   *               |      |      |   /       /       /       /      \       \       \       \   |      |      |
   *               '-------------'  '-------/       /       /        \       \       \-------'  '-------------'
   *                                       /---------------/          \---------------\
   *                                      /       /       /            \       \       \
   *                                     /       /       /              \       \       \
   *                                    '---------------'                '---------------'
   */
   KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                                     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
   XXXXXXX, KC_EXLM, KC_AT  , KC_LBRC, KC_RBRC, KC_PPLS,                                     XXXXXXX, XXXXXXX, KC_UP  , XXXXXXX, XXXXXXX, KC_F12 ,
   _______, KC_AMPR, KC_PIPE, KC_LPRN, KC_RPRN, KC_MINS,                                     XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_QUES, XXXXXXX,
   _______, KC_ASTR, KC_SLSH, KC_LCBR, KC_RCBR, KC_PEQL,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                     XXXXXXX, XXXXXXX,          _______, _______, _______, _______, _______, _______,          XXXXXXX, XXXXXXX,
                                                         _______, _______, _______, _______
   ),
  [_ADJUST] = LAYOUT_5x6_5(
  /* ADJUST
   * .-----------------------------------------.                                  .-----------------------------------------.
   * |  RST |      |      |      |      | QWERT|                                  |COLEM |      |      |      |      | RST  |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |      |      |      |      |   +  |                                  |  B + |      |      |      |      |      |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |      |      |      |      |   -  |                                  |  B - |  <<  | play |  >>  |      |      |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |      |      |      |      |   =  |                                  |      |      |      |      |      |      |
   * '-----------------------------------------/                                  \-----------------------------------------'
   *               |      |      |    /       /---------------.    .---------------\       \    |      |      |
   *               |      |      |   /       /       /       /      \       \       \       \   |      |      |
   *               '-------------'  '-------/       /       /        \       \       \-------'  '-------------'
   *                                       /---------------/          \---------------\
   *                                      /       /       /            \       \       \
   *                                     /       /       /              \       \       \
   *                                    '---------------'                '---------------'
   */
   RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QWERT  ,                                     COLEM  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET  ,
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU,                                     KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,                                     KC_BRID, KC_MRWD, KC_MPLY, KC_MFFD, XXXXXXX, XXXXXXX,
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                     _______, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, _______,
                                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
   )
};

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CM_SPAR:
      return true;
    default:
      return false;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 
  return true;
}
