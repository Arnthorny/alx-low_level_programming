#include "hash_tables.h"

/**
 * zero_ht - This function zeroes out all the memory blocks
 * of a hash table's array
 * @ht_arr: Pointer to hash table array
 * @size: Size of array
 */

void zero_ht(hash_node_t **ht_arr, unsigned long int size)
{
	unsigned long int i = 0;

	while (i < size)
		ht_arr[i++] = NULL;
}

/**
 * hash_table_create - This function creates a hash table
 * @size: The size of the array
 *
 * Return: Pointer to newly created hash table or NULL if failed
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_table = NULL;
	hash_node_t **arr_of_nodes = NULL;

	if (size == 0)
		return (NULL);

	new_table = malloc(sizeof(hash_table_t));
	if (!new_table)
		return (NULL);

	arr_of_nodes = malloc(sizeof(hash_node_t *) * size);
	if (!arr_of_nodes)
	{
		free(new_table);
		return (NULL);
	}

	zero_ht(arr_of_nodes, size);
	new_table->size = size;
	new_table->array = arr_of_nodes;

	return (new_table);
}
