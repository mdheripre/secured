/*
** EPITECH PROJECT, 2023
** HT_SEARCH.C
** File description:
** function to search data in hashtable
*/

#include "../include/hashtable.h"

char *get_search(char *key, data_t *data)
{
    while (my_strcmp(data->key, key) != 0) {
        data = data->next;
        if (data == NULL) {
            return NULL;
        }
    }
    return data->value;
}

char *ht_search(hashtable_t *ht, char *key)
{
    int index = 0;

    if (!ht || !key) {
        return NULL;
    }
    index = ht->function(key, ht[0].len) % ht[0].len;
    if (ht[index].data == NULL)
        return NULL;
    return get_search(key, ht[index].data);
}
