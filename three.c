#include "hash_tables.h"

/**
 * hash_table_get - gets the value processed in a key
 * @ht: the pointer to hash table used
 * @key: the key of the hash
 * Return: value of the hash.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *tmp;

	if (ht == NULL)
	{
	return (NULL);
	}
	if (key == NULL || *key == '\0')
	{
	return (NULL);
	}
	idx = key_index((unsigned char *)key, ht->size);

	tmp = ht->array[idx];

	while (tmp != NULL)
	{
	if (strcmp(tmp->key, key) == 0)
	return (tmp->value);
	tmp = tmp->next;
	}
	return (NULL);
}

