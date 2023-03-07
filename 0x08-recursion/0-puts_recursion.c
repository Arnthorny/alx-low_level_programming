#include "main.h"

/**
  * _puts_recursion - Print a string using recursion.
  * @s: The string to be printed
  */
void _puts_recursion(char *s)
{
	if (!*s)
	{
		_putchar(10);
		return;
	}
	_putchar(*s);
	_puts_recursion(s + 1);
}
