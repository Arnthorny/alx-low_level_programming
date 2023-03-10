#include "main.h"

/**
  * main - Program to print all arguments passed in.
  * @argc: Argument count
  * @argv: Array of strings passed
  * Return: Exit Status Code.
  */

int main(int argc, char *argv[])
{
	int i = 0;

	while (i < argc)
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}
