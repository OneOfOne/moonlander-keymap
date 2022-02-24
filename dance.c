#include "dance.h"

#define GET_IDX uint16_t idx = ((keycode_data_t*)user_data)->idx;
#define GET_TAP_KEY uint16_t tapKC = ((keycode_data_t*)user_data)->tap;
#define GET_HOLD_KEY uint16_t holdKC = ((keycode_data_t*)user_data)->hold;

static tap dance_tap_hold_state[10];

uint8_t dance_step(qk_tap_dance_state_t *state) {
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

void dance_tap_hold(qk_tap_dance_state_t *state, void *user_data) {
	GET_TAP_KEY

	if (state->count == 3) {
		tap_code16(tapKC);
		tap_code16(tapKC);
		tap_code16(tapKC);
	}
	if (state->count > 3) {
		tap_code16(tapKC);
	}
}

void dance_tap_hold_finished(qk_tap_dance_state_t *state, void *user_data) {
	GET_IDX
	GET_TAP_KEY
	GET_HOLD_KEY

	dance_tap_hold_state[idx].step = dance_step(state);

	switch (dance_tap_hold_state[idx].step) {
		case SINGLE_TAP:
			register_code16(tapKC);
			break;
		case SINGLE_HOLD:
			register_code16(holdKC);
			break;
		case DOUBLE_TAP:
			register_code16(tapKC);
			register_code16(tapKC);
			break;
		case DOUBLE_SINGLE_TAP:
			tap_code16(tapKC);
			register_code16(tapKC);
	}
}

void dance_tap_hold_reset(qk_tap_dance_state_t *state, void *user_data) {
	GET_IDX;
	GET_TAP_KEY
	GET_HOLD_KEY

	wait_ms(10);
	switch (dance_tap_hold_state[idx].step) {
		case SINGLE_TAP:
			unregister_code16(tapKC);
			break;
		case SINGLE_HOLD:
			unregister_code16(holdKC);
			break;
		case DOUBLE_TAP:
			unregister_code16(tapKC);
			break;
		case DOUBLE_SINGLE_TAP:
			unregister_code16(tapKC);
			break;
	}
	dance_tap_hold_state[idx].step = 0;
}
