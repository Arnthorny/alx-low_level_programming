#include "main.h"

/**
  * _pow_recursion - Calculate power of a given num.
  * @x: The number.
  * @y: The power.
  * Return: x raised to the power of y.
  */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	else if (y == 0)
		return (1);

	return (x * _pow_recursion(x, y - 1));
}
