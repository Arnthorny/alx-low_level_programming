#include "lists.h"
#include <stdio.h>

/**
  *find_loop_start - Find start of loop.
  *@head: A singly linked list
  *@ind: Index to indicate loop's position
  *Return: The number of nodes in the list.
 */
listint_t const *find_loop_start(const listint_t *head, size_t *ind)
{
	const listint_t *s = head, *f = head;
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
			*ind += 1;
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
  *print_listint_safe - Print all the elements of a listint_t list
  * Also works if list has loop.
  *@head: A singly linked list
  *Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0, i = 0, lCount = 0;
	const listint_t *ret = find_loop_start(head, &i), *s = head;

	while (s)
	{
		printf("[%p] %d\n", (void *)s, s->n);
		s = s->next;
		count += 1;
		lCount += (ret && ret == s ? 1 : 0);

		if (ret && ((s == head) || (lCount == 2)))
		{
			if (lCount == 2)
				printf("-> [%p] %d\n", (void *)ret, ret->n);
			else
				printf("-> [%p] %d\n", (void *)ret->next, ret->next->n);

			return (count);
		}
	}
	return (count);
}
