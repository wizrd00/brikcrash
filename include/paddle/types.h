#ifndef BRIKCRASH_PADDLE_TYPES_H
#define BRIKCRASH_PADDLE_TYPES_H

#include "types.h"

typedef struct paddle {
	object_t block;
	bool movable_rit;
	bool movable_lft;
	void (*move_right)(struct paddle *pd);
	void (*move_left)(struct paddle *pd);
	collide_t (*collide)(struct paddle *pd, size_t x, size_t y);
} paddle_t;

#endif
