#include "lists.h"
/**
 * sum_dlistint - Function to return sum of all data n of a linked list
 * @head: Pointer to linked list head
 * Return: Sum of all data in list
 */

int sum_dlistint(dlistint_t *head)
{
	int sumAll = 0;

	while (head)
	{
		sumAll += head->n;
		head = head->next;
	}
	return (sumAll);
}
