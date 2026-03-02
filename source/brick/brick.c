#include "brick/brick.h"

static collide_t collide(struct brick *bk, coordinate_t *cd)
{
	collide_t _coll;
	size_t top_edge = (bk->edge.top_edge != 0) ? bk->edge.top_edge - 1 : bk->edge.top_edge;
	size_t bottom_edge = bk->edge.btm_edge + 1;
	size_t rigth_edge = bk->edge.rit_edge + 1;
	size_t left_edge = (bk->edge.lft_edge != 0) ? bk->edge.lft_edge - 1 : bk->edge.lft_edge;
	SPECIFY_COLLIDE_TYPE(cd->x, cd->y);
	return _coll;
}

obj_status_t create_brick(matrix_t *matrix, brick_t *brick, pixel_t *pixel, coordinate_t *cd, size_t length)
{
	obj_status_t _stat = OBJ_SUCCESS;
	if ((length == 0) || (length < matrix->col))
		return _stat = OBJ_BADLENGTH;
	if ((cd->x >= matrix->col) || (cd->y >= matrix->row))
		return _stat = OBJ_BADCOORDINATE;
	object_t brick_obj = {
		.shape = RECTANGLE,
		.pixel = *pixel,
		.active = true,
		.fill = true,
		.x = cd->x,
		.y = cd->y,
		.len = length,
		.wid = 1
	};
	if (mx_popup(matrix, &brick_obj, &brick->block) != SUCCESS)
		return _stat = OBJ_FAILURE;
	brick->edge.top_edge = brick->block->y;
	brick->edge.btm_edge = brick->block->y + brick->block->wid - 1;
	brick->edge.rit_edge = brick->block->x + brick->block->len - 1;
	brick->edge.lft_edge = brick->block->x;
	brick->collide = collide;
	return _stat;
}
