#ifndef _KERNEL_TERMINAL_HPP
#define _KERNEL_TERMINAL_HPP
#include "std.hpp"

namespace Terminal
{
	extern uint16_t *buffer;
	const size_t WIDTH = 80, HEIGHT = 25;
	extern size_t cx, cy;

	void initialize();
	void putchar(char chr);
	void puts(const char *str);
}
#endif