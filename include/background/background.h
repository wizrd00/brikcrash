#ifndef BRIKCRASH_BACKGROUND_H
#define BRIKCRASH_BACKGROUND_H

#include "background/types.h"

status_t create_background(background_t *back, pixel_t *floor, pixel_t frame, size_t length, size_t width, const char *title);

#endif
