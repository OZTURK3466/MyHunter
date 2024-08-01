/*
** EPITECH PROJECT, 2023
** projet
** File description:
** display_aide
*/

#include "include/bsprintf.h"

int close_window(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)){
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            display_menu(window);
        }
    }
}

void display_aide(sfRenderWindow *window)
{
    sfTexture* backgroundTexture = sfTexture_createFromFile
    ("allsprite/menu_aide.jpg", NULL);
    sfSprite* backgroundSprite = sfSprite_create();
    sfVector2u windowSize = sfRenderWindow_getSize(window);
    float backgroundScaleX =
    (float)windowSize.x / sfTexture_getSize(backgroundTexture).x;
    float backgroundScaleY =
    (float)windowSize.y / sfTexture_getSize(backgroundTexture).y;

    sfSprite_setTexture(backgroundSprite, backgroundTexture, sfTrue);
    sfSprite_setScale(backgroundSprite, (sfVector2f)
    {backgroundScaleX, backgroundScaleY});
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, backgroundSprite, NULL);
        sfRenderWindow_display(window);
        close_window(window);
    }
    sfTexture_destroy(backgroundTexture);
    sfSprite_destroy(backgroundSprite);
}
