/*
** EPITECH PROJECT, 2023
** MY_PRINTF
** File description:
** my_printf
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "../include/myprintf.h"

static void check_mod_1(struct r_s *r_s, int *i, struct f_a *f_m)
{
    if (r_s->format[*i] == '+') {
        f_m->plus = 1;
        *i += 1;
    }
    if (r_s->format[*i] == '-') {
        f_m->minus = 1;
        *i += 1;
    }
    if (r_s->format[*i] == '.') {
        f_m->check_dot = 1;
        if (r_s->format[*i + 1] >= '0' && r_s->format[*i + 1] <= '9') {
            f_m->precision = my_getnbr((&r_s->format[*i + 1]), i);
        }
        *i += 1;
    }
}

static void check_mod_2(struct r_s *r_s, int *i, struct f_a *f_m)
{
    if (r_s->format[*i] == '#') {
        f_m->hash = 1;
        *i += 1;
    }
    if (r_s->format[*i] == '0') {
        f_m->zero = 1;
        *i += 1;
    }
    if (r_s->format[*i] >= '1' && r_s->format[*i] <= '9') {
        f_m->field = my_getnbr((&r_s->format[*i]), i);
    }
    if (r_s->format[*i] == ' ') {
        f_m->space = 1;
        *i += 1;
    }
}

static void check_mod_3(struct r_s *r_s, int *i, struct f_a *f_m)
{
    if (r_s->format[*i] == 'l') {
        f_m->l += 1;
        *i += 1;
    }
    if (r_s->format[*i] == 'h') {
        f_m->h += 1;
        *i += 1;
    }
}

void check_all_mod(struct r_s *r_s, int *i, struct f_a *f_m)
{
    int j = 0;

    while (r_s->format[*i] < 'A' && r_s->format[*i] != '%') {
        check_mod_1(r_s, i, f_m);
        check_mod_2(r_s, i, f_m);
    }
    for (j = 0; j < 2; j++) {
        check_mod_3(r_s, i, f_m);
    }
}
