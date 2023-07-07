#include "hash_tables.h"

/**
 * hash_table_delete - This function deletes a hash table
 * @ht: The hash table to be deleted
 *
 */

void hash_table_delete(hash_table_t *ht)
{
	unsigned long int index = 0;
	hash_node_t *curr_node = NULL, *next = NULL;

	if (!ht)
		return;

	while (index < ht->size)
	{
		curr_node = (ht->array)[index];
		while (curr_node)
		{
			next = curr_node->next;
			free(curr_node->key);
			free(curr_node->value);
			free(curr_node);
			curr_node = next;
		}
		index++;
	}

	free(ht->array);
	free(ht);
}
