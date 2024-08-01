/*
** EPITECH PROJECT, 2023
** projet
** File description:
** init_var
*/

#include "include/bsprintf.h"
#include "include/struct.h"

entry_t init_var(void)
{
    sfEvent evenement;
    struct entri var;

    var.textureArrierePlan = sfTexture_createFromFile
    ("allsprite/bgdbz.png", NULL);
    var.arrierePlanSprite = sfSprite_create();
    var.sprite = sfSprite_create();
    var.texture = sfTexture_createFromFile("allsprite/as6.png", NULL);
    var.textureCrosshair = sfTexture_createFromFile
    ("allsprite/crosshair.png", NULL);
    var.crosshair = sfSprite_create();
    var.horloge = sfClock_create();
    return (var);
}
