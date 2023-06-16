#include "lists.h"

/**
  *delete_dnodeint_at_index - Function to delete node.at given idx in list
  *@head: A pointer to linked list's head pointer.
  *@index: Location of deletion
  *Return: 1 if success else -1..
  */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int icr = 0;
	dlistint_t *hTmp, *prev_tmp, *next_tmp;

	if (!head || !*head)
		return (-1);
	hTmp = *head;

	while (hTmp)
	{
		if (icr == index)
		{
			prev_tmp = hTmp->prev;
			next_tmp = hTmp->next;

			if (prev_tmp)
			{
				prev_tmp->next = next_tmp;
				if (next_tmp)
					next_tmp->prev = prev_tmp;
			}
			else
			{
				if (next_tmp)
					next_tmp->prev = NULL;
				*head = next_tmp;
			}
			free(hTmp);
			return (1);
		}
		hTmp = hTmp->next;
		icr++;
	}
	return (-1);
}
