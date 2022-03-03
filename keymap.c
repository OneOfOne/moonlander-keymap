#include QMK_KEYBOARD_H
#include "version.h"
#include "moonlander.h"
#include "../../config.h"
#include "keymap_us_international.h"
#include "ledmap.h"
#include "dance.h"

enum custom_keycodes {
	RGB_SLD = ML_SAFE_RANGE,
	ST_MACRO_BR, // [|]
	ST_MACRO_CB, // {|}
	ST_MACRO_PR, // (|)
};

enum layers {
	QWERTY,
	MTGAP,
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[QWERTY] = LAYOUT_moonlander(
		DN(GRV), KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   ,                     KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,
		KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , MC(PR) ,                     MC(CB) , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
		KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_LEAD,                     MC(BR) , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                                       KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
		KC_LCTL, LSFTCTL, TT(SYM), KC_LALT, ALTSPC ,                   KC_MEH ,   KC_HYPR,                   ALTSPC , ALTLBRC, TT(SYM), RSFTCTL, CTLRBRC,
		                                              GUIENT, DN(BS) , KC_LGUI,   OSGUI  , DN(DEL), GUIENT
	),
	// [MTGAP] = LAYOUT_moonlander(
	// 	KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   ,                     KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,
	// 	KC_TAB , KC_Y   , KC_P   , KC_O   , KC_U   , KC_J   , DF(QWERTY),                  KC_DOWN, KC_K   , KC_D   , KC_L   , KC_C   , KC_W   , KC_BSLS,
	// 	KC_ESC , KC_I   , KC_N   , KC_E   , KC_A   , KC_COMM, KC_LEFT,                     KC_RGHT, KC_M   , KC_H   , KC_T   , KC_S   , KC_R   , KC_QUOT,
	// 	KC_LSFT, KC_Q   , KC_Z   , KC_SLSH, KC_DOT , KC_SCLN,                                       KC_B   , KC_F   , KC_G   , KC_V   , KC_X   , KC_RSFT,
	// 	KC_LCTL, LSFTCTL, TT(SYM), KC_LALT, KC_SPC ,                 KC_MEH ,       KC_HYPR,                 KC_SPC , ALTLBRC, TT(SYM), RSFTCTL, CTLRBRC,
	// 	                                            KC_ENT, DNC(BS), KC_LGUI,       KC_MENU, KC_DEL, KC_ENT
	// ),
	[SYM] = LAYOUT_moonlander(
		KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                     KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_PSCR,
		______ , KC_HOME, KC_UP  , KC_END , KC_PGUP, ______ , KC_F13 ,                     KC_F14 , ______ , ______ , ______ , ______ , KC_PGUP, ______ ,
		______ , KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, ______ , KC_F15 ,                     KC_F16 , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_PGDN, ______ ,
		______ , ______ , ______ , ______ , ______ , ______ ,                                       ______ , ______ , ______ , KC_HOME, KC_END , ______ ,
		______ , ______ , ______ , ______ , ______ ,                   KC_MUTE,   KC_MPLY,                    ______ , ______ , ______ , ______ , ______ ,
		                                             ______ , KC_VOLU, KC_VOLD,   KC_MPRV, KC_MNXT, ______
	),
	[NAV] = LAYOUT_moonlander(KC_AUDIO_MUTE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCREEN, KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN, KC_MEDIA_PLAY_PAUSE, ______, ______, ______, ______, ______, ______, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_MINUS, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, ______, ______, MU_TOG, ______, ______, ______, ______, ______, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_ASTERISK, ______, TO(0), ______, ______, ______, ______, RGB_MOD, RGB_TOG, KC_0, KC_KP_DOT, ______, KC_KP_SLASH, ______, RGB_VAD, RGB_VAI, TOGGLE_LAYER_COLOR, RGB_SPI, RGB_HUD, RGB_HUI),
};

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
	[QWERTY] = KEYS_TO_LEDS(
		TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL,                    TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL,
		TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, GREN,                    GREN, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL,
		TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, GOLD,                    GREN, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL,
		TEAL, TEAL, TEAL, TEAL, TEAL, TEAL,                                TEAL, TEAL, TEAL, TEAL, TEAL, TEAL,
		TEAL, TEAL, ORNG, TEAL, TEAL,                TEAL, TEAL,                 TEAL, TEAL, ORNG, TEAL, TEAL,
		                                 TEAL, TEAL, TEAL, TEAL, TEAL, TEAL
	),
	// [MTGAP] = KEYS_TO_LEDS(
	// 	TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL,                    TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL,
	// 	TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, GREN,                    TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL,
	// 	TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL,                    TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL,
	// 	TEAL, TEAL, TEAL, TEAL, TEAL, TEAL,                                TEAL, TEAL, TEAL, TEAL, TEAL, TEAL,
	// 	TEAL, TEAL, ORNG, TEAL, TEAL,                TEAL, TEAL,                 TEAL, TEAL, ORNG, TEAL, TEAL,
	// 	                                 TEAL, TEAL, TEAL, TEAL, TEAL, TEAL
	// ),
	[SYM] = KEYS_TO_LEDS(
		TEAL, ORNG, ORNG, ORNG, ORNG, ORNG, ORNG,                    ORNG, ORNG, ORNG, ORNG, ORNG, ORNG, ORNG,
		BLCK, GOLD, TEAL, GOLD, GOLD, BLCK, BLCK,                    BLCK, BLCK, BLCK, BLCK, BLCK, GOLD, BLCK,
		BLCK, TEAL, TEAL, TEAL, GOLD, BLCK, BLCK,                    BLCK, TEAL, TEAL, TEAL, TEAL, GOLD, BLCK,
		BLCK, BLCK, BLCK, BLCK, BLCK, BLCK,                                BLCK, BLCK, BLCK, GOLD, GOLD, BLCK,
		BLCK, BLCK, ORNG, BLCK, BLCK,                BLCK, BLCK,                 BLCK, BLCK, BLCK, BLCK, BLCK,
		                                 TEAL, TEAL, TEAL, TEAL, TEAL, TEAL
	),
	[NAV] = { {10,204,255}, {10,204,255}, {10,204,255}, {10,204,255}, {10,204,255}, {146,224,255}, {10,204,255}, {10,204,255}, {10,204,255}, {10,204,255}, {146,224,255}, {10,204,255}, {10,204,255}, {10,204,255}, {124,255,199}, {146,224,255}, {10,204,255}, {10,204,255}, {10,204,255}, {10,204,255}, {146,224,255}, {10,204,255}, {10,204,255}, {10,204,255}, {10,204,255}, {146,224,255}, {10,204,255}, {10,204,255}, {10,204,255}, {146,224,255}, {10,204,255}, {10,204,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {33,255,255}, {10,204,255}, {10,204,255}, {10,204,255}, {10,204,255}, {146,224,255}, {10,204,255}, {10,204,255}, {10,204,255}, {10,204,255}, {146,224,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,204,255}, {146,224,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,204,255}, {146,224,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,204,255}, {146,224,255}, {10,204,255}, {10,204,255}, {10,204,255}, {146,224,255}, {10,204,255}, {10,204,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255} },

};

qk_tap_dance_action_t tap_dance_actions[] = {
	[DANCE_BS] = TAP_HOLD_DANCE(KC_BSPC, LCTL(KC_BSPC)),
	[DANCE_DEL] = TAP_HOLD_DANCE(KC_DEL, LCTL(KC_DEL)),
	[DANCE_GRV] = TAP_HOLD_DANCE(KC_GRV, KC_ESC),
};

LEADER_EXTERNS();
bool enable_repeat = false;
void matrix_scan_user(void) {
	LEADER_DICTIONARY() {
		leading = false;

		SEQ_ONE_KEY(KC_T) {
			SEND_STRING(SS_LCTL(SS_LSFT("t")));

		} else SEQ_ONE_KEY(KC_1) {
			enable_repeat = !enable_repeat;

		} else SEQ_ONE_KEY(KC_R) {
			SEND_STRING(SS_LALT(SS_TAP(X_F2)));

		} else SEQ_ONE_KEY(KC_W) {
			SEND_STRING(SS_LALT(SS_TAP(X_F4)));

		} else SEQ_TWO_KEYS(KC_S, KC_A) { // select prev word c+s+left
			SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))));

		} else SEQ_TWO_KEYS(KC_S, KC_D) { // select next word c+s+left
			SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_RIGHT))));

		} else SEQ_TWO_KEYS(KC_G, KC_C) {
			SEND_STRING("gcloud compute ssh ");
		}

		leader_end();
	}
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case KC_A ... KC_0:
			if (!IS_LAYER_ON(QWERTY) || enable_repeat) return true;
			if (process_leader(keycode, record) && record->event.pressed) {
				if (record->event.pressed) {
					tap_code16(keycode);
				}
			} else {
				process_tap_dance(keycode, record);
			}
			break;
		case ST_MACRO_BR:
			if (record->event.pressed) {
				SEND_STRING("[]" SS_TAP(X_LEFT));
			}
			break;
		case ST_MACRO_CB:
			if (record->event.pressed) {
				SEND_STRING("{}" SS_TAP(X_LEFT));
			}
			break;
		case ST_MACRO_PR:
			if (record->event.pressed) {
				SEND_STRING("()" SS_TAP(X_LEFT));
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
	rgblight_mode(1);
	rgb_matrix_config.hsv.v = UINT8_MAX;
}

void set_layer_color(int layer) {
	for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
		HSV hsv = {
			.h = pgm_read_byte(&ledmap[layer][i][0]),
			.s = pgm_read_byte(&ledmap[layer][i][1]),
			.v = pgm_read_byte(&ledmap[layer][i][2]),
		};
		if (!hsv.h && !hsv.s && !hsv.v) {
			rgb_matrix_set_color(i, 0, 0, 0);
		} else {
			RGB rgb = hsv_to_rgb(hsv);
			float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
			rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
		}
	}
}

void rgb_matrix_indicators_user(void) {
	switch (biton32(layer_state)) {
	case 0:
		set_layer_color(0);
		if (leading) {
			rgb_matrix_set_color(31, RGB_RED);
		} else {
			rgb_matrix_set_color(31, RGB_GOLD);
		}

		if (enable_repeat) {
			rgb_matrix_set_color(5, RGB_RED);
		} else {
			rgb_matrix_set_color(5, RGB_TEAL);
		}
		break;
	case 1:
		set_layer_color(1);
		break;
	case 2:
		set_layer_color(2);
		break;
	default:
		if (rgb_matrix_get_flags() == LED_FLAG_NONE)
			rgb_matrix_set_color_all(0, 0, 0);
		break;
	}
}
