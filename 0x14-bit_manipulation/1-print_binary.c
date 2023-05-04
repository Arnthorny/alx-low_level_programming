#include "main.h"

/**
  * prnt_b - Recursive function to aid in printing bits
  * @i: Current index
  * @n: Integer for conversion
  */

void prnt_b(unsigned long int n, int i)
{
	if (n == 0)
	{
		if (i == 0)
			_putchar(n + '0');
		return;
	}
	prnt_b(n >> 1, i + 1);
	_putchar((n & 1) + '0');
}

/**
  * print_binary- Prints the binary rep of a uint.
  * @n: Unsigned long int number
  */

void print_binary(unsigned long int n)
{
	prnt_b(n, 0);
}
