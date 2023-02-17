#include <stdio.h>

/**
  * main - Prints all hexadcimal numbers from 0-f.
  *
  * Return: Exit Status
  */
int main(void)
{
	int i;

	for (i = 0; i < 16; i++)
	{
		if (i < 10)
			putchar(48 + i);
		else
			putchar(97 + (i % 10));

	}
	putchar('\n');

	return (0);
}

