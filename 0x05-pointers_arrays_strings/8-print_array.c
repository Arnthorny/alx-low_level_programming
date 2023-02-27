#include "main.h"

/**
  * print_array - Prints n elements of an array of integers.
  * @a: Array of integers.
  * @n: Number of integers.
  */

void print_array(int *a, int n)
{
	int i = 0;

	while (i < n)
	{
		printf("%d", a[i]);
		i++;
		if (i < n)
			printf(", ");
	}
	printf("%c", 10);
}
