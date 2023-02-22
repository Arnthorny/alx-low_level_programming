#include <stdio.h>
#include "main.h"
/**
  * main - Prints sum of even valued fibonacci numbers.
  *
  * Return: Exit Status
  */

int main(void)
{
	int i = 1;
	int j = 2;
	int sum = 0;

	while (j < 4000000)
	{
		int tmp = 0;

		if (!(j % 2))
		{
			sum += j;
		}
		tmp = i;
		i = j;
		j += tmp;
	}
	printf("%d\n", sum);
	return (0);
}
