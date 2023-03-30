/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
};

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)

#define CTL_BSP CTL_T(KC_BSPC)
#define SFT_SPC SFT_T(KC_SPC)
#define GUI_ENT GUI_T(KC_ENT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
          KC_Q,          KC_W,          KC_F,                    KC_P,          KC_B,                          KC_J,     KC_L,          KC_U,          KC_Y,          MT(LSFT(KC_SCLN), KC_SCLN),
          LSFT_T(KC_A),  LCTL_T(KC_R),  LALT_T(KC_S),            LGUI_T(KC_T),  KC_G,                          KC_M,     RGUI_T(KC_N),  RALT_T(KC_E),  RCTL_T(KC_I),  RSFT_T(KC_O),
          KC_Z,          KC_X,          MT(LGUI(KC_C), KC_C),    KC_D,          MT(LGUI(KC_V), KC_V),          KC_K,     KC_H,          KC_COMM,       KC_DOT,        MT(LSFT(KC_SLSH), KC_SLSH),
                                        KC_BSPC,                 RAISE,         LGUI_T(KC_ESC),                LOWER,    MEH_T(KC_SPC)
  ),

  [LAYER_LOWER] = LAYOUT(
          KC_NO,         KC_SLSH,       KC_LPRN,       KC_RPRN,       KC_BSLS,            KC_QUOT,  KC_1,          KC_2,          KC_3,          KC_SCLN, 
          KC_LSFT,       KC_LCTL,       KC_LALT,       KC_LGUI,       KC_NO,              KC_MINS,  KC_4,          KC_5,          KC_6,          KC_EQL, 
          KC_NO,         KC_LT,         KC_LBRC,       KC_RBRC,       KC_GT,              KC_GRV,   KC_7,          KC_8,          KC_9,          KC_0, 
                                        KC_TRNS,       KC_TRNS,       KC_TRNS,            KC_TRNS,  KC_TRNS
  ),

  [LAYER_RAISE] = LAYOUT(
          RSG(KC_4),     DRGSCRL,       KC_BTN1,       KC_BTN2,       KC_NO,              KC_HOME,  KC_PGDN,       KC_PGUP,       KC_END,        DPI_MOD, 
          KC_LSFT,       KC_LCTL,       KC_LALT,       KC_LGUI,       KC_NO,              KC_LEFT,  KC_DOWN,       KC_UP,         KC_RGHT,       KC_DEL, 
          RGB_MOD,       RGB_RMOD,      RGB_VAI,       RGB_VAD,       RGB_SPI,            SNP_TOG,  KC_NO,         KC_ENT,        KC_TAB,        DPI_RMOD, 
                                        KC_TRNS,       KC_TRNS,       KC_TRNS,            KC_TRNS,  KC_TRNS
  ),
};
// clang-format on
