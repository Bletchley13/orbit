#include "terminal.hpp"
#include "std.hpp"
#include "cstd/string.hpp"
#include "io.hpp"

namespace Terminal {
	uint16_t *buffer;
	size_t cx, cy;
	uint8_t ccolor;
	bool cursor_move;

	void initialize() {
		buffer = (uint16_t *)0x0B8000;
		cx = cy = 0;
		set_color(COLOR_WHITE, COLOR_BLACK);
		cursor_move = true;
		clear();
	}

	void putchar(char chr) {
		if (chr != '\n') { // newline characters are special VGA specific things
			buffer[cy * WIDTH + cx] = ccolor << 8 | chr;
		} else {
			// force a newline
			cx = WIDTH;
		}


		if (++cx >= WIDTH) {
			if (++cy >= HEIGHT) {
				cx = 0;
				cy = HEIGHT - 1;
				scroll();
			} else {
				cx = 0;
			}
		}

		cursor_update();
	}

	void puts(const char *str) {
		bool cursor_move_prev = cursor_move;
		cursor_move = false;
		char chr = '\0';
		size_t idx = 0;
		while ((chr = str[idx++]) != '\0') {
			putchar(chr);
		}
		putchar('\n');
		cursor_move = cursor_move_prev;
		cursor_update();
	}

	void scroll() {
		// copy from line 2 char 1 to line 1 char 1
		memcpy(buffer, buffer + WIDTH, WIDTH * (HEIGHT - 1) * sizeof(uint16_t));
		// clear last line
		memset(buffer + WIDTH * (HEIGHT - 1), 0, WIDTH * sizeof(uint16_t));
	}

	void set_color(enum Colors foreground, enum Colors background) {
		ccolor = background << 4 | foreground;
	}

	void clear() {
		uint16_t entry = (COLOR_BLACK << 4 | COLOR_WHITE) << 8 | ' ';
		for (size_t offset = 0; offset < WIDTH * HEIGHT; ++offset) {
			buffer[offset] = entry;
		}
		cx = cy = 0;
	}

	void cursor_update() {
		if (cursor_move == true) {
			uint16_t position = cy * WIDTH + cx;

			IO::outb(0x03D4, 0x0F);
			IO::outb(0x03D5, (uint8_t)(position & 0xFF));
			IO::outb(0x03D4, 0x0E);
			IO::outb(0x03D5, (uint8_t)((position >> 8) & 0xFF));
		}
	}
}