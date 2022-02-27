LTO_ENABLE = no    	       # link time optimization -- achieves a smaller compiled size
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = yes
LEADER_ENABLE = yes
RGB_MATRIX_ENABLE = yes
VIA_ENABLE = no
TAP_DANCE_ENABLE = yes
BOOTMAGIC_ENABLE = yes         # Enable Bootmagic Lite
DYNAMIC_MACRO_ENABLE = yes
IDLE_TIMEOUT_ENABLE = yes
STARTUP_NUMLOCK_ON = yes
ENCODER_DEFAULTACTIONS_ENABLE = no
STARTUP_NUMLOCK_ON = yes
INVERT_NUMLOCK_INDICATOR = yes

SRC += features/caps_word.c
SRC += features/autocorrection.c