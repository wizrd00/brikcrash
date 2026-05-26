#ifndef BRIKCRASH_BACKGROUND_TYPES_H
#define BRIKCRASH_BACKGROUND_TYPES_H

#include "types.h"

#define MAX_TITLE_SIZE 64

#define CALC_FLOOR_X(matrix_col, floor_len) ((matrix_col - floor_len) / (size_t) 2)

#define CALC_FLOOR_Y(matrix_row, floor_wid) ((matrix_row - floor_wid) / (size_t) 2)

typedef struct background {
	object_t *floor;
	object_t *frame;
	char title[MAX_TITLE_SIZE];
	edge_t edge;
	collide_t (*collide)(struct background *bg, coordinate_t *cd);
} background_t;

#endif
