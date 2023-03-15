#include "main.h"
#include <stdlib.h>

/**
  * word_count- Returns the number of words in a string.
  * @str: Pointer to string.
  * @isSpace: Check if current char is a space.
  * @i: Current index
  * Return: Word count.
  */
int word_count(char *str, int isSpace, int i)
{
	if (!str[i])
		return (0);
	if (i == 0 && !isSpace)
		return (1 + word_count(str, isSpace, i + 1));
	if (isSpace && str[i] != ' ')
		return (1 + word_count(str, *(str + i) == ' ', i + 1));
	return (0 + word_count(str, *(str + i) == ' ', i + 1));
}

/**
  * find_word- Function to find a word in a string.
  * @str: Pointer to string
  * Return: Offset of word from current pointer (Word length).
  */
int find_word(char *str)
{
	return (*str == ' ' || !*str ? 0 : 1 + find_word(str + 1));
}

/**
  * strtow- Function to split a string into a word.
  * @str: String to be split
  * Return: Pointer to arrray of words(strings).
  */
char **strtow(char *str)
{
	int lCount = 0, wCount, i = 0, j = 0;
	char **words;

	if (*str == '\0' || str == NULL)
		return (NULL);
	wCount = word_count(str, *str == ' ', 0);
	words = malloc(sizeof(char *) * (wCount + 1));
	if (!words)
	{
		free(words);
		return (NULL);
	}

	words[wCount] = NULL;
	while (*str && i < wCount)
	{
		lCount = find_word(str);
		if (lCount)
		{
			words[i] = malloc(sizeof(char) * (lCount + 1));
			if (!words[i])
			{
				while (i >= 0)
					free(words[i--]);
				free(words);
				return (NULL);
			}
			for (j = 0; j < lCount; j++)
				words[i][j] = *(str + j);
			words[i][lCount] = '\0';
			str += lCount;
			i++;
		}
		str++;
	}
	return (words);
}
