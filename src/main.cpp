#include "kernel/terminal.hpp"

void main()
{
	Terminal::initialize();
	Terminal::putchar('a');
	Terminal::putchar('\n');
	Terminal::putchar('b');
}