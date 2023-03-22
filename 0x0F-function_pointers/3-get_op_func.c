#include "3-calc.h"

/**
  * get_op_func - Function to select correct function
  * @s: Pointer to operator string
  * Return: Ptr to Fn that takes two int for arithmetic op or NULL if invalid s
  */

int (*get_op_func(char *s))(int a, int b)
{
	int i = 0;

	op_t ops[] = {
	{"+", op_add},
	{"-", op_sub},
	{"*", op_mul},
	{"/", op_div},
	{"%", op_mod},
	{NULL, NULL}
	};

	while (ops[i].op && s)
	{
		if (ops[i].op[0] == s[0])
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
