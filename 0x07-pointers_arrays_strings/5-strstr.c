#include "main.h"

/**
  * _strstr - Searches a given string for a substring.
  * @haystack: Pointer to string.
  * @needle: Substring.
  * Return: Pointer to beginning of located substring.
  */

char *_strstr(char *haystack, char *needle)
{
	int i, inSub;

	while (*haystack)
	{
		i = 0;
		while (needle[i])
		{
			if (needle[i] == haystack[i])
				inSub = 1;
			else
			{
				inSub = 0;
				break;
			}
			i++;
		}
		if (inSub)
			return (haystack);
		haystack++;
	}
	return (NULL);
}
