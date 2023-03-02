#include "main.h"


/**
  * detCase - Determine if a char is a lower or upper.
  * @c: Char to check
  * Return: First letter of base.
  */

int detCase(char c)
{
	int test = 0, caseStart = 0;
	int isUpper = c >= 'A' && c <= 'Z';

	test = isUpper && (caseStart = 65);
	test = test || (caseStart = 97);

	return (caseStart);
}


/**
  * rot13 - Encode a string using rot13.
  * @s: String to be encoded
  * Return: Pointer to the string.
  */
char *rot13(char *s)
{
	int i = 0, cBase;
	char v;

	do {
		v = s[i];
		if ((v >= 'a' && v <= 'z') || (v >= 'A' && v <= 'Z'))
		{
			cBase = detCase(v);
			s[i] = ((v - cBase + 13) % 26) + cBase;
		}
		i++;
	} while (v);

	return (s);
}
