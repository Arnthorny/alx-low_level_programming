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
	printf("%8s   ", "Magic:");
	for (i = 0; i < EI_NIDENT - 1; i++)
		printf("%02hx ", header_ptr->e_ident[i]);
	printf("%02hx\n", header_ptr->e_ident[i]);

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
	switch (header_ptr->e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("  %-35s%s\n", titl, "none");
			break;
		case ELFCLASS32:
			printf("  %-35s%s\n", titl, "ELF32");
			break;
		case ELFCLASS64:
			printf("  %-35s%s\n", titl, "ELF64");
			break;
		default:
			printf("  %-35s<unknown: %x>\n", titl, header_ptr->e_ident[EI_CLASS]);
	}
}

/**
  *prnt_data - Function to print information about ELF data encoding
  *@header_ptr: Pointer to Struct containing the information
  *@titl: Title of current information.
  */
void prnt_data(El *header_ptr, char *titl)
{
	switch (header_ptr->e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("  %-35s%s\n", titl, "none");
			break;
		case ELFDATA2LSB:
			printf("  %-35s%s\n", titl, "2's complement, little endian");
			break;
		case ELFDATA2MSB:
			printf("  %-35s%s\n", titl, "2's complement, big endian");
			break;
		default:
			printf("  %-35s<unknown: %x>\n", titl, header_ptr->e_ident[EI_DATA]);
	}
}

/**
  *prnt_ver - Function to print information about ELF spec version number
  *@header_ptr: Pointer to Struct containing the information
  *@titl: Title of current information.
  */
void prnt_ver(El *header_ptr, char *titl)
{
	switch (header_ptr->e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf("  %-35s%s\n", titl, "1 (current)");
			break;
		default:
			printf("  %-35s%d\n", titl, header_ptr->e_ident[EI_VERSION]);
	}
}

/**
  *prnt_osabi - Function to print information about ELF OS and target ABI.
  *@header_ptr: Pointer to Struct containing the information
  *@titl: Title of current information.
  */
void prnt_osabi(El *header_ptr, char *titl)
{
	switch (header_ptr->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("  %-35s%s\n", titl, "Unix - System V");
			break;
		case ELFOSABI_HPUX:
			printf("  %-35s%s\n", titl, "Unix - HP-UX");
			break;
		case ELFOSABI_NETBSD:
			printf("  %-35s%s\n", titl, "Unix - NetBSD");
			break;
		case ELFOSABI_LINUX:
			printf("  %-35s%s\n", titl, "Unix - GNU");
			break;
		case ELFOSABI_SOLARIS:
			printf("  %-35s%s\n", titl, "Unix - Solaris");
			break;
		case ELFOSABI_IRIX:
			printf("  %-35s%s\n", titl, "Unix - IRIX");
			break;
		case ELFOSABI_FREEBSD:
			printf("  %-35s%s\n", titl, "Unix - FreeBSD");
			break;
		case ELFOSABI_TRU64:
			printf("  %-35s%s\n", titl, "Unix - TRU64");
			break;
		case ELFOSABI_ARM:
			printf("  %-35s%s\n", titl, "ARM");
			break;
		case ELFOSABI_STANDALONE:
			printf("  %-35s%s\n", titl, "Standalone App");
			break;
		default:
			printf("  %-35s<unknown: %x>\n", titl, header_ptr->e_ident[EI_OSABI]);
	}
}

/**
  *prnt_abiVer - Fn to print information about ABI version of target object.
  *@header_ptr: Pointer to Struct containing the information
  *@titl: Title of current information.
  */
void prnt_abiVer(El *header_ptr, char *titl)
{
	printf("  %-35s%d\n", titl, header_ptr->e_ident[EI_ABIVERSION]);
}

/**
  *prnt_type - Function to print information about object file type
  *@header_ptr: Pointer to Struct containing the information
  *@titl: Title of current information.
  */
void prnt_type(El *header_ptr, char *titl)
{
	uint16_t tmp = header_ptr->e_type;

	if (header_ptr->e_ident[EI_DATA] == ELFDATA2MSB)
		tmp = header_ptr->e_type >> 8;
	switch (tmp)
	{
		case ET_NONE:
			printf("  %-35s%s\n", titl, "NONE (None)");
			break;
		case ET_REL:
			printf("  %-35s%s\n", titl, "REL (Relocatable file)");
			break;
		case ET_EXEC:
			printf("  %-35s%s\n", titl, "EXEC (Executable file)");
			break;
		case ET_DYN:
			printf("  %-35s%s\n", titl, "DYN (Shared object file)");
			break;
		case ET_CORE:
			printf("  %-35s%s\n", titl, "CORE (Core file)");
			break;
		default:
			printf("  %-35s<unknown: %x>\n", titl, header_ptr->e_type);
	}
}

/**
  *prnt_epa - Function to print info about entry point address
  *@h_ptr: Pointer to Struct containing the information
  *@titl: Title of current information.
  */
void prnt_epa(El *h_ptr, char *titl)
{
	if (h_ptr->e_ident[EI_DATA] == ELFDATA2MSB)
	{
		h_ptr->e_entry = ((h_ptr->e_entry << 8) & 0xFF00FF00)
			| ((h_ptr->e_entry >> 8) & 0xFF00FF);
		h_ptr->e_entry = (h_ptr->e_entry << 16) | (h_ptr->e_entry >> 16);
	}

	if (h_ptr->e_ident[EI_CLASS] == ELFCLASS32)
		printf("  %-35s%#x\n", titl, (unsigned int)h_ptr->e_entry);
	else
		printf("  %-35s%#lx\n", titl, h_ptr->e_entry);
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
