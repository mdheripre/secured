/*
** EPITECH PROJECT, 2023
** MY_PUT_B
** File description:
** function for %b flag for myprintf
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "../include/myprintf.h"

void my_put_b(unsigned long long nb, struct r_s *r_s)
{
    int i = 1;
    unsigned long long temp = 0;
    int list[256];
    int element = 0;

    while (nb != 0) {
        temp = nb % 2;
        list[element] = temp + 48;
        nb /= 2;
        i *= 10;
        element++;
    }
    list[element] = 0;
    for (int elt = element - 1; list[elt] != 0; elt--) {
        my_putchar(list[elt], r_s);
    }
}
