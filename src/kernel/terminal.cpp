#include "terminal.hpp"
#include <stdint.h>
namespace Terminal
{
	void initialize()
	{
		buffer = (uint16_t *)0x0B8000;
	}
}