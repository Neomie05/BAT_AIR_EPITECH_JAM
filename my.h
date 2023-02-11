/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#include <unistd.h>
#include <stdarg.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Audio/Music.h>
#include <SFML/System.h>
#include <time.h>
#include <stdio.h>
#ifndef MY_H_
    #define MY_H_

struct files {
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *sprite_stick;
    sfTexture *texture_stick;
    sfSprite *sprite_bird;
    sfTexture *texture_bird;
    sfSprite *sprite_th;
    sfTexture *texture_th;
    sfMusic *song;
    sfIntRect rect;
    sfVector2i my_mouse;
    sfVector2f position;
    float pass;
    float path;
};
sfRenderWindow *fonction (unsigned int width, unsigned int height);

sfIntRect move_rect(struct files *func, int offset, int max_value, sfClock *clock);

void function(struct files *func, sfClock *clock, sfRenderWindow *window);

void dec(struct files *func, sfEvent event,sfRenderWindow *window);

#endif
