#include <stdio.h>

void bM(void) __attribute__((constructor));

/**
  *bM - A function that executes before main.
  */
void bM(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

