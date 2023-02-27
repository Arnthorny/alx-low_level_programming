#include "main.h"

/**
  * _strcpy - Copies a string from src to destination.
  * @dest: Destination param.
  * @src: Source param.
  * Return: Pointer to dest
  */

char *_strcpy(char *dest, char *src)
{
	char *destCopy = dest;

	while (*src != '\0')
	{
		*destCopy = *src;
		src++;
		destCopy++;
		if (*src == '\0')
			*destCopy = *src;
	}
	return (dest);
}
