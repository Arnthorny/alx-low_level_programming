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

	int sum = 0, i = 0;
	int len1 = _strlen(n1), len2 = _strlen(n2);

	r[--size_r] = '\0';
	size_r--;
	if (len1 > size_r || len2 > size_r || size_r <= 0)
		return (0);
	do {
		len1--;
		len2--;
		if ((len1 < 0) && (len2 < 0))
		{
			r[size_r] = (sum % 10) + '0';
			sum /= 10;
			break;
		}
		else if (len1 < 0 && len2 >= 0)
			sum = (n2[len2] - '0') + sum;
		else if (len2 < 0 && len1 >= 0)
			sum = (n1[len1] - '0') + sum;
		else
			sum = (n1[len1] - '0') + (n2[len2] - '0') + sum;

		r[size_r] = (sum % 10) + '0';
		sum /= 10;
	} while (--size_r >= 0);

	if (size_r)
	{
		while (r[i + size_r])
		{
			r[i] = r[i + size_r];
			i++;
		}
		r[i] = '\0';
	}
	return (sum == 0 ? r : 0);
}
