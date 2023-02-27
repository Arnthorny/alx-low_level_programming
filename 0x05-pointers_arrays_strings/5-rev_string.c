#include "main.h"

/**
  * count_string - Counts chars in a string.
  * @s: Pointer to the string.
  * Return: String count.
  */

int count_string(char *s)
{
	char *sCopy = s;

	while (*sCopy != '\0')
		sCopy++;
	return (sCopy - s);
}

/**
  * rev_string - Reverses a given string .
  * @s: Pointer to the string.
  */

void rev_string(char *s)
{
	char *sEnd = s + count_string(s) - 1;
	char tmp;

	while (s <= sEnd)
	{
		tmp = *s;
		*s = *sEnd;
		*sEnd = tmp;
		s++;
		sEnd--;
	}
}
