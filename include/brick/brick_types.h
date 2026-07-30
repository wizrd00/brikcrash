#ifndef BRIKCRASH_BRICK_TYPES_H
#define BRIKCRASH_BRICK_TYPES_H

#include "types.h"

typedef struct brick {
	struct object *block;
	edge_t edge;
	void (*disappear)(struct brick *bk);
	void (*activate)(struct brick *bk);
	bool (*is_active)(struct brick *bk);
	collide_t (*collide)(struct brick *bk, coordinate_t *cd);
} brick_t;

#endif
