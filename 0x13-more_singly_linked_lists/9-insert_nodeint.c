#include "lists.h"
#include <string.h>

/**
  *insert_nodeint_at_index - A function to insert node.
  *at given position in list
  *@head: A pointer that points to pointer to head.
  *@idx: Index of the node
  *@n: Integer to inser
  *Return: The address of new node or NULL if failed.
  */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i = 0;
	listint_t *hC = *head, *temp;

	if (!hC)
		return (NULL);

	while (hC->next)
	{
		if (i == idx - 1 || idx == 0)
		{
			temp = malloc(sizeof(listint_t));
			if (!temp)
				return (NULL);

			temp->n = n;
			temp->next = idx ? hC->next : hC;

			if (idx == 0)
				*head = temp;
			else
				hC->next = temp;
			return (temp);
		}
		hC = hC->next;
		i++;
	}
	return (NULL);
}
