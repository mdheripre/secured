/*
** EPITECH PROJECT, 2023
** MY_PUT_P
** File description:
** function for %p flag for myprintf
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "../include/myprintf.h"

void my_put_p(void *adress, struct r_s *r_s, struct f_a *f_m)
{
    unsigned int value = (unsigned long long) adress;

    my_putchar('0', r_s);
    my_putchar('x', r_s);
    my_put_x(value, r_s, f_m);
}
