#ifndef BRIKCRASH_BRICK_TYPES_H
#define BRIKCRASH_BRICK_TYPES_H

#include "types.h"

typedef struct brick {
	object_t block;
	edge_t edge;
	collide_t (*collide)(struct brick *bk, size_t x, size_t y);
} brick_t;

#endif
