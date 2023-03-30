#include "lists.h"
#include <string.h>

/**
  *free_list - A function that frees a list_t list.
  *@head: Pointer to list.
  */
void free_list(list_t *head)
{
	list_t *temp = head;

	if (!head)
		return;

	while (head)
	{
		temp = head->next;
		free(head->str);
		free(head);
		head = temp;
	}

}
