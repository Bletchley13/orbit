#ifndef _KERNEL_TERMINAL_HPP
#define _KERNEL_TERMINAL_HPP
#include "std.hpp"

namespace Terminal
{
	extern uint16_t *buffer;
	const size_t WIDTH = 80, HEIGHT = 25;
	extern size_t cx, cy;
	extern uint8_t ccolor;

	enum Colors
	{
		COLOR_BLACK = 0,
		COLOR_BLUE = 1,
		COLOR_GREEN = 2,
		COLOR_CYAN = 3,
		COLOR_RED = 4,
		COLOR_MAGENTA = 5,
		COLOR_BROWN = 6,
		COLOR_LIGHT_GREY = 7,
		COLOR_DARK_GREY = 8,
		COLOR_LIGHT_BLUE = 9,
		COLOR_LIGHT_GREEN = 10,
		COLOR_LIGHT_CYAN = 11,
		COLOR_LIGHT_RED = 12,
		COLOR_LIGHT_MAGENTA = 13,
		COLOR_LIGHT_BROWN = 14,
		COLOR_WHITE = 15
	};

	void initialize();
	void putchar(char chr);
	void puts(const char *str);
	void scroll();
	void set_color(enum Colors foreground, enum Colors background);
	void clear();
}
#endif