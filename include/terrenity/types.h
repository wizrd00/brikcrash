#ifndef TYPES_H
#define TYPES_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "escape_code.h"
#include "ansi_color.h"

#define CHECK_STAT(val)\
	do {if (val != SUCCESS) {return _stat = val;}} while (0)

#define CHECK_PTR(val, err)\
	do {if (val == NULL) {return _stat = err;}} while (0)

#define CHECK_EQUAL(val0, val1, err)\
	do {if (val0 != val1) {return _stat = err;}} while (0)

#define CHECK_NOTEQUAL(val0, val1, err)\
	do {if (val0 == val1) {return _stat = err;}} while (0)

#define CHECK_GREATER_EQUAL(val0, val1, err)\
	do {if (val0 < val1) {return _stat = err;}} while (0)

typedef enum {
	SUCCESS,
	FAILURE,
	INVROTT,
	NOTCGET,
	NOTCSET,
	NOSHAPE,
	ERRCALL,
	ERRREAD,
	ERRWRIT,
	ERRDRAW,
	ERRALOC,
	ERRFLSH,
	ERRSQRE,
	BADSIZE,
	BADSHAP
} status;

typedef enum {
	ROTCW,
	ROTCC
} rotate;

typedef enum {
	EMPTY,
	RECTANGLE,
	RHOMBUS
} shape;

typedef enum {
	BLACK,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	PURPLE,
	CYAN,
	WHITE
} color;

typedef enum {
	LOCK,
	UNLOCK
} lock;

struct pixel {
	uint8_t ulbd;
	uint8_t bgnd;
	uint8_t fgnd;
	uint8_t cval;
};

struct object {
	shape shape;
	struct pixel pixel;
	bool active;
	bool fill;
	size_t x, y;
	size_t len, wid;
	struct object *prev;
	struct object *next;
};

struct matrix {
	struct pixel **floor_mx;
	struct pixel **float_mx;
	unsigned char *buffer;
	struct object lnobject[2];
	lock update;
	size_t row, col;
	size_t buffer_size;
};

typedef status (*callback)(struct matrix *restrict);

#endif
