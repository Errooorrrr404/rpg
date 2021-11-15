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

void who_is_alive_pkmn_battle(pokemon_t **pokemon, rpg_t *rpg, battle_t *battle)
{
    pkmn_player_t *pkmn_bag = rpg->game->pkmn_bag;
    int stop = 0;

    battle->i_pkmn = 0;
    while (battle->i_pkmn != pkmn_bag->nb_pokemon && stop != 1) {
        if (pokemon[battle->i_pkmn]->current_pv > 0)
            stop = 1;
        else
            battle->i_pkmn++;
    }
}

sfText *sfText_move_animation(char *name, char *ct, int ennemi)
{
    sfText *move_txt = sfText_create();
    char *move_str = malloc(sizeof(char) * (my_strlen(name) + my_strlen(ct) + 50));

    my_strcpy(move_str, name);
    if (ennemi == 0)
        strconcate(move_str, " utilise ");
    else if (ennemi == 1)
        strconcate(move_str, "ennemi utilise ");
    strconcate(move_str, ct);
    move_txt = string2text("./assets/font/pkmn.ttf", move_str, 20);
    free(move_str);
    return (move_txt);
}

void define_value_n_clock_battle(battle_t *battle)
{
    battle->stop = 0;
    battle->loop_nb = 0;
    battle->choice_player = -1;
    battle->stop_sound = 0;
    battle->turn = 0;
    battle->display_pkmn = 1;
    battle->display_pkmn_wild = 1;
    battle->sound_clk.clock_type = sfClock_create();
    battle->plyr_attack_clk.clock_type = sfClock_create();
    battle->effect_hit_clk.clock_type = sfClock_create();
    battle->rdm_attack_clk.clock_type = sfClock_create();
}

void define_view_battle(battle_t *battle, rpg_t *rpg)
{
    sfFloatRect rect;

    sfRenderWindow_clear(rpg->window, sfBlack);
    battle->view_origin = sfView_create();
    battle->view_origin = sfRenderWindow_getDefaultView(rpg->window);
    battle->zoom_xy.x = 0;
    battle->zoom_xy.y = -250;
    rect.height = 130;
    rect.left = 420;
    rect.top = 420;
    rect.width = 190;
    battle->view = sfView_createFromRect(rect);
    sfView_move(battle->view, battle->zoom_xy);
}

void define_battle_struct(battle_t *battle, rpg_t *rpg, pokemon_t **pokemon)
{
    who_is_alive_pkmn_battle(pokemon, rpg, battle);
    choose_random_pkmn_battle(battle, rpg);
    battle->interface.sprite = image2sprite("./assets/sprite/battle.png");
    battle->pkbl = malloc(sizeof(obj_t));
    battle->pkbl->sprite = image2sprite("./assets/sprite/pokeball_interface.png");
    battle->pkmn_life = malloc(sizeof(life_t));
    battle->random_pkmn_life = malloc(sizeof(life_t));
    define_value_n_clock_battle(battle);
    define_view_battle(battle, rpg);
    define_scale_pos_battle(battle, pokemon);
    create_life(battle->random_pkmn_life, battle->random_pkmn, 15, 133);
    create_life(battle->pkmn_life, pokemon[battle->i_pkmn], 730, 280);
    sfMusic_pause(rpg->game->music);
    battle->battle_wild= sfMusic_createFromFile("assets/audio/battle_wild.ogg");
    sfMusic_play(battle->battle_wild);
    sfMusic_setLoop(battle->battle_wild, sfTrue);
    sfRenderWindow_setMouseCursorVisible(rpg->window, sfTrue);
}