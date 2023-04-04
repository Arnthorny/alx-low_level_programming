#include "lists.h"
#include <stdio.h>

/**
  *print_listint - Print all the elements of a listint_t list
  *@h: A singly linked list
  *Return: The number of nodes in the list.
  */

size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}
	return (count);
}
