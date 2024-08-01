/*
** EPITECH PROJECT, 2023
** projet
** File description:
** display_menu
*/

#include "include/bsprintf.h"
#include "include/struct.h"

void manage_click(sfMouseButtonEvent event, sfRenderWindow* window)
{
    if (event.type == sfEvtMouseButtonPressed && event.button == sfMouseLeft) {
        my_printf("Mouse x=%d y=%d\n", event.x, event.y);
        if (event.x >= 795 && event.x <= 1012
        && event.y >= 499 && event.y <= 559) {
            display(window);
        }
        if (event.x >= 825 && event.x <= 981
        && event.y >= 654 && event.y <= 712) {
            display_aide(window);
        }
    }
}

void bouton_quitter(sfMouseButtonEvent event, sfRenderWindow* window)
{
    if (event.type == sfEvtMouseButtonPressed && event.button == sfMouseLeft) {
        my_printf("Mouse x=%d y=%d\n", event.x, event.y);
        if (event.x >= 764 && event.x <= 1042
        && event.y >= 803 && event.y <= 880) {
            sfRenderWindow_close(window);
        }
    }
}

void analyse_evenement(sfRenderWindow* window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        manage_click(event.mouseButton, window);
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        bouton_quitter(event.mouseButton, window);
    }
}

static void display_sprite(sfRenderWindow *window, sfSprite *backgroundSprite)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, backgroundSprite, NULL);
    sfRenderWindow_display(window);
}

void display_menu(sfRenderWindow *window)
{
    sfEvent event;
    sfTexture* backgroundTexture = sfTexture_createFromFile
    ("allsprite/bg_menu.jpg", NULL);
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
        analyse_evenement(window, event);
        display_sprite(window, backgroundSprite);
    }
    sfTexture_destroy(backgroundTexture);
    sfSprite_destroy(backgroundSprite);
}
