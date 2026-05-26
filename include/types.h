#ifndef BRIKCRASH_TYPES_H
#define BRIKCRASH_TYPES_H

#include "terrenity/types.h"
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>

#define ERROR_MSG "[!] Error -> (status code : %d) | (function : %s) | (message : %s)\n"
#define FRAME_TITLE "BRIKCRASH"
#define COEFFICIENT 20
#define FRAME_INTERVAL 80000000
#define FRAME_MINI_INTERVAL (FRAME_INTERVAL / COEFFICIENT)
#define GAP_LENGTH 4
#define BRICK_ROW_COUNT 6
#define BRICK_COL_COUNT 12
#define BRICK_SIZE 8
#define PADDLE_SIZE 8
#define BALL_SIZE 2
#define FLOOR_LENGTH (BRICK_COL_COUNT * BRICK_SIZE)
#define FLOOR_WIDTH 24

#define COLLIDE_TOP_EDGE(y) (y == top_edge)
#define COLLIDE_BOTTOM_EDGE(y) (y == bottom_edge)
#define COLLIDE_RIGHT_EDGE(x) (x == right_edge)
#define COLLIDE_LEFT_EDGE(x) (x == left_edge)
#define COLLIDE_BETWEEN_EDGES(x) ((x > left_edge) && (x < right_edge))

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
