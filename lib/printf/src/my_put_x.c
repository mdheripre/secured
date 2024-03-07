/*
** EPITECH PROJECT, 2023
** MY_PUT_X
** File description:
** function for %x flag for myprintf
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "../include/myprintf.h"

void my_put_hash_x(unsigned long long nb, struct r_s *r_s, struct f_a *f_m)
{
    if (f_m->hash != 0 && nb != 0) {
        my_putchar('0', r_s);
        my_putchar('x', r_s);
    }
}

static void check_zero(unsigned long long nb, struct r_s *r_s)
{
    if (nb == 0) {
        my_putchar('0', r_s);
        return;
    }
}

static void my_do_x(unsigned int element, int *list, struct r_s *r_s)
{
    for (int elt = element - 1; list[elt] != 0; elt --) {
        my_putchar(list[elt], r_s);
    }
}

void my_put_x(unsigned long long nb, struct r_s *r_s, struct f_a *f_m)
{
    unsigned int temp = 0;
    int list[8];
    int element = 0;

    my_put_hash_x(nb, r_s, f_m);
    check_zero(nb, r_s);
    for (int i = 1; nb != 0; i *= 10) {
        temp = nb % 16;
        if (temp > 9 && temp < 16)
            list[element] = temp + 87;
        if (temp < 10)
            list[element] = temp + 48;
        nb /= 16;
        element ++;
    }
    list[element] = 0;
    my_do_x(element, list, r_s);
}
