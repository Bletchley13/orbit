#include "kernel/terminal.hpp"

void main()
{
	Terminal::initialize();
	char str[2];
	str[1] = '\0';
	for (int i = 0; i < 27; ++i) {
		str[0] = i + 65;
		Terminal::puts(str);
	}
}