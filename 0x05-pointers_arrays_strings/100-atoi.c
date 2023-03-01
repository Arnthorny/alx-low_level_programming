#include "main.h"

/**
  * _atoi - Converts a given string to an integer.
  * @s: The string to be converted.
  * Return: The converted integer
  */

int _atoi(char *s)
{
	int num_found = 0, sign = 1, value = 0;

	while (*s)
	{
		if (num_found)
		{
			if (!(*s >= 48 && *s <= 57))
				return (value);
			value *= 10;
			value = value < 0 ? value - (*s - '0') : value + (*s - '0');
			s++;
		}
		else
		{
			if (*s >= 48 && *s <= 57)
			{
				num_found = 1;
				value = (*s - '0') * sign;
			}
			else if (*s == '-')
				sign *= -1;
			s++;
		}
	}
	return (value);
}
