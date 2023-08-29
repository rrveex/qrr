#include "quantum.h"
#include <stdint.h>
#include <time.h>

static uint32_t get_time_ms() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1E3 + ts.tv_nsec / 1E6;
}

void timer_init(void) {}

uint16_t timer_read(void) {
    return get_time_ms();
}

uint32_t timer_read32(void) {
    return get_time_ms();
}

uint16_t timer_elapsed(uint16_t last) {
    return get_time_ms() - last;
}

uint32_t timer_elapsed32(uint32_t last) {
    return get_time_ms() - last;
}

void wait_ms(uint32_t msec) {
    // unsigned long u = 1000;
    // usleep(u * m    struct timespec ts;

    struct timespec ts;
    if (msec < 0) return;

    ts.tv_sec  = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    nanosleep(&ts, &ts);
}

void wait_us(uint16_t usec) {
    struct timespec ts;
    if (usec < 0) return;

    ts.tv_sec  = usec / 1000000;
    ts.tv_nsec = (usec % 1000000) * 1000;

    nanosleep(&ts, &ts);
}
