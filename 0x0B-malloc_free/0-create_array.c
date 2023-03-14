#include "main.h"
#include <stdlib.h>

/**
  * _memset- Fills Memory with a constant byte.
  * @s: Pointer to memory area.
  * @b: Byte to fill memory with.
  * @n: Number of bytes to use in memory area.
  * Return: Pointer to memory area s
  */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}


/**
  * create_array- creates an array and fills with a given char.
  * @size: Size of the array.
  * @c: Character to fill with
  * Return: Pointer to array.
  */

char *create_array(unsigned int size, char c)
{
	char *ptr = malloc(sizeof(char) * size);

	if (!ptr || !size)
		return (NULL);

	return (_memset(ptr, c, size));
}
