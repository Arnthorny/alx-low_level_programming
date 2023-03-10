#include "main.h"


/**
  * main - Program to multiply two given numbers
  * @argc: Argument count
  * @argv: Array of strings passed
  * Return: Exit Status Code.
  */

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	printf("%d\n", (atoi(argv[1])) * (atoi(argv[2])));

	return (0);
}
