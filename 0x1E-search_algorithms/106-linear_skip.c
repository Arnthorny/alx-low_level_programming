#include "search_algos.h"


/**
 * last_el - Given a node in a singly linked list, return its tail.
 *
 * @node: Given node.
 * Return: The last node of the skip singly linked list.
 */
skiplist_t *last_el(skiplist_t *node)
{
	while (node->next)
		node = node->next;

	return (node);
}

/**
 * linear_skip - Function to search through a skip linked list of integers
 *
 * @list: A singly linked list of integers
 * @value: Value to be searched for
 * Return: Index of the value or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	int val_found = 0;
	skiplist_t *curr = NULL, *expr = NULL, *u_bnd = NULL;

	curr = list;
	expr = curr ? curr->express : curr;
	while (curr)
	{
		if (!val_found)
			printf("Value checked at index [%ld] = [%d]\n", expr->index, expr->n);
		else
			printf("Value checked at index [%ld] = [%d]\n", curr->index, curr->n);
		if (val_found)
		{
			if (curr && value == curr->n)
				return (curr);
			else if (curr && curr->n < u_bnd->n)
				curr = curr->next;
			else
				return (NULL);
		}
		else if (!val_found && ((expr && expr->n >= value)
					|| (expr && !expr->express)))
		{
			val_found = 1;
			u_bnd = expr->n >= value ? expr : last_el(expr);
			curr = expr->n >= value ? curr : expr;
			printf("Value found between indexes [%ld] and [%ld]\n",
					curr->index, u_bnd->index);
		}

		if (!val_found)
		{
			curr = expr;
			expr = expr ? expr->express : expr;
		}
	}
	return (NULL);
}
