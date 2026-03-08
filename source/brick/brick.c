#include "brick/brick.h"

static void disappear(struct brick *bk)
{
	bk->block->active = false;
	return;
}

static bool is_active(struct brick *bk)
{
	return bk->block->active;
}

static collide_t collide(struct brick *bk, coordinate_t *cd)
{
	collide_t _coll;
	size_t top_edge = (bk->edge.top_edge != 0) ? bk->edge.top_edge - 1 : bk->edge.top_edge;
	size_t bottom_edge = bk->edge.btm_edge + 1;
	size_t right_edge = bk->edge.rit_edge + 1;
	size_t left_edge = (bk->edge.lft_edge != 0) ? bk->edge.lft_edge - 1 : bk->edge.lft_edge;
	SPECIFY_BRICK_COLLIDE_TYPE(cd->x, cd->y);
	if (_coll != NOCOLLIDE)
		return _coll;
	top_edge++;
	bottom_edge--;
	right_edge--;
	left_edge++;
	SPECIFY_BRICK_COLLIDE_TYPE(cd->x, cd->y);
	return _coll;
}

obj_status_t create_brick(matrix_t *matrix, brick_t *brick, pixel_t *pixel, coordinate_t *coordinate, size_t length)
{
	obj_status_t _stat = OBJ_SUCCESS;
	if ((coordinate->x >= matrix->col) || (coordinate->y >= matrix->row))
		return _stat = OBJ_BADCOORDINATE;
	if ((length == 0) || (length + coordinate->x > matrix->col))
		return _stat = OBJ_BADLENGTH;
	object_t brick_obj = {
		.shape = RECTANGLE,
		.pixel = *pixel,
		.active = true,
		.fill = true,
		.x = coordinate->x,
		.y = coordinate->y,
		.len = length,
		.wid = 1
	};
	if (mx_popup(matrix, &brick_obj, &brick->block) != SUCCESS)
		return _stat = OBJ_FAILURE;
	brick->edge.top_edge = brick->block->y;
	brick->edge.btm_edge = brick->block->y + brick->block->wid - 1;
	brick->edge.rit_edge = brick->block->x + brick->block->len - 1;
	brick->edge.lft_edge = brick->block->x;
	brick->disappear = disappear;
	brick->is_active = is_active;
	brick->collide = collide;
	return _stat;
}
