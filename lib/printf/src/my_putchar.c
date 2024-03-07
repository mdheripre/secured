/*
** EPITECH PROJECT, 2023
** MY_PUTCHAR
** File description:
** put a char in a string
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "../include/myprintf.h"

void my_putchar(char c, struct r_s *r_s)
{
    r_s->fmt[r_s->index] = c;
    r_s->index += 1;
}
