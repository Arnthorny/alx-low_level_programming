#include "lists.h"
#include <string.h>

/**
  *pop_listint - A function that deletes head node of a list.
  *@head: A pointer that points to the pointer pointing to head.
  *Return: The head node's data or 0.
  */

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int tm = 0;

	if (!*head)
		return (tm);

	temp = *head;
	tm = temp->n;

	*head = (*head)->next;
	free(temp);

	return (tm);
}
