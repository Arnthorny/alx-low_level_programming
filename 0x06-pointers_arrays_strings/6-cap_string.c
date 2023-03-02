#include "main.h"


/**
  * dl_chck - Check if char is a delimiter.
  * @c: Char to be checked
  * Return: 1 if char is a delimiter, 0 otherwise.
  */

int dl_chck(char c)
{
	char *del = " \t\n,;.!?\"(){}";

	while (*del)
	{
		if (c == *del)
			return (1);
		del++;
	}
	return (0);
}
/**
  * cap_string - Capitalizes each word in a string.
  * @s: String to be capitalized
  * Return: Pointer to the string.
  */
char *cap_string(char *s)
{
	char v;
	int i = 0, mod;

	do {
		v = s[i];
		if (i == 0 && (v >= 'a' && v <= 'z'))
		{
			mod = (v - 'a') % 26;
			s[i] = 65 + mod;
		}
		else if (v && dl_chck(v) && (s[i + 1] >= 'a' && s[i + 1] <= 'z'))
		{
			mod = (s[i + 1] - 'a') % 26;
			s[i + 1] = 65 + mod;
		}
		i++;
	} while (v);
	return (s);
}
