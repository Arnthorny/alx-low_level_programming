#include "variadic_functions.h"

/**
 * sum_them_all - This function sums all passed integers
 * @n: The number of integers
 * Return: The sum of all the integers.
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list sum_list;
	int val = 0, sum = 0;
	unsigned int i = 0;

	va_start(sum_list, n);
	while (i < n)
	{
		val = va_arg(sum_list, int);
		sum += val;
		i++;
	}
	va_end(sum_list);
	return (sum);
}
