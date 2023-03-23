#include "variadic_functions.h"

/**
 * print_sep - This function determines when to print a separator
 * @i: Current index
 * @format: Pointer to formatted string
 * @hP: 1 or 0 val to test if anything has been printed
 */
void print_sep(unsigned int i, const char * const format, short hP)
{
	char *fmt = "cifs";

	while (*fmt && format[i + 1])
	{
		if (format[i + 1] == *fmt && hP)
		{
			printf(", ");
			break;
		}
		fmt++;
	}
}

/**
 * print_all - This function prints anything passed.
 * @format: Pointer to formatted string.
 */
void print_all(const char * const format, ...)
{
	va_list all_list;
	unsigned int i = 0, hP = 0;
	char c;
	int num;
	float dec;
	char *str;

	va_start(all_list, format);
	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				c = (char) va_arg(all_list, int);
				hP = printf("%c", c);
				break;
			case 'i':
				num = va_arg(all_list, int);
				hP = printf("%d", num);
				break;
			case 'f':
				dec = (float) va_arg(all_list, double);
				hP = printf("%f", dec);
				break;
			case 's':
				str = va_arg(all_list, char *);
				hP = printf("%s", str ? str : "(nil)");
				break;
		}
		print_sep(i, format, hP);
		i++;
	}
	printf("\n");
}
