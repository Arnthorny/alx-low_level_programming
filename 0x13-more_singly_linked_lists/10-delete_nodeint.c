#include "lists.h"
#include <string.h>

/**
  *delete_nodeint_at_index - A function to delete node.
  *at given position in list
  *@head: A pointer that points to pointer to head.
  *@index: Index of the node
  *Return: The address of new node or NULL if failed.
  */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *hC = *head, *temp;

	if (!hC)
		return (-1);
	while (hC && i <= index)
	{
		if (i == index - 1 || index == 0)
		{
			temp = index ? hC->next : hC;

			if (index == 0)
				*head = temp ? temp->next : temp;
			else
				hC->next = temp ? temp->next : temp;

			free(temp);
			return (1);
		}
		hC = hC->next;
		i++;
	}
	return (-1);
}
