# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
AUTO_SHIFT_ENABLE = no
MOUSEKEY_ENABLE = no

WEBUSB_ENABLE = yes
ORYX_ENABLE = yes
TAP_DANCE_ENABLE = yes
LEADER_ENABLE = yes
AUDIO_ENABLE = yes

LTO_ENABLE = yes
DEBOUNCE_TYPE = asym_eager_defer_pk

SRC += dance.c
