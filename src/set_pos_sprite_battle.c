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

void set_pos_sprite_battle(battle_t *battle, pokemon_t **pokemon)
{
    sfSprite_setPosition(pokemon[battle->i_pkmn]->pkmn_battle, pokemon[battle->i_pkmn]->pos_pkmn_battle);
    sfSprite_setPosition(battle->random_pkmn->pkmn,
    battle->random_pkmn_obj.sprite_p);
    sfSprite_setPosition(battle->pkbl->sprite, battle->pkbl->sprite_p);
    sfText_setPosition(pokemon[battle->i_pkmn]->name_pkmn,
    pokemon[battle->i_pkmn]->name_pos);
    sfText_setPosition(battle->random_pkmn->name_pkmn,
    battle->random_pkmn->name_pos);
    sfText_setPosition(pokemon[battle->i_pkmn]->level_pkmn,
    pokemon[battle->i_pkmn]->level_pos);
    sfText_setPosition(battle->random_pkmn->level_pkmn,
    battle->random_pkmn->level_pos);
}