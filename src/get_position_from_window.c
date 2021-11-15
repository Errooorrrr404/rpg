/*
** EPITECH PROJECT, 2019
** ALEXIS DESRUMAUX
** File description:
** file.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics/Texture.h>
#include "my.h"
#include "rpg.h"

void set_n_draw_get_pos(sfSprite *sprite, sfVector2f position,
sfRenderWindow *window2, sfSprite *background)
{
        sfSprite_setPosition(sprite, position);
        sfRenderWindow_drawSprite(window2, background, NULL);
        sfRenderWindow_drawSprite(window2, sprite, NULL);
        sfRenderWindow_display(window2);
        sfRenderWindow_clear(window2, sfBlack);
}

void manage_event_get_pos(sfEvent event, sfVector2f *position,
sfRenderWindow *window2)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window2);
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyLeft)
                position->x -= 1;
        if (event.key.code == sfKeyRight)
                position->x += 1;
        if (event.key.code == sfKeyDown)
                position->y += 1;
        if (event.key.code == sfKeyUp)
                position->y -= 1;
    }
}

void get_position_from_window(sfSprite *sprite, sfVector2f position,
sfRenderWindow *window)
{
    sfEvent event;
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVideoMode mode = {window_size.x, window_size.y, 32};
    sfRenderWindow *window2 = sfRenderWindow_create(mode, "DEBUG",
    sfResize | sfClose, NULL);
    sfTexture *texture = sfTexture_create(window_size.x, window_size.y);
    sfSprite *background = sfSprite_create();

    sfTexture_updateFromRenderWindow(texture, window, 0, 0);
    sfSprite_setTexture(background, texture, sfTrue);
    sfRenderWindow_setFramerateLimit(window2, 100);
    while (sfRenderWindow_isOpen(window2)) {
        while (sfRenderWindow_pollEvent(window2, &event))
            manage_event_get_pos(event, &position, window2);
        set_n_draw_get_pos(sprite, position, window2, background);
    }
    sfRenderWindow_destroy(window2);
    sfSprite_destroy(background);
}