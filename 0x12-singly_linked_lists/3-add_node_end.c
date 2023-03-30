#include "lists.h"
#include <string.h>

/**
  *add_node_end - A function that adds a node to the end of a list.
  *@head: A pointer that points to the pointer pointing to head list.
  *@str: Pointer to string to be added.
  *Return: The number of nodes in the list.
  */
list_t *add_node_end(list_t **head, const char *str)
{
	char *string = strdup(str ? str : "(nil)");
	list_t *temp, *end = *head;

	temp = malloc(sizeof(list_t));
	if (!temp)
		return ((list_t *)0);

	(temp)->next = NULL;
	(temp)->len = strlen(str);
	(temp)->str = string;

	if (!(*head))
		return (*head = temp);

	while (end->next)
		end = end->next;

	end->next = temp;
	return (temp);
}
