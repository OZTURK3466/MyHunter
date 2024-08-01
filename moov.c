/*
** EPITECH PROJECT, 2023
** projet
** File description:
** hunter
*/

#include "include/bsprintf.h"
#include "include/struct.h"

void analyser_evenements(sfRenderWindow *window, sfEvent *evenement)
{
    while (sfRenderWindow_pollEvent(window, evenement)) {
        if (evenement->type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
}

void reinitialiser_position(sfVector2f *positionSprite,
    sfRenderWindow *window, sfFloatRect bounds)
{
    positionSprite->x = -bounds.width;
    positionSprite->y = (float)(rand() %
    (sfRenderWindow_getSize(window).y - (int)bounds.height));
}

void gerer_clic(sfSprite *sprite, sfVector2f *positionSprite,
    sfRenderWindow *window)
{
    sfVector2i mousePosition = sfMouse_getPositionRenderWindow(window);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&bounds, mousePosition.x, mousePosition.y))
            reinitialiser_position(positionSprite, window, bounds);
    }
}

sfIntRect deplacer_rect(sfIntRect *rect, int decalage, int valeur_max)
{
    rect->left += decalage;
    if (rect->left >= valeur_max)
        rect->left = 0;
}

void verifier_et_reinitialiser_position(sfVector2f *positionSprite,
    sfRenderWindow *window, sfSprite *sprite)
{
    sfVector2u tailleFenetre = sfRenderWindow_getSize(window);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);

    if (positionSprite->x > tailleFenetre.x) {
        reinitialiser_position(positionSprite, window, bounds);
    }
}
