/*
** EPITECH PROJECT, 2023
** my_put_g.c
** File description:
** put g flag
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include "../include/myprintf.h"

int length_nb(int nb)
{
    int len = 1;

    if (nb == 0) {
        len = 0;
        return len;
    }
    if (nb > 9) {
        while (nb > 10){
            nb /= 10;
            len ++;
        }
    }
    return len;
}
