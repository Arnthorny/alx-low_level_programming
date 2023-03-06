#include "main.h"

/**
  * _strpbrk - Searches a given string s for a set of bytes.
  * @s: Pointer to string.
  * @accept: Substring containing set of bytes.
  * Return: Pointer to first occurence of matching bytes or NULL.
  */

char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s)
	{
		i = 0;
		while (accept[i])
		{
			if (accept[i] == *s)
				return (s);
			i++;
		}
		s++;
	}
	return (NULL);
}
