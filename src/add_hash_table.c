/*
** EPITECH PROJECT, 2023
** ADD_HASH_TABLE.C
** File description:
** function to add hashtable
*/

#include "../include/hashtable.h"

hashtable_t *new_hashtable(int (*hash) (char *, int), int len)
{
    hashtable_t *new_ht;

    if (len < 0 || !hash)
        return NULL;
    new_ht = malloc(sizeof(hashtable_t) * len);
    if (!new_ht)
        return NULL;
    for (int i = 0; i < len; i++) {
        new_ht[i].function = (*hash);
        new_ht[i].len = len;
        new_ht[i].id = i;
        new_ht[i].data = NULL;
    }
    return new_ht;
}
