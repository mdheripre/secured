/*
** EPITECH PROJECT, 2023
** MY_PUT_U
** File description:
** function for %u flag for myprintf
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "../include/myprintf.h"

void my_put_u(unsigned long long nb, struct r_s *r_s, struct f_a *f_m)
{
    if (nb > 9) {
        my_put_u(nb / 10, r_s, f_m);
    }
    my_putchar(nb % 10 + '0', r_s);
}
