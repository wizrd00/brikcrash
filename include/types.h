#ifndef BRIKCRASH_TYPES_H
#define BRIKCRASH_TYPES_H

#include "terrenity/types.h"
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum {
	TOP,
	BTM,
	RIT,
	LFT
} collide_t;

typedef struct {
	size_t top_edge;
	size_t btm_edge;
	size_t rit_edge;
	size_t lft_edge;
} edge_t;

#endif
