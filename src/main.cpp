#include "kernel/terminal.hpp"

void main()
{
	Terminal::initialize();
	Terminal::set_color(Terminal::COLOR_LIGHT_GREEN, Terminal::COLOR_BLACK);
	Terminal::puts("Lime!");
	Terminal::set_color(Terminal::COLOR_LIGHT_RED, Terminal::COLOR_BLACK);
	Terminal::puts("Red!");
}