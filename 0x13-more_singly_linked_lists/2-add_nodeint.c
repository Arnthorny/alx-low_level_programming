#include "lists.h"
#include <string.h>

/**
  *add_nodeint - A function that adds a node to the beginning of a list.
  *@head: A pointer that points to the pointer pointing to head.
  *@n: Integer to be added.
  *Return: The address of inserted node.
  */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *temp;

	temp = malloc(sizeof(listint_t));
	if (!temp || !head)
		return (NULL);

	temp->next = *head;
	*head = temp;
	(*head)->n = n;

	return (temp);
}
