#include <stdio.h>
#include "main.h"
/**
  * main - Sum of multiples of 3 and 5.
  *
  * Return: Exit Status
  */

int main(void)
{
	int i = 0;
	int sum = 0;

	while (i < 1024)
	{
		if (!(i % 3) || !(i % 5))
		{
			sum += i;
		}
		i++;
	}
	printf("%d\n", sum);

	return (0);
}
