#include "lists.h"
#include <stdio.h>

/**
  *find_loop_start - Find start of loop.
  *@head: A singly linked list
  *Return: The number of nodes in the list.
 */

listint_t const *find_loop_start(const listint_t *head)
{
	const listint_t *s = head, *f = head;
	short int firstMatch = 0;

	if (!head)
		exit(98);

	while (s)
	{
		s = s->next;
		if (!firstMatch)
			f = f ? (f->next ? f->next->next : NULL) : NULL;
		else
			f = f ? f->next : NULL;

		if (f && f == s)
		{
			if (firstMatch)
				return (s);
			s = head;
			firstMatch = 1;
		}

	}
	return (NULL);
}

/**
  *print_listint_safe - Print all the elements of a listint_t list
  * Also works if list has loop.
  *@head: A singly linked list
  *Return: The number of nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t loopC = 0, count = 0;
	const listint_t *ret = find_loop_start(head), *s = head;

	while (s)
	{
		printf("[%p] %d\n", (void *)s, s->n);
		count++;
		s = s->next;
		if (ret && ret == s)
		{
			if (++loopC == 2)
			{
				printf("-> [%p] %d\n", (void *)s, s->n);
				return (count);
			}

			if (count == 1)
			{
				printf("[%p] %d\n", (void *)ret->next, ret->n);
				printf("-> [%p] %d\n", (void *)s, s->n);
				return (count + 1);
			}
		}
	}
	return (count);
}
