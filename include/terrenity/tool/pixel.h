#ifndef PIXEL_H
#define PIXEL_H

#include <stdio.h>

#include "types.h"

#define PIXEL "\x1b[%d;%d;%d;%dm%c"
#define PIXEL_SIZE 16

static inline void
pixelcpy(unsigned char *restrict buf, struct pixel *restrict pix)
{
	char underline = pix->ulbd & 0x04;
	char bold = pix->ulbd & 0x01;
	buf[0] = '\x1b';
	buf[1] = '[';
	buf[2] = (underline) ? underline : '0';
	buf[3] = ';';
	buf[4] = (bold) ? bold : underline + '0';
	buf[5] = ';';
	buf[6] = (char)(pix->bgnd / 100) + '0';
	buf[7] = (char)((pix->bgnd / 10) % 10) + '0';
	buf[8] = (char)(pix->bgnd % 10) + '0';
	buf[9] = ';';
	buf[10] = (char)(pix->fgnd / 100) + '0';
	buf[11] = (char)((pix->fgnd / 10) % 10) + '0';
	buf[12] = (char)(pix->fgnd % 10) + '0';
	buf[13] = 'm';
	buf[14] = pix->cval;
	buf[15] = '\0';
	return;
}

#endif
