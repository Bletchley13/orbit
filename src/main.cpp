#include "kernel/terminal.hpp"

void main() {
	Terminal::initialize();
	Terminal::puts("Terminal initialized.");
}