#include "main.h"

/**
  * _strcmp - Compares two strings.
  * @s1: The first string.
  * @s2: The second string.
  * Return: 0 if equal, else integer value of difference
  */

int _strcmp(char *s1, char *s2)
{
	int cmp = 0, i = 0, diff;

	while (s1[i] && s2[i])
	{
		diff = s1[i] - s2[i];
		if ((diff < cmp) && cmp <= 0)
			cmp = diff;
		else if ((diff > cmp) && cmp >= 0)
			cmp = diff;
		i++;
	}
	return (cmp);
}
