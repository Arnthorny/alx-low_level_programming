#include "main.h"

/**
  * _strchr - Locates a character in a string.
  * @s: Pointer to string.
  * @c: Character to be found.
  * Return: Pointer to first occurence of char.
  */

char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (*s == c ? s : NULL);
}
