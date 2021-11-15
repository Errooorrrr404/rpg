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

void turn_management3(battle_t *battle, pokemon_t **pokemon, rpg_t *rpg)
{
    if (battle->turn == 5)
        define_pkmn_catch(battle, pokemon);
    if (battle->turn == 6)
        cinematic_pkmn_catch(rpg, battle, pokemon);
}

void turn_management2(battle_t *battle, pokemon_t **pokemon, rpg_t *rpg)
{
    if (battle->turn == 2 && battle->random_pkmn->current_pv > 0)
        battle_random_turn(battle,  pokemon);
    if (battle->turn == 3 && battle->random_pkmn->current_pv > 0)
        cinematic_pkmn_random(battle, pokemon);
    if (battle->turn == 2 && battle->random_pkmn->current_pv <= 0)
        battle->turn = 0;
}

void turn_management(battle_t *battle, pokemon_t **pokemon, rpg_t *rpg)
{
    if (battle->choice_player != -1 && battle->turn == 0)
        battle_player_turn(battle, pokemon, rpg);
    if (battle->turn == 1)
        cinematic_pkmn_player(battle, pokemon);
    turn_management2(battle, pokemon, rpg);
    turn_management3(battle, pokemon, rpg);
    
}

void cinematic_pkmn_random(battle_t *battle, pokemon_t **pokemon)
{
    get_time_custom(&battle->rdm_attack_clk);
    get_time_custom(&battle->effect_hit_clk);
    if (battle->rdm_attack_clk.seconds < 0.75) {
        if (battle->effect_hit_clk.seconds < 0.1)
            battle->display_pkmn = 0;
        if (battle->effect_hit_clk.seconds > 0.1 && battle->effect_hit_clk.seconds < 0.2) {
            battle->display_pkmn = 1;
        }
        if (battle->effect_hit_clk.seconds > 0.2)
            sfClock_restart(battle->effect_hit_clk.clock_type);
    }
    if (battle->rdm_attack_clk.seconds > 0.75) {
        battle->turn = 0;
        battle->display_pkmn = 1;
    }
}

void cinematic_pkmn_player(battle_t *battle, pokemon_t **pokemon)
{
    get_time_custom(&battle->plyr_attack_clk);
    get_time_custom(&battle->effect_hit_clk);
    if (battle->plyr_attack_clk.seconds < 0.75) {
        if (battle->effect_hit_clk.seconds < 0.1)
            battle->display_pkmn_wild = 0;
        if (battle->effect_hit_clk.seconds > 0.1 && battle->effect_hit_clk.seconds < 0.2) {
            battle->display_pkmn_wild = 1;
        }
        if (battle->effect_hit_clk.seconds > 0.2)
            sfClock_restart(battle->effect_hit_clk.clock_type);
    }
    if (battle->plyr_attack_clk.seconds > 0.75) {
        sfClock_restart(battle->rdm_attack_clk.clock_type);
        battle->turn = 2;
        battle->display_pkmn_wild = 1;
    }
}