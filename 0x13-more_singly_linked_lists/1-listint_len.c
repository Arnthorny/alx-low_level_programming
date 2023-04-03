#include "lists.h"

/**
  *listint_len - A function that counts the elements of a listint_s list
  *@h: A singly linked list
  *Return: The number of elements in the list.
  */

size_t listint_len(const listint_t *h)
{
	if (!h)
		return (0);

	return (1 + ((h->next) ? listint_len(h->next) : 0));
}
