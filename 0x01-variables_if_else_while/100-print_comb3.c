#include <stdio.h>

/**
  * main - Prints all combo of two digit numbers.
  *
  * Return: Exit Status
  */
int main(void)
{
	int i;
	int j;

	for (i = 0; i < 10; i++)
	{
		for (j = i + 1; j < 10; j++)
		{
			putchar(48 + i);
			putchar(48 + j);
			if (i < 8)
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');

	return (0);
}

