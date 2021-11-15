/*
** EPITECH PROJECT, 2019
** ALEXIS DESRUMAUX
** File description:
** file.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include "my.h"
#include "rpg.h"

void mouse_released(battle_t *battle, rpg_t *rpg)
{
    int stop = 0;

    if (battle->choice_player != -1)
    {
        while (stop == 0) {
            while (sfRenderWindow_pollEvent(rpg->window,
            &rpg->event)) {
                if (rpg->event.type == sfEvtMouseButtonReleased)
                    stop = 1;
            }
        }
        stop = 0;
    }
}

void battle_random_turn(battle_t *battle, pokemon_t **pokemon)
{
    int *alea = binare_tab(0, battle->random_pkmn->nbmoves - 1, 100);
    int choice = 0;
    int calcul1 = 0;
    int calcul2 = 0;
    int calcul3 = 0;
    int pv_lost = 0;

    srand(time(NULL));
    choice = random_value(0, battle->random_pkmn->nbmoves - 1, 100, alea);
    calcul1 = battle->random_pkmn->level * 0.4 + 2;
    calcul2 = battle->random_pkmn->moves[choice]->puissance * battle->random_pkmn->attaque;
    calcul3 = pokemon[battle->i_pkmn]->defense * 50;
    pv_lost = ((calcul1 * calcul2) / calcul3) + 2;
    if (pv_lost < 0)
        pv_lost = pv_lost * -1;
    battle->pkmn_life->life -= pv_lost;
    pokemon[battle->i_pkmn]->current_pv -= pv_lost;
    if (pokemon[battle->i_pkmn]->current_pv < 0) {
        pokemon[battle->i_pkmn]->current_pv = 0;
        battle->pkmn_life->life = 0;
    }
    battle->turn = 3;
    battle->move_random_txt.txt = sfText_move_animation(battle->random_pkmn->name,
    battle->random_pkmn->moves[choice]->name, 1);
    free(alea);
}

void battle_player_turn(battle_t *battle, pokemon_t **pokemon, rpg_t *rpg)
{
    int calcul1 = pokemon[battle->i_pkmn]->level * 0.4 + 2;
    int calcul2 = pokemon[battle->i_pkmn]->moves[battle->choice_player]->puissance *
    pokemon[battle->i_pkmn]->attaque;
    int calcul3 = battle->random_pkmn->defense * 50;
    int pv_lost = ((calcul1 * calcul2) / calcul3) + 2;
    if (pv_lost < 0)
        pv_lost = pv_lost * -1;
    battle->random_pkmn_life->life -= pv_lost;
    battle->random_pkmn->current_pv -= pv_lost;
    if (battle->random_pkmn->current_pv < 0) {
        battle->random_pkmn->current_pv = 0;
        battle->random_pkmn_life->life = 0;
    }
    battle->turn = 1;
    battle->move_player_txt.txt = sfText_move_animation(pokemon[battle->i_pkmn]->name,
    pokemon[battle->i_pkmn]->moves[battle->choice_player]->name, 0);
    sfClock_restart(battle->plyr_attack_clk.clock_type);
}

int choose_capacity_battle_next(rpg_t *rpg, pokemon_t **pokemon, int i_pkmn)
{
    int box3[5] = {570, 750, 484, 540};
    int box4[5] = {750, 950, 484, 540};

    if (pokemon[i_pkmn]->nbmoves >= 3 && rpg->event.type == sfEvtMouseButtonPressed
    && check_touch_boxe_2(box3, rpg->mouse_pos))
        return (2);
    else if (pokemon[i_pkmn]->nbmoves >= 4 && rpg->event.type == sfEvtMouseButtonPressed
    && check_touch_boxe_2(box4, rpg->mouse_pos))
        return (3);
    else
        return (-1);
}

int choose_capacity_battle(rpg_t *rpg, battle_t *battle)
{
    capacity_t **moves = rpg->game->pkmn_bag->pokemon[battle->i_pkmn]->moves;
    pokemon_t **pokemon = rpg->game->pkmn_bag->pokemon;
    int box1[5] = {570, 750, 404, 484};
    int box2[5] = {750, 950, 404, 484};

    if (pokemon[battle->i_pkmn]->nbmoves >= 1 && rpg->event.type == sfEvtMouseButtonPressed
    && check_touch_boxe_2(box1, rpg->mouse_pos))
        return (0);
    else if (pokemon[battle->i_pkmn]->nbmoves >= 2 && rpg->event.type == sfEvtMouseButtonPressed
    && check_touch_boxe_2(box2, rpg->mouse_pos))
        return (1);
    return (choose_capacity_battle_next(rpg, pokemon, battle->i_pkmn));
}