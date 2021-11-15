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

void set_moves_info_pkmn(rpg_t *rpg, pkmn_player_t *pkmn_bag, int i)
{
    int k = 0;
    int pos_y[4] = {392, 432, 472, 512};
    sfText *move_learned = string2text("assets/font/pkmn.ttf",
    "MOVE LEARNED", 20);
    sfVector2f move_pos_title = set_position_csfml(130, 352);

    sfText_setPosition(move_learned, move_pos_title);
    sfRenderWindow_drawText(rpg->window, move_learned, NULL);
    for (; k != pkmn_bag->pokemon[i]->nbmoves; k++) {
        sfText_setCharacterSize(pkmn_bag->pokemon[i]->moves[k]->name_ct, 20);
        pkmn_bag->pokemon[i]->moves[k]->name_pos =
        set_position_csfml(160, pos_y[k]);
        sfText_setPosition(pkmn_bag->pokemon[i]->moves[k]->name_ct,
        pkmn_bag->pokemon[i]->moves[k]->name_pos);
        sfRenderWindow_drawText(rpg->window,
        pkmn_bag->pokemon[i]->moves[k]->name_ct, NULL);
    }
}

void set_stats_info_pkmn(rpg_t *rpg, pkmn_player_t *pkmn_bag, int i)
{
    concat_all_stat_value(pkmn_bag, i);
    sfText_setPosition(pkmn_bag->pokemon[i]->pv_pkmn,
    pkmn_bag->pokemon[i]->pv_pos);
    sfRenderWindow_drawText(rpg->window, pkmn_bag->pokemon[i]->pv_pkmn, NULL);
    pkmn_bag->pokemon[i]->attack_pos = set_position_csfml(665, 405);
    sfText_setPosition(pkmn_bag->pokemon[i]->attack_pkmn,
    pkmn_bag->pokemon[i]->attack_pos);
    sfRenderWindow_drawText(rpg->window, pkmn_bag->pokemon[i]->attack_pkmn,
    NULL);
    pkmn_bag->pokemon[i]->defense_pos = set_position_csfml(665, 435);
    sfText_setPosition(pkmn_bag->pokemon[i]->defense_pkmn,
    pkmn_bag->pokemon[i]->defense_pos);
    sfRenderWindow_drawText(rpg->window, pkmn_bag->pokemon[i]->defense_pkmn,
    NULL);
    pkmn_bag->pokemon[i]->speed_pos = set_position_csfml(665, 465);
    sfText_setPosition(pkmn_bag->pokemon[i]->speed_pkmn,
    pkmn_bag->pokemon[i]->speed_pos);
    sfRenderWindow_drawText(rpg->window, pkmn_bag->pokemon[i]->speed_pkmn,
    NULL);
    destroy_text_display_stats(pkmn_bag, i);
}

void set_basic_info_pkmn_stats2(rpg_t *rpg, pkmn_player_t *pkmn_bag, int i)
{
    color_by_type_pkmn(pkmn_bag->pokemon[i]);
    sfText_setStyle(pkmn_bag->pokemon[i]->type1_pkmn, sfTextBold);
    pkmn_bag->pokemon[i]->type1_pos = set_position_csfml(665, 345);
    sfText_setPosition(pkmn_bag->pokemon[i]->type1_pkmn,
    pkmn_bag->pokemon[i]->type1_pos);
    sfRenderWindow_drawText(rpg->window, pkmn_bag->pokemon[i]->type1_pkmn,
    NULL);
    sfText_setStyle(pkmn_bag->pokemon[i]->type2_pkmn, sfTextBold);
    pkmn_bag->pokemon[i]->type2_pos = set_position_csfml(780, 345);
    sfText_setPosition(pkmn_bag->pokemon[i]->type2_pkmn,
    pkmn_bag->pokemon[i]->type2_pos);
    sfRenderWindow_drawText(rpg->window, pkmn_bag->pokemon[i]->type2_pkmn,
    NULL);
}

void set_basic_info_pkmn_stats(rpg_t *rpg, pkmn_player_t *pkmn_bag, int i)
{
    sfText_setCharacterSize(pkmn_bag->pokemon[i]->name_pkmn, 15);
    pkmn_bag->pokemon[i]->name_pos = set_position_csfml(665, 315);
    sfText_setPosition(pkmn_bag->pokemon[i]->name_pkmn,
    pkmn_bag->pokemon[i]->name_pos);
    sfRenderWindow_drawText(rpg->window, pkmn_bag->pokemon[i]->name_pkmn, NULL);
    sfText_setCharacterSize(pkmn_bag->pokemon[i]->name_pkmn, 12);
    sfText_setCharacterSize(pkmn_bag->pokemon[i]->level_pkmn, 15);
    pkmn_bag->pokemon[i]->level_pos = set_position_csfml(860, 315);
    sfText_setPosition(pkmn_bag->pokemon[i]->level_pkmn,
    pkmn_bag->pokemon[i]->level_pos);
    sfRenderWindow_drawText(rpg->window, pkmn_bag->pokemon[i]->level_pkmn,
    NULL);
    sfText_setCharacterSize(pkmn_bag->pokemon[i]->level_pkmn, 9);
    set_basic_info_pkmn_stats2(rpg, pkmn_bag, i);
}

void display_stats(rpg_t *rpg)
{
    pkmn_player_t *pkmn_bag = rpg->game->pkmn_bag;
    int i = pkmn_bag->pkmn_display_stats;
    sfVector2f scale = {.x = 2.80, .y = 2.80};

    sfRenderWindow_drawSprite(rpg->window, rpg->game->pkmn_bag->stats_menu,
    NULL);
    sfSprite_setScale(pkmn_bag->pokemon[i]->pkmn, scale);
    pkmn_bag->pokemon[i]->pos_pkmn =
    set_position_csfml(720, 1);
    sfSprite_setPosition(pkmn_bag->pokemon[i]->pkmn,
    pkmn_bag->pokemon[i]->pos_pkmn);
    sfSprite_setTextureRect(pkmn_bag->pokemon[i]->pkmn,
    pkmn_bag->pokemon[i]->rect_pkmn);
    sfRenderWindow_drawSprite(rpg->window,
    pkmn_bag->pokemon[i]->pkmn, NULL);
    set_basic_info_pkmn_stats(rpg, pkmn_bag, i);
    set_stats_info_pkmn(rpg, pkmn_bag, i);
    set_moves_info_pkmn(rpg, pkmn_bag, i);
}
