#ifndef BRIKCRASH_H
#define BRIKCRASH_H

#include "types.h"
#include "ball/ball.h"
#include "brick/brick.h"
#include "paddle/paddle.h"
#include "background/background.h"
#include "keyboard/keyboard.h"
#include "terrenity/terrenity.h"
#include <stdio.h>

#define FLOOR_PIXEL() {.ulbd = NONE, .bgnd = LBGBLACK, .fgnd = LFGBLACK, .cval = ' '}

#define FRAME_PIXEL() {.ulbd = NONE, .bgnd = LBGWHITE, .fgnd = LFGWHITE, .cval = ' '}

#define PADDLE_PIXEL() {.ulbd = NONE, .bgnd = HBGWHITE, .fgnd = HFGWHITE, .cval = ' '}

#define BALL_PIXEL() {.ulbd = NONE, .bgnd = HBGRED, .fgnd = HFGRED, .cval = ' '}

#define BRICK_RED_PIXEL() {.ulbd = NONE, .bgnd = LBGRED, .fgnd = LFGBLACK, .cval = '-'}

#define BRICK_PURPLE_PIXEL() {.ulbd = NONE, .bgnd = LBGPURPLE, .fgnd = LFGBLACK, .cval = '-'}

#define BRICK_CYAN_PIXEL() {.ulbd = NONE, .bgnd = LBGCYAN, .fgnd = LFGBLACK, .cval = '-'}

#define BRICK_GREEN_PIXEL() {.ulbd = NONE, .bgnd = LBGGREEN, .fgnd = LFGBLACK, .cval = '-'}

#define BRICK_YELLOW_PIXEL() {.ulbd = NONE, .bgnd = LBGYELLOW, .fgnd = LFGBLACK, .cval = '-'}

#define BRICK_BLUE_PIXEL() {.ulbd = NONE, .bgnd = LBGBLUE, .fgnd = LFGBLACK, .cval = '-'}

#define BRICK_COORDINATE(i, j) //TODO

#define PADDLE_COORDINATE() //TODO

#define BALL_COORDINATE() //TODO

#define TRYCALL(val, ...)\
	do {if (val != SUCCESS) {fprintf(stderr, ERROR_MSG, val, __func__, __VA_ARGS__); destroy_context(&cx); destroy_elements(&cx); return val;}} while (0)

#define TRYOBJ(val, ...)\
	do {if (val != OBJ_SUCCESS) {fprintf(stderr, ERROR_MSG, val, __func__, __VA_ARGS__); destroy_context(&cx); destroy_elements(&cx); return val;}} while (0)

int main(void);

#endif
