#include "background/background.h"

static collide_t collide(struct background *bg, coordinate_t *cd)
{
	collide_t _coll;
	size_t top_edge = bg->edge.top_edge + 1;
	size_t bottom_edge = bg->edge.btm_edge - 1;
	size_t right_edge = bg->edge.rit_edge - 1;
	size_t left_edge = bg->edge.lft_edge + 1;
	SPECIFY_COLLIDE_TYPE(cd->x, cd->y);
	if (_coll != NOCOLLIDE)
		return _coll;
	top_edge--;
	bottom_edge++;
	right_edge++;
	left_edge--;
	SPECIFY_COLLIDE_TYPE(cd->x, cd->y);
	return _coll;
}

obj_status_t create_background(matrix_t *matrix, background_t *background, pixel_t *floor_pixel, pixel_t *frame_pixel, size_t length, size_t width, const char *title)
{
	status_t _stat = OBJ_SUCCESS;
	if ((length == 0) || (length > matrix->col))
		return _stat = OBJ_BADLENGTH;
	if ((width == 0) || (width > matrix->row))
		return _stat = OBJ_BADWIDTH;
	size_t floor_x = CALC_FLOOR_X(matrix->col, length);
	size_t floor_y = CALC_FLOOR_Y(matrix->row, width);
	if (floor_x + length > matrix->col)
		return _stat = OBJ_BADLENGTH;
	if (floor_y + width > matrix->row)
		return _stat = OBJ_BADWIDTH;
	object_t frame_obj = {
		.shape = RECTANGLE,
		.pixel = *frame_pixel,
		.active = true,
		.fill = true,
		.x = 0,
		.y = 0,
		.len = matrix->col,
		.wid = matrix->row
	};
	object_t floor_obj = {
		.shape = RECTANGLE,
		.pixel = *floor_pixel,
		.active = true,
		.fill = true,
		.x = floor_x,
		.y = floor_y,
		.len = length,
		.wid = width
	};
	if (mx_popup(matrix, &frame_obj, &background->frame) != SUCCESS)
		return _stat = OBJ_FAILURE;
	if (mx_popup(matrix, &floor_obj, &background->floor) != SUCCESS)
		return _stat = OBJ_FAILURE;
	strncpy(background->title, title, MAX_TITLE_SIZE);
	background->edge.top_edge = background->floor->y;
	background->edge.btm_edge = background->floor->y + background->floor->wid - 1;
	background->edge.rit_edge = background->floor->x + background->floor->len - 1;
	background->edge.lft_edge = background->floor->x;
	background->collide = collide;
	return _stat;
}
