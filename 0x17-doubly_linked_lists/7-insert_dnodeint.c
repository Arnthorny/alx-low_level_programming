#include "lists.h"

/**
  *insert_dnodeint_at_index - Function to insert node.at given idx in list
  *@h: A pointer to linked list's head pointer.
  *@idx: Location of insertion
  *@n: Data to be insert
  *Return: The address of new node or NULL if failed.
  */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int icr = 0;
	dlistint_t *hTmp, *node;

	hTmp = h ? *h : NULL;
	while (h && (hTmp || idx == 0))
	{
		if (icr == idx - 1 || idx == 0)
		{
			node = malloc(sizeof(dlistint_t));
			if (!node)
				return (NULL);
			node->prev = hTmp;
			node->next = NULL;
			node->n = n;
			if (!hTmp)
				(*h) = node;
			else
			{
				if (idx == 0)
				{
					node->prev = NULL;
					node->next = *h;
					(*h)->prev = node;
					(*h) = node;
				}
				else if (!hTmp->next)
					hTmp->next = node;
				else
				{
					node->next = hTmp->next;
					hTmp->next->prev = node;
					hTmp->next = node;
				}
			}
				return (node);
		}
			hTmp = hTmp->next;
			icr++;
	}
		return (NULL);
}
