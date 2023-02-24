#include "main.h"

/**
  * print_number- Prints an integer using putchar.
  * @n : Integer to be printed.
  *
  */
void print_number(int n)
{
	int div = 1000000000;
	int popDig;
	int neg = n < 0 ? 1 : 0;
	int lZero = 1;

	if (neg)
		_putchar('-');
	if (n == 0)
		_putchar('0');
	while (div && n)
	{
		popDig = n / div;
		if (lZero)
			lZero = popDig != 0 ? 0 : 1;
		n %= div;
		div /= 10;
		if (neg)
			popDig *= -1;
		if (!lZero)
			_putchar('0' + popDig);
	}
}
