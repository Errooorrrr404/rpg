/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** game_rpg
*/

#include "rpg.h"
#include "my.h"

void game_rpg(rpg_t *rpg)
{
    sfRenderWindow_clear(rpg->window, sfBlack);
    if (rpg->game->disp_bag == 0 && rpg->game->disp_pause == 0)
        move_map_player(rpg);
    display_all(rpg);
}
