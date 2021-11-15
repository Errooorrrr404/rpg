/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** how_to_play
*/

#include "rpg.h"
#include "my.h"

void put_player_name(rpg_t *rpg, int size)
{
    static int i = 0;

    if (i >= size)
        return;
    if (rpg->event.text.unicode == 8 && i >= 1) {
        rpg->menu->how_to_play->name[i - 1] = '\0';
        i--;
    } else {
        if (rpg->event.key.code >= 0 && rpg->event.key.code != sfKeyBack)
        	rpg->menu->how_to_play->name[i] = rpg->event.text.unicode;
        if (rpg->event.key.code == sfKeySpace)
        	rpg->menu->how_to_play->name[i] = ' ';
        if (i == 0)
            rpg->menu->how_to_play->name[0] = rpg->event.text.unicode - 32;
        i++;
    }
}

void switch_state_2(rpg_t *rpg, int next[4], int previous[4])
{
    switch (rpg->menu->how_to_play->state) {
        case 2:
            state_is_two(rpg, next);
            break;
        case 3:
            state_is_three(rpg, next);
            break;
        case 4:
            state_is_four(rpg, next, previous);
            break;
        case 5:
            state_is_five(rpg, next, previous);
            break;
        default:
            create_game(rpg->game);
            sfMusic_stop(rpg->menu->music_intro);
            sfMusic_play(rpg->game->music);
            rpg->game_state = 2;
            break;
    }
}

void switch_state(rpg_t *rpg, int next[4], int previous[4])
{
    int left[4] = {225, 325, 219, 418};
    int right[4] = {615, 700, 219, 418};

    switch (rpg->menu->how_to_play->state) {
        case -1:
            state_is_neg(rpg, left, right);
            break;
        case 0:
            state_is_zero(rpg, next);
            break;
        case 1:
            state_is_one(rpg, next, previous);
            break;
        default:
            switch_state_2(rpg, next, previous);
            break;
    }
}

void disp_how_to_play(rpg_t *rpg)
{
    int next[4] = {745, 865, 480, 515};
    int previous[4] = {105, 350,  480, 515};

    rpg->menu->how_to_play->time = sfClock_getElapsedTime
    (rpg->menu->how_to_play->cl_move);
    rpg->menu->how_to_play->seconds = rpg->menu->how_to_play->time.microseconds
    / 1000000.0;
    sfRenderWindow_clear(rpg->window, sfBlack);
    switch_state(rpg, next, previous);
}