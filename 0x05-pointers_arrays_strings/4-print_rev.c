#include "main.h"
/**
  * print_rev - Prints a string, in reverse.
  * @s: Pointer to the string.
  */

void print_rev(char *s)
{
	char *sCopy = s;

	while (*s != '\0')
	{
		s++;
		if (*s == '\0')
		{
			while (sCopy <= s)
			{
				_putchar(*s);
				s--;
			}
		}
	}
	_putchar(10);
}
