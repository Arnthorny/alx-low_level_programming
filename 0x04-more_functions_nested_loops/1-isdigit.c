#include "main.h"
/**
  * _isdigit - Checks if c is a digit
  * @c: The char to be checked
  * Return: Exit Code.
  */

int _isdigit(int c)
{

	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
