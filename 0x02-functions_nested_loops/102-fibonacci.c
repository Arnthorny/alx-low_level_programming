#include <stdio.h>
#include "main.h"
/**
  * main - Prints first 50 fibonacci numbers.
  *
  * Return: Exit Status
  */

int main(void)
{
	long int i = 1;
	long int j = 2;
	long int count = 0;

	printf("%ld, ", i);
	while (count < 49)
	{
		long int tmp = 0;

		if (count == 48)
		{
			printf("%ld", j);
		}
		else
		{
			printf("%ld, ", j);
			tmp = i;
			i = j;
			j += tmp;
		}
		count++;
	}
	printf("\n");
	return (0);
}
