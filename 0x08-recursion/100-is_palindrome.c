#include "main.h"
/**
 * _check - Checks if string is a palindrome.
 * @s: The string.
 * @sDup: The string's duplicate.
 * @i: Counter for current point in s.
 * Return: 1 if palindrome, else 0.
 */

int _check(char *s, char *sDup, int i)
{
	if (*s)
		return (_check(s + 1, sDup, 1));
	if (!(*sDup))
		return (1);
	else if (!((*(s - i) == *sDup) && i))
		return (0);
	return (1 * _check(s, sDup + 1, i + 1));
}

/**
 * is_palindrome - Check if a given string is a palindrome.
 * @s: The string.
 * Return: 1 if the string is palindrome, else 0.
 */
int is_palindrome(char *s)
{
	return (_check(s, s, 1));
}
