/*
** EPITECH PROJECT, 2023
** DISP_FUNCTION
** File description:
** functions disp for the worshop shell
** of organized
*/

#include "../include/hashtable.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;
    int j;

    if (!s1 || !s2)
        return 1;
    while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0')) {
        i++;
    }
    j = s1[i] - s2[i];
    return j;
}
