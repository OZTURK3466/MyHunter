/*
** EPITECH PROJECT, 2023
** projet
** File description:
** hunter
*/

#include "include/bsprintf.h"
#include "include/struct.h"

static void afficher_sprite(sfRenderWindow *window, sfSprite *sprite,
    sfIntRect rect, sfVector2f *positionSprite)
{
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void afficher_crosshair(sfRenderWindow *window, sfSprite *crosshair)
{
    sfRenderWindow_drawSprite(window, crosshair, NULL);
}

void afficher(sfRenderWindow *window, sfSprite *arrierePlan,
    sfSprite *sprite)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, arrierePlan, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
}

void afficher2(sfRenderWindow *window, sfSprite *sprite, sfIntRect rect,
    sfVector2f *positionSprite)
{
    sfSprite_setPosition(sprite, *positionSprite);
    sfSprite_setTextureRect(sprite, rect);
    afficher_sprite(window, sprite, rect, positionSprite);
}

static void afficher3(sfRenderWindow *window, sfSprite *crosshair)
{
    sfVector2i mousePosition = sfMouse_getPositionRenderWindow(window);
    sfVector2f crosshairPosition = {
        (float)mousePosition.x - sfSprite_getGlobalBounds(crosshair).width / 2,
        (float)mousePosition.y - sfSprite_getGlobalBounds(crosshair).height / 2
    };

    sfSprite_setPosition(crosshair, crosshairPosition);
    afficher_crosshair(window, crosshair);
    sfRenderWindow_display(window);
}

void all_sprite(entry_t *var)
{
    sfVideoMode mode = {1920, 1080, 32};

    sfSprite_setTexture(var->crosshair, var->textureCrosshair, sfTrue);
    sfSprite_setScale(var->crosshair,
        (sfVector2f){0.16, 0.16});
    sfSprite_setTexture(var->sprite, var->texture, sfFalse);
    sfSprite_setTexture(var->arrierePlanSprite,
        var->textureArrierePlan, sfFalse);
    sfSprite_setScale(var->arrierePlanSprite,
    (sfVector2f){(float)mode.width / sfTexture_getSize
    (var->textureArrierePlan).x,
    (float)mode.height / sfTexture_getSize(var->textureArrierePlan).y});
}

static void update_crosshair_position(sfSprite *crosshair,
    sfRenderWindow *window)
{
    sfVector2i mousePosition = sfMouse_getPositionRenderWindow(window);
    sfVector2f crosshairPosition = {
        (float)mousePosition.x - sfSprite_getGlobalBounds(crosshair).width / 2,
        (float)mousePosition.y - sfSprite_getGlobalBounds(crosshair).height / 2
    };

    sfSprite_setPosition(crosshair, crosshairPosition);
}

void condition1(entry_t *var, sfTime temps, sfIntRect *rect,
    sfRenderWindow* window)
{
    temps = sfClock_getElapsedTime(var->horloge);
    gerer_clic(var->sprite, &var->positionSprite, window);
    update_crosshair_position(var->crosshair, window);
    if (sfTime_asSeconds(temps) > 0.16) {
        deplacer_rect(rect, 180, 1080);
        sfClock_restart(var->horloge);
    }
    var->positionSprite.x += 1.0f;
    verifier_et_reinitialiser_position(&var->positionSprite,
    window, var->sprite);
    afficher(window, var->arrierePlanSprite, var->sprite);
    afficher2(window, var->sprite, *rect, &var->positionSprite);
    afficher3(window, var->crosshair);
}
