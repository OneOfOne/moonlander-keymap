/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define USB_SUSPEND_WAKEUP_DELAY 0
#define NO_AUTO_SHIFT_TAB
#define NO_AUTO_SHIFT_ALPHA
#define FIRMWARE_VERSION u8"oneofone/moonlander"
#define RGB_MATRIX_STARTUP_SPD 60

#define USB_POLLING_INTERVAL_MS 1

#define LEADER_TIMEOUT 500

#undef TAPPING_TERM
#define TAPPING_TERM 200
#define RETRO_TAPPING
#define IGNORE_MOD_TAP_INTERRUPT

#define TAP_CODE_DELAY 0
#define TAP_HOLD_CAPS_DELAY 0

#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 1000

#define QMK_KEYS_PER_SCAN 10

#define FORCE_NKRO

#undef DEBOUNCE
#define DEBOUNCE 0

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
