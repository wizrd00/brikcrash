#include "brikcrash.h"

static context_t cx;
static keyboard_t key;

static void game_over(void)
{
	//TODO
	deinit();
	exit(EXIT_SUCCESS);
	return;
}

static void reset_bricks(void)
{
	for (size_t i = 0; i < BRICK_ROW_COUNT; i++)
		for (size_t j = 0; j < BRICK_COL_COUNT; j++)
			BRICK(i, j).activate(&BRICK(i, j));
	return;
}

static void reset_ball(void)
{
	cx.bl.set_coordinate(&cx.bl, BALL_COORDINATE());
	return;
}

static void paddle_collide_top_right_corner(void)
{
	switch (cx.bl.vector) {
	case DOWN_RIGHT_STEEP :
		cx.bl.vector = UP_LEFT_STEEP;
		break;
	case DOWN_RIGHT_SHALLOW :
		cx.bl.vector = UP_LEFT_SHALLOW;
		break;
	case DOWN_LEFT_STEEP :
		cx.bl.vector = UP_LEFT_SHALLOW;
		break;
	case DOWN_LEFT_SHALLOW :
		cx.bl.vector = UP_LEFT_SHALLOW;
		break;
	}
	return;
}

static void paddle_collide_top_left_corner(void)
{
	switch (cx.bl.vector) {
	case DOWN_RIGHT_STEEP :
		cx.bl.vector = UP_RIGHT_SHALLOW;
		break;
	case DOWN_RIGHT_SHALLOW :
		cx.bl.vector = UP_RIGHT_SHALLOW;
		break;
	case DOWN_LEFT_STEEP :
		cx.bl.vector = UP_RIGHT_STEEP;
		break;
	case DOWN_LEFT_SHALLOW :
		cx.bl.vector = UP_RIGHT_SHALLOW;
		break;
	}
	return;
}

static void brick_collide_top_edge(void)
{
	switch (cx.bl.vector) {
	case UP_RIGHT_STEEP :
		cx.bl.vector = DOWN_RIGHT_STEEP;
		break;
	case UP_RIGHT_SHALLOW :
		cx.bl.vector = DOWN_RIGHT_SHALLOW;
		break;
	case UP_LEFT_STEEP :
		cx.bl.vector = DOWN_LEFT_STEEP;
		break;
	case UP_LEFT_SHALLOW :
		cx.bl.vector = DOWN_LEFT_SHALLOW;
		break;
	case DOWN_RIGHT_STEEP :
		cx.bl.vector = UP_RIGHT_STEEP;
		break;
	case DOWN_RIGHT_SHALLOW :
		cx.bl.vector = UP_RIGHT_SHALLOW;
		break;
	case DOWN_LEFT_STEEP :
		cx.bl.vector = UP_LEFT_STEEP;
		break;
	case DOWN_LEFT_SHALLOW :
		cx.bl.vector = UP_LEFT_SHALLOW;
		break;
	}
	return;
}

static void brick_collide_top_right_corner(void)
{
	switch (cx.bl.vector) {
	case UP_RIGHT_STEEP :
		cx.bl.vector = DOWN_RIGHT_STEEP;
		break;
	case UP_RIGHT_SHALLOW :
		cx.bl.vector = DOWN_RIGHT_SHALLOW;
		break;
	case UP_LEFT_STEEP :
		cx.bl.vector = DOWN_RIGHT_STEEP;
		break;
	case UP_LEFT_SHALLOW :
		cx.bl.vector = DOWN_RIGHT_SHALLOW;
		break;
	case DOWN_RIGHT_STEEP :
		cx.bl.vector = UP_RIGHT_STEEP;
		break;
	case DOWN_RIGHT_SHALLOW :
		cx.bl.vector = UP_RIGHT_SHALLOW;
		break;
	case DOWN_LEFT_STEEP :
		cx.bl.vector = UP_RIGHT_STEEP;
		break;
	case DOWN_LEFT_SHALLOW :
		cx.bl.vector = UP_RIGHT_SHALLOW;
		break;
	}
	return;
}

static void brick_collide_top_left_corner(void)
{
	switch (cx.bl.vector) {
	case UP_RIGHT_STEEP :
		cx.bl.vector = DOWN_LEFT_STEEP;
		break;
	case UP_RIGHT_SHALLOW :
		cx.bl.vector = DOWN_LEFT_SHALLOW;
		break;
	case UP_LEFT_STEEP :
		cx.bl.vector = DOWN_LEFT_STEEP;
		break;
	case UP_LEFT_SHALLOW :
		cx.bl.vector = DOWN_LEFT_SHALLOW;
		break;
	case DOWN_RIGHT_STEEP :
		cx.bl.vector = UP_RIGHT_STEEP;
		break;
	case DOWN_RIGHT_SHALLOW :
		cx.bl.vector = UP_RIGHT_SHALLOW;
		break;
	case DOWN_LEFT_STEEP :
		cx.bl.vector = UP_LEFT_STEEP;
		break;
	case DOWN_LEFT_SHALLOW :
		cx.bl.vector = UP_LEFT_SHALLOW;
		break;
	}
	return;
}

static void frame_collide_top_edge(void)
{
	cx.bl.swap_vector(&cx.bl);
	return;
}

static void frame_collide_bottom_edge(void)
{
	cx.bl.swap_vector(&cx.bl);
	return;
}

static void frame_collide_right_edge(void)
{
	switch (cx.bl.vector) {
	case UP_RIGHT_STEEP :
		cx.bl.vector = UP_LEFT_STEEP;
		break;
	case UP_RIGHT_SHALLOW :
		cx.bl.vector = UP_LEFT_SHALLOW;
		break;
	case DOWN_RIGHT_STEEP :
		cx.bl.vector = DOWN_LEFT_STEEP;
		break;
	case DOWN_RIGHT_SHALLOW :
		cx.bl.vector = DOWN_LEFT_SHALLOW;
		break;
	}
	return;
}

static void frame_collide_left_edge(void)
{
	switch (cx.bl.vector) {
	case UP_LEFT_STEEP :
		cx.bl.vector = UP_RIGHT_STEEP;
		break;
	case UP_LEFT_SHALLOW :
		cx.bl.vector = UP_RIGHT_SHALLOW;
		break;
	case DOWN_LEFT_STEEP :
		cx.bl.vector = DOWN_RIGHT_STEEP;
		break;
	case DOWN_LEFT_SHALLOW :
		cx.bl.vector = DOWN_RIGHT_SHALLOW;
		break;
	}
	return;
}

static void frame_collide_top_right_corner(void)
{
	switch (cx.bl.vector) {
	case UP_RIGHT_STEEP :
		cx.bl.vector = DOWN_LEFT_STEEP;
		break;
	case UP_RIGHT_SHALLOW :
		cx.bl.vector = DOWN_LEFT_SHALLOW;
		break;
	}
	return;
}

static void frame_collide_top_left_corner(void)
{
	switch (cx.bl.vector) {
	case UP_LEFT_STEEP :
		cx.bl.vector = DOWN_RIGHT_STEEP;
		break;
	case UP_LEFT_SHALLOW :
		cx.bl.vector = DOWN_RIGHT_SHALLOW;
		break;
	}
	return;
}

static void frame_collide_bottom_right_corner(void)
{
	switch (cx.bl.vector) {
	case DOWN_RIGHT_STEEP :
		cx.bl.vector = UP_LEFT_STEEP;
		break;
	case DOWN_RIGHT_SHALLOW :
		cx.bl.vector = UP_LEFT_SHALLOW;
		break;
	}
	return;
}

static void frame_collide_bottom_left_corner(void)
{
	switch (cx.bl.vector) {
	case DOWN_LEFT_STEEP :
		cx.bl.vector = UP_RIGHT_STEEP;
		break;
	case DOWN_LEFT_SHALLOW :
		cx.bl.vector = UP_RIGHT_SHALLOW;
		break;
	}
	return;
}

static bool check_paddle_collide(coordinate_t *cd)
{
	switch (cx.pd.collide(&cx.pd, cd)) {
	case TOP_EDGE :
		cx.bl.swap_vector(&cx.bl);
		return true;
	case TOP_RIGHT_CORNER :
		paddle_collide_top_right_corner();
		return true;
	case TOP_LEFT_CORNER :
		paddle_collide_top_left_corner();
		return true;
	}
	return false;
}

static bool check_bricks_collide(coordinate_t *cd)
{
	size_t count = 0;
	for (size_t i = 0; i < BRICK_ROW_COUNT; i++)
		for (size_t j = 0; j < BRICK_COL_COUNT; j++)
			if (BRICK(i, j).is_active(&BRICK(i, j))) {
				switch (BRICK(i, j).collide(&BRICK(i, j), cd)) {
				case TOP_EDGE :
					brick_collide_top_edge();
					BRICK(i, j).disappear(&BRICK(i, j));
					return true;
				case TOP_RIGHT_CORNER :
					brick_collide_top_right_corner();
					BRICK(i, j).disappear(&BRICK(i, j));
					return true;
				case TOP_LEFT_CORNER :
					brick_collide_top_left_corner();
					BRICK(i, j).disappear(&BRICK(i, j));
					return true;
				}
			} else {
				count++;
			}
	if (count == BRICK_ROW_COUNT * BRICK_COL_COUNT) {
		reset_bricks();
		reset_ball();
	}
	return false;
}

static bool check_frame_collide(coordinate_t *cd)
{
	switch (cx.bg.collide(&cx.bg, cd)) {
	case TOP_EDGE :
		frame_collide_top_edge();
		return true;
	case BOTTOM_EDGE :
		game_over();
		return true;
	case RIGHT_EDGE :
		frame_collide_right_edge();
		return true;
	case LEFT_EDGE :
		frame_collide_left_edge();
		return true;
	case TOP_RIGHT_CORNER :
		frame_collide_top_right_corner();
		return true;
	case TOP_LEFT_CORNER :
		frame_collide_top_left_corner();
		return true;
	case BOTTOM_RIGHT_CORNER :
		game_over();
		return true;
	case BOTTOM_LEFT_CORNER :
		game_over();
		return true;
	}
	return false;
}

void create_context(void)
{
	status_t _stat;
	struct winsize ws;
	if (ioctl(fileno(stdout), TIOCGWINSZ, &ws) != 0)
		TRYCALL((errno > 0) ? -errno : errno, strerror(errno));
	cx.mx.row = (size_t) ws.ws_row;
	cx.mx.col = (size_t) ws.ws_col;
	if ((_stat = mx_init(&cx.mx, true, true)) != SUCCESS) {
		fprintf(stderr, ERROR_MSG, _stat, __func__, "failed to init terrenity");
		exit(EXIT_FAILURE);
	}
	return;
}

void create_elements(void)
{
	pixel_t bg_floor_pixel = FLOOR_PIXEL();
	pixel_t bg_frame_pixel = FRAME_PIXEL();
	pixel_t pd_pixel = PADDLE_PIXEL();
	pixel_t bl_pixel = BALL_PIXEL();
	pixel_t bk_pixel[BRICK_ROW_COUNT] = {
		BRICK_RED_PIXEL(),
		BRICK_BLUE_PIXEL(),
		BRICK_RED_PIXEL(),
		BRICK_BLUE_PIXEL(),
		BRICK_RED_PIXEL(),
		BRICK_BLUE_PIXEL()
	};
	TRYOBJ(create_background(&cx.mx, &cx.bg, &bg_floor_pixel, &bg_frame_pixel, FLOOR_LENGTH, FLOOR_WIDTH, FRAME_TITLE), "failed to create background object");
	cx.floor_x = cx.bg.floor->x;
	cx.floor_y = cx.bg.floor->y;
	cx.floor_row = cx.bg.floor->wid;
	cx.floor_col = cx.bg.floor->len;
	for (size_t i = 0; i < BRICK_ROW_COUNT; i++)
		for (size_t j = 0; j < BRICK_COL_COUNT; j++)
			TRYOBJ(create_brick(&cx.mx, &cx.bk[i][j], &bk_pixel[i], BRICK_COORDINATE(i, j), BRICK_SIZE), "failed to create brick object");
	TRYOBJ(create_paddle(&cx.mx, &cx.pd, &pd_pixel, PADDLE_COORDINATE(), PADDLE_SIZE), "failed to create paddle object");
	TRYOBJ(create_ball(&cx.mx, &cx.bl, &bl_pixel, BALL_COORDINATE()), "failed to create ball object");
	return;
}

void deinit(void)
{
	TRYCALL(mx_deinit(&cx.mx), "failed to deinit terrenity");
	return;
}

void modify_paddle(void)
{
	coordinate_t cd = {.x = 0, .y = cx.pd.edge.top_edge};
	switch (key) {
	case KEY_ARROW_RIGHT :
		cd.x = cx.pd.edge.rit_edge;
		if (cx.bg.collide(&cx.bg, &cd) != BOTTOM_RIGHT_CORNER)
			cx.pd.move_right(&cx.pd);
		if (cx.bg.collide(&cx.bg, &cd) != BOTTOM_RIGHT_CORNER)
			cx.pd.move_right(&cx.pd);
		break;
	case KEY_ARROW_LEFT :
		cd.x = cx.pd.edge.lft_edge;
		if (cx.bg.collide(&cx.bg, &cd) != BOTTOM_LEFT_CORNER)
			cx.pd.move_left(&cx.pd);
		if (cx.bg.collide(&cx.bg, &cd) != BOTTOM_LEFT_CORNER)
			cx.pd.move_left(&cx.pd);
		break;
	}
	return;
}

void check_collide(void)
{
	coordinate_t cd = cx.bl.get_coordinate(&cx.bl);
	if (check_paddle_collide(&cd))
		return;
	check_bricks_collide(&cd);
	check_frame_collide(&cd);
	return;
}

void modify_ball(void)
{
	cx.bl.apply_next_move(&cx.bl);
	return;
}

void render(void)
{
	pixel_t blank_pixel = BLANK_PIXEL();
	mx_clear();
	TRYCALL(mx_fill(&cx.mx, &blank_pixel), "failed to fill screen with blank pixels");
	TRYCALL(mx_refresh(&cx.mx), "failed to refresh");
	TRYCALL(mx_render(&cx.mx, NULL), "failed to render");
	return;
}

int main(void)
{
	bool lock = true;
	create_context();
	create_elements();
	while (lock) {
		for (int i = 0; i < COEFFICIENT; i++) {
			key = getkey();
			if (key == KEY_ESC) {
				lock = false;
				break;
			}
			modify_paddle();
			render();
			WAIT_MINI_INTERVAL();
		}
		modify_ball();
		render();
		check_collide();
	}
	deinit();
	return 0;
}
