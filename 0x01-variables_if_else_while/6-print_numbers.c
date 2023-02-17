#include <stdio.h>

/**
  * main - Prints all numbers from 0-9 with only putchar.
  *
  * Return: Exit Status
  */
int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
		putchar(48 + i);
	putchar('\n');

	return (0);
}
