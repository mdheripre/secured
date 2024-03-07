/*
** EPITECH PROJECT, 2023
** HT_DELETE.C
** File description:
** function to delete data in hashtable
*/

#include "../include/hashtable.h"

void free_data(data_t *del)
{
    free(del->key);
    free(del->value);
    free(del);
}

int delete_node(int index, char *key, hashtable_t *ht)
{
    data_t *del;
    data_t *prev = ht[index].data;

    while (my_strcmp(ht[index].data->key, key) != 0) {
        prev = ht[index].data;
        ht[index].data = ht[index].data->next;
        if (ht[index].data == NULL) {
            return 84;
        }
    }
    del = ht[index].data;
    prev->next = ht[index].data->next;
    ht[index].data = prev;
    free_data(del);
    return 0;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int index = 0;
    data_t *del;

    if (!ht || ht[index].data == NULL || !key) {
        return 84;
    }
    index = ht->function(key, ht[0].len) % ht[0].len;
    if (!key || index < 0 || index > ht[0].len)
        return 84;
    if (my_strcmp(ht[index].data->key, key) == 0) {
        del = ht[index].data;
        ht[index].data = ht[index].data->next;
        free_data(del);
        return 0;
    }
    return delete_node(index, key, ht);
}
