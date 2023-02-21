#include "main.h"
/**
  * _abs - Prints the sign of an integer
  * @n: The integer to be checked
  * Return: Absolute value of integer.
  */


int _abs(int n)
{
	if (n > 0)
	{
		return (n);
	}
	else if (n < 0)
	{
		return (n * -1);
	}
	else
	{
		return (0);
	}
}
