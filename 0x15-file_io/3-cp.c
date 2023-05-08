#include "main.h"

/**
  *err_prnt - A function that handles error printing.
  *@err_code: Error code.
  *@ptr: Part of error msg to be printed.
  */
void err_prnt(int err_code, void *ptr)
{
	ptr = ptr;
	switch (err_code)
	{
		case 97:
			dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
			break;
		case 98:
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", (char *) ptr);
			break;
		case 99:
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", (char *) ptr);
			break;
		case 100:
			dprintf(STDERR_FILENO, "Error: Can't close fd FD_VALUE %d\n", *(int *) ptr);
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
	int c = close(fd);

	if (c == -1)
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
	if (fd_from == -1)
		err_prnt(98, file_from);

	fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
		err_prnt(99, file_to);

	r = read(fd_from, buf, 1024);
	if (r == -1)
		err_prnt(98, file_from);
	do {
		w = write(fd_to, buf, r);
		if (w == -1)
			err_prnt(99, file_to);

		r = read(fd_from, buf, 1024);
		if (r == -1)
			err_prnt(98, file_from);
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

	copy_fn(file_from, file_to);
	return (0);
}
