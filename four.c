#include "hash_tables.h"
/**
 * hash_table_get - func that gets a value processed in a key
 * @ht: pointer to the hash table
 * @key: key of the hash
 * Return: value of the hash.
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int kidx;
	hash_node_t *knew;

	if (ht == NULL)
	return (NULL);

	if (key == NULL || *key == '\0')
	return (NULL);

	kidx = key_index((unsigned char *)key, ht->size);
	new = ht->array[kidx];

	while (new != NULL)
	{
	if (strcmp(new->key, key) == 0;
	return (new->value);
	new = new->next;
	}
	return (NULL);
}

