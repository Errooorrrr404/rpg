/*
** EPITECH PROJECT, 2019
** create.c
** File description:
** create.c
*/

#include "rpg.h"
#include "my.h"

int create_window(rpg_t *rpg)
{
    sfVideoMode mode = {960, 540, 32};

    rpg->window = sfRenderWindow_create(mode, "Poke RPG", sfResize | sfClose,
    NULL);
    if (!rpg->window)
        return 84;
    sfRenderWindow_setFramerateLimit(rpg->window, 100);
    return 0;
}


