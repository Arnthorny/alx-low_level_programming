#include "main.h"
#include <stdio.h>
/**
  * print_to_98 - Prints the all digits from n up to 98.
  * @n: The integer to be checked
  */

void print_to_98(int n)
{
	while (n != 98)
	{
		printf("%d", n);
		printf(", ");
		n >= 98 ? n-- : n++;
	}
		if (n == 98)
			printf("%d\n", n);

}
