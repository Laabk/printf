#include "hash_tables.h"

/**
 * hash_table_set - Adds more of an element in a hash table.
 * @ht: the pointer to hash table.
 * @key: a non empt key to add to has tabl
 * @value: value of key.
 * Return: failure is 0 Otherwise 1.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *tmpt;
	char *valk;
	unsigned long int list, d;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
	return (0);

	valk = strdup(value);
	if (valk == NULL)
	return (0);

	list = key_index((const unsigned char *)key, ht->size);
	for (d = list; ht->array[d]; d++)
	{
	if (strcmp(ht->array[d]->key, key) == 0)
	{
	free(ht->array[d]->value);
	ht->array[d]->value = valk;
	return (1);
	}
	}
	tmpt = malloc(sizeof(hash_node_t));
	if (tmpt == NULL)
	{
	free(valk);
	return (0);
	}
	tmpt->key = strdup(key);
	if (tmpt->key == NULL)
	{
	free(tmpt);
	return (0);
	}
	tmpt->value = valk;
	tmpt->next = ht->array[list];
	ht->array[list] = tmpt;
	return (1);
}

