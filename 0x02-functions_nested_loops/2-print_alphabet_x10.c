#include "main.h"
/**
  * print_alphabet_x10 - Prints letters of alphabet in lowercase, 10X.
  *
  */

void print_alphabet_x10(void)
{
	int i = 0;

	while (i < 10)
	{
		int j = 0;

		while (j < 26)
		{
			_putchar(97 + j);
			j++;
		}
		_putchar('\n');
		i++;
	}
}

