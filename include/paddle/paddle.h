#ifndef BRIKCRASH_PADDLE_H
#define BRIKCRASH_PADDLE_H

#include "paddle/paddle_types.h"
#include "terrenity/terrenity.h"

#define SPECIFY_PADDLE_COLLIDE_TYPE(x, y)\
	do {\
		if (COLLIDE_TOP_EDGE(y)) {\
			if (COLLIDE_RIGHT_EDGE(x))\
				return _coll = TOP_RIGHT_CORNER;\
			else if (COLLIDE_LEFT_EDGE(x))\
				return _coll = TOP_LEFT_CORNER;\
			else\
				return _coll = TOP_EDGE;\
		} else {\
			return _coll = NOCOLLIDE;\
		}\
	} while (0)

obj_status_t create_paddle(matrix_t *matrix, paddle_t *paddle, pixel_t *pixel, coordinate_t *coordinate, size_t length);

#endif
