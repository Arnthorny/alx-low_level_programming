#include "dog.h"

/**
  * init_dog - A function to initialize variable of type struct dog
  * @d: Pointer to struct
  * @name: Pointer to name of dog string.
  * @age: Age of dog.
  * @owner: Name of dog's owner.
  */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = name;
	d->age = age;
	d->owner = owner;
}
