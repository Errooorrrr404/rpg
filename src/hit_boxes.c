/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Untitled-1hit_boxes
*/

#include <stdio.h>
#include "rpg.h"

void my_hiy_box_2(rpg_t *rpg, float *square)
{
    if (check_touch_boxe(square, rpg->game->pos_map) == 1) {
        if (rpg->game->move != 0) {
            rpg->game->rect_player.height = 20;
            if (rpg->game->clock_cb.seconds > 5) {
                pkmn_battle_random(rpg);
                sfClock_restart(rpg->game->clock_cb.clock_type);
            }
        }
    } else
        rpg->game->rect_player.height = 30;
}

void my_hiy_box(rpg_t *rpg, float *square)
{
    if (check_touch_boxe(square, rpg->game->pos_map) == 1) {
        if (rpg->game->move != 0)
            change_move_person(rpg, square, rpg->game->move);
    }
}