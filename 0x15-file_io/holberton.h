#ifndef _HOLBERTON_H
#define _HOLBERTON_H

#include <elf.h>
#include <string.h>


#if defined(__LP64__)
#define ElfA(type) Elf64_ ## type
#else
#define ElfA(type) Elf32_ ## type
#endif

#define stringify ((a),(b)) a ## b


typedef ElfA(Ehdr) El;
typedef void* (*hdr_func)(El *);


#endif /* _HOLBERTON_H */
