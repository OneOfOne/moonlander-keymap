# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
AUTO_SHIFT_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no

VIA_ENABLE = no
WEBUSB_ENABLE = no
ORYX_ENABLE = no
AUDIO_ENABLE = no

MOUSEKEY_ENABLE = no
KEY_LOCK_ENABLE = no
TAP_DANCE_ENABLE = no
LEADER_ENABLE = yes
CIE1931_CURVE = yes

LTO_ENABLE = yes
#DEBOUNCE_TYPE = sym_eager_pk
# DEBOUNCE_TYPE = asym_eager_defer_pk
DEBOUNCE_TYPE = sym_eager_pk

ALLOW_WARNINGS = yes
# SRC += dance.c
