#include "main.h"


/**
  * print_hex_content - Print a hex content of buffer.
  * @b: Pointer to the buffer
  * @i: Current index position
  * @size: Size of the buffer
  */
void print_hex_content(char *b, int i, int size)
{
	int j = 0;

	while (j < 10)
	{
		if (!(j % 2) && j)
			printf(" ");
		if ((i + j) < size)
			printf("%.2x", b[i + j]);
		else
			printf("  ");
		j++;
		if (j == 10)
			printf(" ");
	}
}

/**
  * print_content - Prints the content of a buffer.
  * @b: Pointer to the buffer
  * @i: Current position
  * @size: Size of the buffer
  */
void print_content(char *b, int i, int size)
{
	int k = 0;

	while (k < 10)
	{
		if ((i + k) < size)
		{
			if (b[i + k] >= 20 && b[i + k] <= 126)
				printf("%c", b[i + k]);
			else
				printf(".");
		}
		else
			printf(" ");
		k++;
	}
}

/**
* print_buffer - Print a buffer to the screen.
* @b: Pointer to the buffer
* @size: Size of the buffer
*/
void print_buffer(char *b, int size)
{
	int i = 0;

	while (i < size)
	{
		if (!(i % 10) && i)
			printf("\n");
		printf("%.8x: ", i);
		print_hex_content(b, i, size);
		print_content(b, i, size);

		i += 10;
	}
	printf("\n");
}
