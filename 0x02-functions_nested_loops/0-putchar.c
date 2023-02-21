#include <stdio.h>
#include "main.h"
/**
  * main - Prints all letters pf English alphabet.
  *
  * Return: Exit Status
  */
int main(void)
{
	int i = 0;
	char word[8] = "_putchar";

	while (word[i] != '\0')
	{
		_putchar(word[i]);
		i++;
	}
	_putchar('\n');

	return (0);
}
