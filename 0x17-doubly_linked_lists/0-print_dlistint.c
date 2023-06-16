#include "lists.h"
/**
 * print_dlistint - Function to print nodes of a linked list
 * @h: Pointer to linked list head
 * Return: Number of nodes in list
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;
	const dlistint_t *head;

	head = h;
	while (head)
	{
		printf("%d\n", head->n);
		count++;
		head = head->next;
	}
	return (count);
}
