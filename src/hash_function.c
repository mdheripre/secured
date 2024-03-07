/*
** EPITECH PROJECT, 2023
** MAIN.C
** File description:
** main function for secured program
*/

#include "../include/hashtable.h"

int hash(char *key, int len)
{
    unsigned int result = 0;
    unsigned int hash = 0;
    int j = 0;

    if (!key || len == 0)
        return -1;
    for (unsigned int i = 0; key[i]; i++) {
        hash = (hash << 8) | key[i];
        j++;
        if (j == 4) {
            result ^= hash;
            hash = 0;
            j = 0;
        }
    }
    if (hash != 0) {
        hash = (hash << 8 * j);
        result ^= hash;
    }
    return (int)result;
}
