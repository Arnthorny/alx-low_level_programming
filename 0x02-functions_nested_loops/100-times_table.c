#include "main.h"
/**
  * print_times_table - Prints the n times table.
  * @n: The integer
  */

void print_times_table(int n)
{
	int i = 0;

	if ((n < 0) || (n > 15))
	{
		return;
	}
	while (i <= n)
	{
		int j = 0;

		while (j <= n)
		{
			int p = i * j;

			if (p / 10)
				_putchar((p / 10) + '0');
			_putchar((p % 10) + '0');
			if (j < n)
			{
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
				if (!(p / 10))
					_putchar(' ');
			}
			j++;
		}
		_putchar('\n');
		i++;
	}
}
