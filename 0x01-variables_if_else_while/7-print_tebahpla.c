#include <stdio.h>

/**
  * main - Prints all alphabets in reverse order.
  *
  * Return: Exit Status
  */
int main(void)
{
	int i;

	for (i = 25; i >= 0; i--)
		putchar(97 + i);
	putchar('\n');

	return (0);
}
