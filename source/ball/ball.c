#include "ball/ball.h"

static coordinate_t get_coordinate(struct ball *bl)
{
	coordinate_t cd;
	switch (bl->vector) {
	case UP_RIGHT_STEEP :
	case UP_RIGHT_SHALLOW :
	case DOWN_RIGHT_STEEP :
	case DOWN_RIGHT_SHALLOW :
		cd.x = bl->block->x + 1;
		break;
	case UP_LEFT_STEEP :
	case UP_LEFT_SHALLOW :
	case DOWN_LEFT_STEEP :
	case DOWN_LEFT_SHALLOW :
		cd.x = bl->block->x;
		break;
	}
	cd.y = bl->block->y;
	return cd;
}

static void set_coordinate(struct ball *bl, coordinate_t *cd)
{
	bl->block->x = cd->x;
	bl->block->y = cd->y;
	return;
}

static void apply_next_move(struct ball *bl)
{
	switch (bl->vector) {
	case UP_RIGHT_STEEP :
		bl->block->x++;
		bl->block->y -= (bl->block->y > 0) ? 1 : 0;
		break;
	case UP_RIGHT_SHALLOW :
		bl->block->x += 2;
		bl->block->y -= (bl->block->y > 0) ? 1 : 0;
		break;
	case UP_LEFT_STEEP :
		bl->block->x -= (bl->block->x > 0) ? 1 : 0;
		bl->block->y -= (bl->block->y > 0) ? 1 : 0;
		break;
	case UP_LEFT_SHALLOW :
		bl->block->x -= (bl->block->x > 1) ? 2 : (bl->block->x > 0) ? 1 : 0;
		bl->block->y -= (bl->block->y > 0) ? 1 : 0;
		break;
	case DOWN_RIGHT_STEEP :
		bl->block->x++;
		bl->block->y++;
		break;
	case DOWN_RIGHT_SHALLOW :
		bl->block->x += 2;
		bl->block->y++;
		break;
	case DOWN_LEFT_STEEP :
		bl->block->x -= (bl->block->x > 0) ? 1 : 0;
		bl->block->y++;
		break;
	case DOWN_LEFT_SHALLOW :
		bl->block->x -= (bl->block->x > 1) ? 2 : (bl->block->x > 0) ? 1 : 0;
		bl->block->y++;
		break;
	}
	return;
}

static void swap_vector(struct ball *bl)
{
	switch (bl->vector) {
	case UP_RIGHT_STEEP :
		bl->vector = DOWN_RIGHT_STEEP;
		break;
	case UP_RIGHT_SHALLOW :
		bl->vector = DOWN_RIGHT_SHALLOW;
		break;
	case UP_LEFT_STEEP :
		bl->vector = DOWN_LEFT_STEEP;
		break;
	case UP_LEFT_SHALLOW :
		bl->vector = DOWN_LEFT_SHALLOW;
		break;
	case DOWN_RIGHT_STEEP :
		bl->vector = UP_RIGHT_STEEP;
		break;
	case DOWN_RIGHT_SHALLOW :
		bl->vector = UP_RIGHT_SHALLOW;
		break;
	case DOWN_LEFT_STEEP :
		bl->vector = UP_LEFT_STEEP;
		break;
	case DOWN_LEFT_SHALLOW :
		bl->vector = UP_LEFT_SHALLOW;
		break;
	}
	return;
}

obj_status_t create_ball(matrix_t *matrix, ball_t *ball, pixel_t *pixel, coordinate_t *coordinate)
{
	obj_status_t _stat = OBJ_SUCCESS;
	if ((coordinate->x >= matrix->col) || (coordinate->y >= matrix->row))
		return _stat = OBJ_BADCOORDINATE;
	object_t ball_obj = {
		.shape = RECTANGLE,
		.pixel = *pixel,
		.active = true,
		.fill = false,
		.x = coordinate->x,
		.y = coordinate->y,
		.len = 2,
		.wid = 1
	};
	if (mx_popup(matrix, &ball_obj, &ball->block) != SUCCESS)
		return _stat = OBJ_FAILURE;
	ball->vector = FIRST_VECTOR;
	ball->get_coordinate = get_coordinate;
	ball->set_coordinate = set_coordinate;
	ball->apply_next_move = apply_next_move;
	ball->swap_vector = swap_vector;
	return _stat;
}
