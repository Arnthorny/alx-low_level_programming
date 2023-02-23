#include "main.h"
/**
  * print_line- Prints Line of given length n.
  * @n : Length of line
  *
  */

void print_line(int n)
{
	int i = 0;

	while (i < n)
	{
		_putchar('_');
		i++;
	}
	_putchar('\n');
}

