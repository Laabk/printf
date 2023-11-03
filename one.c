#include "hash_tables.h"

/**
 * hash_table_create - this func makes a hash table in a given size
 * @size: size of the hash table
 * Return: hash table, or Null for fails
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *creat;
	hash_node_t **list;
	unsigned long int d;

	creat = malloc(sizeof(hash_table_t));
	if (creat == NULL)
	return (NULL);

	list = malloc(sizeof(hash_node_t *) * size);
	if (list == NULL)
	return (NULL);

	for (d = 0; d < size; d++)
	list[d] = NULL;

	creat->list = list;
	creat->size = size;

	return (list);
}
