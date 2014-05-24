#include "kernel/terminal.hpp"
#include "kernel/interrupt.hpp"

void main() {
	Terminal::initialize();
	Terminal::set_color(Terminal::COLOR_LIGHT_GREEN, Terminal::COLOR_BLACK);
	Terminal::puts("Terminal initialized.");

	Terminal::set_color(Terminal::COLOR_WHITE, Terminal::COLOR_BLACK);
	Terminal::puts("Initializing interrupts...");

	Interrupt::initialize();

	Terminal::set_color(Terminal::COLOR_LIGHT_GREEN, Terminal::COLOR_BLACK);
	Terminal::puts("Interrupts initialized.");

	int a = 645 / 0;
}