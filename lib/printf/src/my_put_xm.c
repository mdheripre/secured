/*
** EPITECH PROJECT, 2023
** MY_PUT_XM
** File description:
** function for %x flag for myprintf
*/
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "../include/myprintf.h"

static void my_put_hash_xm(int nb, struct r_s *r_s, struct f_a *f_m)
{
    if (f_m->hash != 0 && nb != 0) {
    my_putchar('0', r_s);
    my_putchar('X', r_s);
    }
}

static void my_do_xm(unsigned int element, int *list, struct r_s *r_s)
{
    for (int elt = element - 1; list[elt] != 0; elt --) {
        my_putchar(list[elt], r_s);
    }
}

void my_put_xm(unsigned int nb, struct r_s *r_s, struct f_a *f_m)
{
    unsigned int temp = 0;
    int list[8];
    int element = 0;

    my_put_hash_xm(nb, r_s, f_m);
    if (nb == 0) {
        my_putchar('0', r_s);
        return;
    }
    for (int i = 1; nb != 0; i *= 10) {
        temp = nb % 16;
        if (temp > 9 && temp < 16)
            list[element] = temp + 55;
        if (temp < 10)
            list[element] = temp + 48;
        nb /= 16;
        element ++;
    }
    list[element] = 0;
    my_do_xm(element, list, r_s);
}
