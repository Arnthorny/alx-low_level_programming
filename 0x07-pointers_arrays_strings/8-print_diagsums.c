#include "main.h"
#include <stdio.h>

/**
  * print_diagsums - Prints the sum of the two diagonals of a square mat.
  * @a: Pointer to the matrix.
  * @size: Size of the matrix.
  */

void print_diagsums(int *a, int size)
{
	int tot = size * size;
	int i = 0, j = 0, row = 0;
	int diagsum1 = 0, diagsum2 = 0;
	
	while (row < tot)
	{
		j = 0;
		while (j < size)
		{
			i = row + j;
			if (!(i % (size + 1)))
				diagsum1 += a[i];
			if (!(i % (size - 1)) && i && i < tot - 1)
				diagsum2 += a[i];
			j++;
		}
		row += size;
	}
	printf("%d, %d\n", diagsum1, diagsum2);
}
