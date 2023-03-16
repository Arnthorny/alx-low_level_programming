#include "main.h"

/**
  * malloc_checked - This function allocates memory with malloc
  * @b: number of bytes to allocate
  * Return: Pointer to allocated memory
  */


void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if (!ptr)
		exit(98);
	return (ptr);
}
