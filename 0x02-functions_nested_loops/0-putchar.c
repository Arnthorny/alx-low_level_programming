#include <stdio.h>

/**
  * main - Prints all letters pf English alphabet.
  *
  * Return: Exit Status
  */
int main(void)
{
	int i;

	for (i = 0; i < 26; i++)
		putchar(97 + i);
	putchar('\n');

	return (0);
}
