#include "keyboard/keyboard.h"

static bool is_available(int timeout)
{
	struct pollfd pfd = {.fd = fileno(stdin), .events = POLLIN};
	return ((poll(&pfd, 1, timeout) > 0) && ((pfd.revents & POLLIN) > 0)) ? true : false;
}

static void get_special_key(keyboard_t *key)
{
	unsigned char keychar;
	if (mx_readkey(&keychar, 0) != SUCCESS) {
		*key = KEY_ESC;
		return;
	}
	if (keychar != SPECIAL_CHAR) {
		*key = KEY_NONE;
		return;
	}
	if (mx_readkey(&keychar, 0) != SUCCESS) {
		*key = KEY_NONE;
		return;
	}
	switch (keychar) {
	case ARROW_UP_SPECIAL_CHAR :
		*key = KEY_ARROW_UP;
		break;
	case ARROW_DOWN_SPECIAL_CHAR :
		*key = KEY_ARROW_DOWN;
		break;
	case ARROW_RIGHT_SPECIAL_CHAR :
		*key = KEY_ARROW_RIGHT;
		break;
	case ARROW_LEFT_SPECIAL_CHAR :
		*key = KEY_ARROW_LEFT;
		break;
	default :
		*key = KEY_NONE;
	}
	return;
}

keyboard_t getkey(void)
{
	keyboard_t key;
	status_t _stat;
	unsigned char keychar;
	if (!is_available(POLL_TIMEOUT))
		return key = KEY_NONE;
	if ((_stat = mx_readkey(&keychar, 0)) != SUCCESS) {
		FLUSH();
		return key = KEY_NONE;
	}
	switch (keychar) {
	case ESC_CHAR :
		get_special_key(&key);
		FLUSH();
		break;
	case ENTER_CHAR :
		FLUSH();
		key = KEY_ENTER;
		break;
	case SPACE_CHAR :
		FLUSH();
		key = KEY_SPACE;
		break;
	default :
		key = KEY_NONE;
	}
	return key;
}
