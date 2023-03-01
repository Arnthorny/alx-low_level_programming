#include "main.h"

/**
  * _strcat - Concatenates two strings.
  * @dest: Destination param.
  * @src: Source param.
  * Return: Pointer to resulting dest
  */

char *_strcat(char *dest, char *src)
{
	char *destCopy = dest;
	int destEnd = 0;

	while (*src)
	{
		if (*destCopy == '\0' && !destEnd)
			destEnd = 1;
		if (destEnd)
		{
			*destCopy = *src;
			src++;
		}
		destCopy++;
	}
	return (dest);
}
