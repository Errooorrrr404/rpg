/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** how_to_play_state_part_two
*/

#include "rpg.h"
#include "my.h"

void state_is_five(rpg_t *rpg, int next[4], int previous[4])
{
    if (check_touch_boxe_2(next, rpg->mouse_pos) == 1) {
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->how_to_play->h6_2,
        NULL);
        if (rpg->event.type == sfEvtMouseButtonPressed &&
        rpg->menu->how_to_play->seconds > 1) {
            rpg->menu->how_to_play->state = 6;
            sfClock_restart(rpg->menu->how_to_play->cl_move);
        }
    } else if (check_touch_boxe_2(previous, rpg->mouse_pos) == 1) {
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->how_to_play->h6_3,
        NULL);
        if (rpg->event.type == sfEvtMouseButtonPressed &&
        rpg->menu->how_to_play->seconds > 1) {
            rpg->menu->how_to_play->state = 4;
            sfClock_restart(rpg->menu->how_to_play->cl_move);
        }
    } else
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->how_to_play->h6_1,
        NULL);
}

void state_is_four(rpg_t *rpg, int next[4], int previous[4])
{
    if (check_touch_boxe_2(next, rpg->mouse_pos) == 1) {
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->how_to_play->h5_2,
        NULL);
        if (rpg->event.type == sfEvtMouseButtonPressed &&
        rpg->menu->how_to_play->seconds > 1) {
            rpg->menu->how_to_play->state = 5;
            sfClock_restart(rpg->menu->how_to_play->cl_move);
        }
    } else if (check_touch_boxe_2(previous, rpg->mouse_pos) == 1) {
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->how_to_play->h5_3,
        NULL);
        if (rpg->event.type == sfEvtMouseButtonPressed &&
        rpg->menu->how_to_play->seconds > 1) {
            rpg->menu->how_to_play->state = 3;
            sfClock_restart(rpg->menu->how_to_play->cl_move);
        }
    } else
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->how_to_play->h5_1,
        NULL);
}

void state_is_neg(rpg_t *rpg, int left[4], int right[4])
{
    if (check_touch_boxe_2(right, rpg->mouse_pos) == 1) {
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->how_to_play->boy,
        NULL);
        if (rpg->event.type == sfEvtMouseButtonPressed &&
        rpg->menu->how_to_play->seconds > 1) {
            rpg->menu->how_to_play->state++;
            rpg->game->boy_girl = 2;
            sfClock_restart(rpg->menu->how_to_play->cl_move);
        }
    } else if (check_touch_boxe_2(left, rpg->mouse_pos) == 1) {
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->how_to_play->girl,
        NULL);
        if (rpg->event.type == sfEvtMouseButtonPressed &&
        rpg->menu->how_to_play->seconds > 1) {
            rpg->menu->how_to_play->state++;
            rpg->game->boy_girl = 1;
            sfClock_restart(rpg->menu->how_to_play->cl_move);
        }
    } else
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->how_to_play->select,
        NULL);
}