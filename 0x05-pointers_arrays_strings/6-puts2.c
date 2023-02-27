#include "main.h"

/**
  * puts2 - Prints every other char of a given string .
  * @str: Pointer to the string.
  */

void puts2(char *str)
{
	char *sCopy = str;

	while (*str != '\0')
	{
		if (!((str - sCopy) % 2))
			_putchar(*str);
		str++;
	}
	_putchar(10);
}
