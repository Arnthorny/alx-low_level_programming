#include "main.h"
/**
  * times_table - Prints the 9 times table.
  */

void times_table(void)
{
	int i = 0;

	while (i < 10)
	{
		int j = 0;

		while (j < 10)
		{
			int p = i * j;

			if (p / 10)
				_putchar((p / 10) + '0');
			_putchar((p % 10) + '0');
			if (j < 9)
			{
				_putchar(',');
				_putchar(' ');
				if (p <= 9)
					_putchar(' ');
			}
			j++;
		}
		_putchar('\n');
		i++;
	}
}
