#include "lists.h"
/**
 * free_dlistint - Function to free a linked list
 * @head: Pointer to linked list head
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
