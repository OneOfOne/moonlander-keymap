/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
// #define ORYX_CONFIGURATOR
#define USB_SUSPEND_WAKEUP_DELAY 0
#define NO_AUTO_SHIFT_TAB
#define NO_AUTO_SHIFT_ALPHA
#define FIRMWARE_VERSION u8"oneofone/moonlander"
#define RGB_MATRIX_STARTUP_SPD 60

#define USB_POLLING_INTERVAL_MS 1

#define LEADER_TIMEOUT 1000

#undef TAPPING_TERM
#define TAPPING_TERM 150
// #define RETRO_TAPPING
#define IGNORE_MOD_TAP_INTERRUPT

#define TAP_CODE_DELAY 0
#define TAP_HOLD_CAPS_DELAY 0

#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 1000

#define QMK_KEYS_PER_SCAN 4

#define FORCE_NKRO

#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT
#define NO_AUTO_SHIFT_TAB
#define NO_AUTO_SHIFT_ALPHA
#define HOLD_ON_OTHER_KEY_PRESS

#undef DEBOUNCE
#define DEBOUNCE 5

#undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#define RGB_MATRIX_HUE_STEP 8
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 10
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS

#define _CHIBIOS_HAL_CONF_VER_7_1_
#define _CHIBIOS_RT_CONF_VER_6_1_
