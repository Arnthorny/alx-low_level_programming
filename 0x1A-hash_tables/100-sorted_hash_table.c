#include "hash_tables.h"

/**
 * zero_sht - This function zeroes out all the memory blocks
 * of a sorted hash table's array
 * @ht_arr: Pointer to sorted hash table array
 * @size: Size of array
 */

void zero_sht(shash_node_t **ht_arr, unsigned long int size)
{
	unsigned long int i = 0;

	while (i < size)
		ht_arr[i++] = NULL;
}

/**
 * shash_table_create - This function creates the hash table
 * for a sorted hash table structure.
 * @size: The size of the array
 *
 * Return: Pointer to newly created sorted hash table or NULL if failed
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_table = NULL;
	shash_node_t **arr_of_nodes = NULL;

	if (size == 0)
		return (NULL);

	new_table = malloc(sizeof(*new_table));
	if (!new_table)
		return (NULL);

	arr_of_nodes = malloc(sizeof(*arr_of_nodes) * size);
	if (!arr_of_nodes)
	{
		free(new_table);
		return (NULL);
	}

	zero_sht(arr_of_nodes, size);
	new_table->size = size;
	new_table->array = arr_of_nodes;
	new_table->shead = NULL;
	new_table->stail = NULL;

	return (new_table);
}

/**
 * check_key_s - Function checks if given key
 * exists at given sorted hash table index.
 * @k: The key, string.The key is unique in the sorted HashTable
 * @i_ptr: Pointer to head of list at a given index
 * in the sorted hash table
 * Return: Pointer to node of key else NULL if absent.
 */

shash_node_t *check_key_s(char *k, shash_node_t **i_ptr)
{
	shash_node_t *curr_node = *i_ptr;

	while (curr_node)
	{
		if (strcmp(curr_node->key, k) == 0)
			return (curr_node);
		curr_node = curr_node->next;
	}

	return (NULL);
}


/**
 * sort_this_node - This function inserts a new node
 * into a sorted linked list
 * @node: Pointer to the node being inserted.
 * @ht: Pointer to sorted hash table.
 */


void sort_this_node(shash_node_t *node, shash_table_t *ht)
{
	int tmp_weight = 0;
	shash_node_t *curr_node = ht->shead;

	node->sprev = node->snext = NULL;

	while (curr_node)
	{
		tmp_weight = strcmp(node->key, curr_node->key);
		if (tmp_weight < 0)
		{
			node->snext = curr_node;
			if (curr_node->sprev)
				curr_node->sprev->snext = node;
			node->sprev = curr_node->sprev;
			curr_node->sprev = node;
			break;
		}
		else if (!curr_node->snext)
		{
			node->snext = curr_node->snext;
			if (curr_node->snext)
				curr_node->snext->sprev = node;
			node->sprev = curr_node;
			curr_node->snext = node;
			break;
		}
		curr_node = curr_node->snext;
	}
	ht->shead = node->sprev == NULL ? node : ht->shead;
	ht->stail = node->snext == NULL ? node : ht->stail;
}

/**
 * a_node - This function inserts a node
 * at a given sorted hash table index
 * @k: The key, string. The key is unique in the HashTable
 * @v: The value corresponding to a key
 * @i_ptr: Pointer to head of list at a given index
 * in the sorted hash table
 * @ht: Pointer to sorted hash table to add/update the key/val pair
 * Return: Pointer to newly added (or existing) node
 * else NULL if failed.
 */

shash_node_t *a_node(char *k, char *v, shash_node_t **i_ptr, shash_table_t *ht)
{
	shash_node_t *node = NULL, *head = *i_ptr;
	char *dup_value = NULL;

	node = check_key_s(k, i_ptr);

	if (node)
		free(node->value);
	else
	{
		node = malloc(sizeof(*node));
		if (!node)
			return (NULL);
		node->key = strdup(k);
		node->next = head;
		node->value = NULL;
		sort_this_node(node, ht);
		*i_ptr = node;
	}

	dup_value = strdup(v);
	if (!dup_value)
	{
		if (node->value == NULL)
		{
			free(node->key);
			free(node);
		}
		return (NULL);
	}
	node->value = dup_value;

	return (node);
}

/**
 * shash_table_set - This function adds an element into
 * a given sorted hash table
 * @ht: The sorted hash table to add/update the key/value pair
 * @key: The key to be hashed. It cannot be empty
 * @value: The value to be stored.
 * It must be duplicated and can be an empty string
 *
 * Description: If there is a collision add
 * new node to beginning of linked list
 * Return: 1 if success, else 0.
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	shash_node_t *new_node = NULL;

	if (!ht || !key || !value || !*key)
		return (0);

	index = key_index((unsigned char *)key, ht->size);

	new_node = a_node((char *)key, (char *)value, &(ht->array[index]), ht);

	if (new_node == NULL)
		return (0);
	return (1);
}


/**
 * shash_table_get - This function retrieves a value associated with a key
 * @ht: The sorted hash table to retrieve the key from
 * @key: The key to be searched for. It cannot be empty
 *
 * Return: Value associated with key else NULL if key couldn't be found.
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	shash_node_t *node_retrieved = NULL;

	if (!ht || !key || !*key)
		return (NULL);

	index = key_index((unsigned char *)key, ht->size);

	node_retrieved = check_key_s((char *)key, &(ht->array[index]));

	return (node_retrieved ? node_retrieved->value : NULL);
}



/**
 * shash_table_print - This function prints a sorted hash table
 * using a sorted linked list
 * @ht: The hash table to be printed
 * Description: The key/value pair should
 * be printed in the order that they appear
 * in the sorted linked list.
 *
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *curr_node = NULL;
	short int first_pair = 1;

	if (!ht)
		return;

	curr_node = ht->shead;
	printf("{");
	while (curr_node)
	{
		if (first_pair)
		{
			printf("'%s': '%s'", curr_node->key, curr_node->value);
			first_pair = 0;
		}
		else
			printf(", '%s': '%s'", curr_node->key, curr_node->value);
		curr_node = curr_node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - This function prints a sorted hash table
 * using a sorted linked list in reverse
 * @ht: The hash table to be printed
 * Description: The key/value pair should
 * be printed in reverse order that they appear
 * in the sorted linked list.
 *
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *curr_node = NULL;
	short int first_pair = 1;

	if (!ht)
		return;

	curr_node = ht->stail;
	printf("{");
	while (curr_node)
	{
		if (first_pair)
		{
			printf("'%s': '%s'", curr_node->key, curr_node->value);
			first_pair = 0;
		}
		else
			printf(", '%s': '%s'", curr_node->key, curr_node->value);
		curr_node = curr_node->sprev;
	}
	printf("}\n");
}



/**
 * shash_table_delete - This function deletes a sorted hash table
 * @ht: The sorted hash table to be deleted
 *
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *curr_node = NULL, *next = NULL;

	if (!ht)
		return;
	curr_node = ht->shead;
	while (curr_node)
	{
		next = curr_node->snext;

		free(curr_node->key);
		free(curr_node->value);
		free(curr_node);

		curr_node = next;
	}

	free(ht->array);
	free(ht);
}
