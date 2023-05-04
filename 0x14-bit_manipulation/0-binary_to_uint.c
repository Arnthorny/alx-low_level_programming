#include "main.h"
/**
  * zeroOrOne - Converts char to digit
  * @c: Char to convert.
  * Return: 0 or 1 if valid else -1.
  */

short int zeroOrOne(char c)
{
	return (c != '1' && c != '0' ? -1 : c & 0xf);
}

/**
  * binary_to_uint - Converts a binary num (str) to a uint.
  * @b: Pointer to binary string
  * Return: The converted number or 0 if b is NULL or b contains invalid char
  */
unsigned int binary_to_uint(const char *b)
{
	unsigned int conv = 0, i = 0;
	short int ch;

	while (b && b[i])
	{
		ch = zeroOrOne(b[i]);
		if (ch == -1)
			return (0);
		conv = (conv * 2) + ch;
		i++;
	}
	return (conv);
}
