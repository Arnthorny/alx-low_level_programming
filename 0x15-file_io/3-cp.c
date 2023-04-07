#include "main.h"
#include <string.h>

/**
  *err_prnt - A function that handles error printing.
  *@err_code: Error code.
  *@ptr: Part of error msg to be printed.
  */
void err_prnt(int err_code, __attribute__((unused))void *ptr)
{
	switch (err_code)
	{
		case 97:
			dprintf(2, "Usage: cp file_from file_to\n");
			break;
		case 98:
			dprintf(2, "Error: Can't read from file %s\n", (char *) ptr);
			break;
		case 99:
			dprintf(2, "Error: Can't write to file %s\n", (char *) ptr);
			break;
		case 100:
			dprintf(2, "Error: Can't close fd %d\n", *(int *) ptr);
			break;
	}
	exit(err_code);
}

/**
  *close_fd - A function to close fildes.
  *@fd: Fildes.
  */

void close_fd(int fd)
{
	if (close(fd) != 0)
		err_prnt(100, &fd);
}

/**
  *copy_fn - A function that copies content between files.
  *@file_from: The file to copy from.
  *@file_to: The file to copy to.
  */

void copy_fn(char *file_from, char *file_to)
{
	char buf[1024] = {0};
	int r, w, fd_from, fd_to;

	fd_from = open(file_from, O_RDONLY);
	fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 00664);

	if (fd_to < 0)
		err_prnt(99, file_to);

	do {
		r = read(fd_from, buf, 1024);
		if (fd_from < 0 || r < 0)
			err_prnt(98, file_from);

		w = write(fd_to, buf, r);
		if (w != r || w < 0)
			err_prnt(99, file_to);

	} while (r > 0);

	close_fd(fd_from);
	close_fd(fd_to);
}


/**
  *main - A program that copies content from one file to another.
  *@argc: Number of arguments.
  *@argv: Pointer to array of arguments.
  *Return: Exit status code.
  */

int main(int argc, char *argv[])
{
	char *file_from, *file_to;

	if (argc != 3)
		err_prnt(97, NULL);

	file_from = argv[1];
	file_to = argv[2];

	if (!file_from)
		err_prnt(98, file_from);
	if (!file_to)
		err_prnt(99, file_to);
	copy_fn(file_from, file_to);
	return (0);
}
