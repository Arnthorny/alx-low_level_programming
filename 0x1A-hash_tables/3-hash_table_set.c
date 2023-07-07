#include "hash_tables.h"


/**
 * check_key - Function checks if given key exists at given hash table index
 * @k: The key, string
 * The key is unique in the HashTable
 * @i_ptr: Pointer to head of list at a given index in the hash table
 * Return: Pointer to node of key else NULL if absent.
 */

hash_node_t *check_key(char *k, hash_node_t **i_ptr)
{
	hash_node_t *curr_node = *i_ptr;

	while (curr_node)
	{
		if (strcmp(curr_node->key, k) == 0)
			return (curr_node);
		curr_node = curr_node->next;
	}

	return (NULL);
}

/**
 * add_ht_node - This function inserts a node at a given hash table index
 * @k: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @i_ptr: Pointer to head of list at a given index in the hash table
 * Return: Pointer to newly added (or existing) node
 * else NULL if failed.
 */

hash_node_t *add_ht_node(const char *k, const char *value, hash_node_t **i_ptr)
{
	hash_node_t *node = NULL, *head = *i_ptr;
	char *dup_value = NULL;

	node = check_key((char *)k, i_ptr);

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
		*i_ptr = node;
	}

	dup_value = strdup(value);
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
 * hash_table_set - This function adds an element to a given hash table
 * @ht: The hash table to add/update the key/value pair
 * @key: The key to be hashed. It cannot be empty
 * @value: The value to be stored.
 * It must be duplicated and can be an empty string
 *
 * Description: If there is a collision add
 * new node to beginning of linked list
 * Return: 1 if success, else 0.
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	hash_node_t *new_node = NULL;

	if (!ht || !key || !value || !*key)
		return (0);

	index = key_index((unsigned char *)key, ht->size);

	new_node = add_ht_node(key, value, &(ht->array[index]));

	if (new_node == NULL)
		return (0);
	return (1);
}
