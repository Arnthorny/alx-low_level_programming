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
 * bin_srch - Function to search through an array of integers
 * using the Binary search algorithm.
 *
 * @array: An array of integers
 * @size: The number of elements in the array.
 * @value: Value to be searched for
 * @offset: Offset index from original array.
 * Return: Index of the value or -1 if not found
 */
int bin_srch(int *array, size_t size, int value, size_t offset)
{
	size_t le = 0, ri = size - 1, mid;

	if (!array || size == 0)
		return (-1);

	while (le <= ri)
	{
		mid  = (le + (ri - le) / 2);
		print_srch_arr(&array[le], &array[ri]);
		if (array[mid] == value)
		{
			if (mid >= 1 && array[mid - 1] == value)
				ri = mid - 1;
			else
				return (mid + offset);
		}
		else if (array[mid] < value)
			le = mid + 1;
		else if (array[mid] >= value)
			ri = mid - 1;
	}

	return (-1);
}

/**
 * min - Return the minimum of two values.
 *
 * @val1: First value.
 * @val2: Second value.
 * Return: Minimum value.
 */
size_t min(size_t val1, size_t val2)
{
	return (val1 < val2 ? val1 : val2);
}


/**
 * exponential_search - Function to search through an array of integers
 * using the Exponential search algorithm.
 *
 * @array: An array of integers
 * @size: The number of elements in the array.
 * @value: Value to be searched for
 * Return: Index of the value or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t le = 0, ri = 0;

	if (!array || size == 0)
		return (-1);

	while (ri <= size)
	{
		ri = ri != 0 ? ri * 2 : 1;
		if ((ri >= size) || array[ri] >= value)
		{
			printf("Value found between indexes [%ld] and [%ld]\n",
					le, min(ri, size - 1));
			return (bin_srch(&array[le], (min(ri + 1, size) - le), value, le));
		}
		else if (ri < size)
			printf("Value checked array[%ld] = [%d]\n", ri, array[ri]);
		le = ri;
	}
	return (-1);
}
