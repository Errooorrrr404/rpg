/*
** EPITECH PROJECT, 2019
** event.c
** File description:
** event.c
*/

#include "rpg.h"
#include "my.h"

void event_menu(rpg_t *rpg)
{
    int pos_play[4] = {420, 540, 280, 315};
    int pos_quit[4] = {420, 540, 370, 407};

    if (rpg->event.type == sfEvtMouseButtonPressed && rpg->status == 0) {
        rpg->status = 1;
    } else if (rpg->event.type == sfEvtMouseButtonPressed && rpg->status == 1) {
        if (check_touch_boxe_2(pos_play, rpg->mouse_pos) == 1) {
            rpg->game_state = 1;
            sfMusic_pause(rpg->menu->music);
            sfMusic_play(rpg->menu->music_intro);
        }
        if (check_touch_boxe_2(pos_quit, rpg->mouse_pos) == 1)
            sfRenderWindow_close(rpg->window);
    }
}

void mouse_game(rpg_t *rpg)
{
    int pos_play[4] = {420, 540, 280, 315};
    int pos_quit[4] = {420, 540, 370, 407};

    if (rpg->event.type == sfEvtMouseButtonPressed && rpg->status == 0) {
        rpg->status = 1;
    } else if (rpg->event.type == sfEvtMouseButtonPressed && rpg->status == 1) {
        if (check_touch_boxe_2(pos_play, rpg->mouse_pos) == 1)
            rpg->game->disp_pause = 0;
        if (check_touch_boxe_2(pos_quit, rpg->mouse_pos) == 1)
            sfRenderWindow_close(rpg->window);
    }
}

void event_game(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyI && rpg->event.type == sfEvtKeyPressed) {
        if (rpg->game->disp_bag == 0)
            rpg->game->disp_bag = 1;
        else {
            rpg->game->disp_bag = 0;
            if (rpg->game->pkmn_bag->display_stats == 1)
                rpg->game->pkmn_bag->display_stats = 0;
        }
    }
    if (rpg->event.key.code == sfKeyEscape
        && rpg->event.type == sfEvtKeyPressed) {
        if (rpg->game->disp_pause == 0)
            rpg->game->disp_pause = 1;
        else {
            rpg->game->disp_pause = 0;
            if (rpg->game->pkmn_bag->display_stats == 1)
                rpg->game->pkmn_bag->display_stats = 0;
        }
    }
    mouse_game(rpg);
}

void event(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
    if (rpg->game_state == 0)
        event_menu(rpg);
    if (rpg->game_state == 2)
        event_game(rpg);
}
