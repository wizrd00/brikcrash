#ifndef BRIKCRASH_H
#define BRIKCRASH_H

#include "types.h"
#include "ball/ball.h"
#include "brick/brick.h"
#include "paddle/paddle.h"
#include "background/background.h"
#include "keyboard/keyboard.h"
#include "terrenity/terrenity.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <sys/ioctl.h>

#define WAIT_MINI_INTERVAL() nanosleep(&(struct timespec){.tv_sec = 0, .tv_nsec = FRAME_MINI_INTERVAL}, NULL);

#define BRICK(i, j) (cx.bk[i][j])

#define BLANK_PIXEL() {.ulbd = NONE, .bgnd = LBGBLACK, .fgnd = LBGBLACK, .cval = ' '}

#define FLOOR_PIXEL() {.ulbd = NONE, .bgnd = LBGBLACK, .fgnd = LFGBLACK, .cval = ' '}

#define FRAME_PIXEL() {.ulbd = NONE, .bgnd = LBGWHITE, .fgnd = LFGBLACK, .cval = ' '}

#define PADDLE_PIXEL() {.ulbd = NONE, .bgnd = LBGPURPLE, .fgnd = LFGBLACK, .cval = ' '}

#define BALL_PIXEL() {.ulbd = NONE, .bgnd = LBGCYAN, .fgnd = LFGBLACK, .cval = ' '}

#define BRICK_RED_PIXEL() {.ulbd = NONE, .bgnd = LBGRED, .fgnd = LFGBLACK, .cval = ' '}

#define BRICK_YELLOW_PIXEL() {.ulbd = NONE, .bgnd = HBGYELLOW, .fgnd = LFGBLACK, .cval = ' '}

#define BRICK_GREEN_PIXEL() {.ulbd = NONE, .bgnd = LBGGREEN, .fgnd = LFGBLACK, .cval = ' '}

#define BRICK_BLUE_PIXEL() {.ulbd = NONE, .bgnd = LBGBLUE, .fgnd = LFGBLACK, .cval = ' '}

#define BRICK_COORDINATE(i, j) (&(coordinate_t){.x = (j * BRICK_SIZE) + cx.floor_x, .y = i + GAP_LENGTH + cx.floor_y})

#define PADDLE_COORDINATE() (&(coordinate_t){.x = (cx.mx.col / 2) - PADDLE_SIZE, .y = cx.floor_y + cx.floor_row - 1})

#define BALL_COORDINATE() (&(coordinate_t){.x = (cx.mx.col / 2) - BALL_SIZE, .y = cx.floor_y + cx.floor_row - 8})

#define TRYCALL(val, ...)\
	do {if (val != SUCCESS) {fprintf(stderr, ERROR_MSG, val, __func__, __VA_ARGS__); deinit(); exit(EXIT_FAILURE);}} while (0)

#define TRYOBJ(val, ...)\
	do {if (val != OBJ_SUCCESS) {fprintf(stderr, ERROR_MSG, val, __func__, __VA_ARGS__); deinit(); exit(EXIT_FAILURE);}} while (0)

typedef struct {
	matrix_t mx;
	background_t bg;
	brick_t bk[BRICK_ROW_COUNT][BRICK_COL_COUNT];
	paddle_t pd;
	ball_t bl;
	size_t floor_x;
	size_t floor_y;
	size_t floor_row;
	size_t floor_col;
} context_t;

void create_context(void);

void create_elements(void);

void deinit(void);

void render(void);

int main(void);

#endif
