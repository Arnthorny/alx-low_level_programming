#include "main.h"

/**
  * _memcpy- Copies n bytes from memory area.
  * @dest: Pointer to memory destination area.
  * @src: Pointer to memory src area.
  * @n: Number of bytes to copy from src memory area.
  * Return: Pointer to memory area dest.
  */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}
