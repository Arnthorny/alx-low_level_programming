#include "main.h"
#include <stdlib.h>

/**
  * _slen- Returns the length of a string.
  * @str: Pointer to string.
  * Return: Length of string.
  */

int _slen(char *str)
{
	return (str && *str ? 1 + (_slen(str + 1)) : 0);
}


/**
  * str_concat- Concatenates two strings.
  * @s1: Pointer to string 1.
  * @s2: Pointer to string 2
  * Return: Pointer to concatenated string.
  */

char *str_concat(char *s1, char *s2)
{
	char *sCat;
	int i = 0;
	int lenBoth = _slen(s1) + _slen(s2);

	sCat = malloc(sizeof(char) * (lenBoth + 1));

	if (!sCat)
		return (NULL);

	sCat[lenBoth] = '\0';
	while (i < lenBoth)
	{
		if (!(s1 && *s1) && *s2)
		{
			sCat[i] = *s2;
			s2++;
		}
		else if (s1)
		{
			sCat[i] = *s1;
			s1++;
		}

		i++;
	}
	return (sCat);
}
