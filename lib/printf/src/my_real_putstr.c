/*
** EPITECH PROJECT, 2023
** MY_PUTSTR
** File description:
** my_putstr
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "../include/myprintf.h"

int my_real_putstr(char *str)
{
    int nb = 0;

    while (*str != '\0') {
        nb += my_real_putchar(*str);
        str += 1;
    }
    return nb;
}
