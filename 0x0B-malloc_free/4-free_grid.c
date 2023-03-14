#include "main.h"
#include <stdlib.h>


/**
  * free_grid- Free previously allocated mem.
  * @grid: Pointer to 2-d array.
  * @height: Row count
  */
void free_grid(int **grid, int height)
{
	if (!grid || height <= 0)
		return;
	while (height >= 0)
		free(grid[--height]);
	free(grid);
}
