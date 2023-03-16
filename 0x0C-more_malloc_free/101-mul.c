#include "main.h"

/**
  * _slen- Returns the length of a string.
  * @str: Pointer to string.
  * Return: Length of string.
  */

unsigned int _slen(char *str)
{
	return (str && *str ? 1 + (_slen(str + 1)) : 0);
}

/**
  * _puts - Outputs a string to stdout
  * @s: Pointer to string.
  */
void _puts(char *s)
{
	unsigned int i = 0;

	while (s[i])
		_putchar(s[i++]);
	_putchar('\n');
}

/**
  * _memset- Fills Memory with a constant byte.
  * @s: Pointer to memory area.
  * @b: Byte to fill memory with.
  * @n: Number of bytes to use in memory area.
  * Return: Pointer to memory area s
  */
void *_memset(void *s, char b, unsigned int n)
{
	unsigned int i;
	unsigned char *ptr = s;

	for (i = 0; i < n; i++)
		ptr[i] = b;
	return (s);
}

/**
  * rev_str - Copies a given string and reverses it
  * @str: Given string.
  * @size: Size of the string
  * @readOnly: Indicates if string is stored as a literal
  * Return: Pointer to reversed string.
  */

char *rev_str(char *str, int size, int readOnly)
{
	if (readOnly)
	{
		unsigned int i = 0;
		char tmp, *ptr = malloc(sizeof(*ptr) * (size + 1));

		if (!ptr)
			return (NULL);

		ptr[size--] = '\0';

		while (str[i])
		{
			tmp = str[i++];
			if (!(tmp >= '0' && tmp <= '9'))
			{
				free(ptr);
				_puts("Error");
				exit(98);
			}
			ptr[size--] = tmp;
		}
		return (ptr);
	}
	else
	{
		char *sEnd = str + _slen(str) - 1, tmp;

		while (str <= sEnd)
		{
			tmp = *str;
			*str = *sEnd;
			*sEnd = tmp;
			str++;
			sEnd--;
		}
		return (str);
	}
}

/**
  * cToI - Convert a base10 digit char to an integer
  * @c: Char to be converted.
  * Return: Integer value.
  */
int cToI(char c)
{
	return (c - '0');
}

/**
  *mult - This function uses the long multiplication algo to multiply numbers
  *@n1: First number
  *@n2: Second number
  *@l1: Length of n1.
  *@l2: Length of n2.
  *@res: Buffer for the result
  *@lenRes: Size of the buffer
  *Return: Result
  */

char *mult(char *n1, int l1, char *n2, int l2, char *res, int lenRes)
{
	int carry, i, j, tmpSum;

	res[lenRes] = '\0';

	for (i = 0; i < l1; i++)
	{
		carry = 0;
		for (j = 0; j < l2; j++)
		{
			tmpSum = carry + cToI(res[i + j]) + (cToI(n1[i]) * cToI(n2[j]));
			carry = tmpSum / 10;
			res[i + j] = '0' + (tmpSum % 10);
			res[i + l2] = '0' + carry;
		}
	}
	if (carry == 0)
		res[lenRes - 1] = '\0';
	return (res);
}

/**
  * main - Main function to start program
  * @argc: Argument count
  * @argv: Array of argument strings.
  * Return: Exit Code.
  */

int main(int argc, char *argv[])
{
	int len1, len2, lenRes;
	char *result, *rev1, *rev2;

	if (argc != 3)
	{
		_puts("Error");
		exit(98);
	}

	len1 = _slen(argv[1]);
	len2 = _slen(argv[2]);

	rev1 = rev_str(argv[1], len1, 1);
	rev2 = rev_str(argv[2], len2, 1);

	lenRes = len1 + len2;
	result = malloc(sizeof(*result) * (lenRes + 1));

	if (!result)
		return (1);
	result = _memset(result, '0', lenRes);

	if (len1 > len2)
		result = mult(rev1, len1, rev2, len2, result, lenRes);
	else
		result = mult(rev2, len2, rev1, len1, result, lenRes);

	rev_str(result, lenRes, 0);
	_puts(result);
	free(rev1);
	free(rev2);
	free(result);
	return (0);
}
