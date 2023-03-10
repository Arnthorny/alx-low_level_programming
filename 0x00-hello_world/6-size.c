#include <stdio.h>

/**
  * main - Prints the size of C data types
  *
  * Return: Prints status code.
  */
int main(void)
{
	printf("Size of a char: %li byte(s)\n", sizeof(char));
	printf("Size of an int: %li byte(s)\n", sizeof(int));
	printf("Size of a long int: %li byte(s)\n", sizeof(long));
	printf("Size of a long long int: %li byte(s)\n", sizeof(long long));
	printf("Size of a float: %li byte(s)\n", sizeof(float));

	return (0);
}
