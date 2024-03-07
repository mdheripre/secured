/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#include "../lib/printf/include/myprintf.h"
#include <stdlib.h>

#ifndef HASHTABLE_H
    #define HASHTABLE_H

typedef struct data {
    char *key;
    char *value;
    struct data *next;
} data_t;

typedef struct hashtable_s {
    int (*function)(char *, int);
    int len;
    int id;
    data_t *data;
} hashtable_t;

int hash(char *key, int len);

hashtable_t *new_hashtable(int (*hash)(char *, int), int len);

void delete_hashtable(hashtable_t *ht);

int ht_insert(hashtable_t *ht, char *key, char *value);

int ht_delete(hashtable_t *ht, char *key);

char *ht_search(hashtable_t *ht, char *key);

void ht_dump(hashtable_t *ht);

char *my_strcpy(char *dest, char *src);

char *my_strdup(char *str);

int my_strcmp(char *s1, char *s2);

#endif /* HASHTABLE_H */
