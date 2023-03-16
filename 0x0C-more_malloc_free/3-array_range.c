#include "main.h"

/**
  * array_range - Create an array of integers given a range.
  * @min: Minimum value.
  * @max: Maximum value.
  * Return: Pointer to allocated memory
  */
int *array_range(int min, int max)
{
	int *ptr, sizeArr, i;

	if (min > max)
		return (NULL);

	sizeArr = max - min + 1;
	ptr = malloc(sizeof(*ptr) * (sizeArr));
	if (!ptr)
		return (NULL);

	for (i = 0; i < sizeArr; i++)
		ptr[i] = min + i;
	return (ptr);
}
