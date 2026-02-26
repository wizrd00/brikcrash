#ifndef BRIKCRASH_BACKGROUND_TYPES_H
#define BRIKCRASH_BACKGROUND_TYPES_H

#include "types.h"

#define MAXTITLESIZE 64

typedef struct background {
	object_t floor;
	object_t frame;
	char title[MAXTITLESIZE];
	edge_t edge;
	collide_t (*collide)(struct background *bg, size_t x, size_t y);
} background_t;

#endif
