#include "lists.h"
#include <stdlib.h>
/**
  *print_listint - A function that prints all the elements of a listint_t list
  *@h: A singly linked list
  *Return: The number of nodes in the list.
  */



size_t print_listint(const listint_t *h)
{
	if (!h)
		return (0);

	printf("%d\n", h->n);
	return (1 + ((h->next) ? print_listint(h->next) : 0));
}
