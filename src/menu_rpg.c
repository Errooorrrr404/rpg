/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** menu_rpg
*/

#include "rpg.h"
#include "my.h"

void menu_rpg(rpg_t *rpg)
{
    int pos_play[4] = {420, 540, 280, 315};
    int pos_quit[4] = {420, 540, 370, 407};

    if (rpg->status == 0) {
        sfRenderWindow_drawSprite(
        rpg->window, rpg->menu->how_to_play->before_playing, NULL);
    } else {
        if (check_touch_boxe_2(pos_play, rpg->mouse_pos) == 1)
            sfText_setColor(rpg->menu->play, sfRed);
        else
            sfText_setColor(rpg->menu->play, sfWhite);
        if (check_touch_boxe_2(pos_quit, rpg->mouse_pos) == 1)
            sfText_setColor(rpg->menu->quit, sfRed);
        else
            sfText_setColor(rpg->menu->quit, sfWhite);
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->sp_menu, NULL);
        sfText_setPosition(rpg->menu->play, rpg->menu->pos_play);
        sfText_setPosition(rpg->menu->quit, rpg->menu->pos_quit);
        sfRenderWindow_drawText(rpg->window, rpg->menu->play, NULL);
        sfRenderWindow_drawText(rpg->window, rpg->menu->quit, NULL);
    }
}

void menu_pause(rpg_t *rpg)
{
    int pos_play[4] = {420, 540, 280, 315};
    int pos_quit[4] = {420, 540, 370, 407};
    
    if (check_touch_boxe_2(pos_play, rpg->mouse_pos) == 1)
        sfText_setColor(rpg->menu->play, sfRed);
    else
        sfText_setColor(rpg->menu->play, sfWhite);
    if (check_touch_boxe_2(pos_quit, rpg->mouse_pos) == 1)
        sfText_setColor(rpg->menu->quit, sfRed);
    else
        sfText_setColor(rpg->menu->quit, sfWhite);
    sfText_setPosition(rpg->menu->play, rpg->menu->pos_play);
    sfText_setPosition(rpg->menu->quit, rpg->menu->pos_quit);
    sfRenderWindow_drawText(rpg->window, rpg->menu->play, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->menu->quit, NULL);
}
