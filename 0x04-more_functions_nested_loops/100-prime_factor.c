#include "main.h"
#include <math.h>
/**
  * main- Fizz-Buzz.
  *
  * Return: Exit code
  */

int main(void)
{
	long int num = 612852475143;
	int largest = 1, i = 2, j = 2;

	while (i <= num)
	{
		int isPrime = 1;

		if (num % i == 0)
		{
			while (j < i)
			{
				if (i % j == 0)
				{
					isPrime = 0;
					break;
				}
				j++;
			}
			if (isPrime)
			{
				num /= i;
				largest = i;
			}
		}
		else
			i++;
	}
	printf("%d\n", largest);
	return (0);
}
