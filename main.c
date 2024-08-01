/*
** EPITECH PROJECT, 2023
** projet
** File description:
** main_hunter
*/

#include "include/bsprintf.h"

int main(int ac, char **av)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window = sfRenderWindow_create
    (mode, "SécurityHunter", sfResize | sfClose, NULL);

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        helper();
        return 0;
    }else {
        display_menu(window);
        sfRenderWindow_destroy(window);
    }
}
