#include "main.h"
/**
  * print_diagonal- Prints Line of given length n.
  * @n : Length of diagonal line.
  *
  */

void print_diagonal(int n)
{
	int i = 0, space;

	while (i < n)
	{
		space = 0;

		while (space < i)
		{
			_putchar(' ');
			space++;
		}
		_putchar('\\');
		_putchar('\n');
		i++;
	}
	if (n <= 0)
		_putchar('\n');
}

