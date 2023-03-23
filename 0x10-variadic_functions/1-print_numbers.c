#include "variadic_functions.h"

/**
 * print_numbers - This function prints nums with separator.
 * @n: The number of integers.
 * @separator: Pointer to separator string.
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list num_list;
	int val = 0;
	unsigned int i = 0;

	va_start(num_list, n);
	while (i < n)
	{
		val = va_arg(num_list, int);
		printf("%d", val);
		if (i + 1 < n)
			printf("%s", separator ? separator : "");
		i++;
	}
	va_end(num_list);
	printf("\n");
}
