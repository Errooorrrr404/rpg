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

sfText *concat_stat_value(char *stat, int value, int size)
{
    char *stat_all = malloc(sizeof(char) * (my_strlen(stat) + 10));
    char *value_str = malloc(sizeof(char) * 10);
    sfText *stat_txt;

    value_str = int2char(value_str, value);
    stat_all = my_strcpy(stat_all, stat);
    stat_all = strconcate(stat_all, value_str);
    stat_txt = string2text("assets/font/pkmn.ttf", stat_all, size);
    free(stat_all);
    free(value_str);
    return (stat_txt);
}

void concat_all_stat_value(pkmn_player_t *pkmn_bag, int i)
{
    pkmn_bag->pokemon[i]->pv_pkmn = concat_stat_value("HP: ",
    pkmn_bag->pokemon[i]->pv, 15);
    pkmn_bag->pokemon[i]->attack_pkmn = concat_stat_value("ATTACK: ",
    pkmn_bag->pokemon[i]->attaque, 15);
    pkmn_bag->pokemon[i]->defense_pkmn = concat_stat_value("DEFENSE: ",
    pkmn_bag->pokemon[i]->defense, 15);
    pkmn_bag->pokemon[i]->speed_pkmn = concat_stat_value("SPEED: ",
    pkmn_bag->pokemon[i]->vitesse, 15);
    pkmn_bag->pokemon[i]->pv_pos = set_position_csfml(665, 375);
}