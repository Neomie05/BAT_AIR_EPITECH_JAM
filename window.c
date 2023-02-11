/*
** EPITECH PROJECT, 2022
** window
** File description:
** open a window
*/

#include "my.h"

void cut(struct files *func, sfEvent event, sfRenderWindow *window)
{
    sfClock *clock;
    while (sfRenderWindow_isOpen(window)) {
        sfSprite_setPosition(func->sprite_bird,(sfVector2f)
                                {func->pass, func->path});
        func->pass += 0.05;
        if (func->pass > 112) {
            func->pass = 0;
            func->path = rand () % 220;
        }
        sfRenderWindow_setMouseCursorVisible(window, sfFalse);
        func->rect = move_rect(func, 112, 199, clock);
        sfRenderWindow_drawSprite(window, func->sprite, NULL);
        sfSprite_setTextureRect(func->sprite_bird, func->rect);
        sfSprite_setTextureRect(func->sprite_th, func->rect);
        sfRenderWindow_drawSprite(window, func->sprite_stick, NULL);
        sfRenderWindow_drawSprite(window, func->sprite_bird, NULL);
        sfRenderWindow_drawSprite(window, func->sprite_th, NULL);
        sfRenderWindow_display(window);
        dec(func, event, window);
    }
}

void cutwo(struct files *func)
{
    func->song = sfMusic_createFromFile("song.ogg");
    func->my_mouse;
    func->position.x = 0;
    func->position.y = 0;
    func->pass = 0, func->path = 0;
    func->rect.top = 0;
    func->rect.left = 0;
    func->rect.width = 100;
    func->rect.height = 112;
    sfMusic_play(func->song);
    func->texture = sfTexture_createFromFile("war(3).jpg", NULL);
    func->sprite = sfSprite_create();
    func->texture_bird = sfTexture_createFromFile("iron.png", NULL);
    func->sprite_bird = sfSprite_create();
    func->texture_th = sfTexture_createFromFile("thanos.png", NULL);
    func->sprite_th = sfSprite_create();
    func->texture_stick = sfTexture_createFromFile("stick.png", NULL);
    func->sprite_stick = sfSprite_create();
    sfSprite_setTexture(func->sprite, func->texture, sfTrue);
    sfSprite_setTexture(func->sprite_bird, func->texture_bird, sfTrue);
    sfSprite_setTexture(func->sprite_th, func->texture_th, sfTrue);
    sfSprite_setTexture(func->sprite_stick, func->texture_stick, sfTrue);
}

int main(void)
{
    int max_value, offset;
    struct files file;
    struct files *func = &file;
    sfRenderWindow *window = fonction(1023,576);
    sfEvent event;
    sfClock *clock;
    clock = sfClock_create();
    move_rect(func, offset, max_value, clock);
    cutwo(func);
    cut(func, event, window);
    function(func, clock, window);
    return (0);
}
