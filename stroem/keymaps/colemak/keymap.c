#include "stroem.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define SS_RSFT(string) SS_DOWN(X_RSHIFT) string SS_UP(X_RSHIFT)

enum custom_keycodes {
    M_AE = SAFE_RANGE,
    M_OE,
    M_UE,
    M_ESZ,
    M_MU,
    M_EUR,
    M_DAC,
    M_DGRA,
    M_DCIR,
    M_PND,
    M_YEN,
    M_DEG
};

// setxkbmap -option compose:ralt

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case M_AE:
                SEND_STRING(SS_RALT(SS_LSFT("'"))"a");
                return false;
            case M_OE:
                SEND_STRING(SS_RALT(SS_RSFT("'"))"o");
                return false;
            case M_UE:
                SEND_STRING(SS_RALT(SS_RSFT("'"))"u");
                return false;
            case M_ESZ:
                SEND_STRING(SS_RALT("ss"));
                return false;
            case M_MU:
                SEND_STRING(SS_RALT("/u"));
                return false;
            case M_EUR:
                SEND_STRING(SS_RALT("c="));
                return false;
            case M_DAC:
                SEND_STRING(SS_RALT("'"));
                return false;
            case M_DGRA:
                SEND_STRING(SS_RALT("`"));
                return false;
            case M_DCIR:
                SEND_STRING(SS_RALT("^"));
                return false;
            case M_PND:
                SEND_STRING(SS_RALT("l-"));
                return false;
            case M_YEN:
                SEND_STRING(SS_RALT("y="));
                return false;
            case M_DEG:
                SEND_STRING(SS_RALT("0*"));
                return false;
        }
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  KEYMAP(
		KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCOLON,
		KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O,
		KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMMA, KC_RSPC,
		KC_LCTRL, KC_LGUI, KC_LALT, LT(2,KC_DEL), LT(1, KC_SPACE), LT(1, KC_BSPACE), LT(2, KC_ENTER), KC_ESC, TG(3), KC_TAB),

  KEYMAP(
		KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
		KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_MEDIA_NEXT_TRACK, KC_LBRACKET, KC_RBRACKET, KC_SLASH, KC_QUOTE, KC_EQUAL,
		KC_TRANSPARENT, KC_MINUS, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_PLAY_PAUSE, KC_TAB, KC_GRAVE, KC_BSLASH, KC_DOT, KC_TRANSPARENT,
		KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),

  KEYMAP(
		KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F13, M_PND, M_UE, M_YEN, M_DEG,
		M_AE, KC_F6, M_ESZ, KC_F7, KC_F8, M_DAC, M_DCIR, M_EUR, M_DGRA, M_OE,
		KC_TRANSPARENT, KC_F9, KC_F10, KC_F11, KC_F12, KC_ESC, KC_F22, M_MU, KC_F24, KC_TRANSPARENT,
		KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),

  KEYMAP(
		KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O,
		KC_LSHIFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L,
		KC_TAB, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_P, KC_TRANSPARENT,
		KC_LCTRL, KC_1, MO(4), KC_2, KC_SPACE, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),

  KEYMAP(
		KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_1, KC_2, KC_3, KC_TRANSPARENT, KC_TRANSPARENT,
		KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_4, KC_5, KC_6, KC_TRANSPARENT, KC_TRANSPARENT,
		KC_F11, KC_F12, KC_I, KC_O, KC_P, KC_7, KC_8, KC_9, KC_TRANSPARENT, KC_TRANSPARENT,
		KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_0, KC_TRANSPARENT, KC_DOT, KC_TRANSPARENT, KC_TRANSPARENT)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    return MACRO_NONE;
};
