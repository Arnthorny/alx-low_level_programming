#include "variadic_functions.h"

/**
 * print_strings - This function prints strings with separator.
 * @n: The number of strings.
 * @separator: Pointer to separator string.
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list str_list;
	char *str;
	unsigned int i = 0;

	va_start(str_list, n);
	while (i < n)
	{
		str = va_arg(str_list, char *);
		printf("%s", str ? str : "(nil)");
		if (i + 1 < n)
			printf("%s", separator ? separator : "");
		i++;
	}
	va_end(str_list);
	printf("\n");
}
