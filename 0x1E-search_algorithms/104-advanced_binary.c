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
 * helper_bin - Helper function to search through an array of integers
 * using the Binary search algorithm.
 *
 * @array: An array of integers
 * @size: The number of elements in the array.
 * @value: Value to be searched for
 * @offset: Offset index to start from.
 * Return: Index of the first value or -1 if not found
 */
int helper_bin(int *array, size_t size, int value, size_t offset)
{
	size_t le = 0, ri = size - 1, mid;

	if (!array || size == 0)
		return (-1);

	mid  = (le + (ri - le) / 2);
	print_srch_arr(&array[le], &array[ri]);

	if (size == 1)
		return ((array[mid] == value ? (int)(offset + mid) : -1));
	else if (array[mid] < value)
	{
		le = mid + 1;
		return (helper_bin(&array[le], (ri + 1 - le), value, le + offset));
	}
	else if (array[mid] >= value)
	{
		if (array[mid] == value && mid == 0)
			return (mid + offset);
		ri = mid;
		return (helper_bin(&array[le], (ri + 1 - le), value, le + offset));
	}
	else
		return (mid + offset);
}


/**
 * advanced_binary- Function to search through an array of integers
 * using the Binary search algorithm.
 *
 * @array: An array of integers
 * @size: The number of elements in the array.
 * @value: Value to be searched for
 * Return: Index of the first value or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	return (helper_bin(array, size, value, 0));
}
