#include "main.h"

/**
  * _strlen - Determine a string length.
  * @s: String
  * Return: Length of string.
  */
int _strlen(char *s)
{
	int count = 0;

	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

/**
  * infinite_add - Add two strings as numbers..
  * @n1: String 1
  * @n2: String 2
  * @r: Buffer to store value
  * @size_r: Size of buffer
  * Return: Pointer to the buffer.
  */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int sum = 0, i = 0, j = 0, lBit1, lBit2;
	int len1 = _strlen(n1), len2 = _strlen(n2);

	r[size_r - 1] = '\0';
	size_r--;

	if (size_r < 1 || len1 > size_r || len2 > size_r)
		return (0);
	while ((i < size_r) &&  ((len1 > i) || (len2 > i)))
	{
		lBit1 = (len1 > i) ? n1[len1 - i - 1] - '0' : 0;
		lBit2 = (len2 > i) ? n2[len2 - i - 1] - '0' : 0;
		sum = lBit1 + lBit2 + sum;
		r[size_r - i - 1] = (sum % 10) + '0';
		i++;
		sum = i <= size_r ? sum / 10 : sum;
	}
	if (size_r > i)
	{
		if (sum)
		{
			r[size_r - (i++) - 1] = (sum % 10) + '0';
			sum /= 10;
		}

		if (size_r - i)
		{
			j = 0;
			while ((size_r - i) && r[size_r - i + j])
			{
				r[j] = r[size_r - i + j];
				j++;
			}
			r[j] = '\0';
		}
	}
	return ((sum == 0 && i >= len1 && i >= len2) ? r : 0);
}
