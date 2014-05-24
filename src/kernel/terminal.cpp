#include "terminal.hpp"
#include "std.hpp"

namespace Terminal
{
	uint16_t *buffer;
	size_t cx, cy;

	void initialize()
	{
		buffer = (uint16_t *)0x0B8000;
		cx = cy = 0;
	}

	void putchar(char chr)
	{
		if (chr != '\n') // newline characters are special VGA specific things
		{
			buffer[cy * WIDTH + cx] = 15 << 8 | chr;
		}
		else
		{
			// force a newline
			cx = WIDTH;
		}


		if (++cx >= WIDTH)
		{
			if (++cy >= HEIGHT)
			{
				cx = cy = 0;
				// scroll
			} else {
				cx = 0;
			}
		}
	}
}