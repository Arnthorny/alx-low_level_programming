#include "main.h"

/**
 *read_textfile - A function that reads a text file
 *and prints it to stdout
 *@letters: Number of letters to be read
 *@filename: Pointer to file name.
 *Return: Actual count of letters it could read and print or 0
 */


ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, r, w;
	char *buf = NULL;


	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	buf = malloc(sizeof(*buf) * (letters));
	r = read(fd, buf, letters);

	if (fd < 0 || !buf || r <= 0)
	{
		free(buf);
		return (0);
	}

	w = write(STDOUT_FILENO, buf, r);
	close(fd);
	free(buf);
	return (w == r ? (size_t) w : 0);

}
