/*
** EPITECH PROJECT, 2023
** MY_PUTCHAR
** File description:
** put a char un stdout
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "../include/myprintf.h"

int my_real_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
