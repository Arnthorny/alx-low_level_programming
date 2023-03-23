#include "variadic_functions.h"

/**
 * is_fmt - This function determines if a char is a format type.
 * @i: Current index
 * @format: Pointer to formatted string
 * Return: 1 if a format[i] is a format char.
 */
short int is_fmt(unsigned int i, const char * const format)
{
	char *fmt = "cifs";

	while (*fmt && format[i])
	{
		if (format[i] == *fmt)
			return (1);
		fmt++;
	}
	return (0);
}

/**
 * print_all - This function prints anything passed.
 * @format: Pointer to formatted string.
 * Description: The isFormat variable holds a 1 or 0 to determine
 * if the separator for a previous formatted arg had been printed.
 */
void print_all(const char * const format, ...)
{
	va_list all_list;
	unsigned int i = 0;
	char c;
	int num;
	float dec;
	char *str;
	short int isFormat = 0;

	va_start(all_list, format);
	while (format && format[i])
	{
		if (is_fmt(i, format))
			isFormat = !printf("%s", (isFormat || !format[i + 1]) ? ", " : "");
		switch (format[i])
		{
			case 'c':
				c = (char) va_arg(all_list, int);
				printf("%c", c);
				break;
			case 'i':
				num = va_arg(all_list, int);
				printf("%d", num);
				break;

			case 'f':
				dec = (float) va_arg(all_list, double);
				printf("%f", dec);
				break;
			case 's':
				str = va_arg(all_list, char *);
				printf("%s", str ? str : "(nil)");
				break;
		}
		i++;
	}
	printf("\n");
}
