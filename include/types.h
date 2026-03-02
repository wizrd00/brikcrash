#ifndef BRIKCRASH_TYPES_H
#define BRIKCRASH_TYPES_H

#include "terrenity/types.h"
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum {
	OBJ_SUCCESS,
	OBJ_FAILURE,
	OBJ_BADLENGTH,
	OBJ_BADWIDTH
} obj_status_t;

typedef enum {
	NOCOLLIDE,
	TOP_EDGE,
	BOTTOM_EDGE,
	RIGTH_EDGE,
	LEFT_EDGE,
	TOP_RIGTH_CORNER,
	TOP_LEFT_CORNER,
	BOTTOM_RIGTH_CORNER,
	BOTTOM_LEFT_CORNER
} collide_t;

typedef struct {
	size_t top_edge;
	size_t btm_edge;
	size_t rit_edge;
	size_t lft_edge;
} edge_t;

#endif
