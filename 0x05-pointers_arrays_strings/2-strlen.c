#include "main.h"
/**
  * _strlen - Determines a string length.
  * @s: Pointer to the string.
  * Return: Length of the string
  */

int _strlen(char *s)
{
	char *sCopy = s;

	while (*sCopy != '\0')
	{
		sCopy++;
	}

	return (sCopy - s);
}
