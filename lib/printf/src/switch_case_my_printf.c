/*
** EPITECH PROJECT, 2023
** SWITCH_CASE_MY_PRINTF
** File description:
** switch case for specifiers for my_printf
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "../include/myprintf.h"

static long long get_cast_signed(struct f_a *f_m, va_list va)
{
    if (f_m->h >= 1) {
        return (long long)va_arg(va, int);
    }
    if (f_m->l == 1) {
        return (long long)va_arg(va, long);
    }
    if (f_m->l == 2) {
        return (long long)va_arg(va, long long);
    }
    return va_arg(va, int);
}

static unsigned long long get_cast_unsigned(struct f_a *f_m, va_list va)
{
    if (f_m->h >= 1) {
        return (unsigned long long)va_arg(va, unsigned int);
    }
    if (f_m->l == 1) {
        return (unsigned long long)va_arg(va, unsigned long);
    }
    if (f_m->l == 2) {
        return (unsigned long long)va_arg(va, unsigned long long);
    }
    return va_arg(va, unsigned int);
}

void switch_case_disc(struct r_s *r_s, int *i, struct f_a *f_m, va_list va)
{
    switch (r_s->format[*i]) {
        case 'd' :
        case 'i' :
            my_put_nbr(get_cast_signed(f_m, va), r_s, f_m);
            break;
        case 's' :
            my_putstr(va_arg(va, char *), r_s, f_m);
            break;
        case '%' :
            my_putchar('%', r_s);
            break;
        case 'c' :
            my_putchar(va_arg(va, int), r_s);
            break;
    }
}

void switch_case_uobx(struct r_s *r_s, int *i, struct f_a *f_m, va_list va)
{
    switch (r_s->format[*i]) {
        case 'u' :
            my_put_u(get_cast_unsigned(f_m, va), r_s, f_m);
            break;
        case 'o' :
            my_put_o(get_cast_unsigned(f_m, va), r_s, f_m);
            break;
        case 'b' :
            my_put_b(get_cast_unsigned(f_m, va), r_s);
            break;
        case 'x' :
            my_put_x(get_cast_unsigned(f_m, va), r_s, f_m);
            break;
        case 'X' :
            my_put_xm(get_cast_unsigned(f_m, va), r_s, f_m);
            break;
    }
}

void switch_case_pfn(struct r_s *r_s, int *i, struct f_a *f_m, va_list va)
{
    switch (r_s->format[*i]) {
        case 'p' :
            my_put_p(va_arg(va, void *), r_s, f_m);
            break;
        case 'f' :
        case 'F' :
            my_put_f(va_arg(va, double), r_s, f_m);
            break;
        case 'n' :
            my_put_n(va_arg(va, int *), f_m);
            break;
    }
}

void switch_case_eg(struct r_s *r_s, int *i, struct f_a *f_m, va_list va)
{
    switch (r_s->format[*i]) {
        case 'e' :
            my_put_e(va_arg(va, double), r_s, f_m);
            break;
        case 'E' :
            my_put_em(va_arg(va, double), r_s, f_m);
            break;
        case 'g' :
            my_put_g(va_arg(va, double), r_s, f_m);
            break;
        case 'G' :
            my_put_gm(va_arg(va, double), r_s, f_m);
            break;
    }
}
