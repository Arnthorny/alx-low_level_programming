#include "main.h"

/**
  * _strspn - Gets the length of a prefixed substring.
  * @s: Pointer to string.
  * @accept: Substring.
  * Return: Num of bytes in s consisting of only bytes in accept.
  */

unsigned int _strspn(char *s, char *accept)
{
	int count = 0, inA, i;

	while (*s)
	{
		i = 0;
		while (accept[i])
		{
			inA = 0;
			if (accept[i] == *s)
			{
				inA = 1;
				count++;
				break;
			}
			i++;
		}
		if (!inA)
			return (count);
		s++;
	}
	return (count);
}
