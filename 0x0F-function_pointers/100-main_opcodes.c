#include <stdlib.h>
#include <stdio.h>


/**
  * main - Function to print the opcode of its main fn.
  * @argc: Argument count
  * @argv: Argument strings
  * Return: Exit Status code.
  * Description: This function casts the pointer
  * to main to char type in order to allow access
  * to each individual byte (sizeof char is 1 byte).
  */

int main(int argc, char *argv[])
{
	int i, bytecount;
	char *opcodes;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	bytecount = atoi(argv[1]);
	if (bytecount < 0)
	{
		printf("Error\n");
		return (2);
	}
	opcodes = (char *)main;

	for (i = 0; i < bytecount - 1; i++)
		printf("%02hhx ", opcodes[i]);
	printf("%02hhx\n", opcodes[i]);

	return (0);
}
