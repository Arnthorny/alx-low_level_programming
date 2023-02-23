#include "main.h"
/**
  * print_numbers- Prints all numbers from 0 to 9.
  *
  */

void print_numbers(void)
{
	int i = 0;

	while (i < 10)
	{
		_putchar(48 + i);
		i++;
	}
	_putchar('\n');
}

