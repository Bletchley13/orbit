io.hpp
======

### Description
Provides functions for manipulating IO.

### Functions
| Function Name | Usage/Description |
| --- | --- |
| `void IO::outb(uint16_t port, uint8_t val)` | Pushes the value `val` onto port `port`. |
| `uint8_t IO::inb(uint16_t port)` | Pushes the value from port `port` and returns it. |