#include "main.h"
#include <stdio.h>

/**
  * _chrloc - Locates a substring in a string.
  * @s: Pointer to string.
  * @c: substring to be searched for.
  * @i: For index
  * Return: Pointer to substr location in string, if found. Else NULL pointer.
  */
char *_chrloc(char *s, char *c, int i)
{
	if (!*s)
		return ('\0');
	else if (s[i] == '\0' || c[i] == '*')
		return (s);
	else if ((s[i] == c[i]) && c[i] && s[i])
		return (_chrloc(s, c, i + 1));
	return (_chrloc(s + 1, c, 0));
}

/**
 * wildcmp - Check if two strings can be considered identical.
 * @s1: String 1.
 * @s2: String 2 which may contain wildcard '*'.
 *
 * Description: First checks if '*' is the last character
 * If so, it's a match. If not, check for consecutive '*'
 * Skips to next '*' if true. Else, use _chrloc to determine
 * if the not '*' char after an '*' is in the s1 string.
 * If true, store location in "found", jump there and continue.
 * Return: 1 if string can be considered identical, else 0.
 */
int wildcmp(char *s1, char *s2)
{
	char *found = '\0';

	if (*s2 == '*')
	{
		if (*(s2 + 1) == '\0')
			return (1);

		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));

		found = _chrloc(s1, (s2 + 1), 0);
		if (found)
			return (wildcmp(found, s2 + 1));
		else
			return (wildcmp(s1, s2 + 1));
	}

	else if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else if (*s2 == *s1)
		return (wildcmp(s1 + 1, s2 + 1));
	else
		return (0);

}
