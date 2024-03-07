/*
** EPITECH PROJECT, 2023
** MY_GETNBR
** File description:
** return a number send as a string
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "../include/myprintf.h"

int my_strlen2(char const *str)
{
    int i = 0;

    while (*str != '\0') {
        i += 1;
        str += 1;
    }
    return i;
}

int checksign(char const *str)
{
    int l = 1;
    int m = 0;

    while (str[m] == '-' || str[m] == '+') {
        if (str[m] == '-') {
            l *= -1;
        }
        m += 1;
    }
    return l;
}

int count_sign(char const *str)
{
    int i = 0;

    while (str[i] == '-' || str[i] == '+') {
        i += 1;
    }
    return i;
}

int my_getnbr(char const *str, int *i)
{
    int index = my_strlen2(str);
    int j = count_sign(str);
    long k = 0;
    int l = 0;

    while (j < index) {
        if (l > 10) {
            return 0;
        }
        if (str[j] < '0' || str[j] > '9') {
            return k * checksign(str);
        }
        k = ((k * 10) + (str[j] - 48));
        j += 1;
        l += 1;
        *i += 1;
    }
    k *= checksign(str);
    return (k > INT_MAX || k < INT_MIN ? 0 : k);
}
