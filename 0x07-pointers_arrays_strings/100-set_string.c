#include "main.h"
#include <stdio.h>

/**
  * set_string - Set the value of a pointer to char.
  * @s: Pointer to a pointer.
  * @to: Pointer.
  */

void set_string(char **s, char *to)
{
	*s = to;
}
