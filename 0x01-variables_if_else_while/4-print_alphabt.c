#include <stdio.h>

/**
  * main - Prints all letters except q and e.
  *
  * Return: Exit Status
  */
int main(void)
{
	int i;

	for (i = 0; i < 26; i++)
		if (i != 4 && i != 16)
			putchar(97 + i);
	putchar('\n');

	return (0);
}
