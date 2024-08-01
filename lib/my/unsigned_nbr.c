/*
** EPITECH PROJECT, 2023
** printf
** File description:
** u
*/
#include "../../include/bsprintf.h"

int unsigned_nbr(unsigned int nb)
{
    unsigned int result = 0;

    if (nb < 0){
        result = UINT_MAX - nb;
        return result;
    }
    if (nb > UINT_MAX)
        return 0;
    if (nb / 10)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + '0');
    return 0;
}
