#ifndef BRIKCRASH_BALL_TYPES_H
#define BRIKCRASH_BALL_TYPES_H

#include "types.h"

typedef struct {
	size_t x;
	size_t y;
	enum {
		UP_RIGHT_STEEP,
		UP_RIGHT_SHALLOW,
		UP_LEFT_STEEP,
		UP_LEFT_SHALLOW,
		DOWN_RIGHT_STEEP,
		DOWN_RIGHT_SHALLOW,
		DOWN_LEFT_STEEP,
		DOWN_LEFT_SHALLOW
	} type;
} vector_t;

typedef struct ball {
	object_t block;
	vector_t vector;
	void (*apply_next_move)(struct ball *bl);
	void (*apply_prev_move)(struct ball *bl);
} ball_t;

#endif
