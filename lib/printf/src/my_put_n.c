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

void my_put_n(int *printed_so_far, struct f_a *f_m)
{
    *printed_so_far = f_m->nb;
}
