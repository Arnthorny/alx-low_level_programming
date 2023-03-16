#include "main.h"
/**
  * _slen- Returns the length of a string.
  * @str: Pointer to string.
  * Return: Length of string.
  */

unsigned int _slen(char *str)
{
	return (str && *str ? 1 + (_slen(str + 1)) : 0);
}


/**
  * string_nconcat- Concatenates two strings.
  * @s1: Pointer to string 1.
  * @s2: Pointer to string 2.
  * @n: Number of bytes of s2 to be used
  * Return: Pointer to concatenated string.
  */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *sCat;
	unsigned int i = 0, len2 = _slen(s2);
	unsigned int lenBoth = _slen(s1) + (n >= len2 ? len2 : n);

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
