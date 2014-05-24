#include "terminal.hpp"
#include "std.hpp"
#include "cstd/string.hpp"

namespace Terminal
{
	uint16_t *buffer;
	size_t cx, cy;
	uint8_t ccolor;

	void initialize()
	{
		buffer = (uint16_t *)0x0B8000;
		cx = cy = 0;
		set_color(COLOR_WHITE, COLOR_BLACK);
		clear();
	}

	void putchar(char chr)
	{
		if (chr != '\n') // newline characters are special VGA specific things
		{
			buffer[cy * WIDTH + cx] = ccolor << 8 | chr;
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
				cx = 0;
				cy = HEIGHT - 1;
				scroll();
			}
			else
			{
				cx = 0;
			}
		}
	}

	void puts(const char *str)
	{
		char chr = '\0';
		size_t idx = 0;
		while ((chr = str[idx++]) != '\0')
		{
			putchar(chr);
		}
		putchar('\n');
	}

	void scroll()
	{
		memcpy(buffer, buffer + WIDTH, WIDTH * (HEIGHT - 1) * sizeof(uint16_t));
		memset(buffer + WIDTH * (HEIGHT - 1), 0, WIDTH * sizeof(uint16_t));
	}

	void set_color(enum Colors foreground, enum Colors background)
	{
		ccolor = background << 4 | foreground;
	}

	void clear() {
		memset(buffer, 0, WIDTH * HEIGHT * sizeof(uint16_t));
		cx = cy = 0;
	}
}