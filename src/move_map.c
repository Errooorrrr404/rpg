/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** move_map
*/

#include <SFML/Window/Keyboard.h>
#include "rpg.h"
#include "my.h"

void move_map_up_down(rpg_t *rpg)
{
    if (rpg->game->move == 3 && rpg->event.type == sfEvtKeyPressed) {
        rpg->game->pos_map.y += 1.1;
    } else if (rpg->game->move == 3 && rpg->event.type == sfEvtKeyReleased) {
        rpg->game->move = 0;
        rpg->game->rect_player.left = 250;
    }
    if (rpg->game->move == 4 && rpg->event.type == sfEvtKeyPressed) {
        rpg->game->pos_map.y -= 1.1;
    } else if (rpg->game->move == 4 && rpg->event.type == sfEvtKeyReleased) {
        rpg->game->move = 0;
        rpg->game->rect_player.left = 37;
    }
}

void move_map_left_right(rpg_t *rpg)
{
    if (rpg->game->move == 1 && rpg->event.type == sfEvtKeyPressed) {
        rpg->game->pos_map.x -= 1.2;
    } else if (rpg->game->move == 1 && rpg->event.type == sfEvtKeyReleased) {
        rpg->game->move = 0;
        rpg->game->rect_player.left = 149;
    }
    if (rpg->game->move == 2 && rpg->event.type == sfEvtKeyPressed) {
        rpg->game->pos_map.x += 1.2;
    } else if (rpg->game->move == 2 && rpg->event.type == sfEvtKeyReleased) {
        rpg->game->move = 0;
        rpg->game->rect_player.left = 352;
    }
}

void move_map(rpg_t *rpg)
{
    move_map_up_down(rpg);
    move_map_left_right(rpg);
}

void move_player(rpg_t *rpg)
{
    if (rpg->game->seconds > 0.15 && rpg->game->move != 0) {
        rpg->game->rect_player.left += 35;
        sfClock_restart(rpg->game->cl_move);
    }
    if (rpg->game->move == 1 && rpg->game->rect_player.left >= 247) {
        rpg->game->rect_player.left = 149;
        rpg->game->move = 0;
    }
    if (rpg->game->move == 2 && rpg->game->rect_player.left >= 457) {
        rpg->game->rect_player.left = 352;
        rpg->game->move = 0;
    }
    if (rpg->game->move == 3 && rpg->game->rect_player.left >= 352) {
        rpg->game->rect_player.left = 250;
        rpg->game->move = 0;
    }
    if (rpg->game->move == 4 && rpg->game->rect_player.left >= 142) {
        rpg->game->rect_player.left = 37;
        rpg->game->move = 0;
    }
}

void move_map_player(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyPressed) {
        if (rpg->event.key.code == sfKeyRight && rpg->game->move == 0) {
            rpg->game->rect_player.left = 149;
            rpg->game->move = 1;
        }
        if (rpg->event.key.code == sfKeyLeft && rpg->game->move == 0) {
            rpg->game->rect_player.left = 352;
            rpg->game->move = 2;
        }
        if (rpg->event.key.code == sfKeyUp && rpg->game->move == 0) {
            rpg->game->rect_player.left = 250;
            rpg->game->move = 3;
        }
        if (rpg->event.key.code == sfKeyDown && rpg->game->move == 0) {
            rpg->game->move = 4;
            rpg->game->rect_player.left = 37;
        }
    }
    move_player(rpg);
    move_map(rpg);
}