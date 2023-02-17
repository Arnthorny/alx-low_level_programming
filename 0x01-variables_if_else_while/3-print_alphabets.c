#include <stdio.h>

/**
  * main - Prints all letters pf English alphabet.
  *
  * Return: Exit Status
  */
int main(void)
{
	int i;

	for (i = 0; i < 52; i++)
	{
		if (i < 26)
			putchar(97 + i);
		else
		putchar(65 + (i % 26));
	}
	putchar('\n');

	return (0);
}
