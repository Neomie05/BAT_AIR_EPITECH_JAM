/*
** EPITECH PROJECT, 2022
** windo
** File description:
** windo
*/

#include "my.h"

sfRenderWindow *fonction (unsigned int width, unsigned int height)
{
    sfVideoMode mode = {.width = width, .height = height, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "My window",
                                                sfResize | sfClose, NULL);
    return window;
}

sfIntRect move_rect(struct files *func, int offset, int max_value, sfClock *clock)
{
    float seconds;
    sfTime time;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.2f) {
        if (func->rect.left < 199) {
            func->rect.left += 112;
        } else {
            func->rect.left = 0;
            sfClock_restart(clock);
        }
    }
    return (func->rect);
}

void function(struct files *func, sfClock *clock, sfRenderWindow *window)
{
    sfClock_destroy(clock);
    sfSprite_destroy(func->sprite);
    sfSprite_destroy(func->sprite_stick);
    sfMusic_destroy(func->song);
    sfTexture_destroy(func->texture);
    sfSprite_destroy(func->sprite_bird);
    sfTexture_destroy(func->texture_bird);
    sfSprite_destroy(func->sprite_th);
    sfTexture_destroy(func->texture_th);
    sfRenderWindow_destroy(window);
}

void dec (struct files *func, sfEvent event, sfRenderWindow *window)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        int i = 0, j = 0;
        i = sfMouse_getPositionRenderWindow(window).x;
        j = sfMouse_getPositionRenderWindow(window).y;
        sfVector2f mouse = {i, j};
        sfSprite_setPosition(func->sprite_stick, mouse);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed) {
            func->position = sfSprite_getPosition(func->sprite_bird);
            func->my_mouse = sfMouse_getPositionRenderWindow(window);
            if (func->my_mouse.x >= func->position.x
                && func->my_mouse.x <= (func->position.x + 103)
                && func->my_mouse.y >= func->position.y
                && func->my_mouse.y <= (func->position.y + 103)) {
                func->pass = 0, func->path = rand () % 220;
                sfSprite_setPosition(func->sprite_bird, func->position);
            }
        }
    }
}
