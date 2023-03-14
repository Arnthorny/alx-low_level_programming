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
	int **grid_ptr, i = 0;
	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}
	
	grid_ptr = malloc(sizeof(int *) * height);

	if (!grid_ptr)
	{
		for (i = 0; i < height; i++)
			free(grid_ptr[i]);
		return (NULL);
	}
	
	while (i < height)
	{
		grid_ptr[i] = malloc(sizeof (int) * width);
		if (!grid_ptr[i])
		{
			while (i >= 0)
				free(grid_ptr[i]);
			return (NULL);
		}
			_memset(grid_ptr[i], 0, width);
			i++;
	}
		return (grid_ptr);
}
