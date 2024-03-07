/*
** EPITECH PROJECT, 2023
** MY_PUT_NBR
** File description:
** my_put_nbr for myprintf
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "../include/myprintf.h"

void my_put_nbr(long long nb, struct r_s *r_s, struct f_a *f_m)
{
    if (nb > 0 && f_m->plus == 1 && f_m->zero == 0) {
        my_putchar('+', r_s);
        f_m->plus = 0;
    }
    if (nb < 0) {
        if (f_m->space == 1) {
            f_m->nb += my_real_putchar('-');
            f_m->field -= 1;
            f_m->space = 0;
        } else {
            my_putchar('-', r_s);
        }
        nb = nb * -1;
    }
    if (nb > 9) {
        my_put_nbr(nb / 10, r_s, f_m);
    }
    my_putchar(nb % 10 + '0', r_s);
}
