#include "function_pointers.h"

/**
  * int_index - A fn that searches for an integer.
  * @array: Pointer to the array
  * @size: Size of the array
  * @cmp: Pointer to Fn that compares values.
  * Return: Index if element is found else -1
  */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	while (i < size)
	{
		if (cmp(array[i++]))
			return (i - 1);
	}
	return (-1);
}
