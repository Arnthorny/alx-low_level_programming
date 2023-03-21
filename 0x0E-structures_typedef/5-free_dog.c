#include "dog.h"
#include <stdlib.h>

/**
  * free_dog - A function to free a type struct dog
  * @d: Pointer to struct.
  */

void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->owner);
		free(d->name);
	}
	free(d);
}
