#include "dance.h"

#define GET_UD keycode_data_t* ud = ((keycode_data_t*)user_data);

uint8_t dance_step(tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) return SINGLE_TAP;
		else return SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted) return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else return DOUBLE_TAP;
	}
	return MORE_TAPS;
}

void dance_each(tap_dance_state_t *state, void *user_data) {
	GET_UD

	if (state->count == 3) {
		tap_code16(ud->tap);
		tap_code16(ud->tap);
		tap_code16(ud->tap);
	}
	if (state->count > 3) {
		tap_code16(ud->tap);
	}
}

void dance_tap_hold_dtap_finished(tap_dance_state_t *state, void *user_data) {
	GET_UD

	ud->step = dance_step(state);

	switch (ud->step) {
		case SINGLE_TAP:
			register_code16(ud->tap);
			break;
		case SINGLE_HOLD:
			if (ud->hold) {
				register_code16(ud->hold);
			}
			break;
		case DOUBLE_TAP:
			if (ud->dtap) {
				register_code16(ud->dtap);
			} else {
				register_code16(ud->tap);
				register_code16(ud->tap);
			}
			break;
		case DOUBLE_SINGLE_TAP:
			tap_code16(ud->tap);
			register_code16(ud->tap);
	}
}

void dance_tap_hold_dtap_reset(tap_dance_state_t *state, void *user_data) {
	GET_UD

	wait_ms(1);
	switch (ud->step) {
		case SINGLE_TAP:
			unregister_code16(ud->tap);
			break;
		case SINGLE_HOLD:
			if (ud->hold) {
				unregister_code16(ud->hold);
			}
			break;
		case DOUBLE_TAP:
			if (ud->dtap) {
				unregister_code16(ud->dtap);
			} else {
				unregister_code16(ud->tap);
			}
			break;
		case DOUBLE_SINGLE_TAP:
			unregister_code16(ud->tap);
			break;
	}
	ud->step = 0;
}
