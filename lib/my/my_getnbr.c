/*
** EPITECH PROJECT, 2023
** task01
** File description:
** day07
*/
#include <stdio.h>
#include <limits.h>
#include "../../include/bsprintf.h"
#include <stdlib.h>

#include <limits.h>

int negative(char const *str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-') {
            res++;
        }
    }
    return (res % 2 == 0) ? 1 : -1;
}

long int factor(char const *str)
{
    int j = 0;

    while (str[j] < '0' || str[j] > '9') {
        j++;
    }
    return j;
}

int my_getnbr(char const *str)
{
    long int mult = 1;
    int neg = negative(str);
    long int nb = 0;
    int i = factor(str);

    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + (str[i] - '0');
        mult *= 10;
        i++;
    }
    if (nb > INT_MAX || nb < INT_MIN) {
        return 0;
    }
    return nb * neg;
}
