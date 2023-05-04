#include "main.h"
#include <limits.h>

/**
  * get_bit - Get the value of a bit at a given index.
  * @n: Number to be checked.
  * @index: Given index.
  * Return: The value of bit at that index.
  */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask;

	if (index >= (sizeof(unsigned long) * 8))
		return (-1);

	mask = 1 << index;
	return ((n & mask) >> index);
}
