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
	char *string = strdup(str);
	list_t *temp;

	temp = malloc(sizeof(list_t));
	if (!temp)
		return ((list_t *)0);
	temp->next = *head;
	*head = temp;
	(*head)->str = string;
	(*head)->len = strlen(string);

	return (*head);
}
