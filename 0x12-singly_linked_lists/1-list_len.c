#include "lists.h"

/**
  *list_len - A function that counts the elements of a list_t list
  *@h: A singly linked list
  *Return: The number of elements in the list.
  */

size_t list_len(const list_t *h)
{
	return (1 + ((h->next) ? list_len(h->next) : 0));
	/*
	*int i = 0;
	while (h)
	{
		i += 1;
		h = h->next;
	}
	return (i);
	*/
}
