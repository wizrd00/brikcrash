#ifndef BRIKCRASH_BACKGROUND_H
#define BRIKCRASH_BACKGROUND_H

#include "background/background_types.h"
#include "terrenity/terrenity.h"
#include <string.h>

#define SPECIFY_BACKGROUND_COLLIDE_TYPE(x, y)\
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

obj_status_t create_background(matrix_t *matrix, background_t *background, pixel_t *floor_pixel, pixel_t *frame_pixel, size_t length, size_t width, const char *title);

#endif
