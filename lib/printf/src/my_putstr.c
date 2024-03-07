/*
** EPITECH PROJECT, 2023
** MY_PUTSTR
** File description:
** my_putstr to a string
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "../include/myprintf.h"

void my_putstr(char *str, struct r_s *r_s, struct f_a *f_m)
{
    while (*str != '\0') {
        if (f_m->precision == 0) {
            return;
        }
        if (f_m->check_dot == 1) {
            f_m->precision -= 1;
        }
        my_putchar(*str, r_s);
        str += 1;
    }
}
