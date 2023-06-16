#include "lists.h"
/**
 * dlistint_len - Function to count nodes in a linked list
 * @h: Pointer to linked list head
 * Return: Number of nodes in list
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;
	const dlistint_t *head;

	head = h;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}
