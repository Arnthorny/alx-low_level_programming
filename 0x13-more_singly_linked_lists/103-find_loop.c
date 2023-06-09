#include "lists.h"
#include <stdio.h>

/**
 * find_listint_loop - Frees the loop of a listint_t list
 * @head: Pointer to A singly linked list
 * Return: Pointer to start of loop or NULL if none.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *s = head, *f = head;

	if (!head)
		exit(98);

	while (s)
	{
		s = s->next;
		f = f ? (f->next ? f->next->next : NULL) : NULL;

		if (f && f == s)
		{
			if (s == s->next)
				return (s ? (s->next == head ? s->next : s) : NULL);
			s = head;
			while (s)
			{
				s = s->next;
				f = f ? f->next : NULL;

				if (f && f == s)
					return (s ? (s->next == head ? s->next : s) : NULL);
			}
		}

	}
	return (NULL);
}
