#include "lists.h"
/**
 * get_dnodeint_at_index - Function to return nth node of a linked list
 * @head: Pointer to linked list head
 * @index: nth node to return
 * Return: Number of nodes in list
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i  = 0;

	while (i <= index && head)
	{
		if (i == index)
			return (head);
		i++;
		head = head->next;
	}
	return (NULL);
}
