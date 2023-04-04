#include "lists.h"
#include <stdio.h>

/**
  *print_listint_safe - Print all the elements of a listint_t list
  * Also works if list has loop.
  *@head: A singly linked list
  *Return: The number of nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0, firstMatch = 0;
	const listint_t *s = head, *f = head;

	while (s)
	{
		printf("[%p] %d\n", (void *)s, s->n);
		s = s->next;
		if (!firstMatch)
			f = f ? (f->next ? f->next->next : NULL) : NULL;
		else
			f = f ? f->next : NULL;

		if (f == s)
		{
			if (firstMatch)
			{
				printf("[%p] %d\n", (void *)s, s->n);
				printf("-> [%p] %d\n", (void *)s->next, s->next->n);
				return (count);
			}
			firstMatch = 1;
		}
		count++;
	}
	return (count);
}
