#include "hash_tables.h"

/**
 * hash_table_print - This function prints a hash table
 * @ht: The hash table to be printed
 * Description: The key/value pair should
 * be printed in the order that they appear
 * in the hash table's array
 *
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int index = 0;
	hash_node_t *curr_node = NULL;
	short int first_pair = 1;

	if (!ht)
		return;

	printf("{");
	while (index < ht->size)
	{
		curr_node = (ht->array)[index];
		while (curr_node)
		{
			if (first_pair)
			{
				printf("'%s': '%s'", curr_node->key, curr_node->value);
				first_pair = 0;
			}
			else
				printf(", '%s': '%s'", curr_node->key, curr_node->value);
			curr_node = curr_node->next;
		}
		index++;
	}
	printf("}\n");
}
