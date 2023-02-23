#include "main.h"
/**
  * _isupper - Checks if c is an uppercase letter
  * @c: The char to be checked
  * Return: Exit Code.
  */

int _islower(int c)
{

	if (c >= 65 && c <= 90)
		return (1);
	else
		return (0);
}
