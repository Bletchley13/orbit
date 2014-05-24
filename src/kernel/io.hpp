#ifndef _KERNEL_IO_HPP
#define _KERNEL_IO_HPP
#include "std.hpp"

namespace IO {
	void outb(uint16_t port, uint8_t val);
	uint8_t inb(uint16_t port);
}
#endif