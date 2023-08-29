
KB_DIR = lenix
MATRIX = -DMATRIX_ROWS=13 -DMATRIX_COLS=14 

# KB_DIR = micro
# MATRIX = -DMATRIX_ROWS=6 -DMATRIX_COLS=16

QMKSETTINGS = -DTAPPING_TERM=155 -DIGNORE_MOD_TAP_INTERRUPT 
# -DPERMISSIVE_HOLD -DTAPPING_FORCE_HOLD -DHOLD_ON_OTHER_KEY_PRESS 

# --- ^^^ user settings ^^^ ---

all: exe

CFLAGS = -I. \
		 -Iplatforms \
		 -Iplatforms/x86 \
		 -Itmk_core/protocol \
		 -Iquantum -Iquantum/logging \
		 -Iquantum/keymap_extras \
		 -Iquantum/bootmagic \
		 -Iquantum/process_keycode \
		 -Itmk_core/protocol \
		 -DEEPROM_CUSTOM \
		 -DEEPROM_SIZE=1024 \
		 -DIGNORE_ATOMIC_BLOCK \
		 -DNO_DEBUG \
		 -DMOUSE_ENABLE \
		 -DDIODE_DIRECTION=0 \
		 -DKEY_OVERRIDE_ENABLE \
		 -DCOMBO_ENABLE \
		 -DKEYMAP_C=\"keyboards/$(KB_DIR)/keymap.c\" \
		 -DMOUSEKEY_ENABLE \
		 $(QMKSETTINGS) \
		 $(MATRIX)

CPPFLAGS = -Iplatforms -Iplatforms/x86/cpp -Itmk_core/protocol -Iquantum $(MATRIX) 

cpplib:
	g++ $(CPPFLAGS) -c \
		platforms/x86/cpp/main.cpp \
		platforms/x86/cpp/keyd.cpp \
		platforms/x86/cpp/util.cpp \
		platforms/x86/cpp/keynames.cpp \
		platforms/x86/cpp/uinput.cpp \
		keyboards/$(KB_DIR)/layout.cpp
	ar rs libcpp.a main.o keyd.o util.o keynames.o uinput.o layout.o

exe: cpplib
	gcc $(CFLAGS) -c \
		quantum/main.c quantum/bitwise.c quantum/action.c \
		quantum/action_layer.c quantum/action_tapping.c \
		quantum/action_util.c quantum/bootmagic/magic.c \
		quantum/debounce/none.c quantum/eeconfig.c \
		quantum/keyboard.c quantum/keymap_common.c \
		quantum/keymap_introspection.c quantum/keycode_config.c \
		quantum/led.c quantum/matrix.c quantum/matrix_common.c \
		quantum/mousekey.c quantum/quantum.c quantum/logging/sendchar.c \
		quantum/logging/debug.c quantum/logging/print.c \
		quantum/process_keycode/process_combo.c \
		quantum/process_keycode/process_key_override.c \
		tmk_core/protocol/report.c platforms/x86/eeprom.c \
		platforms/x86/timer.c keyboards/$(KB_DIR)/kb.c
	ar rs libqmk.a main.o bitwise.o action.o action_layer.o action_tapping.o \
		action_util.o magic.o none.o eeconfig.o keyboard.o keymap_common.o \
		keymap_introspection.o keycode_config.o led.o matrix.o matrix_common.o \
		mousekey.o quantum.o sendchar.o debug.o print.o process_combo.o \
		process_key_override.o report.o eeprom.o timer.o kb.o
	g++ -o qrr libqmk.a libcpp.a

clean:
	rm -f quantum/*.o tmk_core/*.o platforms/x86/*.o *.o *.a qrr
