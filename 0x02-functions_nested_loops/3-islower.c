#include "main.h"
/**
  * _islower - Checks if c is a lowercase letter
  * @c: The integer to be checked
  * Return: Exit Code.
  */

int _islower(int c)
{

	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}
