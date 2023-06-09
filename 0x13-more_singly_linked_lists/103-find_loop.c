#include "lists.h"
#include <stdio.h>

/**
  *find_loop_s - Find start of loop.
  *@head: A singly linked list
  *Return: The number of nodes in the list.
 */
listint_t *find_loop_s(listint_t *head)
{
	listint_t *s = head, *f = head;
	short int firstMatch = 0;

	while (s)
	{
		s = s->next;
		if (!firstMatch)
			f = f ? (f->next ? f->next->next : NULL) : NULL;
		else
			f = f ? f->next : NULL;

		if (f && f == s)
		{
			firstMatch = (firstMatch || s == s->next) ? 1 : 0;
			if (firstMatch)
				return (s);
			s = head;
			firstMatch = 1;
		}

	}
	return (NULL);
}

/**
 * find_listint_loop - Frees the loop of a listint_t list
 * @head: Pointer to A singly linked list
 * Return: Pointer to start of loop or NULL if none.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *ret;

	if (!head)
		exit(98);

	ret = find_loop_s(head);
	return (ret ? (ret->next == head ? ret-> next : ret): NULL);
}
