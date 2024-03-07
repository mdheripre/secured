/*
** EPITECH PROJECT, 2023
** DELETE_HASH_TABLE.C
** File description:
** function to delete hashtable
*/

#include "../include/hashtable.h"

void delete_hashtable(hashtable_t *ht)
{
    data_t *del;

    if (!ht)
        return;
    for (int i = 0; i < ht[0].len; i++) {
        while (ht[i].data != NULL) {
            del = ht[i].data;
            ht[i].data = ht[i].data->next;
            free(del->key);
            free(del->value);
            free(del);
        }
    }
    free(ht);
}
