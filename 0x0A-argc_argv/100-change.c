#include "main.h"

/**
  * main - Prints min num of coins to make change
  * @argc: Argument count
  * @argv: Array of strings passed
  * Return: Exit Status Code.
  */

int main(int argc, char *argv[])
{
	int val, coins[] = {25, 10, 5, 2, 1};
	int coinCount = 0, i = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	val = atoi(argv[1]);

	if (val < 0)
	{
		printf("0\n");
		return (0);
	}

	while (val && i < 5)
	{
		if (val >= coins[i])
		{
			val -= coins[i];
			coinCount++;
		}
		else
			i++;
	}

	printf("%d\n", coinCount);
	return (0);
}
