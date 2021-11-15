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

void draw_basics_battle(rpg_t *rpg, battle_t *battle, pokemon_t **pokemon)
{
    sfRenderWindow_drawSprite(rpg->window, battle->interface.sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, battle->pkbl->sprite, NULL);
    set_pos_sprite_battle(battle, pokemon);
    if (battle->display_pkmn == 1)
        sfRenderWindow_drawSprite(rpg->window, pokemon[battle->i_pkmn]->pkmn_battle, NULL);
    if (battle->display_pkmn_wild == 1)
        sfRenderWindow_drawSprite(rpg->window, battle->random_pkmn->pkmn, NULL);
    sfRenderWindow_drawText(rpg->window, pokemon[battle->i_pkmn]->name_pkmn, NULL);
    sfRenderWindow_drawText(rpg->window, battle->random_pkmn->name_pkmn, NULL);
    sfRenderWindow_drawText(rpg->window, pokemon[battle->i_pkmn]->level_pkmn, NULL);
    sfRenderWindow_drawText(rpg->window, battle->random_pkmn->level_pkmn, NULL);
}

void define_scale_pos_battle(battle_t *battle, pokemon_t **pokemon)
{
    battle->pkmn_obj.scale = set_position_csfml_float(3.25, 3.25);
    battle->random_pkmn_obj.scale = set_position_csfml_float(1.25, 1.25);
    sfSprite_setScale(pokemon[battle->i_pkmn]->pkmn_battle, battle->pkmn_obj.scale);
    sfSprite_setScale(pokemon[battle->i_pkmn]->pkmn, battle->random_pkmn_obj.scale);
    sfText_setCharacterSize(battle->random_pkmn->name_pkmn, 15);
    sfText_setCharacterSize(pokemon[battle->i_pkmn]->name_pkmn, 15);
    sfText_setCharacterSize(pokemon[battle->i_pkmn]->level_pkmn, 15);
    sfText_setCharacterSize(battle->random_pkmn->level_pkmn, 15);
    sfSprite_setTextureRect(pokemon[battle->i_pkmn]->pkmn_battle,
    pokemon[battle->i_pkmn]->rect_pkmn_battle);
    sfSprite_setTextureRect(battle->random_pkmn->pkmn,
    battle->random_pkmn->rect_pkmn);
    define_color_moves_battle(pokemon[battle->i_pkmn]->moves, pokemon[battle->i_pkmn]->nbmoves);
    pokemon[battle->i_pkmn]->pos_pkmn_battle = set_position_csfml(103, 296);
    pokemon[battle->i_pkmn]->name_pos = set_position_csfml(681, 244);
    pokemon[battle->i_pkmn]->level_pos = set_position_csfml(863, 244);
    battle->random_pkmn->name_pos = set_position_csfml(22, 88);
    battle->random_pkmn->level_pos = set_position_csfml(225, 88);
    battle->random_pkmn_obj.sprite_p = set_position_csfml(477, 202);
    battle->pkbl->sprite_p = set_position_csfml(470, 470);
}

void choose_random_pkmn_battle(battle_t *battle, rpg_t *rpg)
{
    char *random_pkmn[10] = {"0", "3", "6", "9", "12", "14", "16", "19", "20", NULL};
    char *level_random[11] = {"1", "2", "3", "4", "5", "6", "7",
    "8", "9", "10", NULL};
    int *alea;
    int i = 0;
    int lvl = 0;

    alea = binare_tab(0, 8, 100);
    srand(time(NULL));
    i = random_value(0, 8, 100, alea);
    free(alea);
    alea = binare_tab(0, 9, 100);
    lvl = random_value(0, 9, 100, alea);
    free(alea);
    battle->random_pkmn = add_pkmn(random_pkmn[i], level_random[lvl], rpg->game->files);
}

void begin_wild_battle(rpg_t *rpg, battle_t *battle)
{
    pokemon_t **pokemon = rpg->game->pkmn_bag->pokemon;

    get_time_custom(&battle->sound_clk);  
    while (battle->sound_clk.seconds < 2) {
        get_time_custom(&battle->sound_clk);
        sfRenderWindow_display(rpg->window);
        sfRenderWindow_clear(rpg->window, sfBlack);
    }
    if (battle->sound_clk.seconds < 3)
        sfRenderWindow_setView(rpg->window, battle->view);
    else
        sfRenderWindow_setView(rpg->window, battle->view_origin);
    if (battle->stop_sound == 0) {
        sfMusic_play(battle->random_pkmn->sound);
        battle->stop_sound = 1;
    }
    else if (battle->stop_sound == 1 && battle->sound_clk.seconds > 3) {
        sfMusic_play(pokemon[battle->i_pkmn]->sound);
        battle->stop_sound = 2;
    }
}

void pkmn_battle_random(rpg_t *rpg)
{
    pokemon_t **pokemon = rpg->game->pkmn_bag->pokemon;
    battle_t *battle = malloc(sizeof(battle_t));

    define_battle_struct(battle, rpg, pokemon);
    while (sfRenderWindow_isOpen(rpg->window) && battle->stop != 1) {
        begin_wild_battle(rpg, battle);
        while (sfRenderWindow_pollEvent(rpg->window,
        &rpg->event) && battle->loop_nb >= 1)
            battle->choice_player = event_battle(rpg, battle, pokemon);
        resize_mouse(rpg);
        mouse_released(battle, rpg);
        draw_basics_battle(rpg, battle, pokemon);
        turn_management(battle, pokemon, rpg);
        set_position_draw_moves_loop(pokemon, rpg, battle);
        sfRenderWindow_display(rpg->window);
        sfRenderWindow_clear(rpg->window, sfBlack);
        if (battle->turn == 0 && battle->random_pkmn->current_pv <= 0 ||
        pokemon[battle->i_pkmn]->current_pv <= 0)
            battle->stop = 1;
        battle->loop_nb += 1;
        battle->choice_player = -1;
    }
    free_battle_wild_random(battle, rpg);
}