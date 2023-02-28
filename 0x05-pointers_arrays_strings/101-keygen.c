#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
  * main - Generate random valid passwords for given program 101-crackme.
  * Return: The exit code.
  */

int main(void)
{
	time_t time_seed = time(0);
	int max_sum = 2772, i = 0, sum = 0, diff;
	char pwd[84];

	srand(time_seed);
	while (sum < max_sum)
	{
		pwd[i++] = 33 + (rand() % 94);
		sum += pwd[i - 1];
	}
	pwd[i] = '\0';

	diff = sum - max_sum;
	i = 0;

	while (diff)
	{
		/*split diff in two and subtract each half from two chars*/
		int sub = diff - 1 > (diff / 2) ? diff / 2 : diff;

		if (pwd[i] >= (33 + sub))
		{
			pwd[i] -= sub;
			diff -= sub;
		}
		i++;
	}
	printf("%s\n", pwd);
	return (0);
}
