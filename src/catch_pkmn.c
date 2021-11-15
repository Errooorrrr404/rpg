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

void after_try_catch(rpg_t *rpg, battle_t *battle, pokemon_t **pokemon)
{
    if (battle->catch_pkmn_clk.seconds > 5 && battle->gotcha == 0) {
        sfMusic_play(battle->random_pkmn->sound);
        sfClock_restart(battle->catch_pkmn_clk.clock_type);
        battle->display_pkmn_wild = 1;
        sfClock_restart(battle->rdm_attack_clk.clock_type);
        battle->turn = 2;
    }
    else if (battle->catch_pkmn_clk.seconds > 5 && battle->gotcha == 1) {
        sfMusic_stop(battle->battle_wild);
        sfMusic_play(battle->catch_sucess);
        sfClock_restart(battle->catch_pkmn_clk.clock_type);
        get_time_custom(&battle->catch_pkmn_clk);
        while (battle->catch_pkmn_clk.seconds < 8)
            get_time_custom(&battle->catch_pkmn_clk);
        sfMusic_stop(battle->catch_sucess);
        battle->stop = 1;
    }
}

void cinematic_pkmn_catch(rpg_t *rpg, battle_t *battle, pokemon_t **pokemon)
{
    get_time_custom(&battle->catch_pkmn_clk);
    if (battle->catch_pkmn_clk.seconds < 5) {
        battle->display_pkmn_wild = 0;
        get_time_custom(&battle->catch_effect_clk);
        if (battle->catch_effect_clk.seconds < 1)
            sfSprite_setRotation(battle->pkbl_catch->sprite, 15);
        else if (battle->catch_effect_clk.seconds > 1 && battle->catch_effect_clk.seconds < 2)
            sfSprite_setRotation(battle->pkbl_catch->sprite, 0);
        else
            sfClock_restart(battle->catch_effect_clk.clock_type);
        sfSprite_setPosition(battle->pkbl_catch->sprite, battle->pkbl_catch->sprite_p);
        sfRenderWindow_drawSprite(rpg->window, battle->pkbl_catch->sprite, NULL);
    }
    after_try_catch(rpg, battle, pokemon);
}

void define_pkmn_catch(battle_t *battle, pokemon_t **pokemon)
{
    int *gotcha_alea = binare_tab(0, 1, 100);

    battle->gotcha =
    random_value(0, 1, 100, gotcha_alea);
    free(gotcha_alea);
    battle->pkbl_catch = malloc(sizeof(obj_t));
    battle->pkbl_catch->sprite = image2sprite
    ("./assets/sprite/pokeball.png");
    battle->pkbl_catch->sprite_p = set_position_csfml(485, 250);
    battle->catch_pkmn_clk.clock_type = sfClock_create();
    battle->catch_effect_clk.clock_type = sfClock_create();
    battle->pkbl_catch_sound = sfMusic_createFromFile
    ("assets/audio/pokeball.ogg");
    battle->catch_sucess = sfMusic_createFromFile
    ("assets/audio/catch_pkmn.ogg");
    sfMusic_play(battle->pkbl_catch_sound);
    battle->turn = 6;
}