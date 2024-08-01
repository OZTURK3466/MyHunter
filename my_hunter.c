/*
** EPITECH PROJECT, 2023
** projet
** File description:
** main_hunter
*/

#include "include/bsprintf.h"
#include "include/struct.h"

void destroy(entry_t *var, sfRenderWindow *window, sfMusic *music)
{
    sfMusic_destroy(music);
    sfClock_destroy(var->horloge);
    sfSprite_destroy(var->sprite);
    sfTexture_destroy(var->texture);
    sfSprite_destroy(var->arrierePlanSprite);
    sfTexture_destroy(var->textureArrierePlan);
    sfSprite_destroy(var->crosshair);
    sfTexture_destroy(var->textureCrosshair);
}

void display(sfRenderWindow* window)
{
    entry_t var = init_var();
    sfEvent event;
    sfVector2u windowSize = sfRenderWindow_getSize(window);
    sfTime temps;
    sfIntRect rect = {.left = 0, .top = 0, .width = 180, .height = 142};
    sfMusic* music = sfMusic_createFromFile("music.ogg");

    all_sprite(&var);
    sfMusic_play(music);
    while (sfRenderWindow_isOpen(window)) {
        analyser_evenements(window, &var.evenement);
        condition1(&var, temps, &rect, window);
    }
    destroy(&var, window, music);
}
