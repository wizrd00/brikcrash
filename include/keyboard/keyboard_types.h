#ifndef BRIKCRASH_KEYBOARD_TYPES_H
#define BRIKCRASH_KEYBOARD_TYPES_H

#define ESC_CHAR '\x1b'
#define ENTER_CHAR '\n'
#define SPACE_CHAR ' '
#define SPECIAL_CHAR '['
#define ARROW_UP_SPECIAL_CHAR 'A'
#define ARROW_DOWN_SPECIAL_CHAR 'B'
#define ARROW_RIGHT_SPECIAL_CHAR 'C'
#define ARROW_LEFT_SPECIAL_CHAR 'D'

#define IS_AVAILABLE() (poll(&pfd, 1, 0) > 0)
#define FLUSH() (while (IS_AVAILABLE()) getchar();)

typedef enum {
	KEY_NONE,
	KEY_ARROW_UP,
	KEY_ARROW_DOWN,
	KEY_ARROW_RIGHT,
	KEY_ARROW_LEFT,
	KEY_ENTER,
	KEY_SPACE,
	KEY_ESC
} keyboard_t;

#endif
