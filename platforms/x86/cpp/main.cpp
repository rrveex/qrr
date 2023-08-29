#include <cstring>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <map>
#include <linux/input-event-codes.h>
#include <linux/input.h>
#include <fcntl.h>
#include <unistd.h>
#include "keyd.h"
#include "report.h"
#include "matrix.h"

// defined in keyboards/$(KB)/layout.cpp
extern std::vector<std::string> layout;
extern std::string              kbName;
extern std::vector<std::string> kbBlacklist;

struct device device_table[MAX_DEVICES];
size_t        device_table_sz;

uint16_t catrix[MATRIX_ROWS];
int      fdKeyb, fdMouse;

uint16_t modarr[] = {KEY_LEFTCTRL,  KEY_LEFTSHIFT,  KEY_LEFTALT,  KEY_LEFTMETA, //
                     KEY_RIGHTCTRL, KEY_RIGHTSHIFT, KEY_RIGHTALT, KEY_RIGHTMETA};

extern "C" {

uint8_t host_keyboard_leds(void) {
    return 0;
}
void matrix_read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    // matrix_row_t current_row_value = getMatrixRow(current_row);
    // current_matrix[current_row] = current_row_value;
    current_matrix[current_row] = catrix[current_row];
}
uint16_t getMatrixRow(uint8_t row) {
    return catrix[row];
}

void host_keyboard_send(report_keyboard_t *report) {
    static report_keyboard_t oldReport = {0};
    sync(fdKeyb);
    if (report->mods != oldReport.mods) {
        for (int i = 0; i < 8; i++) {
            int curmod = (report->mods & (1 << i)) >> i;
            int oldmod = (oldReport.mods & (1 << i)) >> i;
            if (curmod == oldmod) continue;
            write_key_event(fdKeyb, modarr[i], curmod);
        }
    }
    for (int i = 0; i < 6; i++) {
        uint16_t linKey = 0;
        int32_t  val    = 0;
        if (report->keys[i] == oldReport.keys[i]) continue;
        if (report->keys[i] == 0) {
            linKey = qmkToLinux[oldReport.keys[i]];
        } else if (oldReport.keys[i] == 0) {
            val    = 1;
            linKey = qmkToLinux[report->keys[i]];
        } else {
            printf("error keys!\n");
            _exit(-1);
        }
        if (linKey == 0) {
            printf("linKey == 0!\n");
            _exit(-1);
        }
        write_key_event(fdKeyb, linKey, val);
    }
    sync(fdKeyb);
    std::memcpy(&oldReport, report, sizeof(report_keyboard_t));
}

uint16_t btnarr[] = {BTN_LEFT, BTN_RIGHT, BTN_MIDDLE};

void host_mouse_send(report_mouse_t *report) {
    // std::cout << "host_mouse_send..." << std::endl;
    static uint8_t oldBtns = 0;
    sync(fdMouse);
    uint8_t btns = report->buttons;
    if (btns != oldBtns) {
        for (int i = 0; i < 3; i++) {
            int32_t curbtn = (btns & (1 << i)) >> i;
            int32_t oldbtn = (oldBtns & (1 << i)) >> i;
            if (curbtn == oldbtn) continue;
            write_key_event(fdMouse, btnarr[i], curbtn);
        }
    }

    sync(fdMouse);
    oldBtns = btns;
}
}

std::map<uint16_t, rc> rowcol;

std::vector<std::string> split(const char *str, char c = ' ') {
    std::vector<std::string> result;

    do {
        const char *begin = str;
        while (*str != c && *str)
            str++;

        result.push_back(std::string(begin, str));
    } while (0 != *str++);

    return result;
}

bool strInVect(const std::string &s, const std::vector<std::string> &v) {
    for (auto i : v) {
        if (s.find(i) != std::string::npos) {
            return true;
        }
    }
    return false;
}

void read_task(int fd) {
    while (1) {
        struct input_event ev;
        ssize_t            bytes;
        if ((bytes = read(fd, &ev, sizeof(ev))) != sizeof(ev)) {
            fprintf(stderr, "read bytes: %ld\n", bytes);
            _exit(-1);
        }
        if (ev.type == EV_KEY) {
            // printf("type %d key %d val %d\n", ev.type, ev.code, ev.value);
            auto row = rowcol[ev.code].r;
            auto col = rowcol[ev.code].c;
            // std::cout << "row: " << row << " col: " << col << std::endl;
            if (row >= 0) {
                uint16_t mask = 1 << col;
                if (ev.value == 0) {
                    catrix[row] &= ~mask;
                } else {
                    catrix[row] |= mask;
                }
            }
        }
    }
}

extern "C" {
void protocol_setup() {
    // fillRowCol
    for (int r = 0; r < layout.size(); r++) {
        std::string matRow = layout[r];
        auto        names  = split(matRow.c_str());
        for (int c = 0; c < names.size(); c++) {
            std::string keyName = names[c];
            auto        keyVal  = keyNameToCode[keyName];
            rowcol[keyVal]      = {r, c};
        }
    }

    device_table_sz = device_scan(device_table);

    std::string path;

    for (int i = 0; i < device_table_sz; i++) {
        if (!(device_table[i].capabilities & CAP_KEYBOARD)) {
            continue;
        }
        std::string name = device_table[i].name;
        if (name.find(kbName) == std::string::npos) {
            continue;
        }
        if (strInVect(name, kbBlacklist)) {
            std::cout << name << " in blacklist, continue" << std::endl;
            continue;
        }

        std::cout << "____ keyboard dev: " << device_table[i].name << std::endl;
        path = device_table[i].path;
        break;
    }

    if (!path.size()) {
        std::cerr << "device not found" << std::endl;
        _exit(-1);
    }
    // open uinput devs
    fdKeyb  = create_keyboard();
    fdMouse = create_mouse();
    if (!fdKeyb || !fdMouse) {
        std::cerr << "failed to create uinput" << std::endl;
        _exit(-1);
    }
    // open input device
    int fd;
    if ((fd = open(path.c_str(), O_RDWR | O_CLOEXEC, 0600)) < 0) {
        std::cerr << "failed to open " << path << std::endl;
        exit(-1);
    }
    if (device_grab(fd) != 0) {
        std::cerr << "failed to grab" << std::endl;
        exit(-1);
    }
    std::cout << "starting read thread" << std::endl;
    // std::thread read_thread(read_task, fd);
    // read_thread.join();
    new std::thread(read_task, fd);
}
}
