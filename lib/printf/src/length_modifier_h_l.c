/*
** EPITECH PROJECT, 2023
** LENGTH_MODIFIER_H_L.c
** File description:
** fonction for length modifier l, ll, hh and h
*/
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "../include/myprintf.h"

long long h_and_l(unsigned int nb, struct f_a *f_m)
{
    if (f_m->l == 1) {
        f_m->l = 0;
        return (long)nb;
    }
    if (f_m->l == 2) {
        f_m->l = 0;
        return (long long)nb;
    }
    if (f_m->h == 1) {
        f_m->h = 0;
        return (short)nb;
    }
    if (f_m->h == 2) {
        f_m->h = 0;
        return (signed char)nb;
    }
    return nb;
}
