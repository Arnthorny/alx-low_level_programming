#include "main.h"

/**
  * set_bit - Set the value of a bit to 1 at a given index.
  * @n: Pointer to number to be checked.
  * @index: Given index.
  * Return: 1 if success else -1.
  */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (!n || index >= (sizeof(unsigned long) * 8))
		return (-1);

	mask = 1 << index;

	*n |= mask;
	return (1);
}
