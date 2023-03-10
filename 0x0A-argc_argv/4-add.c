#include "main.h"

/**
  * main - Program to add all positive numbers
  * @argc: Argument count
  * @argv: Array of strings passed
  * Return: Exit Status Code.
  */

int main(int argc, char *argv[])
{
	int i, j, sum = 0;
	char curr;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		j = 0;
		do {
			curr = argv[i][j];
			if (curr && !(curr >= '0' && curr <= '9'))
			{
				printf("Error\n");
				return (1);
			}
			j++;
		} while (curr);
		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);
	return (0);
}
