#include "main.h"

/**
  * factorial - Calculate factorial of a given num.
  * @n: The number.
  * Return: Factorial.
  */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (1);

	return (n * factorial(n - 1));
}
