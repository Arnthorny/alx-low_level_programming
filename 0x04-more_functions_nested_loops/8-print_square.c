#include "main.h"
/**
  * print_square- Prints # square of given size.
  * @size : Size of square to print.
  *
  */

void print_square(int size)
{
	if (size <= 0)
		_putchar('\n');
	else
	{
		int i = 1;
		int sizeSquare = size * size;

		while (i <= sizeSquare)
		{
			_putchar('#');
			if ((i % size) == 0)
			{
				_putchar('\n');
			}
			i++;
		}
	}
}

