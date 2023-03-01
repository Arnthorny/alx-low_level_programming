#include "main.h"

/**
  * reverse_array - Reverses a given array .
  * @a: Pointer to the array.
  * @n: Size of given array
  */

void reverse_array(int *a, int n)
{
	int *aEnd = a + n - 1;
	int tmp;

	while (a <= aEnd)
	{
		tmp = *a;
		*a = *aEnd;
		*aEnd = tmp;

		a++;
		aEnd--;
	}
}
