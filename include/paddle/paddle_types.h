#ifndef BRIKCRASH_PADDLE_TYPES_H
#define BRIKCRASH_PADDLE_TYPES_H

#include "types.h"

typedef struct paddle {
	object_t *block;
	edge_t edge;
	bool movable_rit;
	bool movable_lft;
	void (*move_right)(struct paddle *pd);
	void (*move_left)(struct paddle *pd);
	collide_t (*collide)(struct paddle *pd, coordinate_t *cd);
} paddle_t;

#endif
