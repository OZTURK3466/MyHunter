/*
** EPITECH PROJECT, 2023
** bsprintf
** File description:
** file .h
*/
#pragma once
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
#include "struct.h"

int my_put_nbr(long int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
void my_putchar(char c);
char *my_strcpy(char *dest, char const *src);
int verif_flags(char s, va_list list, int nb_str);
int my_putnbr_base(int nbr, char *base);
void my_put_float(double nbr, int nbr_decimal, char c);
int unsigned_nbr(unsigned int nb);
int my_printf(const char *format, ...);
int len_nbr(int arg);
void my_put_e(float nbr, char c);
int my_compute_power_rec(int nb, int p);
int my_getnbr(char const *str);
void helper(void);
entry_t init_var(void);
void display_menu(sfRenderWindow *window);
void display(sfRenderWindow* window);
void condition1(entry_t *var, sfTime temps,
    sfIntRect *rect, sfRenderWindow* window);
void all_sprite(entry_t *var);
void verifier_et_reinitialiser_position(sfVector2f *positionSprite,
    sfRenderWindow *window, sfSprite *sprite);
sfIntRect deplacer_rect(sfIntRect *rect, int decalage, int valeur_max);
void reinitialiser_position(sfVector2f *positionSprite,
    sfRenderWindow *window, sfFloatRect bounds);
void analyser_evenements(sfRenderWindow *window, sfEvent *evenement);
void gerer_clic(sfSprite *sprite, sfVector2f *positionSprite,
    sfRenderWindow *window);
void afficher_crosshair(sfRenderWindow *window, sfSprite *crosshair);
void afficher2(sfRenderWindow *window, sfSprite *sprite, sfIntRect rect,
    sfVector2f *positionSprite);
void afficher(sfRenderWindow *window, sfSprite *arrierePlan,
    sfSprite *sprite);
void display_aide(sfRenderWindow *window);
