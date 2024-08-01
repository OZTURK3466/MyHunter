/*
** EPITECH PROJECT, 2023
** len_nbr
** File description:
** calcule la len d'un int
*/

#include "../../include/bsprintf.h"

int len_nbr(int arg)
{
    int res = 0;

    if (arg < 0){
        arg *= -1;
        res++;
    }
    if (arg >= 0 && arg <= 9)
        return 1;
    while (arg > 0){
        arg /= 10;
        res++;
    }
    return res;
}
