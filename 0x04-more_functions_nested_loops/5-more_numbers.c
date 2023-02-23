#include "main.h"
/**
  * more_numbers - Prints all numbers, 14X.
  *
  */

void more_numbers(void)
{
	int i = 0;

	while (i < 10)
	{
		int j = 0;

		while (j < 15)
		{
			if (j >= 10)
				_putchar(48 + (j / 10));
			_putchar(48 + (j % 10));
			j++;
		}
		_putchar('\n');
		i++;
	}
}

