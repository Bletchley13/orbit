#include "string.hpp"
#include "std.hpp"

void *memcpy(void *destination, const void *source, size_t num)
{
	uint8_t *dest = (uint8_t *) destination;
	uint8_t *src = (uint8_t *) source;

	for (size_t offset = 0; offset < num; ++offset)
	{
		dest[offset] = src[offset];
	}

	return destination;
}

void *memset(void *ptr, int val, size_t num)
{
	uint8_t *point = (uint8_t *)ptr;
	uint8_t v = (uint8_t) val;

	for (size_t offset = 0; offset < num; ++offset)
	{
		point[offset] = v;
	}

	return ptr;
}