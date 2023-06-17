#include "lists.h"
/**
 * add_dnodeint - Function to  add node to doubly linked list head
 * @head: Pointer to Pointer of linked list's head
 * @n: Node's data
 * Return: Pointer to new node or NULL if failed
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *node = NULL;

	if (!head)
		return (NULL);

	node = malloc(sizeof(dlistint_t));
	if (!node)
		return (NULL);

	node->prev = NULL;
	if (*head)
		(*head)->prev = node;
	node->next = *head;
	(*head) = node;
	(*head)->n = n;

	return (node);
}
