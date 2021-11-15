/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** how_to_play_state
*/

#include <SFML/Graphics/Font.h>
#include "rpg.h"
#include "my.h"

void state_is_three(rpg_t *rpg, int next[4])
{
    if (check_touch_boxe_2(next, rpg->mouse_pos) == 1) {
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->how_to_play->h4_2,
        NULL);
        if (rpg->event.type == sfEvtMouseButtonPressed &&
        rpg->menu->how_to_play->seconds > 1) {
            rpg->menu->how_to_play->state = 4;
            sfClock_restart(rpg->menu->how_to_play->cl_move);
        }
    } else
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->how_to_play->h4_1,
        NULL);
}

void exec_state_two(rpg_t *rpg, char *tmp, int size, sfFont *font)
{
    sfVector2f pos = {400, 220};

    if ((rpg->event.type == sfEvtTextEntered || rpg->event.type ==
    sfEvtKeyPressed) && rpg->menu->how_to_play->seconds > 0.1) {
        put_player_name(rpg, 15);
        rpg->menu->how_to_play->name[rpg->menu->how_to_play->size] = '\0';
        sfClock_restart(rpg->menu->how_to_play->cl_move);
    }
    sfText_setFont(rpg->menu->how_to_play->name_player, font);
    sfText_setString(rpg->menu->how_to_play->name_player,
    rpg->menu->how_to_play->name);
    exec_stat_two(rpg, pos, font);
}

void state_is_two(rpg_t *rpg, int next[4])
{
    char *tmp = rpg->menu->how_to_play->name;
    int size = 0;
    sfFont* font = sfFont_createFromFile("assets/font/pkmn.ttf");

    if (check_touch_boxe_2(next, rpg->mouse_pos) == 1) {
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->how_to_play->h3_2,
        NULL);
        if (rpg->event.type == sfEvtMouseButtonPressed &&
        rpg->menu->how_to_play->seconds > 1) {
            rpg->menu->how_to_play->state = 3;
            sfClock_restart(rpg->menu->how_to_play->cl_move);
        }
    } else
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->how_to_play->h3_1,
        NULL);
    if (rpg->event.key.code == sfKeyReturn) {
        rpg->menu->how_to_play->state = 3;
        free (rpg->menu->how_to_play->name);
        sfClock_restart(rpg->menu->how_to_play->cl_move);
    }
    exec_state_two(rpg, tmp, size, font);
}

void state_is_one(rpg_t *rpg, int next[4], int previous[4])
{
    if (check_touch_boxe_2(next, rpg->mouse_pos) == 1) {
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->how_to_play->h2_3,
        NULL);
        if (rpg->event.type == sfEvtMouseButtonPressed &&
        rpg->menu->how_to_play->seconds > 1) {
            rpg->menu->how_to_play->state = 3;
            sfClock_restart(rpg->menu->how_to_play->cl_move);
        }
    } else if (check_touch_boxe_2(previous, rpg->mouse_pos) == 1) {
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->how_to_play->h2_2,
        NULL);
        if (rpg->event.type == sfEvtMouseButtonPressed &&
        rpg->menu->how_to_play->seconds > 1) {
            rpg->menu->how_to_play->state = 0;
            sfClock_restart(rpg->menu->how_to_play->cl_move);
        }
    } else
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->how_to_play->h2_1,
        NULL);
}

void state_is_zero(rpg_t *rpg, int next[4])
{
    if (check_touch_boxe_2(next, rpg->mouse_pos) == 1) {
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->how_to_play->h1_2,
        NULL);
        if (rpg->event.type == sfEvtMouseButtonPressed &&
        rpg->menu->how_to_play->seconds > 1) {
            rpg->menu->how_to_play->state = 1;
            sfClock_restart(rpg->menu->how_to_play->cl_move);
        }
    } else
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->how_to_play->h1_1,
        NULL);
}