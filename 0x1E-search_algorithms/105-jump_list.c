#include "search_algos.h"

/**
 * jump_list - Function to search through a singly linked list of integers
 * using the Jump search algorithm, where the root of the size is the jump step
 *
 * @list: A singly linked list of integers
 * @size: The number of elements in the list.
 * @value: Value to be searched for
 * Return: Index of the value or -1 if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t le = 0, jmp = sqrt(size), u_bnd = le + jmp;
	int val_found = 0;

	if (!array || size == 0)
		return (-1);


	while (le < size)
	{
		printf("Value checked array[%ld] = [%d]\n", le, array[le]);
		if (val_found)
		{
			if (value == array[le])
				return (le);
			else if (le < u_bnd)
				le++;
			else
				return (-1);
		}
		else if ((u_bnd < size && array[u_bnd] >= value) || (u_bnd > size))
		{
			val_found = 1;
			printf("Value found between indexes [%ld] and [%ld]\n", le, u_bnd);
		}
		else if (array[le] == value)
			return (le);

		if (!val_found)
		{
			le += jmp;
			u_bnd += jmp;
		}
	}

	return (-1);
}
