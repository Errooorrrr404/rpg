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

int event_battle(rpg_t *rpg, battle_t *battle, pokemon_t **pokemon)
{
    int box1[5] = {470, 540, 470, 540};
    
    if (rpg->event.type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
    if (rpg->event.type == sfEvtMouseButtonPressed
    && check_touch_boxe_2(box1, rpg->mouse_pos))
        battle->turn = 5;
    else
        return (choose_capacity_battle(rpg, battle));
}

void manage_life(sfRenderWindow* window, life_t *life, float pos_x, float pos_y)
{
    sfVector2f position = {pos_x, pos_y};
    sfVector2f size_life_now = {size_life_now.x = 0,
    size_life_now.y = life->size_life.y};
    size_life_now.x = (life->size_life.x * life->life) / life->life_max;

    sfSprite_setPosition(life->sp_life, position);
    sfRenderWindow_drawSprite(window, life->sp_life, NULL);
    sfRectangleShape_setSize(life->rect_life, size_life_now);
    sfRectangleShape_setFillColor(life->rect_life, sfGreen);
    sfRectangleShape_setPosition(life->rect_life, position);
    sfRenderWindow_drawRectangleShape(window, life->rect_life,
    NULL);
}

void create_life(life_t *life, pokemon_t *pokemon, int pos_x, int pos_y)
{
    sfVector2f scale = {0.5, 0.5};

    life->sp_life = image2sprite("./assets/sprite/life.png");
    sfSprite_setScale(life->sp_life, scale);
    life->size_life.x = 180;
    life->life = pokemon->current_pv;
    life->life_max = pokemon->pv;
    life->size_life.y = 9;
    life->pos_life.x = pos_x;
    life->pos_life.y = pos_y;
    life->rect_life = sfRectangleShape_create();
}

void define_color_moves_battle(capacity_t **moves, int nbmoves)
{
    int k = 0;

    for (; k != nbmoves; k++)
        sfText_setColor(moves[k]->name_ct, sfBlack);
}

void set_position_draw_moves_loop(pokemon_t **pokemon,
rpg_t *rpg, battle_t *battle)
{
    capacity_t **moves = pokemon[battle->i_pkmn]->moves;
    int k = 0;
    int pos_x[5] = {570, 750, 570, 750};
    int pos_y[5] = {404, 404, 484, 484};

    for (; k != pokemon[battle->i_pkmn]->nbmoves; k++) {
        sfText_setCharacterSize(pokemon[battle->i_pkmn]->moves[k]->name_ct, 15);
        pokemon[battle->i_pkmn]->moves[k]->name_pos =
        set_position_csfml(pos_x[k], pos_y[k]);
        sfText_setPosition(pokemon[battle->i_pkmn]->moves[k]->name_ct,
        pokemon[battle->i_pkmn]->moves[k]->name_pos);
        sfRenderWindow_drawText(rpg->window,
        pokemon[battle->i_pkmn]->moves[k]->name_ct, NULL);
    }
    manage_life(rpg->window, battle->random_pkmn_life,
    battle->random_pkmn_life->pos_life.x,
    battle->random_pkmn_life->pos_life.y);
    manage_life(rpg->window, battle->pkmn_life,
    battle->pkmn_life->pos_life.x, battle->pkmn_life->pos_life.y);
}