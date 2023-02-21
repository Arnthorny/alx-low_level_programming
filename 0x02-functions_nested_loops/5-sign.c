#include "main.h"
/**
  * print_sign - Prints the sign of an integer
  * @n: The integer to be checked
  * Return: Exit Code.
  */

int print_sign(int n)
{

	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	else
	{
		_putchar('0');
		return (0);
	}
}
