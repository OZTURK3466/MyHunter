/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** struct
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <float.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Window.h>

#pragma once

typedef struct entri{
    sfRenderWindow *window;
    sfEvent evenement;
    sfTexture *textureArrierePlan;
    sfTexture *texture;
    sfTexture *textureCrosshair;
    sfSprite *arrierePlanSprite;
    sfSprite *sprite;
    sfSprite *crosshair;
    sfIntRect rect;
    sfClock *horloge;
    sfTime temps;
    sfVector2f positionSprite;
}entry_t;
