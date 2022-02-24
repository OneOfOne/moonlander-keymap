#pragma once

typedef struct {
	uint16_t tap;
	uint16_t hold;
} keycode_data_t;

#define ACTION_TAP_DANCE_ADV_KEY(user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset, key) \
	{ .fn = {user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset}, .user_data = (void*)&((keycode_data_t){key, 0}), }

#define ACTION_TAP_DANCE_ADV_TAPHOLD(user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset, tap, hold) \
	{ .fn = {user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset}, .user_data = (void*)&((keycode_data_t){tap, hold}), }

#define GET_TAP_KEY uint16_t tapKC = ((keycode_data_t*)user_data)->tap;
#define GET_HOLD_KEY uint16_t holdKC = ((keycode_data_t*)user_data)->hold;

void dance_on_tap_hold(qk_tap_dance_state_t *state, void *user_data);
void dance_on_tap_hold_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_on_tap_hold_reset(qk_tap_dance_state_t *state, void *user_data);
