#include <string.h>
#include "3-calc.h"

/**
  * main - A fn takes two integers to perform arithmetic op on them.
  * @argv: Pointer to an array of string args
  * @argc: Argument count
  * Return: Exit status code
  */

int main(int argc, char *argv[])
{
	int val;
	int (*func)(int a, int b);

	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}

	if (strlen(argv[2]) != 1)
	{
		printf("Error\n");
		return (99);
	}

	func = get_op_func(argv[2]);

	if (!func)
	{
		printf("Error\n");
		return (99);
	}

	val = func(atoi(argv[1]), atoi(argv[3]));
	printf("%d\n", val);

	return (0);
}
