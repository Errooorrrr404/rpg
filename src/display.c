/*
** EPITECH PROJECT, 2019
** display.c
** File description:
** display.c
*/

#include "rpg.h"
#include "my.h"

void set_element_bag(pkmn_player_t *pkmn_bag, int pos[2], int i)
{
    sfVector2f scale = {.x = 0.75, .y = 0.75};

    pkmn_bag->pokemon[i]->name_pos =
    set_position_csfml(pos[0] - 100, pos[1] + 25);
    pkmn_bag->pokemon[i]->level_pos =
    set_position_csfml(pos[0] - 100, pos[1] + 40);
    sfText_setPosition(pkmn_bag->pokemon[i]->name_pkmn,
    pkmn_bag->pokemon[i]->name_pos);
    sfText_setPosition(pkmn_bag->pokemon[i]->level_pkmn,
    pkmn_bag->pokemon[i]->level_pos);
    sfSprite_setScale(pkmn_bag->pokemon[i]->pkmn, scale);
    pkmn_bag->pokemon[i]->pos_pkmn =
    set_position_csfml(pos[0], pos[1]);
    sfSprite_setPosition(pkmn_bag->pokemon[i]->pkmn,
    pkmn_bag->pokemon[i]->pos_pkmn);
    sfSprite_setTextureRect(pkmn_bag->pokemon[i]->pkmn,
    pkmn_bag->pokemon[i]->rect_pkmn);
}

void display_pkmn_menu(pkmn_player_t *pkmn_bag, rpg_t *rpg)
{
    int i;
    int pos[2] = {640, 200};
    int pos_slot[4] = {516, 716, 205, 262};

    //printf("x: %d y: %d\n", rpg->mouse_pos.x, rpg->mouse_pos.y);
    for (i = 0; i != pkmn_bag->nb_pokemon && pkmn_bag->display_stats != 1;) {
        display_pokemon_menu(pkmn_bag, rpg, i, pos);
        if (check_touch_boxe_2(pos_slot, rpg->mouse_pos) == 1 &&
        rpg->event.type == sfEvtMouseButtonPressed) {
            pkmn_bag->display_stats = 1;
            pkmn_bag->pkmn_display_stats = i;
        }
        pos[1] += 75;
        pos_slot[2] += 76;
        pos_slot[3] += 76;
        if (pkmn_bag->display_stats != 1)
        i++;
    }
    if (pkmn_bag->display_stats == 1)
        display_stats(rpg);
}

void display_bag(rpg_t *rpg)
{
    sfText_setPosition(rpg->game->item[0].tx_name, rpg->game->item[0].pos_item);
    sfText_setPosition(rpg->game->item[1].tx_name, rpg->game->item[1].pos_item);
    sfText_setPosition(rpg->game->item[2].tx_name, rpg->game->item[2].pos_item);
    sfText_setPosition(rpg->game->item[0].tx_nb, rpg->game->item[0].pos_nb);
    sfText_setPosition(rpg->game->item[1].tx_nb, rpg->game->item[1].pos_nb);
    sfText_setPosition(rpg->game->item[2].tx_nb, rpg->game->item[2].pos_nb);
    sfRenderWindow_drawSprite(rpg->window, rpg->game->sp_bag, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->game->item[0].tx_name, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->game->item[1].tx_name, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->game->item[2].tx_name, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->game->item[0].tx_nb, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->game->item[1].tx_nb, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->game->item[2].tx_nb, NULL);
    display_pkmn_menu(rpg->game->pkmn_bag, rpg);
}

void display_map_labo(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->game->sp_player, rpg->game->pos_player);
    sfSprite_setTextureRect(rpg->game->sp_player, rpg->game->rect_player);
    sfSprite_setPosition(rpg->game->sp_map, rpg->game->pos_map);
    sfSprite_setPosition(rpg->game->sp_bag, rpg->game->pos_bag);
    sfSprite_setPosition(rpg->game->sp_labo, rpg->game->pos_map);
    if (display_houses_or_map(rpg) == 1) {
        sfRenderWindow_drawSprite(rpg->window, rpg->game->sp_labo, NULL);
        labo_inside_box(rpg);
        market_center_inside(rpg);
        houses_box_inside(rpg);
    } else {
        sfRenderWindow_drawSprite(rpg->window, rpg->game->sp_map, NULL);
        init_hit_box(rpg);
    }
}

void display_all(rpg_t *rpg)
{
    float grass_1[4] = {-705, -561.60, -580, -470};
    float grass_2[4] = {-1092.20, -940, -710, -405.01};

    get_time_game_loop(rpg->game, &rpg->game->clock_cb);
    if (rpg->game->pos_map.x > -800)
        my_hiy_box_2(rpg, grass_1);
    else
        my_hiy_box_2(rpg, grass_2);
    display_map_labo(rpg);
    sfRenderWindow_drawSprite(rpg->window, rpg->game->sp_player, NULL);
    if (rpg->game->disp_bag == 1) {
        sfRenderWindow_setMouseCursorVisible(rpg->window, sfTrue);
        display_bag(rpg);
    } else if (rpg->game->disp_pause == 1) {
        sfRenderWindow_setMouseCursorVisible(rpg->window, sfTrue);
        menu_pause(rpg);
    } else
        sfRenderWindow_setMouseCursorVisible(rpg->window, sfFalse);
}
