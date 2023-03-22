#include "function_pointers.h"

/**
 * print_name - A function that prints a name
 * @name: Pointer to name string
 * @f: Pointer to a function that returns nothing
 */

void print_name(char *name, void (*f)(char *))
{
	f(name);
}
