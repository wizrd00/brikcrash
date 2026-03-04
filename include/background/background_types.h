#ifndef BRIKCRASH_BACKGROUND_TYPES_H
#define BRIKCRASH_BACKGROUND_TYPES_H

#include "types.h"

#define MAX_TITLE_SIZE 64

#define CALC_FLOOR_X(matrix_wid, floor_wid) ((matrix_wid - floor_wid) / 2)

#define CALC_FLOOR_Y(matrix_len, floor_len) ((matrix_len - floor_len) / 2)

typedef struct background {
	object_t *floor;
	object_t *frame;
	char title[MAX_TITLE_SIZE];
	edge_t edge;
	collide_t (*collide)(struct background *bg, coordinate_t *cd);
} background_t;

#endif
