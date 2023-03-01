#include "main.h"

/**
  * string_toupper - Change all lowercase letters to uppercase.
  * @str: String to be upped
  * Return: Pointer to the string.
  */

char *string_toupper(char *str)
{
	int i = 0, mod;
	char val;

	do {
		val = str[i];
		if (val >= 'a' && val <= 'z')
		{
			mod = (val - 'a') % 26;
			str[i] = 65 + mod;
		}
		i++;
	} while (val);
	return (str);
}
