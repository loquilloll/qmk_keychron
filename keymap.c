/*
Copyright 2020 Dimitris Mantzouranis
Copyright 2022 Philip Mourdjis

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
#include QMK_KEYBOARD_H

#define LCTL_KESC LCTL_T(KC_ESC)
#define LGUI_KA   LGUI_T(KC_A)
#define LALT_KS   LALT_T(KC_S)
#define LCTL_KD   LCTL_T(KC_D)
#define LSFT_KF   LSFT_T(KC_F)
#define RSFT_KJ   RSFT_T(KC_J)
#define RCTL_KK   RCTL_T(KC_K)
#define RALT_KL   RALT_T(KC_L)
#define RG_SCLN   RGUI_T(KC_SCLN)

#define LT1_ESC  LT(WIN_FN1,KC_ESC)
#define LT1_BSPC LT(WIN_FN1, KC_BSPC)
#define LT1_SPC LT(WIN_FN1, KC_SPC)

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    WIN_BASE,
    WIN_FN1,
    MAC_BASE,
    MAC_FN1,
    FN2,
};

enum custom_keycodes {
    KC_MISSION_CONTROL = SAFE_RANGE,
    KC_LAUNCHPAD
};

#define KC_TASK LGUI(KC_TAB)        // Task viewer
#define KC_FLXP LGUI(KC_E)          // Windows file explorer
#define KC_MCTL KC_MISSION_CONTROL  // Mission Control
#define KC_LPAD KC_LAUNCHPAD        // Launchpad

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Windows Base
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│MOD│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │HOM│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │PGU│
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ ↑ │PGD│
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │Ctrl│GUI │Alt │         Space          │Ctl│Fn1│Fn2│ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
    [WIN_BASE] = LAYOUT_65_ansi(
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_6, KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,   KC_EQL,    KC_BSPC,          RGB_MOD,
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_Y, KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,   KC_BSLASH, KC_NO,          KC_HOME,
        LCTL_KESC, LGUI_KA, LALT_KS, LCTL_KD, LSFT_KF, KC_G, KC_H, RSFT_KJ, RCTL_KK, RALT_KL, RG_SCLN, KC_QUOT,              KC_ENT,           KC_PGUP,
        KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_N, KC_M,    KC_COMM, KC_DOT,  KC_SLSH,            KC_RSFT,          KC_UP,     KC_PGDOWN, 
        KC_LCTL, KC_LGUI, KC_LALT,                   LT1_SPC,                        KC_RCTRL, MO(WIN_FN1), MO(FN2),     KC_LEFT,   KC_DOWN,   KC_RGHT
    ),
    /* Windows FN1
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │`~ │BRU│BRD│TSK│FLX│VAD│VAI│PRV│PLY│NXT│MTE│VLD│VLU│       │TOG│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │     │   │   │   │   │   │   │   │   │   │INS│DEL│END│     │   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │      │   │   │   │   │   │   │   │   │   │   │   │        │   │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │        │   │   │   │   │   │   │   │   │   │   │      │   │   │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │    │    │    │                        │Alt│   │   │   │   │   │
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
    [WIN_FN1] = LAYOUT_65_ansi(
        KC_GRV,  KC_BRIU, KC_BRID, KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______,          RGB_TOG,
        KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  _______, _______, _______,          _______,
        KC_TRNS, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_UNDS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PPLS, KC_TRNS,          _______,          _______,
        KC_TRNS, KC_TILD, KC_GRV,  KC_LBRC, KC_RBRC, KC_NO,   KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,           KC_PMNS, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
    /* Mac Base
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│MOD│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │HOM│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │PGU│
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ ↑ │PGD│
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │Ctrl│Alt │GUI │         Space          │GUI│Fn1│Fn2│ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
    [MAC_BASE] = LAYOUT_65_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6,   KC_7, KC_8, KC_9,    KC_0,    KC_MINS,     KC_EQL,  KC_BSPC,            RGB_MOD,
        KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y,   KC_U, KC_I, KC_O,    KC_P,    KC_LBRC,     KC_RBRC, KC_BSLASH,          KC_HOME,
        KC_CAPS, KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H,   KC_J, KC_K, KC_L,    KC_SCLN, KC_QUOT,              KC_ENT,             KC_PGUP,
        KC_LSFT,          KC_Z,    KC_X, KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH,              KC_RSFT,   KC_UP,   KC_PGDOWN,
        KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                      KC_RGUI, MO(MAC_FN1), MO(FN2), KC_LEFT,   KC_DOWN, KC_RGHT
    ),
    /* Mac FN1
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │`~ │BRU│BRD│MCT│LPD│VAD│VAI│PRV│PLY│NXT│MTE│VLD│VLU│       │TOG│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │     │   │   │   │   │   │   │   │   │   │INS│DEL│END│     │   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │      │   │   │   │   │   │   │   │   │   │   │   │        │   │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │        │   │   │   │   │   │   │   │   │   │   │      │   │   │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │    │    │    │                        │Alt│   │   │   │   │   │
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
    [MAC_FN1] = LAYOUT_65_ansi(
        KC_GRV,  KC_BRIU, KC_BRID, KC_MCTL, KC_LPAD, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______,          RGB_TOG,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,  KC_DEL,  KC_END,  _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            KC_RALT, _______, _______, _______, _______, _______
    ),
    /* FN2
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │ ~ │ F1│ F2│ F3│ F4│ F5│ F6│ F7│ F8│ F9│F10│F11│F12│ RESET │MOD│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │     │M_P│M_B│M_R│MSW│   │   │   │   │   │   │   │   │     │RMD│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │      │   │   │   │   │   │   │   │   │   │   │   │        │SPI│
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │        │   │   │   │   │   │   │   │   │   │   │      │SAI│SPD│
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │    │    │    │                        │   │   │   │HUD│SAD│HUI│
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
    [FN2] = LAYOUT_65_ansi(
        KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  RESET,            RGB_MOD,
        _______, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, _______, _______, _______, _______, _______, _______, _______, _______, _______,          RGB_RMOD,
        _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,          _______,          RGB_SPI,
        _______,          _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,          _______, RGB_SAI, RGB_SPD,
        _______, _______, _______,                             _______,                            _______, _______, _______, RGB_HUD, RGB_SAD, RGB_HUI
    )
};

bool dip_switch_update_user(uint8_t index, bool active){
    switch(index){
        case 0: // macos/windows togggle
            if(active){ //macos
                layer_move(MAC_BASE);
            }
            else{ //windows
                layer_move(WIN_BASE);
            }
        break;
    }
    return true;
}

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    // debug_enable=true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
      case LSFT_T(KC_F): 
         return TAPPING_TERM_SFT;
      case RSFT_T(KC_J): 
         return TAPPING_TERM_SFT;
      default:
         return TAPPING_TERM;
}}