#include "brikcrash.h"

static context_t cx;

static void create_context(void)
{
	TRYCALL(mx_init(&cx.mx, true, true), "failed to init terrenity");
	return;
}

static void destroy_context(void)
{
	TRYCALL(mx_deinit(&cx.mx), "failed to deinit terrenity");
	return;
}

static void create_elements(void)
{
	pixel_t bg_floor_pixel = FLOOR_PIXEL();
	pixel_t bg_frame_pixel = FRAME_PIXEL();
	pixel_t pd_pixel = PADDLE_PIXEL();
	pixel_t bl_pixel = BALL_PIXEL();
	pixel_t bk_pixel[BRICK_ROW_COUNT] = {
		BRICK_RED_PIXEL(),
		BRICK_PURPLE_PIXEL(),
		BRICK_CYAN_PIXEL(),
		BRICK_GREEN_PIXEL(),
		BRICK_YELLOW_PIXEL(),
		BRICK_BLUE_PIXEL()
	};
	TRYOBJ(create_background(&cx.mx, &cx.bg, &bg_floor_pixel, &bg_frame_pixel, FLOOR_LENGTH, FLOOR_WIDTH, FRAME_TITLE), "failed to create background object");
	for (size_t i = 0; i < BRICK_ROW_COUNT; i++)
		for (size_t j = 0; j < BRICK_COL_COUNT, j++)
			TRYOBJ(create_brick(&cx.mx, &cx.bk[i][j], &bk_pixel[i], BRICK_COORDINATE(i, j), BRICK_SIZE), "failed to create brick object");
	TRYOBJ(create(&cx.mx, &cx.pd, &pd_pixel, PADDLE_COORDINATE(), PADDLE_SIZE), "failed to create paddle object");
	TRYOBJ(create_ball(&cx.mx, &cx.bl, &bl_pixel, BALL_COORDINATE()), "failed to create ball object");
	return;
}

static void destroy_elements(void)
{
	free((void *) cx.bg.floor);
	free((void *) cx.bg.frame);
	for (size_t i = 0; i < BRICK_ROW_COUNT; i++)
		for (size_t j = 0; j < BRICK_COL_COUNT; j++)
			mx_popdown(&cx.mx, cx.bk[i][j].block);
	free((void *) cx.pd.block);
	free((void *) cx.bl.block);
	return;
}

int main(void)
{
	keyboard_t key;
	create_context(&mx);
	create_elements(&mx);
	while (true) {
		key = getkey();
		if (key == KEY_ESC)
			break;
		modify(&mx, key);
		render(&mx);
	}
}
