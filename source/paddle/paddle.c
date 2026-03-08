#include "paddle/paddle.h"

static void move_right(struct paddle *pd)
{
	pd->block->x++;
	pd->edge.rit_edge++;
	pd->edge.lft_edge = pd->block->x;
	return;
}

static void move_left(struct paddle *pd)
{
	pd->block->x -= (pd->block->x > 0) ? 1 : 0;
	pd->edge.rit_edge -= (pd->edge.rit_edge > 0) ? 1 : 0;
	pd->edge.lft_edge = pd->block->x;
	return;
}

static collide_t collide(struct paddle *pd, coordinate_t *cd)
{

	collide_t _coll;
	size_t top_edge = (pd->edge.top_edge != 0) ? pd->edge.top_edge - 1 : pd->edge.top_edge;
	size_t bottom_edge = pd->edge.btm_edge + 1;
	size_t right_edge = pd->edge.rit_edge + 1;
	size_t left_edge = (pd->edge.lft_edge != 0) ? pd->edge.lft_edge - 1 : pd->edge.lft_edge;
	SPECIFY_PADDLE_COLLIDE_TYPE(cd->x, cd->y);
	if (_coll != NOCOLLIDE)
		return _coll;
	top_edge++;
	bottom_edge--;
	right_edge--;
	left_edge++;
	SPECIFY_PADDLE_COLLIDE_TYPE(cd->x, cd->y);
	return _coll;
}

obj_status_t create_paddle(matrix_t *matrix, paddle_t *paddle, pixel_t *pixel, coordinate_t *coordinate, size_t length)
{
	obj_status_t _stat = OBJ_SUCCESS;
	if ((coordinate->x >= matrix->col) || (coordinate->y >= matrix->row))
		return _stat = OBJ_BADCOORDINATE;
	if ((length == 0) || (length + coordinate->x > matrix->col))
		return _stat = OBJ_BADLENGTH;
	object_t paddle_obj = {
		.shape = RECTANGLE,
		.pixel = *pixel,
		.active = true,
		.fill = true,
		.x = coordinate->x,
		.y = coordinate->y,
		.len = length,
		.wid = 1
	};
	if (mx_popup(matrix, &paddle_obj, &paddle->block) != SUCCESS)
		return _stat = OBJ_FAILURE;
	paddle->edge.top_edge = paddle->block->y;
	paddle->edge.btm_edge = paddle->block->y + paddle->block->wid - 1;
	paddle->edge.rit_edge = paddle->block->x + paddle->block->len - 1;
	paddle->edge.lft_edge = paddle->block->x;
	paddle->movable_rit = true;
	paddle->movable_lft = true;
	paddle->move_right = move_right;
	paddle->move_left = move_left;
	paddle->collide = collide;
	return _stat;
}
