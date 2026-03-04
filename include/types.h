#ifndef BRIKCRASH_TYPES_H
#define BRIKCRASH_TYPES_H

#include "terrenity/types.h"
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define COLLIDE_TOP_EDGE(y) (y == top_edge)
#define COLLIDE_BOTTOM_EDGE(y) (y == bottom_edge)
#define COLLIDE_RIGHT_EDGE(x) (x == right_edge)
#define COLLIDE_LEFT_EDGE(x) (x == left_edge)

#define SPECIFY_COLLIDE_TYPE(x, y)\
	do {\
		if (COLLIDE_TOP_EDGE(y)) {\
			if (COLLIDE_RIGHT_EDGE(x))\
				_coll = TOP_RIGHT_CORNER;\
			else if (COLLIDE_LEFT_EDGE(x))\
				_coll = TOP_LEFT_CORNER;\
			else\
				_coll = TOP_EDGE;\
		} else if (COLLIDE_BOTTOM_EDGE(y)) {\
			if (COLLIDE_RIGHT_EDGE(x))\
				_coll = BOTTOM_RIGHT_CORNER;\
			else if (COLLIDE_LEFT_EDGE(x))\
				_coll = BOTTOM_LEFT_CORNER;\
			else\
				_coll = BOTTOM_EDGE;\
		} else if (COLLIDE_RIGHT_EDGE(x)) {\
			_coll = RIGHT_EDGE;\
		} else if (COLLIDE_LEFT_EDGE(x)) {\
			_coll = LEFT_EDGE;\
		} else {\
			_coll = NOCOLLIDE;\
		}\
	} while (0);

typedef enum {
	OBJ_SUCCESS,
	OBJ_FAILURE,
	OBJ_BADCOORDINATE,
	OBJ_BADLENGTH,
	OBJ_BADWIDTH
} obj_status_t;

typedef enum {
	NOCOLLIDE,
	TOP_EDGE,
	BOTTOM_EDGE,
	RIGHT_EDGE,
	LEFT_EDGE,
	TOP_RIGHT_CORNER,
	TOP_LEFT_CORNER,
	BOTTOM_RIGHT_CORNER,
	BOTTOM_LEFT_CORNER
} collide_t;

typedef struct {
	size_t x;
	size_t y;
} coordinate_t;

typedef struct {
	size_t top_edge;
	size_t btm_edge;
	size_t rit_edge;
	size_t lft_edge;
} edge_t;

#endif
