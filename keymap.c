#include QMK_KEYBOARD_H
#include "version.h"
#include "moonlander.h"
#include "../../config.h"
#include "keymap_us_international.h"
#include "ledmap.h"
#include "dance.h"

enum custom_keycodes {
	RGB_SLD = ML_SAFE_RANGE,
};

enum layers {
	QWERTY,
	SYM,
	NAV,
};

enum tap_dance_codes {
	DANCE_Z,
	DANCE_X,
	DANCE_C,
	DANCE_V,

	DANCE_4,
	DANCE_5,
	DANCE_6,
	DANCE_7,
	DANCE_8,
	DANCE_9,
};

#define DNC(x) TD(DANCE_##x)
#define OSML(x) OSM(MOD_L##x)
#define OSMR(x) OSM(MOD_R##x)
#define LSFTCTL LSFT(KC_LCTL)
#define RSFTCTL RSFT(KC_RCTL)
#define _____ KC_TRANSPARENT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[QWERTY] = LAYOUT_moonlander(
		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,                              KC_7, KC_8, KC_9, KC_0, KC_MINUS, KC_EQUAL, KC_BSPACE,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_UP,                             KC_DOWN, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLASH,
		KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_LEFT,                           KC_RGHT, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
		KC_LSFT, DNC(Z), DNC(X), DNC(C), DNC(V), KC_B,                           KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSFT,
		KC_LCTL, LSFTCTL, OSL(1), KC_LALT, KC_SPC,       KC_MEH,       KC_HYPR,         KC_SPC, MT(MOD_RALT, KC_LBRC), DNC(9), RSFTCTL, MT(MOD_RCTL, KC_RBRC),
		                                  KC_ENT, DNC(4), KC_LGUI,       OSL(2), KC_DEL, KC_ENT
	),
	[SYM] = LAYOUT_moonlander(
		AU_TOG, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                       KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR,
		MU_TOG, KC_HOME, KC_UP, KC_END, KC_PGUP, _____, _____,                  _____, _____, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, _____,
		MU_MOD, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _____, _____,               _____, _____, _____, _____, _____, _____, _____,
		_____, KC_VOLU, KC_VOLD, KC_MUTE, _____, _____,                                _____, _____, _____, KC_HOME, KC_UP, KC_END,
		_____, KC_MPLY, KC_MPRV, KC_MNXT, _____,           _____,       _____,                _____, _____, KC_LEFT, KC_DOWN, KC_RGHT,
		                                    _____, _____, OSL(2),       _____, _____, _____
	),
	[NAV] = LAYOUT_moonlander(KC_AUDIO_MUTE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCREEN, KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN, KC_MEDIA_PLAY_PAUSE, _____, _____, _____, _____, _____, _____, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_MINUS, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, _____, _____, MU_TOG, _____, _____, _____, _____, _____, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_ASTERISK, _____, TO(0), _____, WEBUSB_PAIR, _____, _____, RGB_MOD, RGB_TOG, KC_0, KC_KP_DOT, _____, KC_KP_SLASH, _____, RGB_VAD, RGB_VAI, TOGGLE_LAYER_COLOR, RGB_SPI, RGB_HUD, RGB_HUI),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
	rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
	[QWERTY] = KEYS_TO_LEDS(
		TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL,                    TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL,
		TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL,                    TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL,
		TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL,                    TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL,
		TEAL, TEAL, TEAL, TEAL, TEAL, TEAL,                                TEAL, TEAL, TEAL, TEAL, TEAL, TEAL,
		TEAL, TEAL, ORNG, TEAL, TEAL,                TEAL, TEAL,                 TEAL, TEAL, TEAL, TEAL, TEAL,
		                                 TEAL, TEAL, TEAL, ORNG, TEAL, TEAL
	),
	[SYM] = KEYS_TO_LEDS(
		ORNG, ORNG, ORNG, ORNG, ORNG, ORNG, ORNG,                    ORNG, ORNG, ORNG, ORNG, ORNG, ORNG, ORNG,
		ORNG, GOLD, TEAL, GOLD, GOLD, BLCK, BLCK,                    BLCK, BLCK, GOLD, GOLD, GOLD, GOLD, ORNG,
		ORNG, TEAL, TEAL, TEAL, GOLD, BLCK, BLCK,                    BLCK, BLCK, BLCK, BLCK, BLCK, BLCK, BLCK,
		BLCK, BLCK, BLCK, BLCK, BLCK, BLCK,                                BLCK, BLCK, BLCK, GOLD, TEAL, GOLD,
		BLCK, BLCK, ORNG, BLCK, BLCK,                BLCK, BLCK,                 BLCK, BLCK, TEAL, TEAL, TEAL,
		                                 BLCK, BLCK, BLCK, ORNG, BLCK, BLCK
	),
	[NAV] = { {10,204,255}, {10,204,255}, {10,204,255}, {10,204,255}, {10,204,255}, {146,224,255}, {10,204,255}, {10,204,255}, {10,204,255}, {10,204,255}, {146,224,255}, {10,204,255}, {10,204,255}, {10,204,255}, {124,255,199}, {146,224,255}, {10,204,255}, {10,204,255}, {10,204,255}, {10,204,255}, {146,224,255}, {10,204,255}, {10,204,255}, {10,204,255}, {10,204,255}, {146,224,255}, {10,204,255}, {10,204,255}, {10,204,255}, {146,224,255}, {10,204,255}, {10,204,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {33,255,255}, {10,204,255}, {10,204,255}, {10,204,255}, {10,204,255}, {146,224,255}, {10,204,255}, {10,204,255}, {10,204,255}, {10,204,255}, {146,224,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,204,255}, {146,224,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,204,255}, {146,224,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,204,255}, {146,224,255}, {10,204,255}, {10,204,255}, {10,204,255}, {146,224,255}, {10,204,255}, {10,204,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255} },

};


void set_layer_color(int layer) {
	for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
		HSV hsv = {
			.h = pgm_read_byte(&ledmap[layer][i][0]),
			.s = pgm_read_byte(&ledmap[layer][i][1]),
			.v = pgm_read_byte(&ledmap[layer][i][2]),
		};
		if (!hsv.h && !hsv.s && !hsv.v) {
			rgb_matrix_set_color( i, 0, 0, 0 );
		} else {
			RGB rgb = hsv_to_rgb( hsv );
			float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
			rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
		}
	}
}

void rgb_matrix_indicators_user(void) {
	switch (biton32(layer_state)) {
	case 0:
		set_layer_color(0);
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
	case RGB_SLD:
		if (record->event.pressed) {
			rgblight_mode(1);
		}
		return false;
	}
	return true;
}

static tap dance_state[10];

void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 3) {
		tap_code16(KC_Z);
		tap_code16(KC_Z);
		tap_code16(KC_Z);
	}
	if (state->count > 3) {
		tap_code16(KC_Z);
	}
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state[0].step = dance_step(state);
	switch (dance_state[0].step) {
		case SINGLE_TAP:
			register_code16(KC_Z);
			break;
		case SINGLE_HOLD:
			register_code16(LCTL(KC_Z));
			break;
		case DOUBLE_TAP:
			register_code16(KC_Z);
			register_code16(KC_Z);
			break;
		case DOUBLE_SINGLE_TAP:
			tap_code16(KC_Z);
			register_code16(KC_Z);
	}
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state[0].step) {
		case SINGLE_TAP:
			unregister_code16(KC_Z);
			break;
		case SINGLE_HOLD:
			unregister_code16(LCTL(KC_Z));
			break;
		case DOUBLE_TAP:
			unregister_code16(KC_Z);
			break;
		case DOUBLE_SINGLE_TAP:
			unregister_code16(KC_Z);
			break;
	}
	dance_state[0].step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 3) {
		tap_code16(KC_X);
		tap_code16(KC_X);
		tap_code16(KC_X);
	}
	if (state->count > 3) {
		tap_code16(KC_X);
	}
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state[1].step = dance_step(state);
	switch (dance_state[1].step) {
		case SINGLE_TAP:
			register_code16(KC_X);
			break;
		case SINGLE_HOLD:
			register_code16(LCTL(KC_X));
			break;
		case DOUBLE_TAP:
			register_code16(KC_X);
			register_code16(KC_X);
			break;
		case DOUBLE_SINGLE_TAP:
			tap_code16(KC_X);
			register_code16(KC_X);
	}
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state[1].step) {
		case SINGLE_TAP:
			unregister_code16(KC_X);
			break;
		case SINGLE_HOLD:
			unregister_code16(LCTL(KC_X));
			break;
		case DOUBLE_TAP:
			unregister_code16(KC_X);
			break;
		case DOUBLE_SINGLE_TAP:
			unregister_code16(KC_X);
			break;
	}
	dance_state[1].step = 0;
}
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 3) {
		tap_code16(KC_C);
		tap_code16(KC_C);
		tap_code16(KC_C);
	}
	if (state->count > 3) {
		tap_code16(KC_C);
	}
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state[2].step = dance_step(state);
	switch (dance_state[2].step) {
		case SINGLE_TAP:
			register_code16(KC_C);
			break;
		case SINGLE_HOLD:
			register_code16(LCTL(KC_C));
			break;
		case DOUBLE_TAP:
			register_code16(KC_C);
			register_code16(KC_C);
			break;
		case DOUBLE_SINGLE_TAP:
			tap_code16(KC_C);
			register_code16(KC_C);
	}
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state[2].step) {
		case SINGLE_TAP:
			unregister_code16(KC_C);
			break;
		case SINGLE_HOLD:
			unregister_code16(LCTL(KC_C));
			break;
		case DOUBLE_TAP:
			unregister_code16(KC_C);
			break;
		case DOUBLE_SINGLE_TAP:
			unregister_code16(KC_C);
			break;
	}
	dance_state[2].step = 0;
}
void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 3) {
		tap_code16(KC_V);
		tap_code16(KC_V);
		tap_code16(KC_V);
	}
	if (state->count > 3) {
		tap_code16(KC_V);
	}
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state[3].step = dance_step(state);
	switch (dance_state[3].step) {
		case SINGLE_TAP:
			register_code16(KC_V);
			break;
		case SINGLE_HOLD:
			register_code16(LCTL(KC_V));
			break;
		case DOUBLE_TAP:
			register_code16(KC_V);
			register_code16(KC_V);
			break;
		case DOUBLE_SINGLE_TAP:
			tap_code16(KC_V);
			register_code16(KC_V);
	}
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state[3].step) {
		case SINGLE_TAP:
			unregister_code16(KC_V);
			break;
		case SINGLE_HOLD:
			unregister_code16(LCTL(KC_V));
			break;
		case DOUBLE_TAP:
			unregister_code16(KC_V);
			break;
		case DOUBLE_SINGLE_TAP:
			unregister_code16(KC_V);
			break;
	}
	dance_state[3].step = 0;
}
void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 3) {
		tap_code16(KC_BSPACE);
		tap_code16(KC_BSPACE);
		tap_code16(KC_BSPACE);
	}
	if (state->count > 3) {
		tap_code16(KC_BSPACE);
	}
}

void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state[4].step = dance_step(state);
	switch (dance_state[4].step) {
		case SINGLE_TAP:
			register_code16(KC_BSPACE);
			break;
		case SINGLE_HOLD:
			register_code16(LCTL(KC_BSPACE));
			break;
		case DOUBLE_TAP:
			register_code16(KC_BSPACE);
			register_code16(KC_BSPACE);
			break;
		case DOUBLE_SINGLE_TAP:
			tap_code16(KC_BSPACE);
			register_code16(KC_BSPACE);
	}
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state[4].step) {
		case SINGLE_TAP:
			unregister_code16(KC_BSPACE);
			break;
		case SINGLE_HOLD:
			unregister_code16(LCTL(KC_BSPACE));
			break;
		case DOUBLE_TAP:
			unregister_code16(KC_BSPACE);
			break;
		case DOUBLE_SINGLE_TAP:
			unregister_code16(KC_BSPACE);
			break;
	}
	dance_state[4].step = 0;
}
void on_dance_5(qk_tap_dance_state_t *state, void *user_data);
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_5_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_5(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 3) {
		tap_code16(KC_U);
		tap_code16(KC_U);
		tap_code16(KC_U);
	}
	if (state->count > 3) {
		tap_code16(KC_U);
	}
}

void dance_5_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state[5].step = dance_step(state);
	switch (dance_state[5].step) {
		case SINGLE_TAP:
			register_code16(KC_U);
			break;
		case DOUBLE_TAP:
			register_code16(KC_LPRN);
			break;
		case DOUBLE_SINGLE_TAP:
			tap_code16(KC_U);
			register_code16(KC_U);
	}
}

void dance_5_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state[5].step) {
		case SINGLE_TAP:
			unregister_code16(KC_U);
			break;
		case DOUBLE_TAP:
			unregister_code16(KC_LPRN);
			break;
		case DOUBLE_SINGLE_TAP:
			unregister_code16(KC_U);
			break;
	}
	dance_state[5].step = 0;
}
void on_dance_6(qk_tap_dance_state_t *state, void *user_data);
void dance_6_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_6_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_6(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 3) {
		tap_code16(KC_0);
		tap_code16(KC_0);
		tap_code16(KC_0);
	}
	if (state->count > 3) {
		tap_code16(KC_0);
	}
}

void dance_6_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state[6].step = dance_step(state);
	switch (dance_state[6].step) {
		case SINGLE_TAP:
			register_code16(KC_0);
			break;
		case DOUBLE_TAP:
			register_code16(KC_RPRN);
			break;
		case DOUBLE_SINGLE_TAP:
			tap_code16(KC_0);
			register_code16(KC_0);
	}
}

void dance_6_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state[6].step) {
		case SINGLE_TAP:
			unregister_code16(KC_0);
			break;
		case DOUBLE_TAP:
			unregister_code16(KC_RPRN);
			break;
		case DOUBLE_SINGLE_TAP:
			unregister_code16(KC_0);
			break;
	}
	dance_state[6].step = 0;
}
void on_dance_7(qk_tap_dance_state_t *state, void *user_data);
void dance_7_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_7_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_7(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 3) {
		tap_code16(KC_O);
		tap_code16(KC_O);
		tap_code16(KC_O);
	}
	if (state->count > 3) {
		tap_code16(KC_O);
	}
}

void dance_7_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state[7].step = dance_step(state);
	switch (dance_state[7].step) {
		case SINGLE_TAP:
			register_code16(KC_O);
			break;
		case DOUBLE_TAP:
			register_code16(KC_LBRACKET);
			break;
		case DOUBLE_SINGLE_TAP:
			tap_code16(KC_O);
			register_code16(KC_O);
	}
}

void dance_7_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state[7].step) {
		case SINGLE_TAP:
			unregister_code16(KC_O);
			break;
		case DOUBLE_TAP:
			unregister_code16(KC_LBRACKET);
			break;
		case DOUBLE_SINGLE_TAP:
			unregister_code16(KC_O);
			break;
	}
	dance_state[7].step = 0;
}
void on_dance_8(qk_tap_dance_state_t *state, void *user_data);
void dance_8_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_8_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_8(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 3) {
		tap_code16(KC_P);
		tap_code16(KC_P);
		tap_code16(KC_P);
	}
	if (state->count > 3) {
		tap_code16(KC_P);
	}
}

void dance_8_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state[8].step = dance_step(state);
	switch (dance_state[8].step) {
		case SINGLE_TAP:
			register_code16(KC_P);
			break;
		case DOUBLE_TAP:
			register_code16(KC_RBRACKET);
			break;
		case DOUBLE_SINGLE_TAP:
			tap_code16(KC_P);
			register_code16(KC_P);
	}
}

void dance_8_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state[8].step) {
		case SINGLE_TAP:
			unregister_code16(KC_P);
			break;
		case DOUBLE_TAP:
			unregister_code16(KC_RBRACKET);
			break;
		case DOUBLE_SINGLE_TAP:
			unregister_code16(KC_P);
			break;
	}
	dance_state[8].step = 0;
}
void dance_9_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_9_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_9_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state[9].step = dance_step(state);
	switch (dance_state[9].step) {
		case SINGLE_HOLD:
			layer_on(2);
			break;
		case DOUBLE_TAP:
			layer_move(2);
			break;
	}
}

void dance_9_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state[9].step) {
		case SINGLE_HOLD:
			layer_off(2);
			break;
	}
	dance_state[9].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
	[DANCE_Z] = TAP_HOLD_DANCE(0, KC_Z, LCTL(KC_Z)),
	[DANCE_X] = TAP_HOLD_DANCE(1, KC_X, LCTL(KC_X)),
	[DANCE_C] = TAP_HOLD_DANCE(2, KC_C, LCTL(KC_C)),
	[DANCE_V] = TAP_HOLD_DANCE(3, KC_V, LCTL(KC_V)),
	[DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
	[DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
	[DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
	[DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
	[DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
	[DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_9_finished, dance_9_reset),
};
