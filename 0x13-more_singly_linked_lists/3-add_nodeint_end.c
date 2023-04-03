#include "lists.h"
#include <string.h>

/**
  *add_nodeint_end - A function that adds a node to the end of a list.
  *@head: A pointer that points to the pointer pointing to head list.
  *@n: Integer to be added.
  *Return: The number of nodes in the list.
  */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *temp, *end = *head;

	temp = malloc(sizeof(listint_t));
	if (!temp)
		return ((listint_t *)0);

	(temp)->next = NULL;
	(temp)->n = n;

	if (!(*head))
		return (*head = temp);

	while (end->next)
		end = end->next;

	end->next = temp;
	return (temp);
}
