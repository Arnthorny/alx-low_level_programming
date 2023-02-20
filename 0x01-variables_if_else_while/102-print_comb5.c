#include <stdio.h>

/**
  * main - Prints all combo of unique two two digit numbers.
  *
  * Return: Exit Status
  */
int main(void)
{
	int i;
	int j;
	int k;
	int l;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			for (k = i; k < 10; k++)
			{
				if (i != k)
					l = 0;
				else
					l = j + 1;

				for (; l < 10; l++)
				{
					putchar(48 + i);
					putchar(48 + j);
					putchar(' ');
					putchar(48 + k);
					putchar(48 + l);
					if (i == 9 && j == 8 && k == 9 && l == 9)
					{
						continue;
					}
					else
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}
	putchar('\n');

	return (0);
}

