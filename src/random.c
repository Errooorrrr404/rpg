/*
** EPITECH PROJECT, 2019
** ALEXIS DESRUMAUX
** File description:
** file.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "my.h"
#include "rpg.h"

int *binare_tab(int lower, int upper, int max)
{
    int nb = lower;
    int j = 0;
    int *alea = malloc(sizeof(int) * max);

    if (!alea)
        return NULL;
    while (j != max) {
        if (nb == upper + 1)
            nb = lower;
        alea[j] = nb;
        nb++;
        j++;
    }
    return (alea);
}

int random_value(int lower, int upper, int max, int *alea)
{
    int i = 0;

    i = alea[rand() % max + (0 + 1)];
    return (i);
}

//void resize_mouse2(rpg_t *rpg)
//{
//    sfVector2u size_window;
//    size_window = sfRenderWindow_getSize(rpg->window);
//    rpg->mouse_pos.x = (rpg->event.mouseMove.x * 960) / size_window.x;
//    rpg->mouse_pos.y = (rpg->event.mouseMove.y * 540) / size_window.y;
//}

void resize_mouse(rpg_t *rpg)
{
    rpg->size_window = sfRenderWindow_getSize(rpg->window);
    rpg->old_mouse_pos = sfMouse_getPositionRenderWindow(rpg->window);
    rpg->mouse_pos.x = rpg->old_mouse_pos.x * 960 / rpg->size_window.x;
    rpg->mouse_pos.y = rpg->old_mouse_pos.y * 540 / rpg->size_window.y;

}