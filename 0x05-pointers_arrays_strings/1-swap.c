#include "main.h"
/**
  * swap_int - Swaps the value of two integers.
  * @a: Integer A.
  * @b: Integer B
  *
  */

void swap_int(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
