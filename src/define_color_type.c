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

sfColor create_sfcolor_tab(int a, int r, int g, int b)
{
    sfColor color;

    color.a = a;
    color.r = r;
    color.g = g;
    color.b = b;
    return (color);
}

sfColor *define_color_type(void)
{
    sfColor *color = malloc(sizeof(sfColor) * 12);

    color[0] = create_sfcolor_tab(200, 1, 189, 0);
    color[1] = create_sfcolor_tab(200, 87, 67, 39);
    color[2] = create_sfcolor_tab(200, 143, 112, 49);
    color[3] = create_sfcolor_tab(200, 142, 0, 15);
    color[4] = create_sfcolor_tab(200, 0, 72, 218);
    color[5] = create_sfcolor_tab(100, 1, 101, 101);
    color[6] = create_sfcolor_tab(100, 123, 126, 132);
    color[7] = create_sfcolor_tab(100, 101, 152, 255);
    color[8] = create_sfcolor_tab(100, 12, 147, 66);
    color[9] = create_sfcolor_tab(100, 215, 214, 23);
    color[10] = create_sfcolor_tab(100, 1, 1, 1);
    return (color);
}

void switch_color_pkmn2(int i, sfText *type_pkmn, sfColor *color)
{
    switch (i) {
        case 5:
            sfText_setColor(type_pkmn, color[5]);
            break;
        case 6:
            sfText_setColor(type_pkmn, color[6]);
            break;
        case 7:
            sfText_setColor(type_pkmn, color[7]);
            break;
        case 8:
            sfText_setColor(type_pkmn, color[8]);
            break;
        case 9:
            sfText_setColor(type_pkmn, color[9]);
            break;
        case 10:
            sfText_setColor(type_pkmn, color[10]);
            break;
    }
}

void switch_color_pkmn(int i, sfText *type_pkmn)
{
    sfColor *color = define_color_type();
    switch (i) {
        case 0:
            sfText_setColor(type_pkmn, color[0]);
            break;
        case 1:
            sfText_setColor(type_pkmn, color[1]);
            break;
        case 2:
            sfText_setColor(type_pkmn, color[2]);
            break;
        case 3:
            sfText_setColor(type_pkmn, color[3]);
            break;
        case 4:
            sfText_setColor(type_pkmn, color[4]);
            break;
    }
    switch_color_pkmn2(i, type_pkmn, color);
}

void color_by_type_pkmn(pokemon_t *pokemon)
{
    int i = 0;
    int k = 0;
    char *type[12] = {"PLANTE", "SOL", "FEU", "COMBAT", "EAU",
    "ACIER", "NORMAL", "VOL", "INSECTE", "ELEKTRIK", "NULL", NULL};
    sfText *type_text[4] = {pokemon->type1_pkmn, pokemon->type2_pkmn,
    pokemon->type3_pkmn};

    for (; k != 3; k++) {
        for (; match_str(pokemon->type[k], type[i]) != 1; i++);
        switch_color_pkmn(i, type_text[k]);
        i = 0;
    }
}