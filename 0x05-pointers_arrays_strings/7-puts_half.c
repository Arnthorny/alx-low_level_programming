#include "main.h"

/**
  * count_string - Counts chars in a string.
  * @s: Pointer to the string.
  * Return: String count.
  */

int count_string(char *s)
{
	int counter = 0;

	while (*s != '\0')
	{
		s++;
		counter++;
	}
	return (counter);
}

/**
  * puts_half - Prints the second half of a given string .
  * @str: Pointer to the string.
  */

void puts_half(char *str)
{
	int strL = count_string(str);
	int n = strL % 2 ? (strL - 1) / 2 : strL / 2;
	char *start = str + (strL - n);

	while (*start != '\0')
	{
		_putchar(*start);
		start++;
	}
	_putchar(10);
}
