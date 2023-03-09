#include "main.h"

/**
 * subtractor - Subtracts consecutive odd nos from n.
 * @n: The number.
 * @i: An odd number.
 * Return: The final odd number's index, else -1.
 */
int subtractor(int n, int i)
{
	n -= i;
	if (n == 0)
		return ((i + 1) / 2);
	else if (n < 0)
		return (-1);
	return (subtractor(n,  i + 2));
}

/**
  * _sqrt_recursion - Calculate natural square root of a number.
  * @n: The number.
  * Return: The square root.
  */
int _sqrt_recursion(int n)
{
	return (n == 0 ? 0 : subtractor(n, 1));
}
