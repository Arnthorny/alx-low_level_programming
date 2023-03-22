#include "function_pointers.h"


/**
  * array_iterator - A fn that executes another fn on array elems
  * @array: Pointer to the array
  * @size: Size of the array
  * @action: Pointer to Fn to be executed on each array elem.
  */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i = 0;

	while (i < size)
		action(array[i++]);
}
