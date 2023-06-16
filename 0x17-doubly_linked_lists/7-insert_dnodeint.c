#include "lists.h"

/**
  *insert_dnodeint_at_index - Function to insert node.at given idx in list
  *@head: A pointer to linked list's head pointer.
  *@idx: Location of insertion
  *@n: Data to be insert
  *Return: The address of new node or NULL if failed.
  */
dlistint_t *insert_dnodeint_at_index\
		   (dlistint_t **head, unsigned int idx, int n)
{
	unsigned int icr = 0;
	dlistint_t *hTmp, *node;

	if (!head)
		return (NULL);
	hTmp = *head;

	while (hTmp || idx == 0)
	{
		if (icr == idx - 1 || idx == 0 || !hTmp->next)
		{
			node = malloc(sizeof(dlistint_t));

			if (!node)
				return (NULL);

			node->prev = hTmp;
			node->n = n;
			node->next = idx != 0 ? hTmp->next : hTmp;
			if (idx == 0)
				hTmp = node;
			else
				hTmp->next = node;
			return (node);
		}
		hTmp = hTmp->next;
		icr++;
	}
	return (NULL);
}
