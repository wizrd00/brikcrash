#include "brikcrash.h"

static context_t cx;
static keyboard_t key;

void create_context(void)
{
	struct winsize ws;
	if (ioctl(fileno(stdout), TIOCGWINSZ, &ws) != 0)
		TRYCALL((errno > 0) ? -errno : errno, strerror(errno));
	cx.mx.row = (size_t) ws.ws_row;
	cx.mx.col = (size_t) ws.ws_col;
	TRYCALL(mx_init(&cx.mx, true, true), "failed to init terrenity");
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
		BRICK_RED_PIXEL(),
		BRICK_RED_PIXEL(),
		BRICK_RED_PIXEL(),
		BRICK_RED_PIXEL(),
		BRICK_RED_PIXEL()
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

void modify_ball(void)
{
	coordinate_t cd = cx.bl.get_coordinate(&cx.bl);
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
	}
	deinit();
	return 0;
}
