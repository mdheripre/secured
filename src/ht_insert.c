/*
** EPITECH PROJECT, 2023
** HT_INSERT.C
** File description:
** function to insert data in hashtable
*/

#include "../include/hashtable.h"

int insert_value(int index, hashtable_t *ht, char *value, char *key)
{
    data_t *new_data = malloc(sizeof(data_t));

    if (!new_data)
        return 84;
    ht[index].data = new_data;
    ht[index].data->key = my_strdup(key);
    ht[index].data->value = my_strdup(value);
    ht[index].data->next = NULL;
    return 0;
}

int check_key(data_t *data, char *key, char *value)
{
    while (data) {
        if (my_strcmp(data->key, key) == 0) {
            free(data->value);
            data->value = my_strdup(value);
            return 1;
        }
        data = data->next;
    }
    return 0;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int index = 0;
    data_t *new_data;

    if (!key || !value || !ht)
        return 84;
    index = ht->function(key, ht[0].len) % ht[0].len;
    if (ht[index].data != NULL) {
        if (check_key(ht[index].data, key, value) == 1)
            return 0;
        new_data = malloc(sizeof(data_t));
        if (!new_data)
            return 84;
        new_data->key = my_strdup(key);
        new_data->value = my_strdup(value);
        new_data->next = ht[index].data;
        ht[index].data = new_data;
        return 0;
    }
    return insert_value(index, ht, value, key);
}
