#include "lists.h"
#include <string.h>

/**
  *free_listint - A function that frees a listint_t list.
  *@head: Pointer to list.
  */
void free_listint(listint_t *head)
{
	listint_t *temp = head;

	if (!head)
		return;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}

}
