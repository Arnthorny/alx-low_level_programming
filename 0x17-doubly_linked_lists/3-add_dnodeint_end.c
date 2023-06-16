#include "lists.h"
/**
 * add_dnodeint_end - Function to  add node to doubly linked list head
 * @head: Pointer to Pointer of linked list's head
 * @n: Node's data
 * Return: Pointer to new node or NULL if failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *node = NULL, *h;

	if (!head)
		return (NULL);

	h = *head;

	node = malloc(sizeof(dlistint_t));
	if (!node)
		return (NULL);

	node->prev = NULL;
	node->next = NULL;
	node->n = n;

	if (!h)
	{
		*head = node;
		return (node);
	}

	while (h)
	{
		if (!h->next)
		{
			node->prev = h;
			h->next = node;
			return (node);
		}
		h = h->next;
	}
	return (NULL);
}
