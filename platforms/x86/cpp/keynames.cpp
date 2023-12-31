#include <map>
#include <string>
#include <stddef.h>
#include <stdint.h>
#include <linux/input-event-codes.h>

std::map<std::string, uint16_t> keyNameToCode = {
    {"esc", KEY_ESC},
    {"1", KEY_1},
    {"2", KEY_2},
    {"3", KEY_3},
    {"4", KEY_4},
    {"5", KEY_5},
    {"6", KEY_6},
    {"7", KEY_7},
    {"8", KEY_8},
    {"9", KEY_9},
    {"0", KEY_0},
    {"-", KEY_MINUS},
    {"=", KEY_EQUAL},
    {"bksp", KEY_BACKSPACE},
    {"tab", KEY_TAB},
    {"q", KEY_Q},
    {"w", KEY_W},
    {"e", KEY_E},
    {"r", KEY_R},
    {"t", KEY_T},
    {"y", KEY_Y},
    {"u", KEY_U},
    {"i", KEY_I},
    {"o", KEY_O},
    {"p", KEY_P},
    {"[", KEY_LEFTBRACE},
    {"]", KEY_RIGHTBRACE},
    {"ent", KEY_ENTER},
    {"lctl", KEY_LEFTCTRL},
    {"a", KEY_A},
    {"s", KEY_S},
    {"d", KEY_D},
    {"f", KEY_F},
    {"g", KEY_G},
    {"h", KEY_H},
    {"j", KEY_J},
    {"k", KEY_K},
    {"l", KEY_L},
    {";", KEY_SEMICOLON},
    {"'", KEY_APOSTROPHE},
    {"`", KEY_GRAVE},
    {"lsft", KEY_LEFTSHIFT},
    {"\\", KEY_BACKSLASH},
    {"z", KEY_Z},
    {"x", KEY_X},
    {"c", KEY_C},
    {"v", KEY_V},
    {"b", KEY_B},
    {"n", KEY_N},
    {"m", KEY_M},
    {",", KEY_COMMA},
    {".", KEY_DOT},
    {"/", KEY_SLASH},
    {"rsft", KEY_RIGHTSHIFT},
    {"lalt", KEY_LEFTALT},
    {"sp", KEY_SPACE},
    {"cps", KEY_CAPSLOCK},
    {"num", KEY_NUMLOCK},
    {"kp/", KEY_KPSLASH},
    {"kp*", KEY_KPASTERISK},
    {"kp-", KEY_KPMINUS},
    {"kp7", KEY_KP7},
    {"kp8", KEY_KP8},
    {"kp9", KEY_KP9},
    {"kp+", KEY_KPPLUS},
    {"kp4", KEY_KP4},
    {"kp5", KEY_KP5},
    {"kp6", KEY_KP6},
    {"kp1", KEY_KP1},
    {"kp2", KEY_KP2},
    {"kp3", KEY_KP3},
    {"kpe", KEY_KPENTER},
    {"kp0", KEY_KP0},
    {"kp.", KEY_KPDOT},
    {"f1", KEY_F1},
    {"f2", KEY_F2},
    {"f3", KEY_F3},
    {"f4", KEY_F4},
    {"f5", KEY_F5},
    {"f6", KEY_F6},
    {"f7", KEY_F7},
    {"f8", KEY_F8},
    {"f9", KEY_F9},
    {"f10", KEY_F10},
    {"f11", KEY_F11},
    {"f12", KEY_F12},
    {"home", KEY_HOME},
    {"pgup", KEY_PAGEUP},
    {"pgdn", KEY_PAGEDOWN},
    {"end", KEY_END},
    {"left", KEY_LEFT},
    {"down", KEY_DOWN},
    {"up", KEY_UP},
    {"right", KEY_RIGHT},
    {"rctl", KEY_RIGHTCTRL},
    {"ralt", KEY_RIGHTALT},
    {"ins", KEY_INSERT},
    {"del", KEY_DELETE},
    {"mute", KEY_MUTE},
    {"volu", KEY_VOLUMEDOWN},
    {"vold", KEY_VOLUMEUP},
    {"lgui", KEY_LEFTMETA},
    {"rgui", KEY_RIGHTMETA},
    {"print", KEY_SYSRQ},
    {"nop", KEY_MAX},
};
// clang-format off

std::map<uint8_t, uint16_t> qmkToLinux = {
    {0x29, KEY_ESC},
    {0x1e, KEY_1},
    {0x1f, KEY_2},
    {0x20, KEY_3},
    {0x21, KEY_4},
    {0x22, KEY_5},
    {0x23, KEY_6},
    {0x24, KEY_7},
    {0x25, KEY_8},
    {0x26, KEY_9},
    {0x27, KEY_0},
    {0x2d, KEY_MINUS},
    {0x2e, KEY_EQUAL},
    {0x2a, KEY_BACKSPACE},
    {0x2b, KEY_TAB},
    {0x14, KEY_Q},
    {0x1a, KEY_W},
    {0x08, KEY_E},
    {0x15, KEY_R},
    {0x17, KEY_T},
    {0x1c, KEY_Y},
    {0x18, KEY_U},
    {0x0c, KEY_I},
    {0x12, KEY_O},
    {0x13, KEY_P},
    {0x2f, KEY_LEFTBRACE},
    {0x30, KEY_RIGHTBRACE},
    {0x28, KEY_ENTER},
    {0xe0, KEY_LEFTCTRL},
    {0x04, KEY_A},
    {0x16, KEY_S},
    {0x07, KEY_D},
    {0x09, KEY_F},
    {0x0a, KEY_G},
    {0x0b, KEY_H},
    {0x0d, KEY_J},
    {0x0e, KEY_K},
    {0x0f, KEY_L},
    {0x33, KEY_SEMICOLON},
    {0x34, KEY_APOSTROPHE},
    {0x35, KEY_GRAVE},
    {0xe1, KEY_LEFTSHIFT},
    {0x31, KEY_BACKSLASH},
    {0x1d, KEY_Z},
    {0x1b, KEY_X},
    {0x06, KEY_C},
    {0x19, KEY_V},
    {0x05, KEY_B},
    {0x11, KEY_N},
    {0x10, KEY_M},
    {0x36, KEY_COMMA},
    {0x37, KEY_DOT},
    {0x38, KEY_SLASH},
    {0xe5, KEY_RIGHTSHIFT},
    {0xe2, KEY_LEFTALT},
    {0x2c, KEY_SPACE},
    {0x39, KEY_CAPSLOCK},
    {0x53, KEY_NUMLOCK},
    {0x54, KEY_KPSLASH},
    {0x55, KEY_KPASTERISK},
    {0x56, KEY_KPMINUS},
    {0x5f, KEY_KP7},
    {0x60, KEY_KP8},
    {0x61, KEY_KP9},
    {0x57, KEY_KPPLUS},
    {0x5c, KEY_KP4},
    {0x5d, KEY_KP5},
    {0x5e, KEY_KP6},
    {0x59, KEY_KP1},
    {0x5a, KEY_KP2},
    {0x5b, KEY_KP3},
    {0x58, KEY_KPENTER},
    {0x62, KEY_KP0},
    {0x85, KEY_KPDOT},
    {0x3a, KEY_F1},
    {0x3b, KEY_F2},
    {0x3c, KEY_F3},
    {0x3d, KEY_F4},
    {0x3e, KEY_F5},
    {0x3f, KEY_F6},
    {0x40, KEY_F7},
    {0x41, KEY_F8},
    {0x42, KEY_F9},
    {0x43, KEY_F10},
    {0x44, KEY_F11},
    {0x45, KEY_F12},
    {0x4a, KEY_HOME},
    {0x4b, KEY_PAGEUP},
    {0x4e, KEY_PAGEDOWN},
    {0x4d, KEY_END},
    {0x50, KEY_LEFT},
    {0x51, KEY_DOWN},
    {0x52, KEY_UP},
    {0x4f, KEY_RIGHT},
    {0xe4, KEY_RIGHTCTRL},
    {0xe6, KEY_RIGHTALT},
    {0x49, KEY_INSERT},
    {0x4c, KEY_DELETE},
    {0x7f, KEY_MUTE},
    {0x81, KEY_VOLUMEDOWN},
    {0x80, KEY_VOLUMEUP},
    {0xe3, KEY_LEFTMETA},
    {0xe7, KEY_RIGHTMETA},
    {0x9a, KEY_SYSRQ},
};
// clang-format on
