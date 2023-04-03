#include "lists.h"
#include <string.h>

/**
  *sum_listint - A function that returns the sum of all n in list.
  *@head: A pointer that points to the head.
  *Return: The sum of all data or 0 if list is empty.
  */

int sum_listint(listint_t *head)
{
	int sum = 0, i = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
		i++;
	}

	return (sum);
}
