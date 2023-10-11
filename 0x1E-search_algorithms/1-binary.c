#include "search_algos.h"


/**
  * print_srch_arr - This function prints the slice of array being searched
  *
  * @start: The start pointer.
  * @end: Pointet to the end of the slice.
  */
void print_srch_arr(int *start, int *end)
{
	int *tmp = start;

	printf("Searching in array: ");
	while (tmp < end)
	{
		printf("%d, ", *tmp);
		tmp++;
	}

	printf("%d\n", *tmp);
}


/**
 * binary_search - Function to search through an array of integers
 * using the Binary search algorithm.
 *
 * @array: An array of integers
 * @size: The number of elements in the array.
 * @value: Value to be searched for
 * Return: Index of the value or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
	size_t le = 0, ri = size - 1, mid;

	if (!array || size == 0)
		return (-1);

	while (le <= ri)
	{
		mid  = (le + (ri - le) / 2);
		print_srch_arr(&array[le], &array[ri]);
		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			le = mid + 1;
		else if (array[mid] > value)
			ri = mid - 1;
	}

	return (-1);
}
