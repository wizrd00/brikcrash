#ifndef BRIKCRASH_BRICK_H
#define BRIKCRASH_BRICK_H

#include "brick/brick_types.h"
#include "terrenity/terrenity.h"

#define SPECIFY_BRICK_COLLIDE_TYPE(x, y)\
	do {\
		if (COLLIDE_TOP_EDGE(y)) {\
			if (COLLIDE_RIGHT_EDGE(x))\
				return _coll = TOP_RIGHT_CORNER;\
			else if (COLLIDE_LEFT_EDGE(x))\
				return _coll = TOP_LEFT_CORNER;\
			else if (COLLIDE_BETWEEN_EDGES(x))\
				return _coll = TOP_EDGE;\
			else\
				return _coll = NOCOLLIDE;\
		} else {\
			return _coll = NOCOLLIDE;\
		}\
	} while (0)

obj_status_t create_brick(struct matrix *matrix, brick_t *brick, struct pixel *pixel, coordinate_t *coordinate, size_t length);

#endif
