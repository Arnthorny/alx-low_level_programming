#include "main.h"

/**
  * _memset- Fills Memory with a constant byte.
  * @s: Pointer to memory area.
  * @b: Byte to fill memory with.
  * @n: Number of bytes to use in memory area.
  * Return: Pointer to memory area s
  */
void *_memset(void *s, int b, unsigned int n)
{
	unsigned int i;
	unsigned char *ptr = s;

	for (i = 0; i < n; i++)
		ptr[i] = b;
	return (s);
}

/**
  * _calloc - Function allocates memory for an array with malloc
  * @nmemb: number of array members.
  * @size: Size of array elements
  * Return: Pointer to allocated memory
  */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;

	if (nmemb <= 0 || size <= 0)
		return (NULL);

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	return (_memset(ptr, 0, (nmemb * size)));
}
