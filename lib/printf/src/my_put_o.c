/*
** EPITECH PROJECT, 2023
** MY_PUT_O
** File description:
** function for %o flag for myprintf
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "../include/myprintf.h"

void my_put_o(unsigned long long nb, struct r_s *r_s, struct f_a *f_m)
{
    int i = 1;
    unsigned long long temp = 0;

    if (f_m->hash != 0 && nb != 0){
        my_putchar('0', r_s);
    }
    while (nb != 0) {
        temp += (nb % 8) * i;
        nb /= 8;
        i *= 10;
    }
    my_put_nbr(temp, r_s, f_m);
}
