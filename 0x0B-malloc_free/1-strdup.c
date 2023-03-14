#include "main.h"
#include <stdlib.h>

/**
  * _strcpy- Copies n bytes from memory area.
  * @dest: Pointer to memory destination area.
  * @src: Pointer to memory src area.
  * Return: Pointer to memory area dest.
  */

char *_strcpy(char *dest, char *src)
{
	unsigned int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

/**
  * _strlen- Returns the length of a string.
  * @str: Pointer to string.
  * Return: Length of string.
  */

int _strlen(char *str)
{
	return (*str ? 1 + (_strlen(str + 1)) : 0);
}


/**
  * _strdup- Copies a given string.
  * @str: Pointer to string.
  * Return: Pointer to string's copy.
  */

char *_strdup(char *str)
{
	char *sCopy;

	if (!str)
		return (NULL);
	sCopy = malloc(sizeof(*str) * (_strlen(str) + 1));
	if (!sCopy)
		return (NULL);

	return (_strcpy(sCopy, str));
}
