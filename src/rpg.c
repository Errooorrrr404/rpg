/*
** EPITECH PROJECT, 2019
** rpg->c
** File description:
** rpg->c
*/

#include "rpg.h"
#include "my.h"

void game_loop(rpg_t *rpg)
{
    while (sfRenderWindow_isOpen(rpg->window)) {
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event))
            event(rpg);
        resize_mouse(rpg);
        if (rpg->game_state == 0)
            menu_rpg(rpg);
        if (rpg->game_state == 1)
            disp_how_to_play(rpg);
        if (rpg->game_state == 2)
            game_rpg(rpg);
        sfRenderWindow_display(rpg->window);
    }
}

int rpg(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));

    if (!rpg)
        return 84;
    if (init_struct(rpg) == 84)
        return 84;
    game_loop(rpg);
    free_rpg(rpg);
    return 0;
}
