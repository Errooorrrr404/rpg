/*
** EPITECH PROJECT, 2019
** free.c
** File description:
** free.c
*/

#include "rpg.h"
#include "my.h"

void free_htp(htp_t *htp)
{
    sfSprite_destroy(htp->h1_1);
    sfSprite_destroy(htp->h1_2);
    sfSprite_destroy(htp->h2_1);
    sfSprite_destroy(htp->h2_2);
    sfSprite_destroy(htp->h2_3);
    sfSprite_destroy(htp->h3_1);
    sfSprite_destroy(htp->h3_2);
    sfSprite_destroy(htp->h4_1);
    sfSprite_destroy(htp->h4_2);
    sfSprite_destroy(htp->h5_1);
    sfSprite_destroy(htp->h5_2);
    sfSprite_destroy(htp->h5_3);
    sfSprite_destroy(htp->h6_1);
    sfSprite_destroy(htp->h6_2);
    sfSprite_destroy(htp->h6_3);
    sfSprite_destroy(htp->before_playing);
    sfClock_destroy(htp->cl_move);
}

void free_menu(menu_t *menu)
{
    free_htp(menu->how_to_play);
    sfSprite_destroy(menu->sp_menu);
    sfMusic_stop(menu->music);
    sfMusic_destroy(menu->music);
}

void free_item(item_t *item)
{
    sfText_destroy(item[0].tx_name);
    sfText_destroy(item[1].tx_name);
    sfText_destroy(item[2].tx_name);
    sfText_destroy(item[0].tx_nb);
    sfText_destroy(item[1].tx_nb);
    sfText_destroy(item[2].tx_nb);
    free(item[0].nb);
    free(item[1].nb);
    free(item[2].nb);
}

void free_game(game_t *game)
{
    sfMusic_stop(game->music);
    sfSprite_destroy(game->sp_map);
    sfSprite_destroy(game->sp_player);
    sfClock_destroy(game->cl_move);
    sfSprite_destroy(game->sp_bag);
}

void free_rpg(rpg_t *rpg)
{
    free_menu(rpg->menu);
    if (rpg->game_state >= 2) {
        free_game(rpg->game);
        free_item(rpg->game->item);
        free(rpg->game);
    }
    free(rpg->menu);
    free(rpg);
    sfRenderWindow_destroy(rpg->window);
}