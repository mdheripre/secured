/*
** EPITECH PROJECT, 2023
** compute_pow
** File description:
** compute a number nb^p
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "../include/myprintf.h"

int compute_pow(int nb, int p)
{
    int result = nb;
    int i = p;

    if (p == 0) {
        return 1;
    }
    if (p < 0) {
        return 0;
    } else {
        result *= compute_pow(nb, i - 1);
    }
    return result;
}
