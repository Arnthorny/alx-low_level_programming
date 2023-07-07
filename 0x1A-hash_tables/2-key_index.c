#include "hash_tables.h"


/**
 * key_index - This function computes the index
 * in a hash table of given size, for a given key
 * @key: The string to be hashed
 * @size: The size of the hash table's array
 *
 * Return: The index at which the key/value pair sould be stored
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash = 0, index = 0;

	hash = hash_djb2(key);
	index = hash % size;

	return (index);
}
