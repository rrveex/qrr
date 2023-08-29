/*
 * keyd - A key remapping daemon.
 *
 * © 2019 Raheman Vaiya (see also: LICENSE).
 */

#include <errno.h>
#include <fcntl.h>
#include <linux/uinput.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>
#include "keyd.h"

#ifdef __FreeBSD__
#    include <dev/evdev/input-event-codes.h>
#else
#    include <linux/input-event-codes.h>
#endif

int create_keyboard() {
    int                    ret;
    size_t                 code;
    struct uinput_user_dev udev = {0};

    int fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK | O_CLOEXEC);
    if (fd < 0) {
        perror("open uinput");
        _exit(-1);
    }

    if (ioctl(fd, UI_SET_EVBIT, EV_KEY)) {
        perror("ioctl set_evbit");
        _exit(-1);
    }

    if (ioctl(fd, UI_SET_EVBIT, EV_SYN)) {
        perror("ioctl set_evbit");
        _exit(-1);
    }

    for (code = 0; code < 240; code++) {
        if (ioctl(fd, UI_SET_KEYBIT, code)) {
            perror("ioctl set_keybit");
            _exit(-1);
        }
    }

    udev.id.bustype = BUS_VIRTUAL;
    udev.id.vendor  = 0x1a;
    udev.id.product = 0x1b;

    snprintf(udev.name, sizeof(udev.name), "%s", "qrr keyboard");

    /*
     * We use this in favour of the newer UINPUT_DEV_SETUP
     * ioctl in order to support older kernels.
     *
     * See: https://github.com/torvalds/linux/commit/052876f8e5aec887d22c4d06e54aa5531ffcec75
     */
    ret = write(fd, &udev, sizeof udev);

    if (ret < 0) {
        fprintf(stderr, "failed to create uinput device\n");
        _exit(-1);
    }

    if (ioctl(fd, UI_DEV_CREATE)) {
        perror("ioctl dev_create");
        _exit(-1);
    }

    return fd;
}

int create_mouse() {
    uint16_t               code;
    struct uinput_user_dev udev = {0};

    int fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK | O_CLOEXEC);
    if (fd < 0) {
        perror("open");
        _exit(-1);
    }

    ioctl(fd, UI_SET_EVBIT, EV_REL);
    ioctl(fd, UI_SET_EVBIT, EV_KEY);
    ioctl(fd, UI_SET_EVBIT, EV_SYN);

    // ioctl(fd, UI_SET_ABSBIT, ABS_X);
    // ioctl(fd, UI_SET_ABSBIT, ABS_Y);

    ioctl(fd, UI_SET_RELBIT, REL_X);
    ioctl(fd, UI_SET_RELBIT, REL_Y);
    ioctl(fd, UI_SET_RELBIT, REL_WHEEL);
    ioctl(fd, UI_SET_RELBIT, REL_HWHEEL);

    for (code = BTN_LEFT; code <= BTN_EXTRA; code++)
        ioctl(fd, UI_SET_KEYBIT, code);

    udev.id.bustype = BUS_VIRTUAL;
    udev.id.vendor  = 0x1a;
    udev.id.product = 0x1c;

    udev.absmax[ABS_X] = 1024;
    udev.absmax[ABS_Y] = 1024;

    snprintf(udev.name, sizeof(udev.name), "%s", "qrr mouse");

    if (write(fd, &udev, sizeof udev) < 0) {
        fprintf(stderr, "failed to create uinput device\n");
        _exit(-1);
    }

    ioctl(fd, UI_DEV_CREATE);

    return fd;
}

void sync(int fd) {
    struct input_event ev;
    struct timespec    ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    ev.type         = EV_SYN;
    ev.code         = 0;
    ev.value        = 0;
    ev.time.tv_sec  = ts.tv_sec;
    ev.time.tv_usec = ts.tv_nsec / 1000;

    xwrite(fd, &ev, sizeof(ev));
}

void write_key_event(const int fd, uint16_t code, int val) {
    // static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
    struct input_event ev;

    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    // pthread_mutex_lock(&mtx);

    ev.type  = EV_KEY;
    ev.code  = code;
    ev.value = val;

    ev.time.tv_sec  = ts.tv_sec;
    ev.time.tv_usec = ts.tv_nsec / 1000;

    xwrite(fd, &ev, sizeof(ev));

    // pthread_mutex_unlock(&mtx);
}

// vkbd->fd          = create_virtual_keyboard(name);
// vkbd->pfd         = create_virtual_pointer("keyd virtual pointer");
