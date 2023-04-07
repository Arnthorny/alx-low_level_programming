#include "main.h"
#include <string.h>

/**
  *create_file - A function that creates a file.
  *@text_content: String to write to file.
  *@filename: Pointer to file name.
  *Description: Function creates file with specific permissions
  *or truncates it if file exists.
  *Return: 1 on success, -1 on failure.
  */

int create_file(const char *filename, char *text_content)
{
	int fd, w;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd < 0)
		return (-1);
	/**
	*fd = open(filename, O_CREAT | O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR);
	if (fd < 0)
	{
		fd = open(filename, O_WRONLY | O_TRUNC);
		if(fd < 0)
			return (-1);
	}
	*/

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
