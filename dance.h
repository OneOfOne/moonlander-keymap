#pragma once

#include <stdint.h>
#ifndef TAP_DANCE_ENABLE
#    define TAP_DANCE_ENABLE
#endif

#include "moonlander.h"

typedef struct {
    bool    is_press_action;
    uint8_t step;
} tap;

enum { SINGLE_TAP = 1, SINGLE_HOLD, DOUBLE_TAP, DOUBLE_HOLD, DOUBLE_SINGLE_TAP, MORE_TAPS };

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t dtap;
    uint8_t  step;
} keycode_data_t;

#define ACTION_TAP_DANCE_ADV_CUSTOM(user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset, tap, hold, dtap) \
    { .fn = {user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset}, .user_data = (void *)&((keycode_data_t){tap, hold, dtap, 0}), }

#define TAP_HOLD_DANCE(tap, hold) ACTION_TAP_DANCE_ADV_CUSTOM(dance_each, dance_tap_hold_dtap_finished, dance_tap_hold_dtap_reset, tap, hold, 0)

#define TAP_HOLD_DTAP_DANCE(tap, hold, dtap) ACTION_TAP_DANCE_ADV_CUSTOM(dance_each, dance_tap_hold_dtap_finished, dance_tap_hold_dtap_reset, tap, hold, dtap)

#define TAP_DTAP_DANCE(tap, dtap) ACTION_TAP_DANCE_ADV_CUSTOM(dance_each, dance_tap_hold_dtap_finished, dance_tap_hold_dtap_reset, tap, 0, dtap)

uint8_t dance_step(tap_dance_state_t *state);
void    dance_each(tap_dance_state_t *state, void *user_data);
void    dance_tap_hold_dtap_finished(tap_dance_state_t *state, void *user_data);
void    dance_tap_hold_dtap_reset(tap_dance_state_t *state, void *user_data);
