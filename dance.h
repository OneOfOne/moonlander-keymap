#pragma once

#include "moonlander.h"

typedef struct {
	bool is_press_action;
	uint8_t step;
} tap;

enum {
	SINGLE_TAP = 1,
	SINGLE_HOLD,
	DOUBLE_TAP,
	DOUBLE_HOLD,
	DOUBLE_SINGLE_TAP,
	MORE_TAPS
};

typedef struct {
	uint16_t idx;
	uint16_t tap;
	uint16_t hold;
} keycode_data_t;

#define ACTION_TAP_DANCE_ADV_KEY(user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset, key) \
	{ .fn = {user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset}, .user_data = (void*)&((keycode_data_t){0, key, 0}), }

#define ACTION_TAP_DANCE_ADV_TAPHOLD(user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset, idx, tap, hold) \
	{ .fn = {user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset}, .user_data = (void*)&((keycode_data_t){idx, tap, hold}), }

#define TAP_HOLD_DANCE(idx, tap, hold) \
	ACTION_TAP_DANCE_ADV_TAPHOLD(dance_tap_hold, dance_tap_hold_finished, dance_tap_hold_reset, idx, tap, hold)

uint8_t dance_step(qk_tap_dance_state_t *state);
void dance_tap_hold(qk_tap_dance_state_t *state, void *user_data);
void dance_tap_hold_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_tap_hold_reset(qk_tap_dance_state_t *state, void *user_data);
