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

static void print_field(struct f_a *f_m)
{
    if (f_m->zero == 1 && f_m->minus == 0) {
        f_m->nb += my_real_putchar('0');
    } else {
        f_m->nb += my_real_putchar(' ');
    }
    f_m->field -= 1;
}

static void print_space(struct f_a *f_m)
{
    if (f_m->plus == 1) {
        f_m->nb += my_real_putchar('+');
        f_m->field -= 1;
        return;
    }
    if (f_m->space == 1) {
        f_m->nb += my_real_putchar(' ');
        f_m->field -= 1;
    }
}

static void print_string(struct r_s *r_s, struct f_a *f_m)
{
    print_space(f_m);
    if (f_m->field > my_strlen2(r_s->fmt) && f_m->minus == 0) {
        while (f_m->field - my_strlen2(r_s->fmt) > 0) {
            print_field(f_m);
        }
    }
    f_m->nb += my_real_putstr(r_s->fmt);
    if (f_m->field > my_strlen2(r_s->fmt) && f_m->minus == 1) {
        while (f_m->field - my_strlen2(r_s->fmt) > 0) {
            print_field(f_m);
        }
    }
}

void init_flags(struct r_s *r_s, struct f_a *f_m)
{
    f_m->plus = 0;
    f_m->minus = 0;
    f_m->precision = 6;
    f_m->field = 0;
    f_m->hash = 0;
    f_m->zero = 0;
    f_m->space = 0;
    f_m->check_dot = 0;
    f_m->l = 0;
    f_m->h = 0;
    r_s->index = 0;
}

static void do_printf(struct r_s *r_s, struct f_a *f_m, va_list va)
{
    int i = 0;

    for (i = 0; r_s->format[i] != '\0'; i++) {
        if (r_s->format[i] == '%') {
            init_flags(r_s, f_m);
            i++;
            check_all_mod(r_s, &i, f_m);
            switch_case_disc(r_s, &i, f_m, va);
            switch_case_uobx(r_s, &i, f_m, va);
            switch_case_pfn(r_s, &i, f_m, va);
            switch_case_eg(r_s, &i, f_m, va);
            my_putchar('\0', r_s);
            print_string(r_s, f_m);
        } else {
            f_m->nb += my_real_putchar(r_s->format[i]);
        }
    }
}

int my_vprintf(char const *fmt, va_list va)
{
    struct f_a f_m;
    struct r_s r_s;

    init_flags(&r_s, &f_m);
    f_m.nb = 0;
    r_s.format = fmt;
    do_printf(&r_s, &f_m, va);
    return f_m.nb;
}

int my_printf(char const *fmt, ...)
{
    int nb = 0;
    va_list va;

    va_start(va, fmt);
    nb = my_vprintf(fmt, va);
    va_end(va);
    return nb;
}
