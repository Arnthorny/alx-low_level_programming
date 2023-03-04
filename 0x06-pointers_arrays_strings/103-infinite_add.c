#include "main.h"


int _strlen(char *s);
int *a_lB(char *r, int size_r, int len1, int len2, char *n1, char *n2, int *v);
void shift_bytes(int i, int size_r, char *r);

/**
  * infinite_add - Add two strings as numbers.
  * @n1: String 1
  * @n2: String 2
  * @r: Buffer to store value
  * @size_r: Size of buffer
  * Return: Pointer to the buffer.
  */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, sum;
	int len1 = _strlen(n1), len2 = _strlen(n2);
	int v[2] = {0};

	r[size_r - 1] = '\0';
	size_r--;

	if (size_r < 1 || len1 > size_r || len2 > size_r)
		return (0);

	a_lB(r, size_r, len1, len2, n1, n2, v);
	i = v[0];
	sum = v[1];

	if (size_r > i)
	{
		if (sum)
		{
			r[size_r - (i++) - 1] = (sum % 10) + '0';
			sum /= 10;
		}

		if (size_r - i)
			shift_bytes(i, size_r, r);

	}
	return ((sum == 0 && i >= len1 && i >= len2) ? r : 0);
}

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
  * a_lB - Adds the least significant digits.
  * @r: Pointer to buffer
  * @size_r: Size of buffer
  * @n1: Pointer to n1.
  * @n2: Pointer to n2.
  * @len1: Length of n1.
  * @len2: Length of n2.
  * @v: Return array
  * Return: Pointer to array containing sum and i.
  */
int *a_lB(char *r, int size_r, int len1, int len2, char *n1, char *n2, int *v)
{
	int lBit1, lBit2, i = v[0], sum = v[1];

	while ((i < size_r) &&  ((len1 > i) || (len2 > i)))
	{
		lBit1 = (len1 > i) ? n1[len1 - i - 1] - '0' : 0;
		lBit2 = (len2 > i) ? n2[len2 - i - 1] - '0' : 0;
		sum = lBit1 + lBit2 + sum;
		r[size_r - i - 1] = (sum % 10) + '0';
		i++;
		sum = i <= size_r ? sum / 10 : sum;
	}
	v[0] = i;
	v[1] = sum;

	return (v);
}

/**
  * shift_bytes - Shift bytes in a buffer if buffer is larger than required.
  * @size_r: Size of buffer
  * @i: Current index.
  * @r: Buffer
  * Return: Length of strin.
  */
void shift_bytes(int i, int size_r, char *r)
{
	int j = 0;

	while ((size_r - i) && r[size_r - i + j])
	{
		r[j] = r[size_r - i + j];
		j++;
	}
	r[j] = '\0';
}
