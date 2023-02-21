#include "main.h"
/**
  * print_last_digit - Prints the last digit of an integer
  * @n: The integer to be checked
  * Return: The last digit of the integer.
  */

int print_last_digit(int n)
{
	if (n < 0)
		n = -(n % 10);
	else
		n = n % 10;
	_putchar((n % 10) + '0');
	return (n % 10);
}
