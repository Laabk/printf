#include "hash_tables.h"

/**
 * hash_table_delete - this func deletes a hash table completely
 * @ht: thi apointer to hash table
 * Return: nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int d;
	hash_node_t *new1, new2;

	if (ht == NULL)
	return;
	for (d = 0; d < ht->size; d++)
	{
	new1 = ht->array[d];
	while ((new2 = new1) != NULL)
	{
	new1 = new1->next;
	free(new2->key);
	free(new2->value);
	free(new2);
	}
	}
	free(ht->array);
	free(ht);
}

