#include "main.h"


int nOfDig(int i);
int _pow(int m, int n);

/**
  * print_number- Prints an integer using putchar.
  * @n : Integer to be printed.
  *
  */
void print_number(int n)
{
	int digCount = nOfDig(n);
	int div = _pow(10, digCount - 1);
	int i = 0, popDig;
	int neg = n < 0 ? 1 : 0;

	if (neg)
		_putchar('-');
	while ((i < digCount) && div)
	{
		popDig = n / div;
		n %= div;
		div /= 10;
		if (neg)
			popDig *= -1;
		_putchar('0' + popDig);
	}
}

/**
  * nOfDig - Returns the number of digits in an integer
  * @i: The integer to be checked
  *
  * Return: Number of Digits in i.
  */

int nOfDig(int i)
{
	int counter = 1;

	if (i < 0)
	{
		i = -(i / 10) * 10;
	}

	while (i / 10)
	{
		i /= 10;
		counter++;
	}
	return (counter);
}

/**
  * _pow - Returns the number of digits in an integer
  * @m: The integer to be raised
  * @n: The power to raise
  * Return: m raised to n.
  */

int _pow(int m, int n)
{
	int mCopy = 1;
	int i = 0;

	while (i < n)
	{
		mCopy *= m;
		i++;
	}
	return (mCopy);
}
