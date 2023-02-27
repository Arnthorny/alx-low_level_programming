#include "main.h"

/**
  * _atoi - Converts a given string to an integer.
  * @s: The string to be converted.
  * Return: The converted integer
  */

int _atoi(char *s)
{
	int num_found = 0;
	int sign = 1;
	int value = 0;


	while (*s != '\0')
	{
		if (num_found)
		{
			if (!(*s >= 48 && *s <= 57))
				return (value);
			value = value < 0 ? ((value * 10) - (*s - '0')) : (value * 10) + (*s - '0');
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
			{
				sign *= -1;
			}
			s++;
			continue;
		}
	}
	return (value);
}
