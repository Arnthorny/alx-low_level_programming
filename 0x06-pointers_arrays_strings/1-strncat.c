#include "main.h"

/**
  * _strncat - Concatenates two strings upto a given n.
  * @dest: Destination param.
  * @src: Source param.
  * @n: Number of bytes to use in src
  * Return: Pointer to resulting dest
  */

char *_strncat(char *dest, char *src, int n)
{
	char *destCopy = dest;
	int destEnd = 0, i = 0;

	while (*src && i < n)
	{
		if (*destCopy == '\0' && !destEnd)
			destEnd = 1;
		if (destEnd)
		{
			*destCopy = *src;
			src++;
			i++;
		}
		destCopy++;
	}
	return (dest);
}
