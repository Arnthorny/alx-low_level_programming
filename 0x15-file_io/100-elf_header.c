#include "holberton.h"
#include "main.h"
#include <stdint.h>

void err_p(char *str, void *, int);
void prnt_elf(El *header_ptr);
void close_elf(int fd);

void prnt_class(El *header_ptr, char *);
void prnt_data(El *header_ptr, char *);
void prnt_ver(El *header_ptr, char *);
void prnt_osabi(El *header_ptr, char *);
void prnt_abiVer(El *header_ptr, char *);
void prnt_type(El *header_ptr,  char *);
void prnt_epa(El *header_ptr, char *);

/**
  *main - A program that displays information in an ELF file.
  *@argc: Number of arguments.
  *@argv: Pointer to array of arguments.
  *Return: Exit status code.
  */
int main(int argc, char *argv[])
{
	int fd, r;
	char *elf_file;
	El header;

	if (argc != 2)
		err_p("Usage: elf_header elf_filename", NULL, 0);

	elf_file = argv[1];
	fd = open(elf_file, O_RDONLY);

	if (fd == -1)
		err_p("Error: Can't open ", elf_file, 0);

	r = read(fd, &header, sizeof(header));
	if (r == -1)
	{
		close_elf(fd);
		err_p("Error: Can't read from ", elf_file, 0);
	}

	if (!memcmp(header.e_ident, ELFMAG, 4) == 0)
		err_p("Invalid ELF file: ", elf_file, 0);

	prnt_elf(&header);
	close_elf(fd);

	return (0);
}

/**
  *err_p - A function that handles error printing.
  *@str: Error message to print.
  *@f: Filename if required or fd.
  *@end: Integer to indicate f is an fd.
  */
void err_p(char *str, void *f, int end)
{
	if (end)
		dprintf(2, "%s%d\n", str, *(int *)f);
	else
		dprintf(2, "%s%s\n", str, f ? (char *)f : "");
	exit(98);
}

/**
  *prnt_elf - A function to print out information from an ELF header
  *@header_ptr: Pointer to struct containing the information
  */

void prnt_elf(El *header_ptr)
{
	int i = 0;
	char *titl[] = {
		"Class:",
		"Data:",
		"Version:",
		"OS/ABI:",
		"ABI Version:",
		"Type:",
		"Entry point address:",
		NULL};

	hdr_func sel_fn[] = {
		prnt_class,
		prnt_data,
		prnt_ver,
		prnt_osabi,
		prnt_abiVer,
		prnt_type,
		prnt_epa
	};

	printf("ELF Header:\n");
	printf("  %s   ", "Magic:");
	for (i = 0; i < EI_NIDENT - 1; i++)
		printf("%02x ", header_ptr->e_ident[i]);
	printf("%02x\n", header_ptr->e_ident[i]);

	i = 0;
	while (titl[i])
	{
		sel_fn[i](header_ptr, titl[i]);
		i++;
	}

}

/**
  *prnt_class - Function to print information about ELF arch
  *@header_ptr: Pointer to Struct containing the information
  *@titl: Title of current information.
  */

void prnt_class(El *header_ptr, char *titl)
{
	printf("  %s                             ", titl);
	switch (header_ptr->e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("%s\n", "none");
			break;
		case ELFCLASS32:
			printf("%s\n", "ELF32");
			break;
		case ELFCLASS64:
			printf("%s\n", "ELF64");
			break;
		default:
			printf("<unknown: %x>\n", header_ptr->e_ident[EI_CLASS]);
	}
}

/**
  *prnt_data - Function to print information about ELF data encoding
  *@header_ptr: Pointer to Struct containing the information
  *@titl: Title of current information.
  */
void prnt_data(El *header_ptr, char *titl)
{
	printf("  %s                              ", titl);
	switch (header_ptr->e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("%s\n", "none");
			break;
		case ELFDATA2LSB:
			printf("%s\n", "2's complement, little endian");
			break;
		case ELFDATA2MSB:
			printf("%s\n", "2's complement, big endian");
			break;
		default:
			printf("<unknown: %x>\n", header_ptr->e_ident[EI_DATA]);
	}
}

/**
  *prnt_ver - Function to print information about ELF spec version number
  *@header_ptr: Pointer to Struct containing the information
  *@titl: Title of current information.
  */
void prnt_ver(El *header_ptr, char *titl)
{
	printf("  %s                           ", titl);
	switch (header_ptr->e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf("%d %s\n", EV_CURRENT, "(current)");
			break;
		default:
			printf("%d\n", header_ptr->e_ident[EI_VERSION]);
	}
}

/**
  *prnt_osabi - Function to print information about ELF OS and target ABI.
  *@header_ptr: Pointer to Struct containing the information
  *@titl: Title of current information.
  */
void prnt_osabi(El *header_ptr, char *titl)
{
	printf("  %s                            ", titl);
	switch (header_ptr->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("%s\n", "UNIX - System V");
			break;
		case ELFOSABI_HPUX:
			printf("%s\n", "UNIX - HP-UX");
			break;
		case ELFOSABI_NETBSD:
			printf("%s\n", "UNIX - NetBSD");
			break;
		case ELFOSABI_LINUX:
			printf("%s\n", "UNIX - Linux");
			break;
		case ELFOSABI_SOLARIS:
			printf("%s\n", "UNIX - Solaris");
			break;
		case ELFOSABI_IRIX:
			printf("%s\n", "UNIX - IRIX");
			break;
		case ELFOSABI_FREEBSD:
			printf("%s\n", "UNIX - FreeBSD");
			break;
		case ELFOSABI_TRU64:
			printf("%s\n", "UNIX - TRU64");
			break;
		case ELFOSABI_ARM:
			printf("%s\n", "ARM");
			break;
		case ELFOSABI_STANDALONE:
			printf("%s\n", "Standalone App");
			break;
		default:
			printf("<unknown: %x>\n", header_ptr->e_ident[EI_OSABI]);
	}
}

/**
  *prnt_abiVer - Fn to print information about ABI version of target object.
  *@header_ptr: Pointer to Struct containing the information
  *@titl: Title of current information.
  */
void prnt_abiVer(El *header_ptr, char *titl)
{
	printf("  %s                       ", titl);
	printf("%d\n", header_ptr->e_ident[EI_ABIVERSION]);
}

/**
  *prnt_type - Function to print information about object file type
  *@header_ptr: Pointer to Struct containing the information
  *@titl: Title of current information.
  */
void prnt_type(El *header_ptr, char *titl)
{
	uint16_t tmp = header_ptr->e_type;

	printf("  %s                              ", titl);
	if (header_ptr->e_ident[EI_DATA] == ELFDATA2MSB)
		tmp = header_ptr->e_type >> 8;
	switch (tmp)
	{
		case ET_NONE:
			printf("%s\n", "NONE (None)");
			break;
		case ET_REL:
			printf("%s\n", "REL (Relocatable file)");
			break;
		case ET_EXEC:
			printf("%s\n", "EXEC (Executable file)");
			break;
		case ET_DYN:
			printf("%s\n", "DYN (Shared object file)");
			break;
		case ET_CORE:
			printf("%s\n", "CORE (Core file)");
			break;
		default:
			printf("<unknown: %x>\n", header_ptr->e_type);
	}
}

/**
  *prnt_epa - Function to print info about entry point address
  *@h_ptr: Pointer to Struct containing the information
  *@titl: Title of current information.
  */
void prnt_epa(El *h_ptr, char *titl)
{
	printf("  %s               ", titl);
	if (h_ptr->e_ident[EI_DATA] == ELFDATA2MSB)
	{
		h_ptr->e_entry = ((h_ptr->e_entry << 8) & 0xFF00FF00)
			| ((h_ptr->e_entry >> 8) & 0xFF00FF);
		h_ptr->e_entry = (h_ptr->e_entry << 16) | (h_ptr->e_entry >> 16);
	}

	if (h_ptr->e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)h_ptr->e_entry);
	else
		printf("%#lx\n", h_ptr->e_entry);
}

/**
  *close_elf - Function to close fd.
  *@fd: fildes.
  */
void close_elf(int fd)
{
	if (close(fd) == -1)
		err_p("Error: Can't close fildes ", &fd, 1);
}
