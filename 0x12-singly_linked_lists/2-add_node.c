#include "lists.h"
#include <string.h>

/**
  *add_node - A function that adds a node to the beginning of a list.
  *@head: A pointer that points to the pointer pointing to head.
  *@str: Pointer to string to be added.
  *Return: The number of nodes in the list.
  */

list_t *add_node(list_t **head, const char *str)
{
	list_t *temp;

	temp = malloc(sizeof(list_t));
	if (!temp || !head || !str)
		return (NULL);

	temp->next = *head;
	*head = temp;
	(*head)->str = strdup(str);
	(*head)->len = strlen(str);

	return (temp);
}
