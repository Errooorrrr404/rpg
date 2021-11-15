/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** my_hit_box
*/

#include "rpg.h"
#include "my.h"

void change_move_person(rpg_t *rpg, float *square, int move)
{
    switch (move) {
        case 1:
            if (rpg->game->pos_map.x > (square[0] + square[1]) / 2)
            rpg->game->pos_map.x = square[1];
            break;
        case 2:
            if (rpg->game->pos_map.x < (square[0] + square[1]) / 2)
            rpg->game->pos_map.x = square[0];
            break;
        case 3:
            if (rpg->game->pos_map.y < (square[2] + square[3]) / 2)
            rpg->game->pos_map.y = square[2];
            break;
        case 4:
            if (rpg->game->pos_map.y > (square[2] + square[3]) / 2)
            rpg->game->pos_map.y = square[3];
            break;
    }
}

int check_touch_boxe_2(int *size, sfVector2i player)
{
    if (player.x > size[0] && player.x < size[1] &&
    player.y > size[2] && player.y < size[3])
        return (1);
    return (0);
}

int check_touch_boxe(float *size, sfVector2f player)
{
    if (player.x > size[0] && player.x < size[1] &&
    player.y > size[2] && player.y < size[3])
        return (1);
    return (0);
}