#include "lists.h"
#include <stdio.h>

/**
 *reverse_listint - Print all the elements of listint_t list in reverse
 *@head: A pointer to point to the head of singly linked list
 *Return: The pointer to first node in the reversed list.
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *newHead = NULL, *temp;

	if (!head)
		return (NULL);

	while (*head)
	{
		temp = (*head)->next;
		(*head)->next = newHead;
		newHead = (*head);
		(*head) = temp;
	}

	return (*head = newHead);
}
