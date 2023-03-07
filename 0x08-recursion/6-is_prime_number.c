#include "main.h"

/**
 * factor_check - Checks if there are factors of n from 2 to n/2.
 * @n: The number.
 * @i: The divisor.
 * Return: 1 if no factor, else 0.
 */
int factor_check(int n, int i)
{
	if (i == ((n / 2) + 1))
		return (1);
	else if (!(n % i))
		return (0);
	return (factor_check(n, i + 1));
}

/**
 * is_prime_number - Check if a given number is prime.
 * @n: The number.
 * Return: 1 if the number is prime, else 0.
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (factor_check(n, 2));
}
