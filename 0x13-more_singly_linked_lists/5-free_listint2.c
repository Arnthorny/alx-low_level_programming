#include "lists.h"
#include <string.h>

/**
  *free_listint2 - A function that frees a listint_t list.
  *@head: Pointer to list.
  */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (!head)
		return;

	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}
