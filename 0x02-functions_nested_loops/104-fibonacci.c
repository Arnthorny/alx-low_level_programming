#include <stdio.h>

/**
  * nOfDig - Returns the number of digits in an integer
  * @i: The integer to be checked
  *
  * Return: Digits in i.
  */

int nOfDig(long int i)
{
	int counter = 0;

	if (i <= 0)
		return (1);
	while (i / 10)
	{
		i /= 10;
		counter++;
	}
	return (counter);
}


/**
 * main - Prints the first 98 Fibonacci.
 * Description: Increase zeroes in div variable within
 * limits of ulong and change fib_count to print more
 * Return: 0
 */
int main(void)
{
	unsigned long int prev_half1 = 0, prev_half2 = 1;
	unsigned long int next_half1 = 0, next_half2 = 1;
	unsigned long int tmp_half1, tmp_half2;
	unsigned long int div = 1000000;
	int j = 0;
	int fib_count = 98;

	while (j < fib_count)
	{
		int l = 0;

		if (next_half1)
			printf("%ld", next_half1);
		l = nOfDig(next_half2);
		while (next_half2 / div)
		{
			next_half1 += next_half2 / div;
			next_half2 = next_half2 % div;
		}
		l = l == nOfDig(next_half2) ? 0 : l - nOfDig(next_half2);
		printf("%0*ld", l, next_half2);

		tmp_half1 = prev_half1;
		tmp_half2 = prev_half2;

		prev_half1 = next_half1;
		prev_half2 = next_half2;


		next_half1 = tmp_half1 + prev_half1;
		next_half2 = tmp_half2 + prev_half2;
		if (j < (fib_count - 1))
			printf(", ");
		j++;
	}
	printf("\n");
	return (0);
}
