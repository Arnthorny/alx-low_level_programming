#include "dog.h"
#include <stdio.h>

/**
  * print_dog - A function to print a type struct dog
  * @d: Pointer to struct
  */

void print_dog(struct dog *d)
{
	if (!d)
		return;
	if (d->name)
		printf("Name: %s\n", d->name);
	else
		printf("Name: (nil)\n");
	if (d->age)
		printf("Age: %f\n", d->age);
	else
		printf("Name: (nil)\n");
	if (d->owner)
		printf("Name: %s\n", d->owner);
	else
		printf("Name: (nil)\n");
}