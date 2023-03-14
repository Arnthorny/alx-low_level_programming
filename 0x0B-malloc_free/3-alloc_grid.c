#include "main.h"
#include <stdlib.h>

/**
  * _memset- Fills Memory with a constant int.
  * @s: Pointer to memory area.
  * @b: Int to fill memory with.
  * @n: Number of "bytes" to use in memory area.
  */

void _memset(int *s, int b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
}

/**
  * alloc_grid- Allocate memory to 2d-array and initialize elementss to 0.
  * @width: Column count.
  * @height: Row count
  * Return: Pointer to 2d-array.
  */

int **alloc_grid(int width, int height)
{
	int **d_ptr, i = 0;

	if (height <= 0 || width <= 0)
		return (NULL);

	d_ptr = malloc(sizeof(int *) * height);

	if (d_ptr == NULL)
	{
		free(d_ptr);
		return (NULL);
	}

	for (i = 0; i < height; i++)
	{
		d_ptr[i] = malloc(sizeof(int) * width);
		if (d_ptr[i] == NULL)
		{
			while (i >= 0)
			{
				free(d_ptr[i]);
				i--;
			}
			free(d_ptr);
			return (NULL);
		}
	}

	for (i = 0; i < height; i++)
	{
		_memset(d_ptr[i], 0, width);
		i++;
	}
	return (d_ptr);
}
