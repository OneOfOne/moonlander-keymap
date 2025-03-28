#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE
// #include "keycode.h"
// #include QMK_KEYBOARD_H
// #include "dance.h"
// #include "keymap_us_international.h"
#include "ledmap.h"
// #include "moonlander.h"
// #include "version.h"

#include "password.h"

enum custom_keycodes {
	// RGB_SLD = SAFE_RANGE,
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

// #define DN(x) TD(DANCE_##x)
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
		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, /* -------------------- */ KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_MEH, /* ------------------ */ KC_HYPR, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
		KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, QK_LEAD, /* ----------------- */ QK_LEAD, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, /* ------------------------- */ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
		KC_LCTL, LSFTCTL, MO(SYM), KC_LALT, KC_SPC, KC_MEH, /*-------------- */KC_HYPR, KC_SPC, ALTLBRC, MO(SYM), KC_RBRC, KC_RCTL,
		/* ------------------- */ KC_ENT, KC_BSPC, KC_LGUI, /*--------------*/ KC_APP, KC_DEL, KC_ENT /* ---------------------- */
	),

	[SYM] = LAYOUT_moonlander(
		______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, /* ----------------- */ KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR,
		______, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_INS, KC_F13, /* ----------------- */ KC_F14, ______, ______, ______, ______, ______, KC_BRK,
		______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, ______, ______, /* ----------------- */ ______, ______, ______, ______, ______, ______, ______,
		______, MS_BTN4, ______, MS_BTN5, ______, ______, /* ----------------- */ ______, ______, ______, ______, ______, ______,
		______, ______, TO(0), ______, ______, KC_MUTE, /* ----------------- */ KC_MPLY, ______, ______, TO(0), ______, ______,
		______, KC_VOLU, KC_VOLD, KC_MPRV, KC_MNXT, ______
	),

};

const HSV PROGMEM ledmap[][RGB_MATRIX_LED_COUNT] = {
	[QWERTY] = KEYS_TO_LEDS(
		MEDSEA, GREN, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA,
		MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, GREN, GREN, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA,
		MEDSEA, MEDSEA, MEDSEA, MEDSEA, GOLD, GOLD, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA,
		MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, ORNG, MEDSEA, MEDSEA, MEDSEA,
		MEDSEA, MEDSEA, MEDSEA, ORNG, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA, MEDSEA
	),
	[SYM] = KEYS_TO_LEDS(MEDSEA, ORNG, ORNG, GREN, ORNG, ORNG, ORNG, ORNG, ORNG, ORNG, ORNG, ORNG, ORNG, ORNG, BLCK, GOLD, MEDSEA, GOLD, GOLD, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, ORNG, BLCK, MEDSEA, MEDSEA, MEDSEA, GOLD, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, RED, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, ORNG, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, ORNG, BLCK, BLCK, BLCK, MEDSEA, MEDSEA, MEDSEA, MEDSEA, BLCK),

};

// qk_tap_dance_action_t tap_dance_actions[] = {
// 	[DANCE_BS] = TAP_HOLD_DANCE(KC_BSPC, LCTL(KC_BSPC)),
// 	[DANCE_DEL] = TAP_HOLD_DANCE(KC_DEL, LCTL(KC_DEL)),
// 	[DANCE_GRV] = TAP_HOLD_DANCE(KC_GRV, KC_ESC),
// };

bool is_leading = false;
void leader_start_user(void) {
	is_leading = true;
}
void leader_end_user(void) {
	if (leader_sequence_one_key(KC_T)) {
		SEND_STRING(SS_LCTL(SS_LSFT("t")));
	}

	if (leader_sequence_one_key(KC_1)) {
		layer_move(QWERTY);
	}

	if (leader_sequence_one_key(KC_3)) {
		layer_move(SYM);
	}

	if (leader_sequence_one_key(KC_W)) {
		SEND_STRING(SS_LALT(SS_TAP(X_F4)));
	}

	if (leader_sequence_one_key(KC_V)) {
		SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_INS))));
	}

	if (leader_sequence_two_keys(KC_S, KC_A)) {
		SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))));
	}

	if (leader_sequence_two_keys(KC_S, KC_D)) {
		SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_RIGHT))));
	}

	if (leader_sequence_two_keys(KC_P, KC_W)) {
		SEND_STRING(PASSWORD);
	}

	if (leader_sequence_one_key(KC_R)) {
		SEND_STRING(SS_LALT(SS_TAP(X_F2)));
	}

	is_leading = false;
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	// switch (keycode) {
	// case ST_MACRO_BR:
	// 	if (record->event.pressed) {
	// 		if (leading) {
	// 			SEND_STRING("&& ");
	// 		} else {
	// 			SEND_STRING("[]" SS_UP(X_LSFT) SS_TAP(X_LEFT));
	// 		}
	// 	}
	// 	break;
	// case ST_MACRO_EQ:
	// 	if (record->event.pressed) {
	// 		if (leading) {
	// 			SEND_STRING("<- ");
	// 		} else {
	// 			SEND_STRING(":= ");
	// 		}
	// 	}
	// 	break;
	// case ST_MACRO_PR:
	// 	if (record->event.pressed) {
	// 		if (leading) {
	// 			SEND_STRING("|| ");
	// 		} else {
	// 			SEND_STRING("()" SS_UP(X_LSFT) SS_TAP(X_LEFT));
	// 		}
	// 	}
	// 	break;
	// default:
	// 	return true;
	// }

	// return false;
// }

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
	for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
		HSV hsv = ledmap[layer][i];
		set_color_at(i, f, hsv.h, hsv.s, hsv.v);
	}
}

bool rgb_matrix_indicators_user(void) {
	const float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
	const uint8_t layer = biton32(layer_state);
	set_layer_color(layer, f);

	if (is_leading) {
		set_color_at(31, f, HSV_RED);
		set_color_at(32, f, HSV_RED);
	} else {
		set_color_at(31, f, HSV_GOLD);
		set_color_at(32, f, HSV_GOLD);
	}
	return true;
}
