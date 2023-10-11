#include "search_algos.h"

/**
 * linear_search - Function to search through an array of integers
 * using the Linear search algorithm.
 *
 * @array: An array of integers
 * @size: The number of elements in the array.
 * @value: Value to be searched for
 * Return: Index of the value or -1 if not found
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (!array || size == 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
