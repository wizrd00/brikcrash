#ifndef TERRENITY_H
#define TERRENITY_H

#include <sys/ioctl.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <termios.h>
#include <errno.h>

#include "types.h"
#include "tool/pixel.h"
#include "tool/draw.h"
#include "tool/rotation.h"

#define ISSQUARE(mx) (mx->row == mx->col)
#define OFFSET(i, j, k) (((i * k) + j) * PIXEL_SIZE)

status mx_init(struct matrix *restrict, bool, bool);

status mx_deinit(struct matrix *restrict);

status mx_refresh(struct matrix *restrict);

status mx_render(struct matrix *restrict, callback);

status mx_reset(struct matrix *restrict);

status mx_setpixel(struct matrix *restrict, struct pixel *restrict, size_t,
    size_t);

status mx_fill(struct matrix *restrict, struct pixel *restrict);

status mx_popup(struct matrix *restrict, struct object *restrict, struct object
    **restrict);

status mx_popdown(struct matrix *restrict, struct object *restrict);

status mx_rotate(struct matrix *restrict, rotate);

status mx_unlock(struct matrix *restrict);

status mx_readkey(unsigned char *, unsigned char);

status mx_clear(void);

status mx_echo_on(void);

status mx_echo_off(void);

status mx_hide_cursor(void);

status mx_show_cursor(void);

#endif
