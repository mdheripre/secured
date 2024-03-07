/*
** EPITECH PROJECT, 2023
** my_put_gm.c
** File description:
** put G flag
*/
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include "../include/myprintf.h"

static double loop_em_for_precision_gm(double nb)
{
    while (nb > 10){
        nb -= 10;
    }
    return nb;
}

void print_nb_egm(double nb, int power, struct r_s *r_s, struct f_a *f_m)
{
    int nb_char = 0;

    my_putchar((int)nb + 48, r_s);
    nb_char ++;
    if (f_m->precision >= 2 && power > 1) {
        my_putchar('.', r_s);
    }
    while ((nb_char) < f_m->precision && power > 1) {
        nb *= 10;
        nb = loop_em_for_precision_gm(nb) + 1e-15;
        if ((nb_char + 1) == f_m->precision) {
            nb += 0.45;
        }
        my_putchar(((int)nb % 10) + 48, r_s);
        nb_char ++;
    }
}

static void display_em_power_gm(int power, struct r_s *r_s, struct f_a *f_m)
{
    my_putchar('E', r_s);
    if (power < 10 && power > -10){
        if (power < 0){
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

static void my_put_em_gm(double nb, struct r_s *r_s, struct f_a *f_m)
{
    int power = 0;

    if (nb >= 0)
        while (nb > 10){
            nb /= 10;
            power ++;
        }
    if (nb < 1 && nb > 0)
        while (nb < 1){
            nb *= 10;
            power --;
        }
    print_nb_egm(nb, power, r_s, f_m);
    display_em_power_gm(power, r_s, f_m);
}

static void my_put_f_gm(double nb, struct r_s *r_s, struct f_a *f_m)
{
    int int_p = (int) nb;
    int len = length_nb(int_p);
    double compute = (nb - int_p) * compute_pow(10, (f_m->precision - len));
    int float_p = (int) (compute + 0.45);

    if (float_p > 1) {
        while ((float_p % 10) == 0) {
            float_p /= 10;
        }
    }
    if (float_p >= 1){
        my_put_nbr(int_p, r_s, f_m);
        my_putchar('.', r_s);
        my_put_nbr(float_p, r_s, f_m);
    } else {
        my_put_nbr(int_p, r_s, f_m);
    }
}

static int compute_cond_gm(double nb)
{
    int power = 0;

    if (nb < 1) {
        while ((int)nb < 1) {
            nb *= 10;
            power --;
        }
    } else {
        while ((int)nb > 10) {
            nb /= 10;
            power ++;
        }
    }
    return power;
}

static void check_hash(int power, int nb, struct r_s *r_s, struct f_a *f_m)
{
    if (power < -4 || power >= f_m->precision) {
        f_m->precision -= 1;
    my_put_e(nb, r_s, f_m);
    } else {
        f_m->precision -= length_nb(nb);
        my_put_f(nb, r_s, f_m);
    }
}

void my_put_gm(double nb, struct r_s *r_s, struct f_a *f_m)
{
    int power;

    if (nb == (double)0){
        my_putchar('0', r_s);
        return;
    }
    power = compute_cond_gm(nb);
    if (f_m->hash == 0) {
        if (power < -4 || power >= f_m->precision) {
            my_put_em_gm(nb, r_s, f_m);
        } else {
            my_put_f_gm(nb, r_s, f_m);
        }
    } else {
            check_hash(power, nb, r_s, f_m);
    }
}
