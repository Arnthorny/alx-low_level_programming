#include "main.h"
#include <stdio.h>

/**
  * get_endianness - Function to check endianness of sys.
  * Return: 0 if big endian, 1 if little endian.
  */

int get_endianness(void)
{
	int test = 1;

	return (*(char *)&test);
}
