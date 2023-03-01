#include "main.h"

/**
  * _strncpy - Copies src string into dest upto a given n.
  * @dest: Destination param.
  * @src: Source param.
  * @n: Number of bytes to use in src
  * Return: Pointer to resulting dest
  */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0, srcEnd = 0;

	while (i < n)
	{
		if (src[i] && !srcEnd)
			dest[i] = src[i];
		else
		{
			dest[i] = '\0';
			srcEnd = 1;
		}
		i++;
	}
	return (dest);
}
