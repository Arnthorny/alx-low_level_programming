#include "holberton.h"
#include "main.h"

void err_p(char *str, char *file);
void prnt_elf(El *header_ptr);

void *prnt_class(El *header_ptr);
void *prnt_data(El *header_ptr);
void *prnt_ver(El *header_ptr);
void *prnt_osabi(El *header_ptr);
void *prnt_abiVer(El *header_ptr);
void *prnt_type(El *header_ptr);
void *prnt_epa(El *header_ptr);

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
		err_p("Usage: elf_header elf_filename", NULL);

	elf_file = argv[1];
	fd = open(elf_file, O_RDONLY);

	if (fd == -1)
		err_p("Error: Can't open ", elf_file);

	r = read(fd, &header, sizeof(header));
	if (r == -1)
	{
		err_p("Error: Can't read from ", elf_file);
		close(fd);
	}

	if (!memcmp(header.e_ident, ELFMAG, 4) == 0)
		err_p("Invalid ELF file: ", elf_file);

	prnt_elf(&header);
	close(fd);

	return (0);
}

/**
  *err_p - A function that handles error printing.
  *@str: Error message to print.
  *@file: Filename if required.
  */
void err_p(char *str, char *file)
{
	dprintf(2, "%s%s\n", str, file ? file : "");
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
		if (titl[i + 1])
			printf("  %-35s%s\n", titl[i], (char *) sel_fn[i](header_ptr));
		else
			printf("  %-35s%#lx\n", titl[i], *(unsigned long *) sel_fn[i](header_ptr));
		i++;
	}

}

/**
  *prnt_class - Function to return information about ELF arch
  *@header_ptr: Pointer to Struct containing the information
  *Return: Appropriate string, same as 'readelf -h' format
  */

void *prnt_class(El *header_ptr)
{
	switch (header_ptr->e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			return ("none");
		case ELFCLASS32:
			return ("ELF32");
		case ELFCLASS64:
			return ("ELF64");
		default:
			err_p("Can't read binary's arch", NULL);
	}
	return (NULL);
}

/**
  *prnt_data - Function to return information about ELF data encoding
  *@header_ptr: Pointer to Struct containing the information
  *Return: Appropriate string, same as 'readelf -h' format
  */
void *prnt_data(El *header_ptr)
{
	switch (header_ptr->e_ident[EI_DATA])
	{
		case ELFDATANONE:
			return ("none");
		case ELFDATA2LSB:
			return ("2's complement, little endian");
		case ELFDATA2MSB:
			return ("2's complement, big endian");
		default:
			err_p("Can't read binary's data encoding type", NULL);
	}
	return (NULL);
}

/**
  *prnt_ver - Function to return information about ELF spec version number
  *@header_ptr: Pointer to Struct containing the information
  *Return: Appropriate string, same as 'readelf -h' format
  */
void *prnt_ver(El *header_ptr)
{
	switch (header_ptr->e_ident[EI_VERSION])
	{
		case EV_NONE:
			return ("0");
		case EV_CURRENT:
			return ("1 (current)");
		default:
			err_p("Can't determine ELF version number", NULL);
	}
	return (NULL);
}

/**
  *prnt_osabi - Function to return information about ELF OS and target ABI.
  *@header_ptr: Pointer to Struct containing the information
  *Return: Appropriate string, same as 'readelf -h' format
  */
void *prnt_osabi(El *header_ptr)
{
	switch (header_ptr->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			return ("Unix - System V");
		case ELFOSABI_HPUX:
			return ("Unix - HP-UX");
		case ELFOSABI_NETBSD:
			return ("Unix - NetBSD");
		case ELFOSABI_LINUX:
			return ("Unix - GNU");
		case ELFOSABI_SOLARIS:
			return ("Unix - Solaris");
		case ELFOSABI_AIX:
			return ("Unix - AIX");
		case ELFOSABI_IRIX:
			return ("Unix - IRIX");
		case ELFOSABI_FREEBSD:
			return ("Unix - FreeBSD");
		case ELFOSABI_TRU64:
			return ("Unix - TRU64");
		case ELFOSABI_MODESTO:
			return ("Novell - Modesto");
		case ELFOSABI_OPENBSD:
			return ("Unix - OpenBSD");
		case ELFOSABI_ARM:
			return ("ARM");
		case ELFOSABI_STANDALONE:
			return ("Stand-alone");
		default:
			err_p("Can't determine operating system and ABI", NULL);
	}
	return (NULL);
}

/**
  *prnt_abiVer - Fn to return information about ABI version of target object.
  *@header_ptr: Pointer to Struct containing the information
  *Return: Appropriate string, same as 'readelf -h' format
  */
void *prnt_abiVer(El *header_ptr)
{
	switch (header_ptr->e_ident[EI_ABIVERSION])
	{
		case 0:
			return ("0");
		default:
			err_p("Non conformant ABI version", NULL);
	}
	return (NULL);
}

/**
  *prnt_type - Function to return information about object file type
  *@header_ptr: Pointer to Struct containing the information
  *Return: Appropriate string, same as 'readelf -h' format
  */
void *prnt_type(El *header_ptr)
{
	switch (header_ptr->e_type)
	{
		case ET_NONE:
			return ("NONE (None)");
		case ET_REL:
			return ("REL (Relocatable file)");
		case ET_EXEC:
			return ("EXEC (Executable file)");
		case ET_DYN:
			return ("DYN (Shared object file)");
		case ET_CORE:
			return ("CORE (Core file)");
		default:
			err_p("Invalid object file type", NULL);
	}
	return (NULL);
}

/**
  *prnt_epa - Function to return info about entry point address
  *@header_ptr: Pointer to Struct containing the information
  *Return: Pointer to hex address, same as 'readelf -h' format
  */
void *prnt_epa(El *header_ptr)
{
	return (&(header_ptr->e_entry));
}
