/*
** EPITECH PROJECT, 2019
** ALEXIS DESRUMAUX
** File description:
** file.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "rpg.h"

void free_sfml_clock_t_struct(sfml_clock_t *clock_st)
{
    if (clock_st->clock_type != NULL)
        sfClock_destroy(clock_st->clock_type);
}

void free_life_t_struct(life_t *life)
{
    if (life->sp_life != NULL)
        sfSprite_destroy(life->sp_life);
    if (life->rect_life != NULL)
        sfRectangleShape_destroy(life->rect_life);
    free(life);
}

void free_battle_wild_random(battle_t *battle, rpg_t *rpg)
{
    int nb_pokemon = 0;

    if (battle->gotcha == 1 && rpg->game->pkmn_bag->nb_pokemon != 3) {
        rpg->game->pkmn_bag->nb_pokemon++;
        nb_pokemon = rpg->game->pkmn_bag->nb_pokemon;
        rpg->game->pkmn_bag->pokemon[nb_pokemon - 1] = battle->random_pkmn;
    }
    else {
        sfMusic_stop(battle->battle_wild);
        sfMusic_play(rpg->game->music);
        free_pkmn_struct(battle->random_pkmn);
        free_life_t_struct(battle->pkmn_life);
        free_life_t_struct(battle->random_pkmn_life);
        free_sfml_clock_t_struct(&battle->plyr_attack_clk);
        free_sfml_clock_t_struct(&battle->effect_hit_clk);
        free_sfml_clock_t_struct(&battle->rdm_attack_clk);
        sfMusic_destroy(battle->battle_wild);
        sfView_destroy(battle->view);
        free(battle);
    }
}