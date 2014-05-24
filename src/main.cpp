#include "kernel/terminal.hpp"

void main()
{
	Terminal::initialize();
	Terminal::puts("Hello, world!");
	Terminal::puts("This is on a new line.");
}