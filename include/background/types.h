#ifndef BRIKCRASH_BACKGROUND_TYPES_H
#define BRIKCRASH_BACKGROUND_TYPES_H

#include "types.h"

#define MAX_TITLE_SIZE 64

#define COLLIDE_TOP_EDGE(y) (y == top_edge)
#define COLLIDE_BOTTOM_EDGE(y) (y == bottom_edge)
#define COLLIDE_RIGTH_EDGE(x) (x == right_edge)
#define COLLIDE_LEFT_EDGE(x) (x == left_edge)

#define CALC_FLOOR_X(matrix_wid, floor_wid) ((matrix_wid - floor_wid) / 2)

#define CALC_FLOOR_Y(matrix_len, floor_len) ((matrix_len - floor_len) / 2)

typedef struct background {
	object_t *floor;
	object_t *frame;
	char title[MAX_TITLE_SIZE];
	edge_t edge;
	collide_t (*collide)(struct background *bg, size_t x, size_t y);
} background_t;

#endif
