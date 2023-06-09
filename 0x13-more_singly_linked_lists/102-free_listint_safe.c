#include "lists.h"
#include <stdio.h>

/**
  *find_loop_st - Find start of loop.
  *@head: A singly linked list
  *@ind: Index to indicate loop's position
  *Return: The number of nodes in the list.
 */
listint_t *find_loop_st(listint_t *head, size_t *ind)
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
  *free_listint_safe - Frees elements of a listint_t list
  * Also works if list has loop.
  *@head: A singly linked list
  *Return: The number of nodes in the list.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0, i = 0, lCount = 0;
	listint_t *ret, *s, *tmp;


	if (!h)
		exit(98);

	ret = find_loop_st(*h, &i);
	s = *h;
	while (s)
	{
		tmp = s->next;
		free(s);
		s = tmp;
		count += 1;
		lCount += (ret && ret == s ? 1 : 0);

		if (ret && ((s == *h) || (lCount == 2)))
		{
			*h = NULL;
			/*
			if (lCount == 2)
				printf("-> [%p] %d\n", (void *)ret, ret->n);
			else
				printf("-> [%p] %d\n", (void *)ret->next, ret->next->n);
			*/
			return (count);
		}
	}
	*h = NULL;
	return (count);
}
