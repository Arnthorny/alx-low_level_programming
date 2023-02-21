#include "main.h"
/**
  * print_alphabet - Returns all letters of English alphabet in lowercase.
  *
  */

void print_alphabet(void)
{
	int i = 0;
	while (i < 26)
	{
		_putchar(97 + i);
		i++;
	}
	_putchar('\n');
}

