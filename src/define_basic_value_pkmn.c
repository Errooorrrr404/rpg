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

int add_sprite_text_stats(pokemon_t *pkmn, char *level)
{
    if (!pkmn->pkmn_battle)
        return 84;
    pkmn->rect_pkmn_battle.top = 80 * pkmn->case_pos_y;
    pkmn->rect_pkmn_battle.left = 80 * pkmn->case_pos_x;
    pkmn->rect_pkmn_battle.width = 80;
    pkmn->rect_pkmn_battle.height = 80;
    pkmn->rect_pkmn.top = 80 * pkmn->case_pos_y;
    pkmn->rect_pkmn.left = 80 * pkmn->case_pos_x;
    pkmn->rect_pkmn.width = 80;
    pkmn->rect_pkmn.height = 80;
    pkmn->name_pkmn = string2text("assets/font/pkmn.ttf", pkmn->name, 12);
    pkmn->level_pkmn = string2text("assets/font/pkmn.ttf", level, 9);
    pkmn->type1_pkmn = string2text("assets/font/pkmn.ttf", pkmn->type[0], 14);
    pkmn->type2_pkmn = string2text("assets/font/pkmn.ttf", pkmn->type[1], 14);
    pkmn->type3_pkmn = string2text("assets/font/pkmn.ttf", pkmn->type[2], 14);
    if (!pkmn->name_pkmn || !pkmn->level_pkmn || !pkmn->type1_pkmn
    || !pkmn->type2_pkmn || !pkmn->type3_pkmn)
        return 84;
    free(level);
    return 0;
}

int add_sprite_pkmn(pokemon_t *pkmn)
{
    char *level_number = malloc(sizeof(char) * 10);
    char *level;

    if (!level_number)
        return 84;
    level_number = int2char(level_number, pkmn->level);
    level = malloc(sizeof(char) * (30 + my_strlen(level_number)));
    if (!level)
        return 84;
    level = my_strcpy(level, "N. ");
    level = strconcate(level, level_number);
    pkmn->pkmn = image2sprite("assets/sprite/sprite_pokemon_menu.png");
    if (!pkmn->pkmn)
        return 84;
    pkmn->pkmn_battle = image2sprite("assets/sprite/sprite_pokemon_battle.png");
    if (add_sprite_text_stats(pkmn, level) == 84)
        return 84;
    free(level_number);
    return 0;
}

int define_basic_stats_pkmn(int i, char *level, char **pokemon_params,
pokemon_t *pokemon)
{
    int level_nb;

    pokemon->level = my_putint(level);
    level_nb = pokemon->level - 1;
    pokemon->pv = catch_str_int(0, ':', pokemon_params[i], '\0');
    pokemon->pv = (((2 * pokemon->pv + 31 + (1/4)) * level_nb) /100) + level_nb + 10;
    pokemon->current_pv = pokemon->pv;
    pokemon->attaque = catch_str_int(0, ':', pokemon_params[i + 1], '\0');
    pokemon->attaque = ((((2 * pokemon->attaque + 31 + (1/4)) * level_nb) / 100) + 5) * 1;
    pokemon->defense = catch_str_int(0, ':', pokemon_params[i + 2], '\0');
    pokemon->defense = ((((2 * pokemon->defense + 31 + (1/4)) * level_nb) / 100) + 5) * 1;
    pokemon->vitesse = catch_str_int(0, ':', pokemon_params[i + 3], '\0');
    pokemon->vitesse = ((((2 * pokemon->vitesse + 31 + (1/4)) * level_nb) / 100) + 5) * 1;
    if (pokemon->attaque == -1 || pokemon->defense == -1 ||
    pokemon->vitesse == -1)
        return 84;
    return 0;
}

int move_by_level(int i, char **pokemon_params, pokemon_t *pokemon)
{
    int nb_capacity = 0;
    int k = i;
    int j = 0;

    for (; match_str(pokemon_params[k], "#STATS") != 1; k++, nb_capacity++);
    pokemon->capacity = define_strtab(sizeof(char *) * (nb_capacity + 2));
    pokemon->level_capacity = define_strtab(sizeof(char *) * (nb_capacity + 2));
    if (!pokemon->capacity || !pokemon->level_capacity)
        return -1;
    for (; match_str(pokemon_params[i], "#STATS") != 1; i++, j++) {
        pokemon->capacity[j] = catch_str(0, '\0', pokemon_params[i], ' ');
        pokemon->level_capacity[j] = catch_str(0, ' ', pokemon_params[i], '\0');
        if (!pokemon->capacity[j] || !pokemon->level_capacity[j])
            return -1;
    }
    return (i);
}

int add_basic_parameters(pokemon_t *pkmn, int line, char **pkmn_p,
int id_pkmn)
{
    char *str = NULL;

    if (!pkmn)
        return 84;
    pkmn->id = id_pkmn;
    pkmn->name = catch_str(0, ':', pkmn_p[line + 1], '\0');
    pkmn->case_pos_x = catch_str_int(0, ':', pkmn_p[line + 2], '\0');
    pkmn->case_pos_y = catch_str_int(0, ':', pkmn_p[line + 3], '\0');
    str = catch_str(0, ':', pkmn_p[line + 4], '\0');
    if (add_basic_parameter(str, pkmn, pkmn_p, line) == 84)
        return 84;
    pkmn->type = define_strtab(sizeof(char *) * 4);
    pkmn->type[0] = catch_str(0, ':', pkmn_p[line + 6], '\0');
    pkmn->type[1] = catch_str(0, ':', pkmn_p[line + 7], '\0');
    pkmn->type[2] = catch_str(0, ':', pkmn_p[line + 8], '\0');
    if (!pkmn->type || !pkmn->type[0] || !pkmn->type[1] ||
    !pkmn->type[2])
        return 84;
    return 0;
}