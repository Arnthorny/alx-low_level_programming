#include "lists.h"
#include <string.h>

/**
  *get_nodeint_at_index - A function to return nth node of a list.
  *@head: A pointer that points to head.
  *@index: Index of the node
  *Return: The nth node.
  */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (!head)
		return (NULL);

	while (i <= index && head->next)
	{
		if (i == index)
			return (head);
		head = head->next;
		i++;
	}
	return (NULL);
}
