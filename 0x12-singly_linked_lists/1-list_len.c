#include "lists.h"

/**
  *print_list - A function that prints all the elements of a list_t list
  *@h: A singly linked list
  *Return: The number of nodes in the list.
  */



size_t print_list(const list_t *h)
{
	if (!h)
		return (0);

	printf("[%d] %s\n", h->len, h->str ? h->str : "(nil)");
	return (1 + ((h->next) ? print_list(h->next) : 0));

	/**
	 *int i = 0;
	 while (h)
	 {
		i += 1;
		printf("[%d] %s\n", h->len, h->str ? h->str : "(nil)");
		h = h->next;
	}
	return (i);
	*/
}
