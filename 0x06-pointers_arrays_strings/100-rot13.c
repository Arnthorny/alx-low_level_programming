#include "main.h"


/**
  * isLetter - Determine if a char is a letter..
  * @c: Char to check
  * Return: 0 if char is not, 1 if lowercase, 2 if uppercase .
  */

int isLetter(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (2);
	return (0);
}

/**
  * rot13 - Encode a string using rot13.
  * @s: String to be encoded
  * Return: Pointer to the string.
  */
char *rot13(char *s)
{
	int i = 0, type, base;

	do {
		type = isLetter(s[i]);
		if (type)
		{
			base = type == 1 ? 97 : 65;
			s[i] = ((s[i] - base + 13) % 26) + base;
		}
		i++;
	} while (s[i]);

	return (s);
}
