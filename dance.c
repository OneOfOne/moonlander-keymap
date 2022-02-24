#include "dance.h"


void dance_on_tap_hold(qk_tap_dance_state_t *state, void *user_data) {
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

void dance_on_tap_hold_finished(qk_tap_dance_state_t *state, void *user_data) {

}
void dance_on_tap_hold_reset(qk_tap_dance_state_t *state, void *user_data);
