#ifndef BRIKCRASH_BACKGROUND_H
#define BRIKCRASH_BACKGROUND_H

#include "background/types.h"
#include <string.h>

obj_status_t create_background(matrix_t *matrix, background_t *background, pixel_t *floor_pixel, pixel_t *frame_pixel, size_t length, size_t width, const char *title);

#endif
