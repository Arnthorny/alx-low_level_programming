#include "main.h"
#include <stdlib.h>

/**
  * _slen- Returns the length of a string.
  * @str: Pointer to string.
  * Return: Length of string.
  */

int _slen(char *str)
{
	return (str && *str ? 1 + (_slen(str + 1)) : 0);
}

/**
  * argstostr- Concatenate args passed to main in one string.
  * @ac: Arg count
  * @av: Array of Arg strings
  * Return: Pointer to string.
  */

char *argstostr(int ac, char **av)
{
	int i = 0, tot_len = 0, j = 0;
	char *arg_cat;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
		tot_len += _slen(av[i]) + 1;

	arg_cat = malloc((sizeof(char) * (tot_len + 1)));
	if (!arg_cat)
	{
		free(arg_cat);
		return (NULL);
	}

	for (i = 0; i < tot_len; i++)
	{
		if ((*av)[j] == '\0')
		{
			arg_cat[i] = '\n';
			j = 0;
			av++;
			continue;
		}
		arg_cat[i] = (*av)[j++];
	}
	arg_cat[i] = '\0';
	return (arg_cat);
}
