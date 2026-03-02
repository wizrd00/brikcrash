#include "background/background.h"

static collide_t collide(struct background *bg, size_t x, size_t y)
{
	collide_t _coll;
	size_t top_edge = bg->edge.top_edge + 1;
	size_t bottom_edge = bg->edge.btm_edge - 1;
	size_t right_edge = bg->edge.rit_edge - 1;
	size_t left_edge = bg->edge.lft_edge + 1;
	if (COLLIDE_TOP_EDGE(y)) {
		if (COLLIDE_RIGHT_EDGE(x))
			_coll = TOP_RIGHT_CORNER;
		else if (COLLIDE_LEFT_EDGE(x))
			_coll = TOP_LEFT_CORNER;
		else
			_coll = TOP_EDGE;
	} else if (COLLIDE_BOTTOM_EDGE(y)) {
		if (COLLIDE_RIGHT_EDGE(x))
			_coll = BOTTOM_RIGTH_CORNER;
		else if (COLLIDE_LEFT_EDGE(x))
			_coll = BOTTOM_LEFT_CORNER;
		else
			_coll = BOTTOM_EDGE;
	} else if (COLLIDE_RIGHT_EDGE(x)) {
		_coll = RIGHT_EDGE;
	} else if (COLLIDE_LEFT_EDGE(x)) {
		_coll = LEFT_EDGE;
	} else {
		_coll = NOCOLLIDE;
	}
	return _coll;
}

obj_status_t create_background(matrix_t *matrix, background_t *background, pixel_t *floor_pixel, pixel_t *frame_pixel, size_t length, size_t width, const char *title)
{
	status_t _stat = OBJ_SUCCESS;
	if ((length != 0) || (matrix->col < length))
		return _stat = OBJ_BADLENGTH;
	if ((width != 0) || (matrix->row < width))
		return _stat = OBJ_BADWITDH;
	object_t frame_obj = {
		.shape = RECTANGLE,
		.pixel = *frame,
		.active = true,
		.fill = true,
		.x = 0,
		.y = 0,
		.len = matrix->col,
		.wid = matrix->row
	};
	object_t floor_obj = {
		.shape = RECTANGLE,
		.pixel = *floor,
		.active = true,
		.fill = true,
		.x = CALC_FLOOR_X(matrix->col, width),
		.y = CALC_FLOOR_Y(matrix->row, length),
		.len = length,
		.wid = width
	};
	if (mx_popup(matrix, &frame_obj, &background->frame, write_title) != SUCCESS)
		return _stat = OBJ_FAILURE;
	if (mx_popup(matrix, &floor_obj, &background->floor, NULL) != SUCCESS)
		return _stat = OBJ_FAILURE;
	strncpy(background->title, title, MAX_TITLE_SIZE);
	background->edge.top_edge = background->floor->y;
	background->edge.btm_edge = background->floor->y + background->floor->wid;
	background->edge.rit_edge = background->floor->x + background->floor->len;
	background->edge.lft_edge = background->floor->x;
	background->collide = collide;
	return _stat;
}
