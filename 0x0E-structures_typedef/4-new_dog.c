#include "dog.h"
#include "string.h"
#include <stdlib.h>

/**
  * new_dog - A function to create a type struct dog
  * @name: Pointer to name of dog string.
  * @age: Age of dog.
  * @owner: Name of dog's owner.
  * Return: Pointer to type struct dog
  */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;

	d = malloc(sizeof(dog_t));
	if (!d)
		return (NULL);
	d->name = malloc(sizeof(*d->name) * (strlen(name) + 1));
	if (!d->name)
		return (NULL);
	d->name = strcpy(d->name, name);
	d->age = age;

	d->owner = malloc(sizeof(*d->owner) * (strlen(owner) + 1));
	if (!d->owner)
		return (NULL);
	d->owner = strcpy(d->owner, owner);

	return (d);
}
