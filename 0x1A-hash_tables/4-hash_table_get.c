#include "hash_tables.h"

/**
 * hash_table_get - This function retrieves a value associated with a key
 * @ht: The hash table to retrieve the key from
 * @key: The key to be searched for. It cannot be empty
 *
 * Return: Value associated with key else NULL if key couldn't be found.
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	hash_node_t *node_retrieved = NULL;

	if (!ht || !key || !*key)
		return (NULL);

	index = key_index((unsigned char *)key, ht->size);

	node_retrieved = check_key((char *)key, &(ht->array[index]));

	return (node_retrieved ? node_retrieved->value : NULL);
}
