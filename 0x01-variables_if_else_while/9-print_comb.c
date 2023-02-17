#include <stdio.h>

/**
  * main - Prints all combo of single digit numbers.
  *
  * Return: Exit Status
  */
int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		putchar(48 + i);
		if (i != 9)
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');

	return (0);
}

