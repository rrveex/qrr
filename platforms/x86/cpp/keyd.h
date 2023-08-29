
/*
 * keyd - A key remapping daemon.
 *
 * © 2019 Raheman Vaiya (see also: LICENSE).
 */
#ifndef DEVICE_H
#define DEVICE_H

#include <stdint.h>
#include <string>
#include <map>

extern std::map<std::string, int>  keyNameToCode;
extern std::map<uint8_t, uint16_t> qmkToLinux;

void xwrite(int fd, const void *buf, size_t sz);
void xread(int fd, void *buf, size_t sz);
int  create_keyboard();
int  create_mouse();
void write_key_event(const int fd, uint16_t code, int val);
void sync(int fd);

// row-column index pair
struct rc {
    int r;
    int c;
};

#define CAP_MOUSE 0x1
#define CAP_MOUSE_ABS 0x2
#define CAP_KEYBOARD 0x4

#define MAX_DEVICES 64

struct device {
    /*
     * A file descriptor that can be used to monitor events subsequently read with
     * device_read_event().
     */
    int fd;

    uint8_t  grabbed;
    uint8_t  capabilities;
    uint16_t product_id;
    uint16_t vendor_id;

    char name[64];
    char path[256];

    /* Internal. */
    uint32_t _maxx;
    uint32_t _maxy;
    uint32_t _minx;
    uint32_t _miny;

    /* Reserved for the user. */
    void *data;
};

struct device_event {
    enum {
        DEV_KEY,

        DEV_MOUSE_MOVE,
        /* All absolute values are relative to a resolution of 1024x1024. */
        DEV_MOUSE_MOVE_ABS,
        DEV_MOUSE_SCROLL,

        DEV_REMOVED,
    } type;

    uint8_t  code;
    uint8_t  pressed;
    uint32_t x;
    uint32_t y;
};

struct device_event *device_read_event(struct device *dev);

int device_scan(struct device devices[MAX_DEVICES]);
int device_grab(int fd);
int device_ungrab(struct device *dev);

int  devmon_create();
int  devmon_read_device(int fd, struct device *dev);
void device_set_led(const struct device *dev, int led, int state);

#endif
