#include "keycode.h"
#include QMK_KEYBOARD_H
#include "version.h"
#include "moonlander.h"
#include "keymap_us_international.h"
#include "ledmap.h"
#include "dance.h"

#include "password.h"

enum custom_keycodes {
	RGB_SLD = ML_SAFE_RANGE,
	ST_MACRO_BR, // [|]
	ST_MACRO_EQ, // := |
	ST_MACRO_PR, // (|)
};

enum layers {
	QWERTY,
	QMAC,
	SYM,
	NAV,
};

enum tap_dance_codes {
	DANCE_BS,
	DANCE_DEL,
	DANCE_GRV,
};

#define DN(x) TD(DANCE_##x)
#define OSML(x) OSM(MOD_L##x)
#define OSMR(x) OSM(MOD_R##x)
#define LSFTCTL LSFT(KC_LCTL)
#define RSFTCTL RSFT(KC_RCTL)
#define ______ KC_TRANSPARENT
#define ALTLBRC MT(MOD_RALT, KC_LBRC)
#define CTLRBRC MT(MOD_RCTL, KC_RBRC)
#define GUIENT MT(MOD_LGUI, KC_ENT)
#define ALTSPC MT(MOD_LALT, KC_SPC)
#define OSGUI OSM(MOD_LGUI)
#define MC(x) ST_MACRO_##x

#define KC_ORYX WEBUSB_PAIR

#define MS_UP KC_MS_UP
#define MS_DOWN KC_MS_DOWN
#define MS_LEFT KC_MS_LEFT
#define MS_RGHT KC_MS_RIGHT
#define MS_BTN1 KC_MS_BTN1
#define MS_BTN2 KC_MS_BTN2
#define MS_BTN3 KC_MS_BTN3
#define MS_BTN4 KC_MS_BTN4
#define MS_BTN5 KC_MS_BTN5
#define MS_BTN6 KC_MS_BTN6
#define MS_W_U KC_MS_WH_UP
#define MS_W_D KC_MS_WH_DOWN
#define MS_W_L KC_MS_WH_LEFT
#define MS_W_R KC_MS_WH_RIGHT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[QWERTY] = LAYOUT_moonlander(
		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,    /* ----------------- */ KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, MC(EQ),   /* ----------------- */ MC(BR), KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
		KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_LEAD,  /* ----------------- */ MC(PR), KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,           /* -----------------*/ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
		KC_LCTL, LSFTCTL, MO(SYM), KC_LALT, KC_SPC,      KC_MEH, KC_HYPR,          KC_SPC, ALTLBRC, MO(SYM), RSFTCTL, CTLRBRC,
											KC_ENT, KC_BSPC, KC_LGUI, KC_APP, DN(DEL), KC_ENT
	),

	[QMAC] = LAYOUT_moonlander(
		DN(GRV), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,    /* ----------------- */ KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, MC(EQ),   /* ----------------- */ MC(BR), KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
		KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_LEAD,  /* ----------------- */ MC(PR), KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,          /* ----------------- */ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
		KC_LGUI, LSFTCTL, MO(SYM), KC_LCTL, KC_SPC, /* ----- */ KC_MEH, KC_HYPR, KC_SPC, /* ----- */ ALTLBRC, MO(SYM), RSFTCTL, CTLRBRC,
											KC_ENT, DN(BS), KC_LALT, KC_APP, DN(DEL), KC_ENT
	),

	[SYM]    = LAYOUT_moonlander(
		______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, /* ----------------- */ KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR,
		______, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_INS, KC_F13, /* ----------------- */ KC_F14, ______, ______, ______, ______, ______, KC_BRK,
		______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, ______, ______, /* ----------------- */  ______, ______, ______, ______, KC_LOCK, ______, ______,
		______, MS_BTN4, ______, MS_BTN5, ______, ______, /* ----------------- */  ______, ______, ______, ______, ______, ______,
		______, ______, TO(0), ______, ______, KC_MUTE, /* ----------------- */ KC_MPLY, ______, ______, TO(0), ______, ______,
											______, KC_VOLU, KC_VOLD, KC_MPRV, KC_MNXT, ______
		),

	[NAV]    = LAYOUT_moonlander(AU_TOG, MS_BTN1, MS_BTN2, MS_BTN3, MS_BTN4, MS_BTN5, MS_BTN6, ______, ______, ______, ______, ______, ______, KC_ORYX, MU_TOG, MS_W_U, MS_UP, MS_W_D, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, MU_MOD, MS_LEFT, MS_DOWN, MS_RGHT, ______, ______, ______, ______, RGB_HUD, RGB_HUI, RGB_SPD, RGB_SPI, ______, ______, ______, MS_W_L, ______, MS_W_R, ______, ______, RGB_VAD, RGB_VAI, RGB_SLD, RGB_MOD, ______, ______, ______, ______, TO(0), ______, ______, ______, ______, ______, ______, TO(0), ______, ______, ______, ______, ______, ______, ______, ______),
};

const HSV PROGMEM ledmap[][DRIVER_LED_TOTAL] = {
	[QWERTY] = KEYS_TO_LEDS(MEDSEA, GREN, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, GREN, GREN, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, GOLD, GREN, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, ORNG, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, ORNG, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA),
	[QMAC]  = KEYS_TO_LEDS(MEDSEA, MEDSEA, GREN, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, GREN, GREN, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, GOLD, GREN, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, ORNG, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, ORNG, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA),
	[SYM]    = KEYS_TO_LEDS(MEDSEA, ORNG, ORNG, GREN, ORNG, ORNG, ORNG, ORNG, ORNG, ORNG, ORNG, ORNG, ORNG, ORNG, BLCK, GOLD, MEDSEA, GOLD, GOLD, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, ORNG, BLCK, MEDSEA, MEDSEA, MEDSEA, GOLD, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, RED, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, ORNG, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, ORNG, BLCK, BLCK, BLCK, MEDSEA, MEDSEA, MEDSEA, MEDSEA, BLCK),
	[NAV]    = KEYS_TO_LEDS(BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, ORNG, BLCK, BLCK, MEDSEA, MEDSEA, BLCK, BLCK, ORNG, BLCK, BLCK, MEDSEA, MEDSEA, MEDSEA, BLCK, BLCK, BLCK),

};

qk_tap_dance_action_t tap_dance_actions[] = {
	[DANCE_BS]  = TAP_HOLD_DANCE(KC_BSPC, LCTL(KC_BSPC)),
	[DANCE_DEL] = TAP_HOLD_DANCE(KC_DEL, LCTL(KC_DEL)),
	[DANCE_GRV] = TAP_HOLD_DANCE(KC_GRV, KC_ESC),
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
	LEADER_DICTIONARY() {
		leading = false;

		SEQ_ONE_KEY(KC_T) {
			SEND_STRING(SS_LCTL(SS_LSFT("t")));
		}

		SEQ_ONE_KEY(KC_1) {
			layer_move(QWERTY);
		}

		SEQ_ONE_KEY(KC_2) {
			layer_move(QMAC);
		}

		SEQ_ONE_KEY(KC_3) {
			layer_move(SYM);
		}

		SEQ_ONE_KEY(KC_4) {
			layer_move(NAV);
		}

		SEQ_ONE_KEY(KC_R) {
			SEND_STRING(SS_LALT(SS_TAP(X_F2)));
		}

		SEQ_ONE_KEY(KC_W) {
			SEND_STRING(SS_LALT(SS_TAP(X_F4)));
		}

		SEQ_ONE_KEY(KC_V) {
			SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_INS))));
		}

		SEQ_TWO_KEYS(KC_S, KC_A) { // select prev word c+s+left
			SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))));
		}

		SEQ_TWO_KEYS(KC_S, KC_D) { // select next word c+s+left
			SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_RIGHT))));
		}

		SEQ_TWO_KEYS(KC_D, KC_D) { // select all and backspace
			SEND_STRING(SS_TAP(X_END) SS_LSFT(SS_TAP(X_HOME)) SS_TAP(X_BSPACE) SS_TAP(X_BSPACE));
		}

		SEQ_TWO_KEYS(KC_G, KC_C) {
			SEND_STRING("gcloud compute ssh ");
		}

		SEQ_TWO_KEYS(KC_P, KC_W) {
			SEND_STRING(PASSWORD SS_TAP(X_ENTER));
		}

		leader_end();
	}
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case ST_MACRO_BR:
			if (record->event.pressed) {
				if (leading) {
					SEND_STRING("&& ");
				} else {
					SEND_STRING("[]" SS_UP(X_LSFT) SS_TAP(X_LEFT));
				}
			}
			break;
		case ST_MACRO_EQ:
			if (record->event.pressed) {
				if (leading) {
					SEND_STRING("<- ");
				} else {
					SEND_STRING(":= ");
				}
			}
			break;
		case ST_MACRO_PR:
			if (record->event.pressed) {
				if (leading) {
					SEND_STRING("|| ");
				} else {
					SEND_STRING("()" SS_UP(X_LSFT) SS_TAP(X_LEFT));
				}
			}
			break;
		default:
			return true;
	}

	return false;
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
	rgb_matrix_enable();
}

void set_color_at(int i, float f, uint8_t h, uint8_t s, uint8_t v) {
	if (!h && !s && !v) {
		rgb_matrix_set_color(i, 0, 0, 0);
		return;
	}
	HSV hsv = {
		.h = h,
		.s = s,
		.v = v,
	};
	RGB rgb = hsv_to_rgb(hsv);
	rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
}

void set_layer_color(int layer, float f) {
	for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
		HSV hsv = ledmap[layer][i];
		set_color_at(i, f, hsv.h, hsv.s, hsv.v);
	}
}

void rgb_matrix_indicators_user(void) {
	const float   f     = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
	const uint8_t layer = biton32(layer_state);
	set_layer_color(layer, f);

	if (leading) {
		set_color_at(31, f, HSV_RED);
	} else {
		set_color_at(31, f, HSV_GOLD);
	}
}
