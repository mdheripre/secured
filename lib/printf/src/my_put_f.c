/*
** EPITECH PROJECT, 2023
** MY_PUT_F
** File description:
** function for %f flag for myprintf
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "../include/myprintf.h"

static void print_zero(int nb_float_part, struct r_s *r_s, struct f_a *f_m)
{
    while (f_m->precision - length_nb(nb_float_part) > 0) {
        my_put_nbr(0, r_s, f_m);
        f_m->precision -= 1;
    }
}

void my_put_f(double nb, struct r_s *r_s, struct f_a *f_m)
{
    int nb_int_part = (int) nb;
    double compute = (nb - nb_int_part) * compute_pow(10, f_m->precision);
    int nb_float_part = (int) compute;

    my_put_nbr(nb_int_part, r_s, f_m);
    my_putchar('.', r_s);
    if (nb_float_part != 0) {
        my_put_nbr(nb_float_part, r_s, f_m);
    } else {
        print_zero(nb_float_part, r_s, f_m);
    }
}
