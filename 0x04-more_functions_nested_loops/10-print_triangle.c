#include "main.h"
/**
  * print_triangle- Prints a triangle of given height.
  * @size : Size of triangle.
  *
  */

void print_triangle(int size)
{
	int i = 0, space, j;

	while (i < size)
	{
		j = 0;
		space = size - i - 1;

		while (space)
		{
			_putchar(' ');
			space--;
		}
		while (j <= i)
		{
			_putchar('#');
			j++;
		}
		_putchar('\n');
		i++;
	}
	if (size <= 0)
		_putchar('\n');
}

