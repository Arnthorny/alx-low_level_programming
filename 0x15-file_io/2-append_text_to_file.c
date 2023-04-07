#include "main.h"
#include <string.h>

/**
  *append_text_to_file - A function that appends text to a file's end.
  *@text_content: String to write to file.
  *@filename: Pointer to file name.
  *Description: Function appends text_content to file.
  *Return: 1 on success, -1 on failure.
  */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, w;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd < 0)
		return (-1);

	if (!text_content)
	{
		close(fd);
		return (1);
	}

	w = write(fd, text_content, strlen(text_content));
	if (w < 0)
	{
		close(fd);
		return (-1);
	}
	return (1);

}
