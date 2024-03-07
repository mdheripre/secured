/*
** EPITECH PROJECT, 2023
** HT_DUMP.C
** File description:
** function to display hashtable
*/

#include "../include/hashtable.h"

void print_list(data_t *data, hashtable_t *ht)
{
    while (data != NULL) {
        my_printf("> %d - %s\n",
            ht->function(data->key, ht[0].len),
            data->value);
        data = data->next;
    }
}

void ht_dump(hashtable_t *ht)
{
    int len = 0;

    if (!ht)
        return;
    len = ht[0].len;
    for (int i = 0; i < len; i++) {
        if (ht[i].data == NULL) {
            my_printf("[%i]:\n", ht[i].id);
        } else {
            my_printf("[%i]:\n", ht[i].id);
            print_list(ht[i].data, ht);
        }
    }
}
