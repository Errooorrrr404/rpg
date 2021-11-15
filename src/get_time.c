/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** get_time
*/

#include "rpg.h"
#include "my.h"

void get_time_custom(sfml_clock_t *clock_st)
{
    clock_st->time_type = sfClock_getElapsedTime(clock_st->clock_type);
    clock_st->seconds = clock_st->time_type.microseconds / 1000000.0;
}

void get_time(game_t *game)
{
    game->time = sfClock_getElapsedTime(game->cl_move);
    game->seconds = game->time.microseconds / 1000000.0;
}

void get_time_game_loop(game_t *game, sfml_clock_t *clock_st)
{
    get_time(game);
    get_time_custom(clock_st);
}