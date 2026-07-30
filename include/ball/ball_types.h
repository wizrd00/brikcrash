#ifndef BRIKCRASH_BALL_TYPES_H
#define BRIKCRASH_BALL_TYPES_H

#include "types.h"

#define FIRST_VECTOR UP_RIGHT_SHALLOW

typedef enum {
	UP_RIGHT_STEEP,
	UP_RIGHT_SHALLOW,
	UP_LEFT_STEEP,
	UP_LEFT_SHALLOW,
	DOWN_RIGHT_STEEP,
	DOWN_RIGHT_SHALLOW,
	DOWN_LEFT_STEEP,
	DOWN_LEFT_SHALLOW
} vector_t;

typedef struct ball {
	struct object *block;
	vector_t vector;
	coordinate_t (*get_coordinate)(struct ball *bl);
	void (*set_coordinate)(struct ball *bl, coordinate_t *cd);
	void (*apply_next_move)(struct ball *bl);
	void (*swap_vector)(struct ball *bl);
} ball_t;

#endif
