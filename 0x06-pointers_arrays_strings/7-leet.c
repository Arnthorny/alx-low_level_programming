#include "main.h"



/**
  * leet - Encode a string into 1337 (leet).
  * @s: String to be encoded
  * Return: Pointer to the string.
  */
char *leet(char *s)
{
	char *lt[] = {"aA4", "eE3", "oO0", "tT7", "lL1"};
	int i, j;
	char v;

	do {
		v = s[i];
		for (j = 0; j < 5; j++)
		{
			if ((v == lt[j][0]) || (v == lt[j][1]))
			{
				s[i] = lt[j][2];
				break;
			}
		}
		i++;
	} while (v);

	return (s);
}
