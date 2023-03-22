#include "3-calc.h"

/**
  * op_add - Function to add two integers together
  * @a: Integer 1
  * @b: Integer 2
  * Return: The sum of a and b
  */

int op_add(int a, int b)
{
	return (a + b);
}

/**
  * op_sub - Function to subtract two integers
  * @a: Integer 1
  * @b: Integer 2
  * Return: The difference of a and b
  */

int op_sub(int a, int b)
{
	return (a - b);
}

/**
  * op_mul - Function to multiply two integers together
  * @a: Integer 1
  * @b: Integer 2
  * Return: The product of a and b
  */

int op_mul(int a, int b)
{
	return (a * b);
}
/**
  * op_div - Function to divide two integers if b is not 0.
  * @a: Integer 1
  * @b: Integer 2
  * Return: The division of a by b.
  */

int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}
/**
  * op_mod - Function to perform modulo op on two integers if b is not 0.
  * @a: Integer 1
  * @b: Integer 2
  * Return: The remainder of division a by b
  */

int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
