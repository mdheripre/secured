/*
** EPITECH PROJECT, 2023
** flag_E.c
** File description:
** flag E
*/
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "../include/myprintf.h"

double precision_loop_em(double nb)
{
    double ten = 10;

    while (nb > ten){
        nb -= 10;
    }
    return nb;
}

void print_em_nb(double nb, struct r_s *r_s, struct f_a *f_m)
{
    my_putchar((int)nb + 48, r_s);
    if (f_m->precision > 0) {
        my_putchar('.', r_s);
        for (int rep = f_m->precision; rep != 0; rep --) {
            nb *= 10;
            nb = precision_loop_em(nb) + 1e-14;
            my_putchar(((int)nb % 10) + 48, r_s);
        }
    }
}

void print_em_fin(int power, struct r_s *r_s, struct f_a *f_m)
{
    my_putchar('E', r_s);
    if (power < 10 && power > -10) {
        if (power < 0) {
            my_putchar('-', r_s);
            power *= -1;
        } else {
            my_putchar('+', r_s);
        }
        my_putchar('0', r_s);
    }
    if (power > 9)
        my_putchar('+', r_s);
    my_put_nbr_e(power, r_s, f_m);
}

void my_put_em(double nb, struct r_s *r_s, struct f_a *f_m)
{
    int power = 0;

    if (nb < 1 && nb > 0)
        while (nb < 1){
            nb *= 10;
            power --;
        }
    if (nb >= 1)
        while (nb > 10){
            nb /= 10;
            power ++;
        }
    if (nb == (double)10){
        nb -= 9;
        power ++;
    }
    print_em_nb(nb, r_s, f_m);
    print_em_fin(power, r_s, f_m);
}
